//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 32 // Maximum bits for an unsigned integer

// Function to convert a decimal number to its binary representation
void decimalToBinary(unsigned int num, char *binary) {
    for (int i = 0; i < MAX_BITS; i++) {
        binary[MAX_BITS - 1 - i] = (num & (1U << i)) ? '1' : '0';
    }
    binary[MAX_BITS] = '\0'; // Null-terminate the string
}

// Function to print the binary representation
void printBinary(const char *binary) {
    int leadingZero = 1; // Flag to skip leading zeros
    
    for (int i = 0; i < MAX_BITS; i++) {
        if (binary[i] == '1') {
            leadingZero = 0; // Found the first '1'
        }
        // Print binary only if leadingZero is off
        if (!leadingZero) {
            putchar(binary[i]);
        }
    }
    
    if (leadingZero) {
        // If the number was zero
        putchar('0');
    }
    
    putchar('\n');
}

// Function to reverse a binary string for display
void reverseBinary(const char *binary, char *reversed) {
    for (int i = 0; i < MAX_BITS; i++) {
        reversed[i] = binary[MAX_BITS - 1 - i];
    }
    reversed[MAX_BITS] = '\0'; // Null-terminate
}

// Input validation function
unsigned int getInput() {
    unsigned int num;
    char term;

    while (1) {
        printf("Enter a non-negative decimal integer: ");
        if (scanf("%u%c", &num, &term) != 2 || term != '\n') {
            printf("Invalid input. Please enter a valid non-negative integer.\n");
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            break;
        }
    }

    while (getchar() != '\n'); // Clear the input buffer
    return num;
}

int main() {
    unsigned int decimal;
    char binary[MAX_BITS + 1];       // Buffer for binary representation
    char reversed[MAX_BITS + 1];     // Buffer for reversed binary representation

    decimal = getInput(); // Get user input

    decimalToBinary(decimal, binary); // Convert to binary

    printf("Binary Representation: ");
    printBinary(binary); // Print the binary representation

    reverseBinary(binary, reversed); // Reverse the binary representation

    printf("Reversed Binary Representation: ");
    printBinary(reversed); // Print the reversed binary representation

    return 0;
}