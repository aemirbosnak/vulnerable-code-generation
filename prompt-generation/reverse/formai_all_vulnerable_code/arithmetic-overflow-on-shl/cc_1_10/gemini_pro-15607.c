//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_BINARY_DIGITS 32
#define MAX_DECIMAL_DIGITS 10

unsigned int decimal_to_binary(int decimal);
int binary_to_decimal(unsigned int binary);
void print_binary(unsigned int binary);

int main()
{
    int decimal;
    unsigned int binary;
    char buffer[MAX_DECIMAL_DIGITS + 1];

    printf("Enter a decimal integer: ");
    fgets(buffer, sizeof(buffer), stdin);
    decimal = atoi(buffer);

    binary = decimal_to_binary(decimal);
    printf("The binary representation of %d is: ", decimal);
    print_binary(binary);

    binary = binary_to_decimal(binary);
    printf("The decimal representation of %u is: %d\n", binary, binary);

    return 0;
}

unsigned int decimal_to_binary(int decimal)
{
    unsigned int binary = 0;
    int i = 0;

    while (decimal > 0)
    {
        if (decimal % 2 == 1)
        {
            binary |= (1 << i);
        }
        decimal /= 2;
        i++;
    }

    return binary;
}

int binary_to_decimal(unsigned int binary)
{
    int decimal = 0;
    int i = 0;

    while (binary > 0)
    {
        if (binary & 1)
        {
            decimal += (1 << i);
        }
        binary >>= 1;
        i++;
    }

    return decimal;
}

void print_binary(unsigned int binary)
{
    int i;

    for (i = MAX_BINARY_DIGITS - 1; i >= 0; i--)
    {
        if (binary & (1 << i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

    printf("\n");
}