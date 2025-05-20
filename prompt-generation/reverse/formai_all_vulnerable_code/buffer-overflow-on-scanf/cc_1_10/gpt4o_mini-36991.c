//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal, char *binary, int size) {
    // Ensure the binary string is initialized to all zeros
    memset(binary, '0', size - 1);
    binary[size - 1] = '\0'; // Null-terminate the string

    int index = size - 2; // Start filling from the second last position

    // Convert decimal to binary
    while (decimal > 0) {
        binary[index--] = (decimal % 2) + '0'; // Convert int to char
        decimal /= 2;
    }
}

// Function to display binary representation neatly
void displayBinary(const char *binary) {
    printf("The binary representation is: %s\n", binary);
}

int main() {
    // Exciting introductory display
    printf("Welcome to the Ultimate Decimal to Binary Converter!\n");
    printf("Let the binary magic begin...\n\n");

    int decimalInput;
    char binaryOutput[33]; // 32 bits + 1 for null terminator

    // Input loop to keep asking for numbers
    while (1) {
        printf("Please enter a decimal number (or -1 to exit): ");
        scanf("%d", &decimalInput);

        // Exit condition
        if (decimalInput == -1) {
            printf("Thank you for using the Awesome Converter! Goodbye!\n");
            break; // Exit the loop and the program
        }

        // Let's only convert non-negative integers for now
        if (decimalInput < 0) {
            printf("Uh oh! Negative numbers are not allowed. Try again!\n\n");
            continue; // Restart the loop
        }

        // Call function to convert
        decimalToBinary(decimalInput, binaryOutput, sizeof(binaryOutput));

        // Display the result
        displayBinary(binaryOutput);
        printf("\nYou just transformed %d into binary with style!\n", decimalInput);
        printf("Isn't programming just thrilling? 🚀 Let's do it again!\n\n");
    }

    return 0;
}