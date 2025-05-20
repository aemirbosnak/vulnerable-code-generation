//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Create a macro to print a binary representation of a number
#define PRINT_BINARY(x) \
    printf("%s: 0b", #x); \
    for (int i = sizeof(x) * 8 - 1; i >= 0; i--) { \
        printf("%d", (x >> i) & 1); \
    } \
    printf("\n")

// Create a function to perform bitwise operations on two numbers
int bitwise_operations(int a, int b) {
    // Print the binary representations of the numbers
    PRINT_BINARY(a);
    PRINT_BINARY(b);

    // Perform bitwise AND operation
    int and_result = a & b;
    PRINT_BINARY(and_result);

    // Perform bitwise OR operation
    int or_result = a | b;
    PRINT_BINARY(or_result);

    // Perform bitwise XOR operation
    int xor_result = a ^ b;
    PRINT_BINARY(xor_result);

    // Perform bitwise left shift operation
    int left_shift_result = a << 2;
    PRINT_BINARY(left_shift_result);

    // Perform bitwise right shift operation
    int right_shift_result = a >> 2;
    PRINT_BINARY(right_shift_result);

    // Perform bitwise ones complement operation
    int ones_complement_result = ~a;
    PRINT_BINARY(ones_complement_result);

    return 0;
}

int main() {
    // Get two numbers from the user
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Perform bitwise operations on the numbers
    bitwise_operations(a, b);

    return 0;
}