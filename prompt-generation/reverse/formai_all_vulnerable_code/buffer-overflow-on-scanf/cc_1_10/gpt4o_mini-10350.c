//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>

int main() {
    // Introduction to Bitwise Operations
    printf("Welcome to the World of Bitwise Operations!\n");
    printf("In this program, we'll explore various bitwise operations in C.\n");
    
    unsigned int a, b; // Define two unsigned integers
    unsigned int result;

    // Let's start by asking the user for their input
    printf("Please enter two positive integers (a b): ");
    scanf("%u %u", &a, &b);

    // Display the binary representation of the numbers
    printf("\nBinary representation of %u: ", a);
    for (int i = sizeof(a) * 8 - 1; i >= 0; i--) {
        printf("%u", (a >> i) & 1);
    }
    
    printf("\nBinary representation of %u: ", b);
    for (int i = sizeof(b) * 8 - 1; i >= 0; i--) {
        printf("%u", (b >> i) & 1);
    }
    
    // Bitwise AND operation
    result = a & b;
    printf("\n\nPerforming Bitwise AND operation (a & b): %u\n", result);
    printf("Binary result of a & b: ");
    for (int i = sizeof(result) * 8 - 1; i >= 0; i--) {
        printf("%u", (result >> i) & 1);
    }

    // Bitwise OR operation
    result = a | b;
    printf("\n\nPerforming Bitwise OR operation (a | b): %u\n", result);
    printf("Binary result of a | b: ");
    for (int i = sizeof(result) * 8 - 1; i >= 0; i--) {
        printf("%u", (result >> i) & 1);
    }

    // Bitwise XOR operation
    result = a ^ b;
    printf("\n\nPerforming Bitwise XOR operation (a ^ b): %u\n", result);
    printf("Binary result of a ^ b: ");
    for (int i = sizeof(result) * 8 - 1; i >= 0; i--) {
        printf("%u", (result >> i) & 1);
    }

    // Bitwise NOT operation
    result = ~a;
    printf("\n\nPerforming Bitwise NOT operation (~a): %u\n", result);
    printf("Binary result of ~a: ");
    for (int i = sizeof(result) * 8 - 1; i >= 0; i--) {
        printf("%u", (result >> i) & 1);
    }

    // Left shift operation
    printf("\n\nPerforming Left Shift operation (a << 1): %u\n", a << 1);
    printf("Binary result of a << 1: ");
    result = a << 1;
    for (int i = sizeof(result) * 8 - 1; i >= 0; i--) {
        printf("%u", (result >> i) & 1);
    }

    // Right shift operation
    printf("\n\nPerforming Right Shift operation (b >> 1): %u\n", b >> 1);
    printf("Binary result of b >> 1: ");
    result = b >> 1;
    for (int i = sizeof(result) * 8 - 1; i >= 0; i--) {
        printf("%u", (result >> i) & 1);
    }

    // Combining operations to illustrate their power
    printf("\n\nCombining Operations: (a & b) << 2 | (a ^ b)\n");
    result = (a & b) << 2 | (a ^ b);
    printf("Result: %u\n", result);
    printf("Binary result of combined operations: ");
    for (int i = sizeof(result) * 8 - 1; i >= 0; i--) {
        printf("%u", (result >> i) & 1);
    }

    // Conclusion
    printf("\n\nWe have reached the end of our Bitwise Operations exploration!\n");
    printf("Bitwise operations allow for powerful manipulations of data at the binary level.\n");
    printf("Try experimenting with different numbers to see the effects!\n");

    return 0;
}