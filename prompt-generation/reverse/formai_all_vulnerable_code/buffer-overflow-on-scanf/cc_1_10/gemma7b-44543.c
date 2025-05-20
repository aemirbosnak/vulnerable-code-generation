//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function to convert hexadecimal to decimal
int hex_to_dec(char hex)
{
    // Convert hex character to uppercase
    hex = toupper(hex);

    // Check if character is a number or letter
    if (hex >= 'A' && hex <= 'F')
    {
        // Subtract 58 from character to get decimal value
        return hex - 58;
    }
    else
    {
        // Return -1 for invalid character
        return -1;
    }
}

int main()
{
    // Get the hexadecimal number from the user
    char hex_num[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_num);

    // Convert the hexadecimal number to decimal
    int dec_num = 0;
    int i = 0;
    while (hex_num[i] != '\0')
    {
        // Get the hexadecimal character
        char hex_char = hex_num[i];

        // Convert the character to decimal
        int hex_dec = hex_to_dec(hex_char);

        // Multiply the decimal value by the appropriate power of 16
        int dec_pow = 1;
        for (int j = 0; j < i; j++)
        {
            dec_pow *= 16;
        }

        // Add the decimal value to the decimal number
        dec_num += hex_dec * dec_pow;

        // Increment the index
        i++;
    }

    // Print the decimal number
    printf("The decimal number is: %d\n", dec_num);

    return 0;
}