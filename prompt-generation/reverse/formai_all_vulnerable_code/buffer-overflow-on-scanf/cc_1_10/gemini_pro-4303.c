//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to convert hexadecimal to decimal
int hexToDecimal(char hexValue[]) {
    int len = strlen(hexValue);

    // Initialize base value to 1, and initialize result to 0
    int base = 1;
    int dec = 0;

    // Iterate through the hexadecimal number from right to left
    for (int i = len - 1; i >= 0; i--) {
        // Check if the character is a digit
        if (hexValue[i] >= '0' && hexValue[i] <= '9') {
            // Convert the digit to an integer value
            dec += (hexValue[i] - '0') * base;
        }
        // Check if the character is an uppercase letter
        else if (hexValue[i] >= 'A' && hexValue[i] <= 'F') {
            // Convert the letter to an integer value
            dec += (hexValue[i] - 'A' + 10) * base;
        }
        // Check if the character is a lowercase letter
        else if (hexValue[i] >= 'a' && hexValue[i] <= 'f') {
            // Convert the letter to an integer value
            dec += (hexValue[i] - 'a' + 10) * base;
        }

        // Multiply base by 16 to move to the next digit
        base *= 16;
    }

    // Return the decimal value
    return dec;
}

// Function to convert decimal to hexadecimal
char *decimalToHexadecimal(int dec) {
    // Initialize the hexadecimal string
    char *hex = malloc(sizeof(char) * 100);

    // Iterate through the decimal number from right to left
    int i = 0;
    while (dec > 0) {
        // Get the remainder
        int remainder = dec % 16;

        // Convert the remainder to a hexadecimal digit
        char digit;
        if (remainder < 10) {
            digit = '0' + remainder;
        } else {
            digit = 'A' + (remainder - 10);
        }

        // Append the digit to the hexadecimal string
        hex[i++] = digit;

        // Divide the decimal number by 16
        dec /= 16;
    }

    // Reverse the hexadecimal string
    char *reversedHex = malloc(sizeof(char) * 100);
    int j = 0;
    for (int k = i - 1; k >= 0; k--) {
        reversedHex[j++] = hex[k];
    }

    // Free the memory allocated for the original hexadecimal string
    free(hex);

    // Return the reversed hexadecimal string
    return reversedHex;
}

// Driver program to test the hexToDecimal and decimalToHexadecimal functions
int main() {
    // Get the hexadecimal number from the user
    char hexValue[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hexValue);

    // Convert the hexadecimal number to decimal
    int dec = hexToDecimal(hexValue);

    // Print the decimal value
    printf("The decimal value of %s is: %d\n", hexValue, dec);

    // Convert the decimal number to hexadecimal
    char *hex = decimalToHexadecimal(dec);

    // Print the hexadecimal value
    printf("The hexadecimal value of %d is: %s\n", dec, hex);

    // Free the memory allocated for the hexadecimal string
    free(hex);

    return 0;
}