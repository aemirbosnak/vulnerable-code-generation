//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }

    int binary[32];
    int index = 0;
    
    while (decimal > 0) {
        binary[index] = decimal % 2;
        decimal = decimal / 2;
        index++;
    }

    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to convert binary to decimal
int binaryToDecimal(const char* binary) {
    int decimal = 0;
    int base = 1;
    int length = strlen(binary);

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Decimal-Binary Converter ---\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Please select an option: ");
}

// Main function
int main() {
    int choice, decimal;
    char binary[33];

    while(1) {
        displayMenu();
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
                // Validation of binary input
                int isBinary = 1;
                for (int i = 0; i < strlen(binary); i++) {
                    if (binary[i] != '0' && binary[i] != '1') {
                        isBinary = 0;
                        break;
                    }
                }
                if (isBinary) {
                    int result = binaryToDecimal(binary);
                    printf("Decimal: %d\n", result);
                } else {
                    printf("Invalid binary number. Please enter only 0s and 1s.\n");
                }
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}