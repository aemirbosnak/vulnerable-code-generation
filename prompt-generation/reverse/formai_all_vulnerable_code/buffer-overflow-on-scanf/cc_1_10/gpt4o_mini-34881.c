//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
void decimalToBinary(int n);
int binaryToDecimal(const char *binary);
int isBinary(const char *str);

int main() {
    int choice;
    int decimalNum;
    char binaryNum[65]; // Enough to hold binary representation of a 64-bit integer

    printf("Welcome to the Binary Converter!\n");
    printf("Select an option:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");

    while (1) {
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNum);
                printf("Binary representation of %d is: ", decimalNum);
                decimalToBinary(decimalNum);
                printf("\n");
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binaryNum);
                if (isBinary(binaryNum)) {
                    int decimalValue = binaryToDecimal(binaryNum);
                    printf("Decimal representation of %s is: %d\n", binaryNum, decimalValue);
                } else {
                    printf("Error: Input is not a valid binary number.\n");
                }
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select 1, 2, or 3.\n");
        }
    }
    return 0;
}

// Convert decimal to binary recursively
void decimalToBinary(int n) {
    if (n > 1) {
        decimalToBinary(n / 2);
    }
    printf("%d", n % 2);
}

// Convert binary string to decimal
int binaryToDecimal(const char *binary) {
    int decimalValue = 0;
    int power = 1; // 2^0

    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimalValue += power;
        }
        power *= 2;
    }
    return decimalValue;
}

// Check if the given string is a valid binary number
int isBinary(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != '0' && str[i] != '1') {
            return 0; // Not a binary number
        }
    }
    return 1; // Valid binary number
}