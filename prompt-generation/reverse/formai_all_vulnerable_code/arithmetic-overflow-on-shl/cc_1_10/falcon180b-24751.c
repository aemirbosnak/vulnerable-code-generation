//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print binary representation of a number
void printBinary(int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

// Function to perform bitwise AND operation
int bitwiseAND(int num1, int num2) {
    return num1 & num2;
}

// Function to perform bitwise OR operation
int bitwiseOR(int num1, int num2) {
    return num1 | num2;
}

// Function to perform bitwise XOR operation
int bitwiseXOR(int num1, int num2) {
    return num1 ^ num2;
}

// Function to perform bitwise NOT operation
int bitwiseNOT(int num) {
    return ~num;
}

// Function to perform bitwise left shift operation
int bitwiseLeftShift(int num, int shift) {
    return num << shift;
}

// Function to perform bitwise right shift operation
int bitwiseRightShift(int num, int shift) {
    return num >> shift;
}

int main() {
    // Example usage of bitwise AND operation
    int num1 = 10, num2 = 7;
    printf("Bitwise AND of %d and %d is %d\n", num1, num2, bitwiseAND(num1, num2));

    // Example usage of bitwise OR operation
    int num3 = 15, num4 = 12;
    printf("Bitwise OR of %d and %d is %d\n", num3, num4, bitwiseOR(num3, num4));

    // Example usage of bitwise XOR operation
    int num5 = 20, num6 = 25;
    printf("Bitwise XOR of %d and %d is %d\n", num5, num6, bitwiseXOR(num5, num6));

    // Example usage of bitwise NOT operation
    int num7 = 5;
    printf("Bitwise NOT of %d is %d\n", num7, bitwiseNOT(num7));

    // Example usage of bitwise left shift operation
    int num8 = 3, shift = 2;
    printf("Bitwise left shift of %d by %d is %d\n", num8, shift, bitwiseLeftShift(num8, shift));

    // Example usage of bitwise right shift operation
    int num9 = 100, shift2 = 3;
    printf("Bitwise right shift of %d by %d is %d\n", num9, shift2, bitwiseRightShift(num9, shift2));

    // Example usage of print binary representation of a number
    int num10 = 255;
    printBinary(num10);

    return 0;
}