//LLAMA2-13B DATASET v1.0 Category: Bitwise operations ; Style: authentic
#include <stdio.h>
#include <stdint.h>

// Function to print bitwise AND of two integers
void print_and(int a, int b) {
    int result = a & b;
    for (int i = 0; i < 32; i++) {
        if (result & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

// Function to print bitwise OR of two integers
void print_or(int a, int b) {
    int result = a | b;
    for (int i = 0; i < 32; i++) {
        if (result & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

// Function to print bitwise XOR of two integers
void print_xor(int a, int b) {
    int result = a ^ b;
    for (int i = 0; i < 32; i++) {
        if (result & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

int main() {
    int a = 0x12345678;
    int b = 0x23456789;

    // Print bitwise AND of a and b
    print_and(a, b);

    // Print bitwise OR of a and b
    print_or(a, b);

    // Print bitwise XOR of a and b
    print_xor(a, b);

    return 0;
}