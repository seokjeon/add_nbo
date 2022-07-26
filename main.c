#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char** argv)
{
    char *first_operand_path = argv[1];
    char *second_operand_path = argv[2];

    FILE *pfirst = fopen(first_operand_path, "rb");
    FILE *psecond = fopen(second_operand_path, "rb");

    uint32_t first_operand = 0;
    uint32_t second_operand = 0;
    uint32_t sum = 0;

    fread(&first_operand, sizeof(first_operand), 1, pfirst);
    fread(&second_operand, sizeof(second_operand), 1, psecond);

    fclose(pfirst);
    fclose(psecond);

    first_operand = ntohl(first_operand);
    second_operand = ntohl(second_operand);
    sum = first_operand + second_operand;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", first_operand, first_operand, second_operand, second_operand, sum, sum);

    return 0;
}

