//FormAI DATASET v1.0 Category: Binary Converter ; Style: minimalist
#include <stdio.h>
#include <math.h>

/**
 * Function to convert decimal to binary
 * @param num the decimal number to convert
 * @return the equivalent binary number as a long long integer
 */
long long decimalToBinary(int num) {
    long long binaryNum = 0, count = 0;

    while (num != 0) {
        int remainder = num % 2;
        num = num / 2;

        binaryNum += remainder * pow(10, count);
        count++;
    }

    return binaryNum;
}

/**
 * Function to convert binary to decimal
 * @param num the binary number to convert
 * @return the equivalent decimal number as an integer
 */
int binaryToDecimal(long long num) {
    int decimalNum = 0, count = 0;

    while (num != 0) {
        int remainder = num % 10;
        num /= 10;

        decimalNum += remainder * pow(2, count);
        count++;
    }

    return decimalNum;
}

int main() {
    int decimalNum;
    long long binaryNum;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);
    binaryNum = decimalToBinary(decimalNum);
    printf("Binary equivalent: %lld\n", binaryNum);

    printf("Enter a binary number: ");
    scanf("%lld", &binaryNum);
    decimalNum = binaryToDecimal(binaryNum);
    printf("Decimal equivalent: %d\n", decimalNum);

    return 0;
}