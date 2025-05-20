//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int n) {
    // Arrays to store binary representation
    int binary[32];
    int index = 0;

    // Edge case for zero
    if (n == 0) {
        printf("Binary equivalent: 0\n");
        return;
    }

    // Convert decimal to binary
    while (n > 0) {
        binary[index] = n % 2;
        n = n / 2;
        index++;
    }

    // Print binary representation in reverse order
    printf("Binary equivalent: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

void binaryToDecimal(char* binary) {
    int decimal = 0;
    int base = 1;
    int len = strlen(binary);

    // Ensure we read the string from right to left
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    printf("Decimal equivalent: %d\n", decimal);
}

void menu() {
    printf("Choose an option:\n");
    printf("1. Decimal to Binary Conversion\n");
    printf("2. Binary to Decimal Conversion\n");
    printf("3. Exit\n");
}

int main() {
    int choice, decimal;
    char binary[32];

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimalToBinary(decimal);
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binary);
                binaryToDecimal(binary);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 3.\n");
        }
        
        printf("\n");
    } while (choice != 3);

    return 0;
}