//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void decimalToBinary(int decimal);
void binaryToDecimal(char *binary);

int main() {
    int choice;
    do {
        // Display menu options
        printf("\n***** Binary Converter *****\n");
        printf("1. Convert Decimal to Binary\n");
        printf("2. Convert Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Please enter your choice (1-3): ");
        
        // Get user choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 3.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1: {
                int decimal;
                printf("Enter a decimal number: ");
                if (scanf("%d", &decimal) != 1) {
                    printf("Invalid input. Please enter a valid decimal number.\n");
                    while(getchar() != '\n'); // Clear the input buffer
                    break;
                }
                decimalToBinary(decimal);
                break;
            }
            case 2: {
                char binary[65]; // Enough space for 64-bit binary plus null terminator
                printf("Enter a binary number: ");
                scanf("%s", binary);
                binaryToDecimal(binary);
                break;
            }
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    if (decimal < 0) {
        printf("Please enter a non-negative decimal number.\n");
        return;
    }

    char binary[65]; // For 64-bit representation
    int index = 0;

    // Special case for zero
    if (decimal == 0) {
        strcpy(binary, "0");
        index = 1;
    } else {
        while (decimal > 0) {
            binary[index++] = (decimal % 2) + '0'; // Convert int to char
            decimal /= 2;
        }
    }

    // Reverse the binary string
    binary[index] = '\0';
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }

    printf("Binary representation: %s\n", binary);
}

// Function to convert binary to decimal
void binaryToDecimal(char *binary) {
    int decimal = 0;
    int base = 1; // 2^0
    int length = strlen(binary);
    
    // Validate binary input
    for (int i = 0; i < length; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("Invalid binary number. Please enter a binary number using only 0s and 1s.\n");
            return;
        }
    }

    // Convert binary to decimal
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2; // Next power of 2
    }

    printf("Decimal representation: %d\n", decimal);
}