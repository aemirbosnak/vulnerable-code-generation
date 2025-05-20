//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print binary representation of a number
void print_binary(unsigned int n) {
    unsigned int mask = 1 << 31;
    while (mask > 0) {
        if (n & mask) {
            printf("1");
        } else {
            printf("0");
        }
        mask >>= 1;
    }
}

// Function to perform bitwise AND operation on two numbers
unsigned int bitwise_and(unsigned int a, unsigned int b) {
    return a & b;
}

// Function to perform bitwise OR operation on two numbers
unsigned int bitwise_or(unsigned int a, unsigned int b) {
    return a | b;
}

// Function to perform bitwise XOR operation on two numbers
unsigned int bitwise_xor(unsigned int a, unsigned int b) {
    return a ^ b;
}

// Function to perform bitwise NOT operation on a number
unsigned int bitwise_not(unsigned int a) {
    return ~a;
}

// Function to perform bitwise left shift operation on a number
unsigned int bitwise_left_shift(unsigned int a, int b) {
    return a << b;
}

// Function to perform bitwise right shift operation on a number
unsigned int bitwise_right_shift(unsigned int a, int b) {
    return a >> b;
}

int main() {
    unsigned int num1 = 0b10101010;
    unsigned int num2 = 0b11010000;

    // Perform bitwise AND operation
    printf("Bitwise AND: ");
    print_binary(bitwise_and(num1, num2));
    printf("\n");

    // Perform bitwise OR operation
    printf("Bitwise OR: ");
    print_binary(bitwise_or(num1, num2));
    printf("\n");

    // Perform bitwise XOR operation
    printf("Bitwise XOR: ");
    print_binary(bitwise_xor(num1, num2));
    printf("\n");

    // Perform bitwise NOT operation
    printf("Bitwise NOT: ");
    print_binary(bitwise_not(num1));
    printf("\n");

    // Perform bitwise left shift operation
    printf("Bitwise left shift by 2 positions: ");
    print_binary(bitwise_left_shift(num1, 2));
    printf("\n");

    // Perform bitwise right shift operation
    printf("Bitwise right shift by 2 positions: ");
    print_binary(bitwise_right_shift(num1, 2));
    printf("\n");

    return 0;
}