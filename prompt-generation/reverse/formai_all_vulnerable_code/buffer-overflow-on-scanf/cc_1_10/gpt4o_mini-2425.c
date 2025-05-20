//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to binary
char* decimalToBinary(int decimal) {
    // Allocate enough space for binary representation (32 bits + null terminator)
    char* binary = (char*)malloc(33);
    if (!binary) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    binary[32] = '\0'; // Null-terminate the string

    for (int i = 31; i >= 0; i--) {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
    }

    return binary;
}

// Function to convert binary string to decimal
int binaryToDecimal(const char* binary) {
    int decimal = 0;
    size_t length = strlen(binary);
    
    for (size_t i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += (1 << (length - 1 - i));
        } else if (binary[i] != '0') {
            fprintf(stderr, "Invalid binary string: %s\n", binary);
            exit(EXIT_FAILURE);
        }
    }

    return decimal;
}

// Function to display a menu and get user choice
int displayMenu() {
    int choice;

    printf("Binary Converter\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Select an option (1-3): ");
    scanf("%d", &choice);

    return choice;
}

int main() {
    while (1) {
        int choice = displayMenu();

        switch (choice) {
            case 1: {
                int decimal;
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);

                char* binary = decimalToBinary(decimal);
                printf("Binary representation: %s\n", binary);
                free(binary);
                break;
            }
            case 2: {
                char binary[33];
                printf("Enter a binary number: ");
                scanf("%s", binary);

                int decimal = binaryToDecimal(binary);
                printf("Decimal representation: %d\n", decimal);
                break;
            }
            case 3:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}