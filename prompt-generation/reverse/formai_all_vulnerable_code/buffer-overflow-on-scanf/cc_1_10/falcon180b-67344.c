//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LENGTH 32

// Function to convert binary to decimal
int binaryToDecimal(char* binaryNum) {
    int decimal = 0, i = 0;
    while (binaryNum[i]!= '\0') {
        if (binaryNum[i] == '1') {
            decimal += pow(2, MAX_NUM_LENGTH - i - 1);
        }
        i++;
    }
    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal, char* binaryNum) {
    int i = 0;
    while (decimal > 0) {
        if (decimal % 2 == 1) {
            binaryNum[i] = '1';
        } else {
            binaryNum[i] = '0';
        }
        i++;
        decimal /= 2;
    }
    binaryNum[i] = '\0';
}

int main() {
    char binaryNum[MAX_NUM_LENGTH];
    int decimal;

    printf("Enter a binary number: ");
    scanf("%s", binaryNum);

    decimal = binaryToDecimal(binaryNum);
    printf("Decimal equivalent: %d\n", decimal);

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal, binaryNum);
    printf("Binary equivalent: %s\n", binaryNum);

    return 0;
}