//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void convert_hex_to_decimal(char hex_number[]);
void convert_decimal_to_hex(int decimal_number);

int main()
{
    printf("Welcome to Hexadecimal Converter!\n\n");
    printf("Select an option:\n");
    printf("1. Convert Hexadecimal to Decimal\n");
    printf("2. Convert Decimal to Hexadecimal\n");
    printf("Enter a choice: ");

    int choice;
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        {
            char hex_number[100];
            printf("\nEnter the hexadecimal number: ");
            scanf("%s", hex_number);
            convert_hex_to_decimal(hex_number);
            break;
        }
        case 2:
        {
            int decimal_number;
            printf("\nEnter the decimal number: ");
            scanf("%d", &decimal_number);
            convert_decimal_to_hex(decimal_number);
            break;
        }
        default:
        {
            printf("\nInvalid choice. Please select 1 or 2.\n");
            break;
        }
    }

    return 0;
}

void convert_hex_to_decimal(char hex_number[])
{
    int hexadecimal_len = strlen(hex_number);
    int decimal_number = 0;

    for (int i = 0; hex_number[i] != '\0'; i++)
    {
        int decimal_value;

        if (hex_number[i] >= '0' && hex_number[i] <= '9')
        {
            decimal_value = hex_number[i] - 48;
        }
        else if (hex_number[i] >= 'a' && hex_number[i] <= 'f')
        {
            decimal_value = hex_number[i] - 87;
        }
        else if (hex_number[i] >= 'A' && hex_number[i] <= 'F')
        {
            decimal_value = hex_number[i] - 55;
        }

        decimal_number += decimal_value * pow(16, hexadecimal_len - 1 - i);
    }

    printf("\nThe decimal number of %s is %d\n", hex_number, decimal_number);
}

void convert_decimal_to_hex(int decimal_number)
{
    char hex_number[100];
    int i = 0;

    while (decimal_number != 0)
    {
        int remainder = decimal_number % 16;
        if (remainder < 10)
        {
            hex_number[i++] = 48 + remainder;
        }
        else
        {
            hex_number[i++] = 55 + remainder;
        }
        decimal_number /= 16;
    }

    if (i == 0)
    {
        printf("\nThe hexadecimal number of 0 is 0\n");
    }
    else
    {
        printf("\nThe hexadecimal number of %d is ", decimal_number);
        for (int j = i - 1; j >= 0; j--)
        {
            printf("%c", hex_number[j]);
        }
        printf("\n");
    }
}