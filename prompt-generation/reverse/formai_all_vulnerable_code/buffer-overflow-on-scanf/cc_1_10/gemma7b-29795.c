//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: brave
// Hexadecimal Converter with a sprinkle of unicorn dust

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of digits in the hexadecimal number
#define MAX_DIGITS 16

// Function to convert hexadecimal to decimal
int hex_to_dec(char hex_digit)
{
    // Convert the character to uppercase for consistency
    hex_digit = toupper(hex_digit);

    // Check if the character is a number or a letter
    if (hex_digit >= 'A' && hex_digit <= 'F')
    {
        // Subtract 58 from the character to get the decimal equivalent
        return hex_digit - 58;
    }
    else
    {
        // Return -1 for invalid input
        return -1;
    }
}

// Function to convert decimal to hexadecimal
char dec_to_hex(int decimal)
{
    // Calculate the number of digits in the hexadecimal number
    int num_digits = decimal / MAX_DIGITS + 1;

    // Allocate memory for the hexadecimal number
    char *hex_number = malloc(num_digits);

    // Convert the decimal number to hexadecimal
    hex_number[num_digits - 1] = '\0';
    for (int i = num_digits - 2; i >= 0; i--)
    {
        int digit = decimal % MAX_DIGITS;
        hex_number[i] = digit + 58;
        decimal /= MAX_DIGITS;
    }

    // Return the hexadecimal number
    return *hex_number;
}

int main()
{
    // Get the input number
    char input_number[20];
    printf("Enter a hexadecimal number: ");
    scanf("%s", input_number);

    // Convert the input number to decimal
    int decimal_number = strtol(input_number, NULL, 16);

    // Convert the decimal number to hexadecimal
    char hex_number = dec_to_hex(decimal_number);

    // Print the hexadecimal number
    printf("The hexadecimal number is: %c\n", hex_number);

    return 0;
}