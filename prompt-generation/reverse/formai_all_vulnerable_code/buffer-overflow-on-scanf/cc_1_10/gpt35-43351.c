//FormAI DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

//Function to convert decimal to binary
long long decimalToBinary(int decimalNum) {
    long long binaryNum = 0;
    int remainder, i = 1;
    while(decimalNum != 0) {
        remainder = decimalNum % 2;
        decimalNum /= 2;
        binaryNum += remainder * i;
        i *= 10;
    }
    return binaryNum;
}

//Function to convert binary to decimal
int binaryToDecimal(long long binaryNum) {
    int decimalNum = 0, i = 0, remainder;
    while(binaryNum != 0) {
        remainder = binaryNum % 10;
        binaryNum /= 10;
        decimalNum += remainder * pow(2, i);
        ++i;
    }
    return decimalNum;
}

int main() {
    char choice;
    int decimalNum, binaryNum;
    long long binary;

    while(1) {
        printf("Choose Conversion :-\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNum);
                binary = decimalToBinary(decimalNum);
                printf("Binary equivalent of %d is %lld\n", decimalNum, binary);
                break;
            case '2':
                printf("Enter a binary number: ");
                scanf("%lld", &binaryNum);
                decimalNum = binaryToDecimal(binaryNum);
                printf("Decimal equivalent of %lld is %d\n", binaryNum, decimalNum);
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
    return 0;
}