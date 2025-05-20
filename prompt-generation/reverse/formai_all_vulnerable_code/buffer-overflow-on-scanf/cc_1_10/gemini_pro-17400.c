//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex) {
    int value = 0;
    int i;
    int length = strlen(hex);

    // Iterate over the hexadecimal string
    for (i = 0; i < length; i++) {
        // Get the digit value
        int digit;
        if (hex[i] >= '0' && hex[i] <= '9') {
            digit = hex[i] - '0';
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digit = hex[i] - 'a' + 10;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digit = hex[i] - 'A' + 10;
        } else {
            // Invalid character
            return -1;
        }

        // Shift the value by 4 bits
        value <<= 4;

        // Add the digit value
        value += digit;
    }

    return value;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int value) {
    char *hex = malloc(sizeof(char) * 9);
    int i = 0;

    // Iterate over the bits of the integer
    while (value > 0) {
        // Get the remainder when dividing by 16
        int remainder = value % 16;

        // Convert the remainder to a hexadecimal digit
        char digit;
        if (remainder < 10) {
            digit = '0' + remainder;
        } else {
            digit = 'a' + (remainder - 10);
        }

        // Store the digit in the hexadecimal string
        hex[i++] = digit;

        // Divide the value by 16
        value /= 16;
    }

    // Reverse the hexadecimal string
    char *reversed_hex = malloc(sizeof(char) * (i + 1));
    int j = 0;
    while (i >= 0) {
        reversed_hex[j++] = hex[i--];
    }
    reversed_hex[j] = '\0';

    // Free the original hexadecimal string
    free(hex);

    // Return the reversed hexadecimal string
    return reversed_hex;
}

int main() {
    // Get the hexadecimal string from the user
    char hex[100];
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex);

    // Convert the hexadecimal string to an integer
    int value = hex_to_int(hex);

    // Print the integer value
    printf("Integer value: %d\n", value);

    // Convert the integer value to a hexadecimal string
    char *new_hex = int_to_hex(value);

    // Print the new hexadecimal string
    printf("New hexadecimal string: %s\n", new_hex);

    // Free the new hexadecimal string
    free(new_hex);

    return 0;
}