//FormAI DATASET v1.0 Category: Bitwise operations ; Style: invasive
#include <stdio.h>

/* This program showcases the use of bitwise operations */

/* Function to convert decimal to binary */
void decimalToBinary(int num) {
    int binaryNum[32];
    int i = 0;
    while (num > 0) {
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }
    printf("\nBinary equivalent: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

/* Invasive Bitwise operation function */
int bitwiseOperation(int x, int y) {
    int result;
    result = x & y; /* Performs Bitwise AND operation */
    printf("\nBitwise AND operation\nx: %d, y: %d, result: %d", x, y, result);

    result = x | y; /* Performs Bitwise OR operation */
    printf("\nBitwise OR operation\nx: %d, y: %d, result: %d", x, y, result);

    result = x ^ y; /* Performs Bitwise XOR operation */
    printf("\nBitwise XOR operation\nx: %d, y: %d, result: %d", x, y, result);

    result = ~x; /* Performs Bitwise NOT operation */
    printf("\nBitwise NOT operation\nx: %d, y: %d, result: %d", x, y, result);

    result = x << y; /* Performs Bitwise left shift operation */
    printf("\nBitwise left shift operation\nx: %d, y: %d, result: %d", x, y, result);

    result = x >> y; /* Performs Bitwise right shift operation */
    printf("\nBitwise right shift operation\nx: %d, y: %d, result: %d", x, y, result);

    return result;
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    decimalToBinary(num1);
    decimalToBinary(num2);

    bitwiseOperation(num1, num2);

    return 0;
}