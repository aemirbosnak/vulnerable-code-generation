//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal digit to its corresponding decimal value
int hex_to_dec(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    } else if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    } else {
        // Invalid hexadecimal digit
        return -1;
    }
}

// Function to convert a hexadecimal string to its corresponding decimal value
int hex_to_dec_string(char *hex_string) {
    int decimal_value = 0;
    int len = strlen(hex_string);

    // Iterate over the hexadecimal string from right to left
    for (int i = len - 1; i >= 0; i--) {
        // Convert the current hexadecimal digit to its corresponding decimal value
        int digit_value = hex_to_dec(hex_string[i]);

        // If the hexadecimal digit is invalid, return -1
        if (digit_value == -1) {
            return -1;
        }

        // Multiply the decimal value by the appropriate power of 16
        decimal_value += digit_value * (1 << ((len - 1 - i) * 4));
    }

    return decimal_value;
}

// Function to convert a decimal value to its corresponding hexadecimal string
char *dec_to_hex_string(int decimal_value) {
    // Allocate memory for the hexadecimal string
    char *hex_string = malloc(sizeof(char) * 100);

    // Initialize the hexadecimal string to empty
    strcpy(hex_string, "");

    // Iterate over the decimal value until it is 0
    while (decimal_value > 0) {
        // Get the remainder of the decimal value when divided by 16
        int remainder = decimal_value % 16;

        // Convert the remainder to its corresponding hexadecimal digit
        char hex_digit;
        if (remainder >= 0 && remainder <= 9) {
            hex_digit = remainder + '0';
        } else if (remainder >= 10 && remainder <= 15) {
            hex_digit = remainder - 10 + 'A';
        } else {
            // Invalid decimal value
            return NULL;
        }

        // Append the hexadecimal digit to the hexadecimal string
        strcat(hex_string, &hex_digit);

        // Divide the decimal value by 16
        decimal_value /= 16;
    }

    // Reverse the hexadecimal string
    int len = strlen(hex_string);
    for (int i = 0; i < len / 2; i++) {
        char temp = hex_string[i];
        hex_string[i] = hex_string[len - 1 - i];
        hex_string[len - 1 - i] = temp;
    }

    return hex_string;
}

// Main function
int main() {
    // Get the hexadecimal string from the user
    char hex_string[100];
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex_string);

    // Convert the hexadecimal string to its corresponding decimal value
    int decimal_value = hex_to_dec_string(hex_string);

    // Check if the hexadecimal string is valid
    if (decimal_value == -1) {
        printf("Invalid hexadecimal string\n");
        return 1;
    }

    // Print the decimal value
    printf("Decimal value: %d\n", decimal_value);

    // Convert the decimal value to its corresponding hexadecimal string
    char *new_hex_string = dec_to_hex_string(decimal_value);

    // Check if the decimal value is valid
    if (new_hex_string == NULL) {
        printf("Invalid decimal value\n");
        return 1;
    }

    // Print the hexadecimal string
    printf("Hexadecimal string: %s\n", new_hex_string);

    // Free the allocated memory
    free(new_hex_string);

    return 0;
}