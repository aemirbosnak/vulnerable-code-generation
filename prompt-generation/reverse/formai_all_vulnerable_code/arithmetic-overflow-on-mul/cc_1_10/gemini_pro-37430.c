//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal number to its decimal equivalent
int hexToDecimal(char hexValue[])
{
    int len = strlen(hexValue);

    // Initialize the decimal value to 0
    int decimalValue = 0;

    // Iterate over each character in the hexadecimal number
    for (int i = 0; i < len; i++)
    {
        // Get the current character
        char ch = hexValue[i];

        // Check if the character is a digit
        if (ch >= '0' && ch <= '9')
        {
            // Convert the character to its decimal equivalent
            decimalValue = decimalValue * 16 + (ch - '0');
        }
        // Check if the character is an uppercase letter
        else if (ch >= 'A' && ch <= 'F')
        {
            // Convert the character to its decimal equivalent
            decimalValue = decimalValue * 16 + (ch - 'A' + 10);
        }
        // Check if the character is a lowercase letter
        else if (ch >= 'a' && ch <= 'f')
        {
            // Convert the character to its decimal equivalent
            decimalValue = decimalValue * 16 + (ch - 'a' + 10);
        }
        else
        {
            // If the character is not a valid hexadecimal digit, return -1
            return -1;
        }
    }

    // Return the decimal value
    return decimalValue;
}

// Function to convert a decimal number to its hexadecimal equivalent
char *decimalToHex(int decimalValue)
{
    // Create a buffer to store the hexadecimal number
    char *hexValue = (char *)malloc(100);

    // Initialize the buffer to 0
    memset(hexValue, 0, 100);

    // Iterate over the digits of the hexadecimal number
    int i = 0;
    while (decimalValue != 0)
    {
        // Get the remainder of the division by 16
        int remainder = decimalValue % 16;

        // Convert the remainder to a hexadecimal digit
        char digit;
        if (remainder < 10)
        {
            digit = '0' + remainder;
        }
        else
        {
            digit = 'A' + (remainder - 10);
        }

        // Add the hexadecimal digit to the buffer
        hexValue[i++] = digit;

        // Divide the decimal value by 16
        decimalValue /= 16;
    }

    // Reverse the hexadecimal number
    for (int j = 0; j < i / 2; j++)
    {
        char temp = hexValue[j];
        hexValue[j] = hexValue[i - j - 1];
        hexValue[i - j - 1] = temp;
    }

    // Return the hexadecimal number
    return hexValue;
}

// Function to test the hexToDecimal and decimalToHex functions
int main()
{
    // Test the hexToDecimal function
    char hexValue[] = "123456789ABCDEF";
    int decimalValue = hexToDecimal(hexValue);
    printf("The decimal equivalent of %s is %d\n", hexValue, decimalValue);

    // Test the decimalToHex function
    decimalValue = 123456789;
    char *hexValue2 = decimalToHex(decimalValue);
    printf("The hexadecimal equivalent of %d is %s\n", decimalValue, hexValue2);

    return 0;
}