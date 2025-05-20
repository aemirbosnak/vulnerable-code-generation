//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void dec_to_hex(int decimal_num)
{
    int remainder, quotient;
    char hex_num[100];
    quotient = decimal_num;
    int i = 0;

    while (quotient != 0)
    {
        remainder = quotient % 16;

        if (remainder < 10)
            hex_num[i++] = 48 + remainder;
        else
            hex_num[i++] = 55 + remainder;

        quotient = quotient / 16;
    }
    hex_num[i] = '\0';

    printf("\nHexadecimal number of %d is: ", decimal_num);

    for (int j = strlen(hex_num) - 1; j >= 0; j--)
        printf("%c", hex_num[j]);
}

void hex_to_dec(char hex_num[])
{
    int decimal_num = 0;
    int len = strlen(hex_num);
    int base = 1;

    for (int i = len - 1; i >= 0; i--)
    {
        if (hex_num[i] >= '0' && hex_num[i] <= '9')
        {
            decimal_num += (hex_num[i] - 48) * base;
            base *= 16;
        }
        else if (hex_num[i] >= 'A' && hex_num[i] <= 'F')
        {
            decimal_num += (hex_num[i] - 55) * base;
            base *= 16;
        }
    }
    printf("\nDecimal number of %s is %d\n", hex_num, decimal_num);
}

int main()
{
    int choice;
    int decimal_num;
    char hex_num[100];

    printf("Welcome to the Hexadecimal Converter\n");
    do
    {
        printf("\nConvert:\n");
        printf("1. Decimal to Hexadecimal\n");
        printf("2. Hexadecimal to Decimal\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the decimal number: ");
            scanf("%d", &decimal_num);
            dec_to_hex(decimal_num);
            break;
        case 2:
            printf("\nEnter the hexadecimal number: ");
            scanf("%s", &hex_num);
            hex_to_dec(hex_num);
            break;
        case 3:
            printf("\nThank you for using the Hexadecimal Converter. Goodbye!\n");
            exit(0);
        default:
            printf("\nInvalid choice. Please choose again.\n");
        }
    } while (choice != 3);

    return 0;
}