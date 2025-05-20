//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
int decimalToBinary(int n) {
    int binary = 0;
    int remainder;

    // Repeatedly divide the number by 2 and store the remainder in the binary variable
    while (n > 0) {
        remainder = n % 2;
        binary = binary * 10 + remainder;
        n /= 2;
    }

    // Return the binary representation of the number
    return binary;
}

// Function to convert a binary number to decimal
int binaryToDecimal(int n) {
    int decimal = 0;
    int power = 1;

    // Repeatedly divide the number by 10 and multiply the remainder by the power of 2
    while (n > 0) {
        int remainder = n % 10;
        decimal += remainder * power;
        power *= 2;
        n /= 10;
    }

    // Return the decimal representation of the number
    return decimal;
}

int main() {
    int choice;

    printf("Binary Converter\n");
    printf("----------------\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            int decimal;
            scanf("%d", &decimal);
            printf("Binary representation: %d\n", decimalToBinary(decimal));
            break;
        case 2:
            printf("Enter a binary number: ");
            int binary;
            scanf("%d", &binary);
            printf("Decimal representation: %d\n", binaryToDecimal(binary));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}