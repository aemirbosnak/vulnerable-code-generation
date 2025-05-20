//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: introspective
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

// Function to perform left shift operation on an integer
int left_shift(int a, int b) {
    return a << b;
}

// Function to perform right shift operation on an integer
int right_shift(int a, int b) {
    return a >> b;
}

// Function to perform bitwise AND operation on all bits of two integers
int bitwise_and_all_bits(int a, int b) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        if ((a & (1 << i)) && (b & (1 << i))) {
            result |= (1 << i);
        }
    }
    return result;
}

// Function to perform bitwise OR operation on all bits of two integers
int bitwise_or_all_bits(int a, int b) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        if ((a & (1 << i)) || (b & (1 << i))) {
            result |= (1 << i);
        }
    }
    return result;
}

// Function to perform bitwise XOR operation on all bits of two integers
int bitwise_xor_all_bits(int a, int b) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        if ((a & (1 << i)) ^ (b & (1 << i))) {
            result |= (1 << i);
        }
    }
    return result;
}

int main() {
    int a = 0b10101010;
    int b = 0b11110000;

    // Perform bitwise AND operation on two integers
    printf("Bitwise AND: %d\n", bitwise_and(a, b));

    // Perform bitwise OR operation on two integers
    printf("Bitwise OR: %d\n", bitwise_or(a, b));

    // Perform bitwise XOR operation on two integers
    printf("Bitwise XOR: %d\n", bitwise_xor(a, b));

    // Perform bitwise NOT operation on an integer
    printf("Bitwise NOT: %d\n", bitwise_not(a));

    // Perform left shift operation on an integer
    printf("Left Shift: %d\n", left_shift(a, 2));

    // Perform right shift operation on an integer
    printf("Right Shift: %d\n", right_shift(a, 2));

    // Perform bitwise AND operation on all bits of two integers
    printf("Bitwise AND (all bits): %d\n", bitwise_and_all_bits(a, b));

    // Perform bitwise OR operation on all bits of two integers
    printf("Bitwise OR (all bits): %d\n", bitwise_or_all_bits(a, b));

    // Perform bitwise XOR operation on all bits of two integers
    printf("Bitwise XOR (all bits): %d\n", bitwise_xor_all_bits(a, b));

    return 0;
}