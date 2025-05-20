//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of digits in the binary representation
#define MAX_DIGITS 32

// Define the base of the binary representation
#define BASE 2

// Function to convert a decimal number to binary representation
char *decimalToBinary(int decimalNumber) {
    // Allocate memory for the binary representation
    char *binaryRepresentation = malloc(MAX_DIGITS + 1);

    // Initialize the binary representation to all zeros
    for (int i = 0; i < MAX_DIGITS; i++) {
        binaryRepresentation[i] = '0';
    }

    // Convert the decimal number to binary representation
    int index = MAX_DIGITS - 1;
    while (decimalNumber > 0) {
        // Get the remainder of the division by the base
        int remainder = decimalNumber % BASE;

        // Convert the remainder to a character
        char digit = remainder + '0';

        // Store the digit in the binary representation
        binaryRepresentation[index--] = digit;

        // Divide the decimal number by the base
        decimalNumber /= BASE;
    }

    // Add the null-terminator to the binary representation
    binaryRepresentation[MAX_DIGITS] = '\0';

    // Return the binary representation
    return binaryRepresentation;
}

// Function to convert a binary representation to a decimal number
int binaryToDecimal(char *binaryRepresentation) {
    // Initialize the decimal number to zero
    int decimalNumber = 0;

    // Convert the binary representation to a decimal number
    int index = 0;
    while (binaryRepresentation[index] != '\0') {
        // Get the digit at the current index
        char digit = binaryRepresentation[index++];

        // Convert the digit to an integer
        int value = digit - '0';

        // Add the value to the decimal number
        decimalNumber += value * (1 << (index - 1));
    }

    // Return the decimal number
    return decimalNumber;
}

// Driver program to test the decimalToBinary and binaryToDecimal functions
int main() {
    // Get the decimal number from the user
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Convert the decimal number to binary representation
    char *binaryRepresentation = decimalToBinary(decimalNumber);

    // Print the binary representation
    printf("Binary representation: %s\n", binaryRepresentation);

    // Convert the binary representation to a decimal number
    int convertedDecimalNumber = binaryToDecimal(binaryRepresentation);

    // Print the converted decimal number
    printf("Converted decimal number: %d\n", convertedDecimalNumber);

    // Free the memory allocated for the binary representation
    free(binaryRepresentation);

    return 0;
}