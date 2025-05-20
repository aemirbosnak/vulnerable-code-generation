//FormAI DATASET v1.0 Category: Bitwise operations ; Style: modular
#include <stdio.h>
#include <stdbool.h>

// Function to perform bitwise AND operation
int bitwiseAND(int x, int y) {
    return x & y;
}

// Function to perform bitwise OR operation
int bitwiseOR(int x, int y) {
    return x | y;
}

// Function to perform bitwise XOR operation
int bitwiseXOR(int x, int y) {
    return x ^ y;
}

// Function to perform bitwise NOT operation
int bitwiseNOT(int x) {
    return ~x;
}

// Function to perform left shift operation
int leftShift(int x, int n) {
    return x << n;
}

// Function to perform right shift operation
int rightShift(int x, int n) {
    return x >> n;
}

// Function to perform arithmetic right shift operation
int arithRightShift(int x, int n) {
    return (x < 0) ? ((x >> n) | ~(~0U >> n)) : (x >> n);
}


int main() {
    int x, y;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);

    printf("\nBitwise AND of %d and %d is: %d", x, y, bitwiseAND(x, y));
    printf("\nBitwise OR of %d and %d is: %d", x, y, bitwiseOR(x, y));
    printf("\nBitwise XOR of %d and %d is: %d", x, y, bitwiseXOR(x, y));
    printf("\nBitwise NOT of %d is: %d", x, bitwiseNOT(x));
    printf("\nLeft shift of %d by 2 is: %d", x, leftShift(x, 2));
    printf("\nRight shift of %d by 2 is: %d", x, rightShift(x, 2));
    printf("\nArithmetic right shift of %d by 2 is: %d\n", x, arithRightShift(x, 2));
    return 0;
}