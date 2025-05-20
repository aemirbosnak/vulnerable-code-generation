//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int n, char *binaryStr) {
    for (int i = 31; i >= 0; i--) {
        binaryStr[i] = (n & 1) ? '1' : '0';
        n >>= 1;
    }
    binaryStr[32] = '\0';
}

void binaryToDecimal(const char *binaryStr) {
    int decimal = 0;
    for (int i = 0; binaryStr[i] != '\0'; i++) {
        decimal <<= 1;
        if (binaryStr[i] == '1') {
            decimal |= 1;
        }
    }
    printf("Decimal value: %d\n", decimal);
}

void displayMenu() {
    printf("Binary Converter Menu:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Please choose an option (1-3): ");
}

int getIntegerInput(const char *prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1 || value < 0) {
        printf("Invalid input. Please enter a non-negative integer: ");
        while (getchar() != '\n'); // Clear invalid input
    }
    return value;
}

void getBinaryInput(char *binaryStr) {
    printf("Enter a binary number: ");
    scanf("%s", binaryStr);
}

int main() {
    int choice;
    char binaryStr[33];

    while (1) {
        displayMenu();
        choice = getIntegerInput("");

        switch (choice) {
            case 1: {
                int decimal = getIntegerInput("Enter a decimal number: ");
                decimalToBinary(decimal, binaryStr);
                printf("Binary representation of %d: %s\n", decimal, binaryStr);
                break;
            }
            case 2: {
                getBinaryInput(binaryStr);
                binaryToDecimal(binaryStr);
                break;
            }
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option from the menu.\n");
                break;
        }
        printf("\n");
    }
    
    return 0;
}