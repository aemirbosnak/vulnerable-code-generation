//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert hexadecimal string to integer
int hex_to_int(char *hex_string)
{
    int length = strlen(hex_string), decimal_value = 0, base = 1;
    for (int i = length - 1; i >= 0; i--)
    {
        // if character lies in 0-9 range, convert it to an integer by subtracting 48
        if (hex_string[i] >= '0' && hex_string[i] <= '9')
        {
            decimal_value += (hex_string[i] - 48) * base;
            base *= 16;
        }
        // if character lies in A-F range, convert it to an integer by subtracting 55
        else if (hex_string[i] >= 'A' && hex_string[i] <= 'F')
        {
            decimal_value += (hex_string[i] - 55) * base;
            base *= 16;
        }
        // if character lies in a-f range, convert it to an integer by subtracting 87
        else if (hex_string[i] >= 'a' && hex_string[i] <= 'f')
        {
            decimal_value += (hex_string[i] - 87) * base;
            base *= 16;
        }
        // if character is not hexadecimal, return -1
        else
        {
            return -1;
        }
    }
    return decimal_value;
}

int main()
{
    char selection;
    char hex_string[50];
    int decimal_value;
    printf("Welcome to the hexadecimal converter!\n");
    while (1)
    {
        printf("Please select which conversion you would like to perform:\n");
        printf("1. Hexadecimal to decimal conversion\n");
        printf("2. Decimal to hexadecimal conversion\n");
        printf("3. Exit the program\n");
        scanf(" %c", &selection);

        switch (selection)
        {
            case '1':
                printf("Please enter a hexadecimal value to convert to decimal:\n");
                scanf(" %s", hex_string);
                decimal_value = hex_to_int(hex_string);
                if (decimal_value != -1)
                {
                    printf("The decimal value of %s is %d\n", hex_string, decimal_value);
                }
                else
                {
                    printf("Invalid hexadecimal value entered. Please try again.\n");
                }
                break;
            case '2':
                printf("Please enter a decimal value to convert to hexadecimal:\n");
                scanf(" %d", &decimal_value);
                if (decimal_value >= 0)
                {
                    printf("The hexadecimal value of %d is %X\n", decimal_value, decimal_value);
                }
                else
                {
                    printf("Invalid decimal value entered. Please try again.\n");
                }
                break;
            case '3':
                printf("Thank you for using the hexadecimal converter! Goodbye.\n");
                exit(0);
            default:
                printf("Invalid selection. Please try again.\n");
        }
    }
    return 0;
}