//FormAI DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void decimalToBinary(char binaryNumber[], int decimalNumber) {
    int quotient = decimalNumber;
    int index = 0;
 
    while (quotient != 0) {
        binaryNumber[index++] = quotient % 2 + '0';
        quotient /= 2;
    }
    binaryNumber[index] = '\0';
}
 
int binaryToDecimal(char binaryNumber[]) {
    int decimalNumber = 0;
    int power = 0;
    int length = strlen(binaryNumber);
 
    for (int i = length - 1; i >= 0; i--, power++) {
        if (binaryNumber[i] == '1') {
            decimalNumber += pow(2, power);
        } else if (binaryNumber[i] != '0') {
            printf("Invalid binary number.\n");
            return -1;
        }
    }
 
    return decimalNumber;
}

int main() {
    int decimalNumber;
    char binaryNumber[100];

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    decimalToBinary(binaryNumber, decimalNumber);
    printf("Binary number: %s\n", binaryNumber);

    printf("Enter a binary number: ");
    scanf("%s", binaryNumber);

    int result = binaryToDecimal(binaryNumber);

    if (result != -1) {
        printf("Decimal number: %d\n", result);
    }

    return 0;
}