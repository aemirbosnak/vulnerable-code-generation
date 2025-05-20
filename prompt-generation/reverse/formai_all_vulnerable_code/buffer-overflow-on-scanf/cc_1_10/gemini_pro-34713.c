//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_HEX_DIGITS 16

// Function to convert a hexadecimal digit to its decimal value
int hex_to_decimal(char hex_digit) {
    if (hex_digit >= '0' && hex_digit <= '9') {
        return hex_digit - '0';
    } else if (hex_digit >= 'A' && hex_digit <= 'F') {
        return hex_digit - 'A' + 10;
    } else if (hex_digit >= 'a' && hex_digit <= 'f') {
        return hex_digit - 'a' + 10;
    } else {
        return -1;
    }
}

// Function to convert a hexadecimal string to its decimal value
int hex_to_decimal_string(const char *hex_string) {
    int decimal_value = 0;
    int hex_digit_value;
    int i;

    // Iterate over the hexadecimal string from right to left
    for (i = strlen(hex_string) - 1; i >= 0; i--) {
        // Convert the current hexadecimal digit to its decimal value
        hex_digit_value = hex_to_decimal(hex_string[i]);
        if (hex_digit_value == -1) {
            return -1;
        }

        // Multiply the decimal value by the appropriate power of 16 and accumulate the result
        decimal_value += hex_digit_value * (1 << (4 * (strlen(hex_string) - 1 - i)));
    }

    return decimal_value;
}

// Function to convert a decimal value to its hexadecimal representation
char *decimal_to_hex_string(int decimal_value) {
    // Allocate memory for the hexadecimal string
    char *hex_string = malloc(MAX_HEX_DIGITS + 1);
    if (hex_string == NULL) {
        return NULL;
    }

    // Initialize the hexadecimal string to all zeros
    memset(hex_string, '0', MAX_HEX_DIGITS);
    hex_string[MAX_HEX_DIGITS] = '\0';

    // Iterate over the hexadecimal string from right to left
    int i = MAX_HEX_DIGITS - 1;
    while (decimal_value > 0) {
        // Get the remainder of the decimal value when divided by 16
        int remainder = decimal_value % 16;

        // Convert the remainder to a hexadecimal digit
        char hex_digit;
        if (remainder < 10) {
            hex_digit = '0' + remainder;
        } else {
            hex_digit = 'A' + remainder - 10;
        }

        // Store the hexadecimal digit in the string
        hex_string[i--] = hex_digit;

        // Divide the decimal value by 16
        decimal_value /= 16;
    }

    // Return the hexadecimal string
    return hex_string;
}

int main() {
    // Get the hexadecimal string from the user
    char hex_string[MAX_HEX_DIGITS + 1];
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex_string);

    // Convert the hexadecimal string to its decimal value
    int decimal_value = hex_to_decimal_string(hex_string);
    if (decimal_value == -1) {
        printf("Invalid hexadecimal string\n");
        return EXIT_FAILURE;
    }

    // Print the decimal value
    printf("Decimal value: %d\n", decimal_value);

    // Convert the decimal value back to its hexadecimal representation
    char *hex_string_back = decimal_to_hex_string(decimal_value);
    if (hex_string_back == NULL) {
        printf("Error allocating memory\n");
        return EXIT_FAILURE;
    }

    // Print the hexadecimal representation
    printf("Hexadecimal representation: %s\n", hex_string_back);

    // Free the allocated memory
    free(hex_string_back);

    return EXIT_SUCCESS;
}