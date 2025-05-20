//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

// Function to perform bitwise AND operation
int bitwise_and(int a, int b) {
    return a & b;
}

// Function to perform bitwise OR operation
int bitwise_or(int a, int b) {
    return a | b;
}

// Function to perform bitwise XOR operation
int bitwise_xor(int a, int b) {
    return a ^ b;
}

// Function to perform bitwise NOT operation
int bitwise_not(int a) {
    return ~a;
}

// Function to perform bitwise left shift operation
int bitwise_left_shift(int a, int b) {
    return a << b;
}

// Function to perform bitwise right shift operation
int bitwise_right_shift(int a, int b) {
    return a >> b;
}

int main() {
    int num1, num2;

    // Bitwise AND operation
    printf("Bitwise AND operation:\n");
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    printf("Bitwise AND of %d and %d is %d\n", num1, num2, bitwise_and(num1, num2));

    // Bitwise OR operation
    printf("\nBitwise OR operation:\n");
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    printf("Bitwise OR of %d and %d is %d\n", num1, num2, bitwise_or(num1, num2));

    // Bitwise XOR operation
    printf("\nBitwise XOR operation:\n");
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    printf("Bitwise XOR of %d and %d is %d\n", num1, num2, bitwise_xor(num1, num2));

    // Bitwise NOT operation
    printf("\nBitwise NOT operation:\n");
    printf("Enter an integer: ");
    scanf("%d", &num1);
    printf("Bitwise NOT of %d is %d\n", num1, bitwise_not(num1));

    // Bitwise left shift operation
    printf("\nBitwise left shift operation:\n");
    printf("Enter an integer and a number of positions to shift: ");
    scanf("%d %d", &num1, &num2);
    printf("Bitwise left shift of %d by %d positions is %d\n", num1, num2, bitwise_left_shift(num1, num2));

    // Bitwise right shift operation
    printf("\nBitwise right shift operation:\n");
    printf("Enter an integer and a number of positions to shift: ");
    scanf("%d %d", &num1, &num2);
    printf("Bitwise right shift of %d by %d positions is %d\n", num1, num2, bitwise_right_shift(num1, num2));

    return 0;
}