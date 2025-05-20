//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

// Function to convert decimal number to hexadecimal string
void decimalToHex(int decimal, char *hexStr) {
    sprintf(hexStr, "%X", decimal);
}

// Function to convert hexadecimal string to decimal number
int hexToDecimal(const char *hexStr) {
    return (int) strtol(hexStr, NULL, 16);
}

// Function to display menu and get user choice
int displayMenu() {
    int choice;
    printf("\nHexadecimal Converter\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
    scanf("%d", &choice);
    return choice;
}

// Function to handle Decimal to Hex conversion
void handleDecimalToHex() {
    int decimal;
    char hexStr[MAX_INPUT_LENGTH];

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToHex(decimal, hexStr);
    printf("Decimal: %d -> Hexadecimal: %s\n", decimal, hexStr);
}

// Function to handle Hex to Decimal conversion
void handleHexToDecimal() {
    char hexStr[MAX_INPUT_LENGTH];
    int decimal;

    printf("Enter a hexadecimal string: ");
    scanf("%s", hexStr);

    decimal = hexToDecimal(hexStr);
    printf("Hexadecimal: %s -> Decimal: %d\n", hexStr, decimal);
}

// Main function
int main() {
    int choice;

    do {
        choice = displayMenu();

        switch (choice) {
            case 1:
                handleDecimalToHex();
                break;
            case 2:
                handleHexToDecimal();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose a valid option (1-3).\n");
                break;
        }
    } while (choice != 3);

    return 0;
}