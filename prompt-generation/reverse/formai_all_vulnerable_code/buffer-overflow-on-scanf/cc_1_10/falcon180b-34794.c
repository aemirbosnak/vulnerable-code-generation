//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define bitwise operators
#define AND &
#define OR |
#define XOR ^
#define NOT ~
#define LEFT_SHIFT <<
#define RIGHT_SHIFT >>

// Define bitwise functions
int bitwise_and(int a, int b);
int bitwise_or(int a, int b);
int bitwise_xor(int a, int b);
int bitwise_not(int a);
int bitwise_left_shift(int a, int b);
int bitwise_right_shift(int a, int b);

int main() {
    int num1, num2;

    // Prompt user for input
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Perform bitwise operations
    int result1 = bitwise_and(num1, num2);
    int result2 = bitwise_or(num1, num2);
    int result3 = bitwise_xor(num1, num2);
    int result4 = bitwise_not(num1);
    int result5 = bitwise_left_shift(num1, 2);
    int result6 = bitwise_right_shift(num1, 2);

    printf("\nBitwise AND: %d\n", result1);
    printf("Bitwise OR: %d\n", result2);
    printf("Bitwise XOR: %d\n", result3);
    printf("Bitwise NOT: %d\n", result4);
    printf("Bitwise Left Shift: %d\n", result5);
    printf("Bitwise Right Shift: %d\n", result6);

    return 0;
}

// Bitwise AND function
int bitwise_and(int a, int b) {
    return a & b;
}

// Bitwise OR function
int bitwise_or(int a, int b) {
    return a | b;
}

// Bitwise XOR function
int bitwise_xor(int a, int b) {
    return a ^ b;
}

// Bitwise NOT function
int bitwise_not(int a) {
    return ~a;
}

// Bitwise Left Shift function
int bitwise_left_shift(int a, int b) {
    return a << b;
}

// Bitwise Right Shift function
int bitwise_right_shift(int a, int b) {
    return a >> b;
}