//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void decimalToBinary(int decimal) {
    // Convert the decimal number to a binary string
    char binary[32];
    int index = 0;
    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0'; // store '0' or '1'
        decimal /= 2;
    }
    binary[index] = '\0'; // Null-terminate the string

    // Reverse the string to get the correct binary representation
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }

    printf("Binary Representation: %s\n", binary);
}

int binaryToDecimal(const char *binary) {
    // Convert a binary string to a decimal number
    int decimal = 0;
    int base = 1; // The base value for binary (2^0)

    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base; // Add the value of 1 times the base
        }
        base *= 2; // Increase the base value (to the next power of 2)
    }

    return decimal;
}

bool isBinaryString(const char *str) {
    // Validate if a string is a binary number
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return false; // If not 0 or 1
        }
    }
    return true; // Valid binary string
}

void showMenu() {
    // Display a menu for user options
    printf("\n--- Binary Converter ---\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    printf("------------------------\n");
}

int main() {
    int choice;
    do {
        showMenu(); // Display options to user
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice); // Get user choice

        switch (choice) {
            case 1: {
                int decimal;
                printf("Enter a decimal number: ");
                scanf("%d", &decimal); // Get decimal input
                if (decimal < 0) {
                    printf("Please enter a non-negative decimal number.\n");
                } else {
                    decimalToBinary(decimal); // Call conversion function
                }
                break;
            }
            case 2: {
                char binary[32];
                printf("Enter a binary number: ");
                scanf("%s", binary); // Get binary input
                if (isBinaryString(binary)) {
                    int decimal = binaryToDecimal(binary); // Convert
                    printf("Decimal Representation: %d\n", decimal);
                } else {
                    printf("Invalid binary number! Only use 0s and 1s.\n");
                }
                break;
            }
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 3); // Continue until user chooses to exit

    return 0; // Successful program termination
}