//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void decimalToBinary(int decimalNumber);
void binaryToDecimal(const char* binaryString);
int isBinary(const char* binaryString);
void printMenu();

// Main function
int main() {
    int choice;
    int decimalNumber;
    char binaryString[65];

    while (1) {
        printMenu();
        printf("Enter your choice (1-4, or 0 to exit): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                printf("Binary representation of %d: ", decimalNumber);
                decimalToBinary(decimalNumber);
                printf("\n");
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binaryString);
                if (isBinary(binaryString)) {
                    binaryToDecimal(binaryString);
                } else {
                    printf("Invalid binary number!\n");
                }
                printf("\n");
                break;

            case 3:
                printf("Enter a decimal number to convert: ");
                scanf("%d", &decimalNumber);
                printf("Binary representation of %d: ", decimalNumber);
                decimalToBinary(decimalNumber);
                printf("\n");
                binaryToDecimal(binaryString);
                printf("\n");
                break;

            case 4:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }
    return 0;
}

// Function to convert a decimal number to binary
void decimalToBinary(int decimalNumber) {
    if (decimalNumber > 1) {
        decimalToBinary(decimalNumber / 2);
    }
    printf("%d", decimalNumber % 2);
}

// Function to convert a binary string to decimal
void binaryToDecimal(const char* binaryString) {
    int decimalNumber = 0;
    int length = strlen(binaryString);

    for (int i = 0; i < length; i++) {
        if (binaryString[length - i - 1] == '1') {
            decimalNumber += (1 << i);
        }
    }

    printf("Decimal representation of %s: %d\n", binaryString, decimalNumber);
}

// Function to validate if the input string is a binary number
int isBinary(const char* binaryString) {
    for (int i = 0; i < strlen(binaryString); i++) {
        if (binaryString[i] != '0' && binaryString[i] != '1') {
            return 0; // Not a binary number
        }
    }
    return 1; // It is a binary number
}

// Function to print the menu options
void printMenu() {
    printf("=== Binary Converter Menu ===\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Convert Decimal and then Binary (for learning)\n");
    printf("4. Exit\n");
    printf("==============================\n");
}