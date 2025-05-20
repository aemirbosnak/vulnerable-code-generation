//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32

void decimalToBinary(int num, char* buffer) {
    int index = MAX_BITS - 1;
    buffer[index + 1] = '\0'; // Null terminate the string
    for (int i = 0; i < MAX_BITS; i++) {
        buffer[index--] = (num & (1 << (MAX_BITS - 1 - i))) ? '1' : '0';
    }
}

void binaryToDecimal(const char* binary, int* num) {
    *num = 0;
    for (int i = 0; i < MAX_BITS; i++) {
        *num <<= 1;
        if (binary[i] == '1') {
            *num |= 1;
        }
    }
}

void displayMenu() {
    printf("Binary Converter\n");
    printf("=================\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Exit\n");
}

void handleDecimalToBinaryConversion() {
    int decimalNumber;
    char binaryOutput[MAX_BITS + 1];

    printf("Enter a decimal number (0 - %d): ", (1 << MAX_BITS) - 1);
    scanf("%d", &decimalNumber);

    if (decimalNumber < 0 || decimalNumber >= (1 << MAX_BITS)) {
        printf("Please enter a valid number between 0 and %d.\n", (1 << MAX_BITS) - 1);
        return;
    }

    decimalToBinary(decimalNumber, binaryOutput);
    printf("Binary representation: %s\n", binaryOutput);
}

void handleBinaryToDecimalConversion() {
    char binaryInput[MAX_BITS + 1];
    int decimalOutput;

    printf("Enter a binary number (up to %d bits): ", MAX_BITS);
    scanf("%s", binaryInput);

    if (strlen(binaryInput) > MAX_BITS) {
        printf("Invalid input! Please enter a valid binary number with up to %d bits.\n", MAX_BITS);
        return;
    }

    for (int i = 0; i < strlen(binaryInput); i++) {
        if (binaryInput[i] != '0' && binaryInput[i] != '1') {
            printf("Invalid input! Please enter only 0s and 1s.\n");
            return;
        }
    }

    binaryToDecimal(binaryInput, &decimalOutput);
    printf("Decimal representation: %d\n", decimalOutput);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                handleDecimalToBinaryConversion();
                break;
            case 2:
                handleBinaryToDecimalConversion();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}