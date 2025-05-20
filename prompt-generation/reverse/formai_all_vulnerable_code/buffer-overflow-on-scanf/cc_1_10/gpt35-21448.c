//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToHex(int);
void hexToDecimal(char*);

int main()
{
    int option;
    printf("********************************************\n");
    printf("*                                          *\n");
    printf("*          C Hexadecimal Converter         *\n");
    printf("*                                          *\n");
    printf("********************************************\n\n");
    printf("Please choose an option:\n");
    printf("1. Decimal to Hexadecimal Conversion\n");
    printf("2. Hexadecimal to Decimal Conversion\n");
    printf("Option: ");
    scanf("%d", &option);
    fflush(stdin);

    switch(option)
    {
        case 1:
            {
                int decimal;
                printf("\nEnter a decimal number: ");
                scanf("%d", &decimal);
                printf("\nHexadecimal equivalent: ");
                decimalToHex(decimal);
                break;
            }
        case 2:
            {
                char hex[10];
                printf("\nEnter a hexadecimal number: ");
                fflush(stdin);
                gets(hex);
                hexToDecimal(hex); 
                break;
            }
        default:
            {
                printf("\nInvalid option!\n");
                break;
            }
    }
    printf("\n"); 
    return 0;
}

void decimalToHex(int decimal)
{
    int remainder;
    if (decimal == 0)
    {
        return;
    }
    else
    {
        remainder = decimal % 16;
        decimalToHex(decimal / 16);
        if (remainder < 10)
        {
            printf("%d", remainder);
        }
        else
        {
            printf("%c", remainder + 55);
        }
    }
}

void hexToDecimal(char* hex)
{
    int length = strlen(hex);
    int decimal = 0;
    for (int i = 0; i < length; i++)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            decimal = decimal * 16 + (hex[i] - '0');
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            decimal = decimal * 16 + (hex[i] - 'a' + 10);
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            decimal = decimal * 16 + (hex[i] - 'A' + 10);
        }
        else
        {
            printf("\nInvalid hexadecimal number!\n");
            return;
        }
    }
    printf("\nDecimal equivalent: %d", decimal);
}