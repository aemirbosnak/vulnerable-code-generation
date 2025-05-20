//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// function to convert decimal to binary
void decimalToBinary(int decimal) {
    char binary[33]; // binary number can have at most 32 digits + 1 for null terminator
    int i = 0;
    while (decimal > 0) {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[i] = '\0'; // null terminator
    printf("Binary representation: %s\n", binary);
}

// function to convert binary to decimal
int binaryToDecimal(char binary[]) {
    int decimal = 0, base = 1;
    int length = strlen(binary) - 1;
    for (int i = length; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

int main() {
    int choice, decimal;
    char binary[33];

    do {
        printf("Enter your choice:\n");
        printf("1. Decimal to binary conversion\n");
        printf("2. Binary to decimal conversion\n");
        printf("3. Exit\n");
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
                printf("Decimal representation: %d\n", binaryToDecimal(binary));
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}