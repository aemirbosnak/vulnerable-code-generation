//FormAI DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>
#include <math.h>

int decimalToBinary(int decimal);
int binaryToDecimal(long long binary);

int main() {
    int choice, decimal, binary;
    printf("Welcome to Binary Converter!\n\n");

    do {
        printf("Please select an option:\n");
        printf("1) Convert decimal to binary\n");
        printf("2) Convert binary to decimal\n");
        printf("3) Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter a decimal number: ");
                scanf("%d", &decimal);
                printf("%d (decimal) = %d (binary)\n\n", decimal, decimalToBinary(decimal));
                break;
            case 2:
                printf("\nEnter a binary number: ");
                scanf("%lld", &binary);
                printf("%lld (binary) = %d (decimal)\n\n", binary, binaryToDecimal(binary));
                break;
            case 3:
                printf("\nThank you for using Binary Converter!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }

    } while (choice != 3);

    return 0;
}

int decimalToBinary(int decimal) {
    int binary = 0, digit, exponent = 0;
    while (decimal > 0) {
        digit = decimal % 2;
        binary += digit * pow(10, exponent);
        decimal /= 2;
        exponent++;
    }
    return binary;
}

int binaryToDecimal(long long binary) {
    int decimal = 0, digit, exponent = 0;
    while (binary != 0) {
        digit = binary % 10;
        decimal += digit * pow(2, exponent);
        binary /= 10;
        exponent++;
    }
    return decimal;
}