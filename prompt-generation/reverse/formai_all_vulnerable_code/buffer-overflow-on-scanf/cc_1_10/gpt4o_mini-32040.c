//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void decimalToBinary(int decimal, char *binary);
void binaryToDecimal(const char *binary, int *decimal);
void displayMenu();
void handleDecimalConversion();
void handleBinaryConversion();

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                handleDecimalConversion();
                break;
            case 2:
                handleBinaryConversion();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n=== Binary Converter ===\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void handleDecimalConversion() {
    int decimal;
    char binary[33];  // 32 bits for binary + 1 for null terminator

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    decimalToBinary(decimal, binary);
    printf("Binary representation of %d is: %s\n", decimal, binary);
}

void decimalToBinary(int decimal, char *binary) {
    int index = 0;

    if (decimal == 0) {
        strcpy(binary, "0");
        return;
    }

    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0';  // Convert to char
        decimal /= 2;
    }

    binary[index] = '\0';                      // Null terminate the string

    // Reverse the binary string
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
}

void handleBinaryConversion() {
    char binary[33];
    int decimal;

    printf("Enter a binary number: ");
    scanf("%s", binary);
    
    binaryToDecimal(binary, &decimal);
    printf("Decimal representation of %s is: %d\n", binary, decimal);
}

void binaryToDecimal(const char *binary, int *decimal) {
    *decimal = 0;
    int length = strlen(binary);
    
    for (int i = 0; i < length; i++) {
        if (binary[length - i - 1] == '1') {
            *decimal += (1 << i);  // 2^i
        }
    }
}