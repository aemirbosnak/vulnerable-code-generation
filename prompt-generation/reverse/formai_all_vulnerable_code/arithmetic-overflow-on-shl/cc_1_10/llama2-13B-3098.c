//LLAMA2-13B DATASET v1.0 Category: Bitwise operations ; Style: detailed
#include <stdio.h>

// Function to print a binary representation of a number
void print_binary(int num) {
    int i, j;
    for (i = 0; i < 32; i++) {
        if (num & (1 << i)) {
            for (j = 0; j < i; j++) {
                printf("1");
            }
            printf("0");
        }
    }
}

// Function to perform bitwise AND operation
int bitwise_and(int a, int b) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        if (a & (1 << i)) {
            if (b & (1 << i)) {
                result |= (1 << i);
            }
        }
    }
    return result;
}

// Function to perform bitwise OR operation
int bitwise_or(int a, int b) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        if (a & (1 << i)) {
            result |= (1 << i);
        }
        if (b & (1 << i)) {
            result |= (1 << i);
        }
    }
    return result;
}

// Function to perform bitwise XOR operation
int bitwise_xor(int a, int b) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        if (a & (1 << i)) {
            result |= (1 << i) ^ (b & (1 << i));
        }
    }
    return result;
}

int main() {
    int a = 0b11010101;
    int b = 0b10101010;
    int c = 0b00000000;

    // Demonstrate bitwise AND operation
    printf("Bitwise AND of 0b11010101 and 0b10101010: ");
    print_binary(bitwise_and(a, b));
    printf("\n");

    // Demonstrate bitwise OR operation
    printf("Bitwise OR of 0b11010101 and 0b10101010: ");
    print_binary(bitwise_or(a, b));
    printf("\n");

    // Demonstrate bitwise XOR operation
    printf("Bitwise XOR of 0b11010101 and 0b10101010: ");
    print_binary(bitwise_xor(a, b));
    printf("\n");

    // Demonstrate bitwise operations on multiple values
    int d = 0b11010101;
    int e = 0b10101010;
    int f = 0b00000000;

    printf("Bitwise AND of 0b11010101 and 0b10101010: ");
    print_binary(bitwise_and(d, e));
    printf("\n");

    printf("Bitwise OR of 0b11010101 and 0b10101010: ");
    print_binary(bitwise_or(d, e));
    printf("\n");

    printf("Bitwise XOR of 0b11010101 and 0b10101010: ");
    print_binary(bitwise_xor(d, e));
    printf("\n");

    return 0;
}