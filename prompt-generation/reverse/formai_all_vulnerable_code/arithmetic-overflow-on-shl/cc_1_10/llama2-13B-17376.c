//LLAMA2-13B DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include <stdio.h>

// Function to print the binary representation of a number
void print_binary(int num) {
    int i, j;
    for (i = 0, j = 0; i < 32; i++, j += 3) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

// Function to perform bitwise AND operation
int bitwise_and(int a, int b) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
        if (a & (1 << i)) {
            res |= b & (1 << i);
        }
    }
    return res;
}

// Function to perform bitwise OR operation
int bitwise_or(int a, int b) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
        res |= a & (1 << i);
        res |= b & (1 << i);
    }
    return res;
}

// Function to perform bitwise XOR operation
int bitwise_xor(int a, int b) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
        res ^= a & (1 << i);
        res ^= b & (1 << i);
    }
    return res;
}

int main() {
    int a = 0x12345678;
    int b = 0x89abcdef;

    // Perform bitwise AND operation
    int result = bitwise_and(a, b);
    print_binary(result);

    // Perform bitwise OR operation
    result = bitwise_or(a, b);
    print_binary(result);

    // Perform bitwise XOR operation
    result = bitwise_xor(a, b);
    print_binary(result);

    return 0;
}