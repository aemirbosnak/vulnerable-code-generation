//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to perform bitwise AND operation on two integers
int bitwise_and(int a, int b) {
    return a & b;
}

// Function to perform bitwise OR operation on two integers
int bitwise_or(int a, int b) {
    return a | b;
}

// Function to perform bitwise XOR operation on two integers
int bitwise_xor(int a, int b) {
    return a ^ b;
}

// Function to perform bitwise NOT operation on an integer
int bitwise_not(int a) {
    return ~a;
}

// Function to perform bitwise shift left operation on an integer
int bitwise_left_shift(int a, int b) {
    return a << b;
}

// Function to perform bitwise shift right operation on an integer
int bitwise_right_shift(int a, int b) {
    return a >> b;
}

// Function to perform bitwise rotate left operation on an integer
int bitwise_rotate_left(int a, int b) {
    return (a << b) | (a >> (sizeof(int) * 8 - b));
}

// Function to perform bitwise rotate right operation on an integer
int bitwise_rotate_right(int a, int b) {
    return (a >> b) | (a << (sizeof(int) * 8 - b));
}

// Function to perform bitwise set operation on an integer
int bitwise_set(int a, int b, int c) {
    return (a & ~(b | c));
}

int main() {
    // Example usage of bitwise operations
    int a = 5;
    int b = 3;

    printf("Bitwise AND: %d\n", bitwise_and(a, b));
    printf("Bitwise OR: %d\n", bitwise_or(a, b));
    printf("Bitwise XOR: %d\n", bitwise_xor(a, b));
    printf("Bitwise NOT: %d\n", bitwise_not(a));
    printf("Bitwise shift left: %d\n", bitwise_left_shift(a, 2));
    printf("Bitwise shift right: %d\n", bitwise_right_shift(a, 2));
    printf("Bitwise rotate left: %d\n", bitwise_rotate_left(a, 2));
    printf("Bitwise rotate right: %d\n", bitwise_rotate_right(a, 2));
    printf("Bitwise set: %d\n", bitwise_set(a, 3, 7));

    return 0;
}