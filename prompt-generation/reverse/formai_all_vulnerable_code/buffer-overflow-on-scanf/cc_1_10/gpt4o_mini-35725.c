//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToBinary(int num, char* binaryStr) {
    if (num == 0) {
        strcpy(binaryStr, "0");
        return;
    }
    
    int index = 0;
    while (num > 0) {
        binaryStr[index++] = (num % 2) + '0';
        num = num / 2;
    }
    binaryStr[index] = '\0';

    // Reverse the string to get the correct binary representation
    for (int i = 0; i < index / 2; i++) {
        char temp = binaryStr[i];
        binaryStr[i] = binaryStr[index - i - 1];
        binaryStr[index - i - 1] = temp;
    }
}

int binaryToDecimal(const char* binaryStr) {
    int decimal = 0;
    int base = 1;

    int length = strlen(binaryStr);
    for (int i = length - 1; i >= 0; i--) {
        if (binaryStr[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    
    return decimal;
}

void displayMenu() {
    printf("\n=== Binary Converter ===\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Exit\n");
}

void handleDecimalToBinary() {
    int decimalNumber;
    char binaryStr[65];  // This should be sufficient for 64-bit integers

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    
    decimalToBinary(decimalNumber, binaryStr);
    printf("Binary representation: %s\n", binaryStr);
}

void handleBinaryToDecimal() {
    char binaryStr[65];
    
    printf("Enter a binary number: ");
    scanf("%s", binaryStr);

    // Check if the input string is a valid binary number
    for (int i = 0; i < strlen(binaryStr); i++) {
        if (binaryStr[i] != '0' && binaryStr[i] != '1') {
            printf("Invalid binary number.\n");
            return;
        }
    }

    int decimalNumber = binaryToDecimal(binaryStr);
    printf("Decimal representation: %d\n", decimalNumber);
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                handleDecimalToBinary();
                break;
            case 2:
                handleBinaryToDecimal();
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}