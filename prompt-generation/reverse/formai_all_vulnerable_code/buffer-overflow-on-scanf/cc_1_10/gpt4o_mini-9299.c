//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert Decimal to Binary
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }

    char binary[32]; // to hold the binary representation
    binary[31] = '\0'; // null-terminate the string
    
    for (int i = 30; i >= 0; i--) {
        binary[i] = (decimal % 2) ? '1' : '0';
        decimal /= 2;
    }
    
    printf("Binary: %s\n", &binary[strspn(binary, "0")]); // Print binary skipping leading zeros
}

// Function to convert Binary to Decimal
int binaryToDecimal(const char *binary) {
    int decimal = 0;
    int base = 1; // Base value for binary conversion starting from the right

    int length = strlen(binary);
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        } else if (binary[i] != '0') {
            // Handle invalid binary input
            printf("Error: Input is not a valid binary number!\n");
            return -1;
        }
        base *= 2; // Move to the next base
    }
    
    return decimal;
}

// Main function
int main() {
    int choice;
    printf("Binary Converter Program\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");

    while (1) {
        printf("Enter your choice (1-3): ");
        if (scanf("%d", &choice) != 1) { // Input validation
            printf("Invalid input. Please enter a number between 1 and 3.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }
        
        switch (choice) {
            case 1: {
                int decimal;
                printf("Enter a decimal number: ");
                if (scanf("%d", &decimal) != 1) { // Input validation
                    printf("Invalid input. Please enter a valid decimal number.\n");
                    while(getchar() != '\n'); // Clear the input buffer
                    continue;
                }
                decimalToBinary(decimal);
                break;
            }

            case 2: {
                char binary[33]; // Buffer for binary input
                printf("Enter a binary number: ");
                scanf("%s", binary);
                
                int decimal = binaryToDecimal(binary);
                if (decimal != -1) {
                    printf("Decimal: %d\n", decimal);
                }
                break;
            }

            case 3:
                printf("Exiting the program.\n");
                return 0; // Exit the program

            default:
                printf("Invalid choice. Please select 1, 2 or 3.\n");
                break;
        }
        
        printf("\n"); // Add space between iterations
    }

    return 0;
}