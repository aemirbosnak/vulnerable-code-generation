//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    // Maximum bits needed for conversion of an integer
    int size = sizeof(n) * 8; 
    char *binary = (char *)malloc(size + 1);
    binary[size] = '\0'; // Null-terminate the string

    for (int i = size - 1; i >= 0; i--) {
        binary[i] = (n & 1) ? '1' : '0';
        n >>= 1; // Right shift to get the next bit
    }

    printf("Binary: %s\n", binary);
    free(binary); // Free up allocated memory
}

// Function to convert binary to decimal
int binaryToDecimal(const char *binary) {
    int decimal = 0;
    int base = 1; // Represents the base (2^0 = 1)

    // Start from the last character of the binary string
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base; // Add value if current bit is 1
        }
        base *= 2; // Increment base
    }

    return decimal;
}

// Function to validate if a string is binary
int isBinary(const char *str) {
    while (*str) {
        if (*str != '0' && *str != '1') {
            return 0; // Not binary
        }
        str++;
    }
    return 1; // Valid binary string
}

int main() {
    int choice;
    int decimal;
    char binary[32]; // Buffer for binary string input

    do {
        printf("=== Decimal and Binary Converter ===\n");
        printf("1. Convert Decimal to Binary\n");
        printf("2. Convert Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimalToBinary(decimal);
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binary);
                if (isBinary(binary)) {
                    int result = binaryToDecimal(binary);
                    printf("Decimal: %d\n", result);
                } else {
                    printf("Error: Not a valid binary number.\n");
                }
                break;

            case 3:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        printf("\n");
    } while (choice != 3);

    return 0;
}