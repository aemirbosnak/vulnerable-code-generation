//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 32

// Function to convert a decimal number to binary
void decimalToBinary(int n, char *binary) {
    for (int i = MAX_DIGITS - 1; i >= 0; i--) {
        binary[i] = (n % 2) + '0'; // Store binary digit in char array
        n = n / 2;
    }
    binary[MAX_DIGITS] = '\0'; // Null terminate the string
}

// Function to convert binary string back to decimal
int binaryToDecimal(const char *binary) {
    int decimal = 0;
    for (int i = 0; i < MAX_DIGITS; i++) {
        decimal = decimal * 2 + (binary[i] - '0'); // Build decimal from binary
    }
    return decimal;
}

// Display menu options
void displayMenu() {
    printf("\n=== Binary Converter ===\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Exit\n");
    printf("========================\n");
    printf("Please select an option: ");
}

// Main function
int main() {
    int choice;
    int decimalNumber, convertedDecimal;
    char binary[MAX_DIGITS + 1];

    // Loop until the user chooses to exit
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Decimal to binary conversion
                printf("Enter a decimal number (0 to 4294967295): ");
                scanf("%d", &decimalNumber);
                
                if (decimalNumber < 0 || decimalNumber > 4294967295) {
                    printf("Invalid input! Please enter a number between 0 and 4294967295.\n");
                } else {
                    decimalToBinary(decimalNumber, binary);
                    printf("Binary representation: %s\n", binary);
                }
                break;
            
            case 2:
                // Binary to decimal conversion
                printf("Enter a binary number (up to 32 bits): ");
                scanf("%s", binary);
                
                // Check for valid binary input
                if (strlen(binary) > MAX_DIGITS) {
                    printf("Input too long! Max 32 bits allowed.\n");
                } else {
                    for (int i = 0; i < strlen(binary); i++) {
                        if (binary[i] != '0' && binary[i] != '1') {
                            printf("Invalid binary number! Please enter a valid binary number.\n");
                            break;
                        }
                    }
                    convertedDecimal = binaryToDecimal(binary);
                    printf("Decimal representation: %d\n", convertedDecimal);
                }
                break;

            case 3:
                // Exit from the program
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}