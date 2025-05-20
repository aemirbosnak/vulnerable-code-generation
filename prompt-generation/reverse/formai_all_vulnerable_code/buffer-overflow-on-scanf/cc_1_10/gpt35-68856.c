//FormAI DATASET v1.0 Category: Binary Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int binaryToDecimal(int num) {
    int decimal = 0, i = 0, remainder;
    while (num != 0) {
        remainder = num % 10;
        num /= 10;
        decimal += remainder * pow(2, i);
        ++i;
    }
    return decimal;
}

int decimalToBinary(int num) {
    int binary = 0, i = 1, remainder;
    while (num != 0) {
        remainder = num % 2;
        num /= 2;
        binary += remainder * i;
        i *= 10;
    }
    return binary;
}

int main() {
    int num, choice;
    printf("Welcome to the Binary Converter Genius Program\n");
    printf("--------------------------------------------\n");
    printf("Enter 1 to convert binary to decimal\n");
    printf("Enter 2 to convert decimal to binary\n");
    printf("Enter 3 to exit\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter a binary number: ");
                scanf("%d", &num);
                printf("Decimal equivalent of %d is %d\n", num, binaryToDecimal(num));
                break;
            case 2:
                printf("\nEnter a decimal number: ");
                scanf("%d", &num);
                printf("Binary equivalent of %d is %d\n", num, decimalToBinary(num));
                break;
            case 3:
                printf("\nThank you for using the Binary Converter Genius Program!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}