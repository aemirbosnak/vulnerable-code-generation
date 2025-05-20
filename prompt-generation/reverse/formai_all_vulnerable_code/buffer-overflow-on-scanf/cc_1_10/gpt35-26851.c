//FormAI DATASET v1.0 Category: Binary Converter ; Style: thoughtful
#include <stdio.h>

int convertToBinary(int decimal);
int convertToDecimal(long binary);

int main() {
    int choice, decimal;
    long binary;
    printf("Welcome to the Binary Converter!\n");
    printf("What would you like to convert?\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("\nEnter a decimal number: ");
            scanf("%d", &decimal);
            printf("%d in decimal = %d in binary\n", decimal, convertToBinary(decimal));
            break;
        case 2:
            printf("\nEnter a binary number: ");
            scanf("%ld", &binary);
            printf("%ld in binary = %d in decimal\n", binary, convertToDecimal(binary));
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}

int convertToBinary(int decimal) {
    int binary = 0, base = 1;
    while (decimal > 0) {
        binary += (decimal % 2) * base;
        decimal /= 2;
        base *= 10;
    }
    return binary;
}

int convertToDecimal(long binary) {
    int decimal = 0, base = 1, remainder;
    while (binary > 0) {
        remainder = binary % 10;
        decimal += remainder * base;
        binary /= 10;
        base *= 2;
    }
    return decimal;
}