//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int n, char *binary) {
    int index = 0;
    while (n > 0) {
        binary[index++] = (n % 2) ? '1' : '0';
        n /= 2;
    }
    binary[index] = '\0';

    // Reverse the string for correct order
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
}

// Function to convert binary to decimal
int binaryToDecimal(const char *binary) {
    int decimal = 0;
    int base = 1;
    int len = strlen(binary);
    
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }

    return decimal;
}

// Function to print the menu
void printMenu() {
    printf("==== Binary Converter ====\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Exit\n");
    printf("==========================\n");
}

// Main program
int main() {
    int choice;
    char binary[32];
    int decimal;

    while (1) {
        printMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Decimal to Binary
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimalToBinary(decimal, binary);
                printf("Binary representation: %s\n", binary);
                break;

            case 2: // Binary to Decimal
                printf("Enter a binary number: ");
                scanf("%s", binary);
                decimal = binaryToDecimal(binary);
                printf("Decimal representation: %d\n", decimal);
                break;

            case 3: // Exit
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}