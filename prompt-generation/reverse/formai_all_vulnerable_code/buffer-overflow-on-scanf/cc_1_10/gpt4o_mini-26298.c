//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32

// Function to convert decimal to binary
void decimalToBinary(int n, char* binary) {
    int index = MAX_BITS - 1;
    while (n > 0) {
        binary[index--] = (n % 2) + '0'; // Convert int to char
        n /= 2;
    }
    // Fill remaining bits with '0'
    while (index >= 0) {
        binary[index--] = '0';
    }
    binary[MAX_BITS] = '\0'; // Null-terminate for string representation
}

// Function to convert binary to decimal
int binaryToDecimal(const char* binary) {
    int decimal = 0;
    for (int i = 0; i < MAX_BITS; i++) {
        decimal = (decimal << 1) | (binary[i] - '0'); 
    }
    return decimal;
}

// Function to display menu
void displayMenu() {
    printf("Binary Converter Menu:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
}

// Function to get an integer input from user
int getIntegerInput() {
    int num;
    printf("Enter an integer: ");
    while (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter an integer: ");
        while(getchar() != '\n'); // Clear the input buffer
    }
    return num;
}

// Function to get binary string input from user
void getBinaryInput(char* binary) {
    printf("Enter a binary number: ");
    while (1) {
        scanf("%s", binary);
        if (strlen(binary) <= MAX_BITS) {
            int valid = 1;
            for (int i = 0; binary[i] != '\0'; i++) {
                if (binary[i] != '0' && binary[i] != '1') {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                break;
            } else {
                printf("Invalid binary format. Please enter again: ");
            }
        } else {
            printf("Binary number is too long. Max length is %d bits. Enter again: ", MAX_BITS);
        }
    }
}

// Main function
int main() {
    int choice;
    char binary[MAX_BITS + 1]; // Extra space for null-terminator

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        choice = getIntegerInput();

        switch (choice) {
            case 1: {
                // Decimal to binary conversion
                int decimal = getIntegerInput();
                decimalToBinary(decimal, binary);
                printf("Decimal: %d\nBinary: %s\n", decimal, binary);
                break;
            }
            case 2: {
                // Binary to decimal conversion
                getBinaryInput(binary);
                int decimal = binaryToDecimal(binary);
                printf("Binary: %s\nDecimal: %d\n", binary, decimal);
                break;
            }
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    }
    
    return 0;
}