//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    char binary[33];
    int i = 0;

    // Initialize binary with 0s
    for (int j = 0; j < 32; j++) {
        binary[j] = '0';
    }

    // Convert decimal to binary
    while (decimal > 0) {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
        i++;
    }

    // Reverse the binary string
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", binary[j]);
    }
}

int main() {
    int decimal, choice;

    // Prompt user to enter a decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Prompt user to choose between decimal and binary conversion
    printf("\nChoose conversion type:\n1. Decimal to Binary\n2. Binary to Decimal\n");
    scanf("%d", &choice);

    // Perform conversion based on user choice
    switch (choice) {
        case 1:
            decimalToBinary(decimal);
            printf("\nBinary representation: ");
            break;
        case 2:
            printf("\nBinary representation: ");
            while (decimal > 0) {
                printf("%d", decimal % 2);
                decimal /= 2;
            }
            break;
        default:
            printf("\nInvalid choice!");
            break;
    }

    return 0;
}