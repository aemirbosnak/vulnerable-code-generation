//LLAMA2-13B DATASET v1.0 Category: Bitwise operations ; Style: scientific
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
            for (j = 0; j < i; j++) {
                printf("0");
            }
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
    uint32_t a, b, c;

    // Example 1: Performing bitwise AND operation
    a = 0x12345678;
    b = 0x89abcdef;
    c = bitwise_and(a, b);
    print_binary(c);

    // Example 2: Performing bitwise OR operation
    a = 0x12345678;
    b = 0x89abcdef;
    c = bitwise_or(a, b);
    print_binary(c);

    // Example 3: Performing bitwise XOR operation
    a = 0x12345678;
    b = 0x89abcdef;
    c = bitwise_xor(a, b);
    print_binary(c);

    // Example 4: Performing bitwise AND and OR operation
    a = 0x12345678;
    b = 0x89abcdef;
    c = bitwise_and(a, b) | bitwise_or(a, b);
    print_binary(c);

    // Example 5: Performing bitwise XOR and AND operation
    a = 0x12345678;
    b = 0x89abcdef;
    c = bitwise_xor(a, b) & bitwise_and(a, b);
    print_binary(c);

    return 0;
}