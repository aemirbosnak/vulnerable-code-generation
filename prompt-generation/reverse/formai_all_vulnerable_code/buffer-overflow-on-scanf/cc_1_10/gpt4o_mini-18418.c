//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 32

// Function to convert decimal to binary
void decimalToBinary(int n, char *binary) {
    int index = 0;

    if (n == 0) {
        binary[index++] = '0';
    } else {
        while (n > 0) {
            binary[index++] = (n % 2) + '0'; // Convert to character
            n = n / 2;
        }
    }
    binary[index] = '\0';

    // Reverse the string
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
}

// Function to display the binary representation
void displayBinary(char *binary) {
    printf("Binary representation: %s\n", binary);
}

// Function to handle user input and call conversion function
void inputAndConvert() {
    int number;
    char binary[MAX_LENGTH];

    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("Enter a decimal number (0 to exit): ");

    while (1) {
        scanf("%d", &number);
        if (number == 0) {
            printf("Exiting the converter. Goodbye!\n");
            break;
        }
        if (number < 0) {
            printf("Only non-negative integers are allowed. Try again: ");
            continue;
        }
        decimalToBinary(number, binary);
        displayBinary(binary);
        printf("Enter another decimal number (0 to exit): ");
    }
}

// Main function to run the program
int main() {
    inputAndConvert();
    return 0;
}