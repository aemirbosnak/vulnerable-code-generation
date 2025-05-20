//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    char binary[32]; // Maximum 32 bits for binary representation
    int i = 0;
    while (decimal > 0) {
        binary[i++] = decimal % 2 + '0';
        decimal /= 2;
    }
    binary[i] = '\0'; // Add null terminator to the end of binary string
    printf("Binary representation of %d is: %s\n", decimal, binary);
}

// Function to convert binary to decimal
int binaryToDecimal(char binary[]) {
    int decimal = 0;
    int base = 1;
    int i = strlen(binary) - 1;
    while (i >= 0) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
        i--;
    }
    return decimal;
}

int main() {
    int choice;
    char input[32]; // Maximum 32 bits for binary representation

    do {
        printf("Binary Converter\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%s", input);
            decimalToBinary(atoi(input));
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%s", input);
            printf("Decimal representation of %s is: %d\n", input, binaryToDecimal(input));
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}