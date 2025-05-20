//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: imaginative
#include <stdio.h>

// Function to perform bitwise AND operation
unsigned int bitwise_and(unsigned int a, unsigned int b) {
    return a & b;
}

// Function to perform bitwise OR operation
unsigned int bitwise_or(unsigned int a, unsigned int b) {
    return a | b;
}

// Function to perform bitwise XOR operation
unsigned int bitwise_xor(unsigned int a, unsigned int b) {
    return a ^ b;
}

// Function to perform bitwise NOT operation
unsigned int bitwise_not(unsigned int a) {
    return ~a;
}

// Function to perform bitwise left shift operation
unsigned int bitwise_left_shift(unsigned int a, int b) {
    return a << b;
}

// Function to perform bitwise right shift operation
unsigned int bitwise_right_shift(unsigned int a, int b) {
    return a >> b;
}

int main() {
    unsigned int a, b, result;

    // Example of bitwise AND operation
    printf("Bitwise AND operation:\n");
    printf("Enter first number: ");
    scanf("%u", &a);
    printf("Enter second number: ");
    scanf("%u", &b);
    result = bitwise_and(a, b);
    printf("Result: %u\n", result);

    // Example of bitwise OR operation
    printf("\nBitwise OR operation:\n");
    printf("Enter first number: ");
    scanf("%u", &a);
    printf("Enter second number: ");
    scanf("%u", &b);
    result = bitwise_or(a, b);
    printf("Result: %u\n", result);

    // Example of bitwise XOR operation
    printf("\nBitwise XOR operation:\n");
    printf("Enter first number: ");
    scanf("%u", &a);
    printf("Enter second number: ");
    scanf("%u", &b);
    result = bitwise_xor(a, b);
    printf("Result: %u\n", result);

    // Example of bitwise NOT operation
    printf("\nBitwise NOT operation:\n");
    printf("Enter number: ");
    scanf("%u", &a);
    result = bitwise_not(a);
    printf("Result: %u\n", result);

    // Example of bitwise left shift operation
    printf("\nBitwise left shift operation:\n");
    printf("Enter number: ");
    scanf("%u", &a);
    printf("Enter shift value: ");
    scanf("%d", &b);
    result = bitwise_left_shift(a, b);
    printf("Result: %u\n", result);

    // Example of bitwise right shift operation
    printf("\nBitwise right shift operation:\n");
    printf("Enter number: ");
    scanf("%u", &a);
    printf("Enter shift value: ");
    scanf("%d", &b);
    result = bitwise_right_shift(a, b);
    printf("Result: %u\n", result);

    return 0;
}