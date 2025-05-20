//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function to convert hexadecimal to decimal
int hex_to_dec(char hex)
{
    int decimal = 0;

    // Convert hex character to uppercase
    hex = toupper(hex);

    // Calculate the decimal value of the hex character
    if (hex >= 'A')
    {
        decimal = hex - 'A' + 10;
    }
    else
    {
        decimal = hex - '0';
    }

    return decimal;
}

int main()
{
    char hex_number[100];
    int i, decimal_number = 0, length = 0;

    // Get the hexadecimal number from the user
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_number);

    // Calculate the length of the hexadecimal number
    for (i = 0; hex_number[i] != '\0'; i++)
    {
        length++;
    }

    // Convert the hexadecimal number to decimal
    for (i = 0; i < length; i++)
    {
        int hex_digit = hex_to_dec(hex_number[i]);
        decimal_number = decimal_number * 16 + hex_digit;
    }

    // Print the decimal number
    printf("Decimal number: %d", decimal_number);

    return 0;
}