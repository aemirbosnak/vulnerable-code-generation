//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define BINARY_SIZE 32 // Define the size of the binary representation

// Function to convert a decimal number to binary
void decimalToBinary(int number, char *binary) {
    // Reset the binary string
    for (int i = 0; i < BINARY_SIZE; i++) {
        binary[i] = '0';
    }
    binary[BINARY_SIZE] = '\0'; // Null-terminate the string

    // Handle negative numbers using two's complement
    if (number < 0) {
        number = (1 << BINARY_SIZE) + number; // Convert to positive equivalent
    }

    // Fill the binary representation
    for (int i = BINARY_SIZE - 1; i >= 0; i--) {
        binary[i] = (number % 2) + '0'; // Add the last bit
        number /= 2; // Shift right
    }
}

// Function to display the binary representation
void displayBinary(const char *binary) {
    printf("Binary representation: ");
    for (int i = 0; i < BINARY_SIZE; i++) {
        // Print space every 4 bits for better readability
        if (i > 0 && i % 4 == 0) {
            printf(" ");
        }
        printf("%c", binary[i]);
    }
    printf("\n");
}

int main() {
    int number; // Variable to hold the input number
    char binary[BINARY_SIZE + 1]; // Array to hold binary representation

    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("Please enter an integer (positive or negative): ");

    // Prompt user for input
    while (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter a valid integer: ");
        while (getchar() != '\n'); // Clear input buffer
    }

    // Convert decimal to binary
    decimalToBinary(number, binary);

    // Display the binary representation
    displayBinary(binary);

    return 0;
}