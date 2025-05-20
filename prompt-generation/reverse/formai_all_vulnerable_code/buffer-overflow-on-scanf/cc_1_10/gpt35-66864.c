//FormAI DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int decimalNum) {
    int binaryNum[32];
    int i = 0;
    while(decimalNum > 0) {
        binaryNum[i] = decimalNum % 2;
        decimalNum = decimalNum / 2;
        i++;
    }
    printf("Binary Conversion: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d",binaryNum[j]);
    }
}

int binaryToDecimal(long long binaryNum) {
    int decimalNum = 0, i = 0, remainder;
    while(binaryNum > 0) {
        remainder = binaryNum % 10;
        binaryNum = binaryNum / 10;
        decimalNum += remainder * pow(2,i);
        i++;
    }
    return decimalNum;
}

int main() {
    int choice, decimalNum;
    long long binaryNum;
    printf("Please choose an Option:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter a Decimal number: ");
            scanf("%d", &decimalNum);
            decimalToBinary(decimalNum);
            break;
        case 2:
            printf("Enter a Binary number: ");
            scanf("%lld", &binaryNum);
            printf("Decimal Conversion: %d", binaryToDecimal(binaryNum));
            break;
        default:
            printf("Invalid Choice!");
            break;
    }
    return 0;
}