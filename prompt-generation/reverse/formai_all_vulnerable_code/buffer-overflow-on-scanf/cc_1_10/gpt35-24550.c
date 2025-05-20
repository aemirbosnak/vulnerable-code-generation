//FormAI DATASET v1.0 Category: Binary Converter ; Style: complex
#include <stdio.h>

/*
 * This program converts a decimal number to binary
 * and vice versa.
 */

int decimalToBinary(int decimal);
int binaryToDecimal(int binary);

int main() {
    int choice, input;

    printf("Binary Converter\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter decimal number: ");
        scanf("%d", &input);
        printf("Binary: %d", decimalToBinary(input));
    } else if (choice == 2) {
        printf("Enter binary number: ");
        scanf("%d", &input);
        printf("Decimal: %d", binaryToDecimal(input));
    } else {
        printf("Invalid choice.");
    }

    return 0;
}

int decimalToBinary(int decimal) {
    int binary = 0, i = 1;

    while (decimal > 0) {
        binary += (decimal % 2) * i;
        decimal /= 2;
        i *= 10;
    }

    return binary;
}

int binaryToDecimal(int binary) {
    int decimal = 0, i = 0, rem;

    while (binary > 0) {
        rem = binary % 10;
        decimal += rem * (1 << i);
        binary /= 10;
        i++;
    }

    return decimal;
}