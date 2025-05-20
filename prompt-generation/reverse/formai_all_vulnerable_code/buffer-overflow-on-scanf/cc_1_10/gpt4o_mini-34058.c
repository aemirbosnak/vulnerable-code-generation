//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>

#define MAX_BITS 32 

// Function prototypes
void decimalToBinary(int decimal);
void reverseArray(char *arr, int start, int end);
void initializeArray(char *arr, int size);
void printBinary(char *binary, int size);

int main() {
    int decimalInput;

    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("Please enter a decimal number (0 to terminate): ");
    
    // Input loop to allow multiple conversions
    while (1) {
        scanf("%d", &decimalInput);
        if (decimalInput < 0) {
            printf("Terminating program. Goodbye!\n");
            break;
        }

        decimalToBinary(decimalInput);
        printf("Please enter another decimal number (0 to terminate): ");
    }

    return 0;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    char binary[MAX_BITS + 1]; // +1 for null terminator
    initializeArray(binary, MAX_BITS);

    int index = MAX_BITS - 1;
    int tempDecimal = decimal;

    // Convert decimal to binary using bit manipulation
    while (tempDecimal > 0) {
        binary[index--] = (tempDecimal & 1) + '0'; // Extract the last bit
        tempDecimal >>= 1; // Right shift to process next bit
    }

    binary[MAX_BITS] = '\0'; // Null terminate the string

    printf("Decimal: %d\n", decimal);
    printBinary(binary, MAX_BITS);
}

// Function to initialize array to '0'
void initializeArray(char *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = '0';
    }
}

// Function to print the binary representation
void printBinary(char *binary, int size) {
    printf("Binary: ");
    int firstNonZeroFound = 0; // Flag to track the first non-zero digit
    for (int i = 0; i < size; i++) {
        if (binary[i] == '1') {
            firstNonZeroFound = 1;
        }
        if (firstNonZeroFound) {
            putchar(binary[i]); // Print the character
        }
    }
    if (!firstNonZeroFound) {
        // If number is zero
        putchar('0');
    }
    putchar('\n'); // New line after printing binary
}