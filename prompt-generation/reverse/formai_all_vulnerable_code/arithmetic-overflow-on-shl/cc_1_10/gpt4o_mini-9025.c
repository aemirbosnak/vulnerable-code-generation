//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal number to binary
void decimalToBinary(int n, char *binary) {
    // Initialize binary string
    binary[0] = '\0';
    
    // Convert decimal to binary
    for(int i = 31; i >= 0; i--) {
        if(n & (1 << i)) {
            strncat(binary, "1", 1);
        } else {
            strncat(binary, "0", 1);
        }
    }
    
    // Remove leading zeros
    char *trimmedBinary = binary + strspn(binary, "0");
    if (*trimmedBinary == '\0') {
        // If all were zeros
        strcpy(binary, "0");
    } else {
        strcpy(binary, trimmedBinary);
    }
}

// Function to convert binary number to decimal
int binaryToDecimal(const char *binary) {
    int decimal = 0;
    int base = 1;

    // Get length of binary string
    int length = strlen(binary);
    for(int i = length - 1; i >= 0; i--) {
        if(binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

// Function to display menu
void displayMenu() {
    printf("\n=== C Binary Converter ===\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Exit\n");
    printf("==========================\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    int choice;
    int decimalNumber;
    char binaryNumber[33]; // 32 bits + 1 for the null terminator
    char input[50];

    while(1) {
        displayMenu();
        
        // Get user choice
        fgets(input, sizeof(input), stdin);
        choice = atoi(input);

        switch(choice) {
            case 1:
                printf("Enter a decimal number: ");
                fgets(input, sizeof(input), stdin);
                decimalNumber = atoi(input);
                decimalToBinary(decimalNumber, binaryNumber);
                printf("Decimal %d in Binary: %s\n", decimalNumber, binaryNumber);
                break;

            case 2:
                printf("Enter a binary number: ");
                fgets(input, sizeof(input), stdin);
                // Remove newline character
                input[strcspn(input, "\n")] = '\0';
                decimalNumber = binaryToDecimal(input);
                printf("Binary %s in Decimal: %d\n", input, decimalNumber);
                break;

            case 3:
                printf("Exiting program... Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}