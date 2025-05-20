//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Modular function to convert hex to decimal
int hex_to_decimal(char hex)
{
    // Convert hex character to upper case
    hex = toupper(hex);

    // Check if character is a number or letter
    if ((hex >= 'A') && (hex <= 'F'))
    {
        // Subtract 58 from character to get decimal value
        return 16 + hex - 'A';
    }
    else
    {
        // Return -1 for invalid input
        return -1;
    }
}

int main()
{
    // Get the hexadecimal number from the user
    char hex_number[20];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_number);

    // Convert the hexadecimal number to decimal
    int decimal_value = 0;
    for (int i = 0; hex_number[i] != '\0'; i++)
    {
        // Convert each character in the hexadecimal number to decimal
        int hex_digit = hex_to_decimal(hex_number[i]);

        // If the character is not valid, break out of the loop
        if (hex_digit == -1)
        {
            printf("Invalid input.\n");
            break;
        }

        // Multiply the decimal value by the appropriate power of 16 and add it to the total decimal value
        decimal_value += hex_digit * pow(16, i);
    }

    // Print the decimal value
    if (decimal_value != -1)
    {
        printf("Decimal value: %d\n", decimal_value);
    }

    return 0;
}