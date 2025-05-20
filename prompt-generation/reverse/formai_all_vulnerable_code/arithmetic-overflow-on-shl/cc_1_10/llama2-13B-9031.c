//LLAMA2-13B DATASET v1.0 Category: Bitwise operations ; Style: dynamic
#include <stdio.h>
#include <stdint.h>

// Function to print the binary representation of a number
void print_binary(uint32_t num) {
    int i, j;
    for (i = 0; i < 32; i++) {
        if (num & (1 << i)) {
            for (j = 0; j < i; j++) {
                printf("0");
            }
            printf("1");
        } else {
            printf("0");
        }
    }
}

// Function to perform bitwise AND operation
uint32_t bitwise_and(uint32_t a, uint32_t b) {
    return a & b;
}

// Function to perform bitwise OR operation
uint32_t bitwise_or(uint32_t a, uint32_t b) {
    return a | b;
}

// Function to perform bitwise XOR operation
uint32_t bitwise_xor(uint32_t a, uint32_t b) {
    return a ^ b;
}

int main() {
    uint32_t a = 0x12345678;
    uint32_t b = 0x89abcdef;
    uint32_t c = 0x12345678;

    // Perform bitwise AND operation
    c = bitwise_and(a, b);
    print_binary(c);

    // Perform bitwise OR operation
    c = bitwise_or(a, b);
    print_binary(c);

    // Perform bitwise XOR operation
    c = bitwise_xor(a, b);
    print_binary(c);

    // Perform bitwise NOT operation
    c = ~a;
    print_binary(c);

    // Perform bitwise LEFT shift
    c = a << 4;
    print_binary(c);

    // Perform bitwise RIGHT shift
    c = a >> 4;
    print_binary(c);

    return 0;
}