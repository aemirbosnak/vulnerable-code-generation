//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(const char *hex) {
    int len = strlen(hex);
    int base = 1;
    int value = 0;

    // Iterate over the hexadecimal string in reverse order
    for (int i = len - 1; i >= 0; i--) {
        // Get the digit value of the current character
        int digit;
        if (hex[i] >= '0' && hex[i] <= '9') {
            digit = hex[i] - '0';
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digit = hex[i] - 'a' + 10;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digit = hex[i] - 'A' + 10;
        } else {
            printf("Error: Invalid hexadecimal character '%c'\n", hex[i]);
            return -1;
        }

        // Multiply the digit value by the appropriate power of 16
        value += digit * base;
        base *= 16;
    }

    return value;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int value) {
    // Allocate memory for the hexadecimal string
    char *hex = malloc(11);

    // Convert the integer to a hexadecimal string
    sprintf(hex, "%x", value);

    // Return the hexadecimal string
    return hex;
}

// Main function
int main() {
    // Get the hexadecimal string from the user
    char hex[100];
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex);

    // Convert the hexadecimal string to an integer
    int value = hex_to_int(hex);

    // Check if the conversion was successful
    if (value == -1) {
        printf("Error: Invalid hexadecimal string\n");
        return 1;
    }

    // Convert the integer to a hexadecimal string
    char *new_hex = int_to_hex(value);

    // Print the original and converted hexadecimal strings
    printf("Original hexadecimal string: %s\n", hex);
    printf("Converted hexadecimal string: %s\n", new_hex);

    // Free the memory allocated for the converted hexadecimal string
    free(new_hex);

    return 0;
}