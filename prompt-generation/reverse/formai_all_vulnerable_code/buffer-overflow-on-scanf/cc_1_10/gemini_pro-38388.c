//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of characters in a hexadecimal string
#define MAX_HEX_STRING_LENGTH 100

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex_string) {
    int value = 0;
    int length = strlen(hex_string);

    // Iterate through the hexadecimal string from right to left
    for (int i = length - 1; i >= 0; i--) {
        // Get the current character
        char character = hex_string[i];

        // Convert the character to a digit
        int digit = 0;
        if (character >= '0' && character <= '9') {
            digit = character - '0';
        } else if (character >= 'a' && character <= 'f') {
            digit = character - 'a' + 10;
        } else if (character >= 'A' && character <= 'F') {
            digit = character - 'A' + 10;
        }

        // Multiply the digit by the appropriate power of 16
        value += digit * (1 << ((length - i - 1) * 4));
    }

    // Return the integer value
    return value;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int value) {
    // Allocate memory for the hexadecimal string
    char *hex_string = malloc(MAX_HEX_STRING_LENGTH * sizeof(char));

    // Iterate through the hexadecimal string from left to right
    int i = 0;
    while (value > 0) {
        // Get the remainder of the division by 16
        int remainder = value % 16;

        // Convert the remainder to a character
        char character = '0';
        if (remainder < 10) {
            character = '0' + remainder;
        } else {
            character = 'a' + (remainder - 10);
        }

        // Append the character to the hexadecimal string
        hex_string[i] = character;
        i++;

        // Divide the value by 16
        value /= 16;
    }

    // Terminate the hexadecimal string with a null character
    hex_string[i] = '\0';

    // Reverse the hexadecimal string
    int length = strlen(hex_string);
    for (int i = 0; i < length / 2; i++) {
        char temp = hex_string[i];
        hex_string[i] = hex_string[length - i - 1];
        hex_string[length - i - 1] = temp;
    }

    // Return the hexadecimal string
    return hex_string;
}

// Main function
int main() {
    // Get the hexadecimal string from the user
    char hex_string[MAX_HEX_STRING_LENGTH];
    printf("Enter the hexadecimal string: ");
    scanf("%s", hex_string);

    // Convert the hexadecimal string to an integer
    int value = hex_to_int(hex_string);

    // Print the integer value
    printf("The integer value is: %d\n", value);

    // Convert the integer value to a hexadecimal string
    char *new_hex_string = int_to_hex(value);

    // Print the new hexadecimal string
    printf("The new hexadecimal string is: %s\n", new_hex_string);

    // Free the memory allocated for the new hexadecimal string
    free(new_hex_string);

    return 0;
}