//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_STRING_LENGTH 1024

// Define the maximum number of bits in a binary number
#define MAX_BINARY_LENGTH 32

// Main function
int main() {
    // Declare the input string
    char input[MAX_STRING_LENGTH];

    // Prompt the user to enter a binary number
    printf("Enter a binary number: ");
    scanf("%s", input);

    // Check if the input string is valid
    if (!isValidBinary(input)) {
        printf("Invalid binary number: %s\n", input);
        return EXIT_FAILURE;
    }

    // Convert the binary number to a decimal number
    int decimal = binaryToDecimal(input);

    // Print the decimal number
    printf("Decimal number: %d\n", decimal);

    return EXIT_SUCCESS;
}

// Check if the input string is a valid binary number
int isValidBinary(char *input) {
    // Check if the input string is empty
    if (strlen(input) == 0) {
        return 0;
    }

    // Check if the input string contains only 0s and 1s
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != '0' && input[i] != '1') {
            return 0;
        }
    }

    // The input string is a valid binary number
    return 1;
}

// Convert the binary number to a decimal number
int binaryToDecimal(char *input) {
    // Declare the decimal number
    int decimal = 0;

    // Loop through the input string
    for (int i = strlen(input) - 1; i >= 0; i--) {
        // Check if the current character is a 1
        if (input[i] == '1') {
            // Add the corresponding power of 2 to the decimal number
            decimal += (1 << (strlen(input) - 1 - i));
        }
    }

    // Return the decimal number
    return decimal;
}