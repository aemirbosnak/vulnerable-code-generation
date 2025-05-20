//FormAI DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * This is a binary converter program that converts decimal numbers to binary and vice versa.
 */

int decimalToBinary(int decimalNum) {
    int binaryNum = 0, i = 1;

    while (decimalNum > 0) {
        binaryNum += (decimalNum % 2) * i;
        decimalNum /= 2;
        i *= 10;
    }

    return binaryNum;
}

int binaryToDecimal(int binaryNum) {
    int decimalNum = 0, i = 0, remainder;

    while (binaryNum != 0) {
        remainder = binaryNum % 10;
        binaryNum /= 10;
        decimalNum += remainder * pow(2, i);
        i++;
    }

    return decimalNum;
}

int main() {
    int option, num;

    printf("=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
    printf("=*=* Binary Converter Program by Chatbot *=*=*\n");
    printf("=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");

    do {
        printf("\nChoose an option:\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter a decimal number: ");
                scanf("%d", &num);
                printf("\nBinary equivalent: %d\n", decimalToBinary(num));
                break;
            case 2:
                printf("\nEnter a binary number: ");
                scanf("%d", &num);
                printf("\nDecimal equivalent: %d\n", binaryToDecimal(num));
                break;
            case 3:
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    } while (option != 3);

    return 0;
}