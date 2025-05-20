//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32

void decimalToBinary(int num, char *binary) {
    int index = 0;

    // Handle the case of zero explicitly
    if (num == 0) {
        strcpy(binary, "0");
        return;
    }

    while (num > 0) {
        binary[index++] = (num % 2) + '0'; // Convert digit to character
        num = num / 2;
    }
    binary[index] = '\0';

    // Reverse the string to get the correct binary representation
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
}

void displayMenu() {
    printf("\n-------- Binary Converter --------\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    printf("----------------------------------\n");
    printf("Choose an option (1-3): ");
}

int binaryToDecimal(const char *binary) {
    int decimal = 0;
    int base = 1; // 2^0

    // Perform the conversion
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2; // Move to the next binary position
    }

    return decimal;
}

int isValidBinary(const char *binary) {
    for (int i = 0; binary[i] != '\0'; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            return 0; // Invalid binary
        }
    }
    return 1; // Valid binary
}

int main() {
    int option, decimal;
    char binary[MAX_BITS + 1]; // Buffer for binary representation

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1: // Decimal to Binary
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimalToBinary(decimal, binary);
                printf("Binary representation: %s\n", binary);
                break;

            case 2: // Binary to Decimal
                printf("Enter a binary number: ");
                scanf("%s", binary);

                if (isValidBinary(binary)) {
                    decimal = binaryToDecimal(binary);
                    printf("Decimal representation: %d\n", decimal);
                } else {
                    printf("Invalid binary number. Please enter a valid binary.\n");
                }
                break;

            case 3: // Exit
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option. Please choose a valid option (1-3).\n");
        }
    }

    return 0;
}