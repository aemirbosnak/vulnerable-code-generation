//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>

// Function to find the bitwise AND of two numbers recursively
int bitwise_and(int a, int b) {
    // Base case: if either number is 0
    if (b == 0) return 0;
    if (a == 0) return 0;

    // Recursive case: perform bitwise AND without using the & operator
    return (a & b) + (bitwise_and(a >> 1, b >> 1) << 1);
}

// Function to find the bitwise OR of two numbers recursively
int bitwise_or(int a, int b) {
    // Base case: if both numbers are 0
    if (a == 0 && b == 0) return 0;

    // Recursive case: perform bitwise OR without using the | operator
    return (bitwise_and(a, b) ^ (a | b));
}

// Function to find the bitwise XOR of two numbers recursively
int bitwise_xor(int a, int b) {
    // Base case: if either number is 0
    if (a == 0) return b;
    if (b == 0) return a;

    // Recursive case: perform bitwise XOR without using the ^ operator
    return bitwise_or(bitwise_and(a, ~b), bitwise_and(~a, b));
}

// Function to print the binary representation of a number
void print_binary(int n) {
    if (n > 1) {
        print_binary(n >> 1);
    }
    printf("%d", n & 1);
}

// Function to demonstrate all bitwise operations
void demonstrate_bitwise_operations(int a, int b) {
    printf("Number A: %d (", a);
    print_binary(a);
    printf(")\n");

    printf("Number B: %d (", b);
    print_binary(b);
    printf(")\n");

    printf("Bitwise AND of A and B: %d (", bitwise_and(a, b));
    print_binary(bitwise_and(a, b));
    printf(")\n");

    printf("Bitwise OR of A and B: %d (", bitwise_or(a, b));
    print_binary(bitwise_or(a, b));
    printf(")\n");

    printf("Bitwise XOR of A and B: %d (", bitwise_xor(a, b));
    print_binary(bitwise_xor(a, b));
    printf(")\n");
}

// Main function to test the recursive bitwise operations
int main() {
    int a, b;

    // Input two integers
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Demonstrate bitwise operations
    demonstrate_bitwise_operations(a, b);

    return 0;
}