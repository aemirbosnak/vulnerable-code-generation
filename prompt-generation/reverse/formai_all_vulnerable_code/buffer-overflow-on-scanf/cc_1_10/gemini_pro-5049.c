//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    char hex[100];
    int dec;
    int i, j, k, l;
    int len;

    // Get the hexadecimal number from the user
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    // Find the length of the hexadecimal number
    len = strlen(hex);

    // Convert the hexadecimal number to decimal
    dec = 0;
    for (i = 0; i < len; i++) {
        // Get the current character
        char c = hex[i];

        // Convert the character to a digit
        int digit;
        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            digit = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
        } else {
            // Invalid character
            printf("Invalid hexadecimal number: %s\n", hex);
            return 1;
        }

        // Multiply the digit by the appropriate power of 16
        for (j = 0; j < len - i - 1; j++) {
            digit *= 16;
        }

        // Add the digit to the decimal number
        dec += digit;
    }

    // Print the decimal number
    printf("Decimal number: %d\n", dec);

    return 0;
}