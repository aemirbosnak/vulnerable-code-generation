//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal, char *binary) {
    // Initialize all bits to 0
    int index = 0;
    for (int i = 31; i >= 0; i--) {
        if (decimal & (1 << i)) {
            binary[index++] = '1';
        } else {
            binary[index++] = '0';
        }
    }
    binary[index] = '\0'; // Null terminator at the end of string
}

// Function to get binary representation of an integer
void getBinaryRepresentation() {
    int num = 0;
    char binary[35]; // To accommodate 32 bits + null terminator

    printf("Enter a decimal number: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input, please enter a valid integer.\n");
        exit(EXIT_FAILURE);
    }

    decimalToBinary(num, binary);
    printf("Binary representation of %d is: %s\n", num, binary);
}

// Function to convert binary string to decimal
int binaryToDecimal(const char *binary) {
    int decimal = 0;
    int base = 1;

    // Process the binary string from end to start
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base <<= 1; // Move to the next base (2, 4, 8, ...)
    }

    return decimal;
}

// Function to get decimal value from binary string
void getDecimalFromBinary() {
    char binary[35]; // To accommodate 32 bits + null terminator

    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Check for invalid binary input
    for (int i = 0; i < strlen(binary); i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("Invalid input, please enter a valid binary string.\n");
            exit(EXIT_FAILURE);
        }
    }

    int decimal = binaryToDecimal(binary);
    printf("Decimal representation of %s is: %d\n", binary, decimal);
}

// Function to display the menu
void displayMenu() {
    printf("Binary Converter Menu:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-3): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice, please enter a number between 1 and 3.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                getBinaryRepresentation();
                break;
            case 2:
                getDecimalFromBinary();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please pick a valid option from the menu.\n");
        }
    }

    return 0;
}