//FormAI DATASET v1.0 Category: Binary Converter ; Style: thoughtful
#include <stdio.h>

// function to convert decimal to binary
void decimalToBinary(int decimal) {
    int binary[32], index = 0;

    // finding binary representation of decimal
    while (decimal > 0) {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }

    // printing binary representation of decimal
    printf("Binary representation: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

// function to convert binary to decimal
void binaryToDecimal(int binary) {
    int decimal = 0, base = 1;

    // finding decimal representation of binary
    while (binary > 0) {
        int lastDigit = binary % 10;
        decimal += lastDigit * base;
        base *= 2;
        binary /= 10;
    }

    // printing decimal representation of binary
    printf("Decimal representation: %d", decimal);
}

int main() {
    int choice, decimal, binary;

    printf("Binary Converter\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter decimal number: ");
            scanf("%d", &decimal);
            decimalToBinary(decimal);
            break;
        case 2:
            printf("Enter binary number: ");
            scanf("%d", &binary);
            binaryToDecimal(binary);
            break;
        default:
            printf("Invalid choice");
    }

    return 0;
}