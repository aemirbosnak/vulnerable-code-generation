//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: thoughtful
// Binary Converter: A Comprehensive Guide

#include <stdio.h>
#include <stdlib.h>

// Declare function prototypes
int decimalToBinary(int);
int binaryToDecimal(int);

int main() {
    int choice, number;

    // Display menu options
    printf("Binary Converter\n\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Quit\n\n");

    // Get user choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Handle user choice
    switch (choice) {
        case 1:
            // Decimal to Binary
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            printf("Binary representation: %d\n", decimalToBinary(number));
            break;
        case 2:
            // Binary to Decimal
            printf("Enter a binary number: ");
            scanf("%d", &number);
            printf("Decimal representation: %d\n", binaryToDecimal(number));
            break;
        case 3:
            // Quit
            printf("Exiting...\n");
            exit(0);
        default:
            // Invalid choice
            printf("Invalid choice. Please enter a number between 1 and 3.\n");
    }

    return 0;
}

// Converts a decimal number to its binary representation
int decimalToBinary(int decimal) {
    int binary = 0, remainder, i = 1;

    while (decimal != 0) {
        remainder = decimal % 2;
        binary += remainder * i;
        decimal /= 2;
        i *= 10;
    }

    return binary;
}

// Converts a binary number to its decimal representation
int binaryToDecimal(int binary) {
    int decimal = 0, i = 0, remainder;

    while (binary != 0) {
        remainder = binary % 10;
        binary /= 10;
        decimal += remainder * pow(2, i);
        i++;
    }

    return decimal;
}