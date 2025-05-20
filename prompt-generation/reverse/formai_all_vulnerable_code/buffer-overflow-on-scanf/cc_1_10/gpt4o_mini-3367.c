//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: invasive
#include <stdio.h>

// Function to perform bitwise AND
int bitwise_and(int a, int b) {
    return a & b;
}

// Function to perform bitwise OR
int bitwise_or(int a, int b) {
    return a | b;
}

// Function to perform bitwise XOR
int bitwise_xor(int a, int b) {
    return a ^ b;
}

// Function to perform bitwise NOT
int bitwise_not(int a) {
    return ~a;
}

// Function to left shift
int left_shift(int a, int positions) {
    return a << positions;
}

// Function to right shift
int right_shift(int a, int positions) {
    return a >> positions;
}

// A function to display the binary representation of a number
void display_binary(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

// A utility function to demonstrate all bitwise operations
void demonstrate_bitwise_operations(int a, int b) {
    printf("a = %d, b = %d\n", a, b);
    printf("Binary representation of a: ");
    display_binary(a);
    printf("\nBinary representation of b: ");
    display_binary(b);
    printf("\n");
    
    printf("Bitwise AND (a & b): %d\n", bitwise_and(a, b));
    printf("Binary: ");
    display_binary(bitwise_and(a, b));
    printf("\n\n");

    printf("Bitwise OR (a | b): %d\n", bitwise_or(a, b));
    printf("Binary: ");
    display_binary(bitwise_or(a, b));
    printf("\n\n");

    printf("Bitwise XOR (a ^ b): %d\n", bitwise_xor(a, b));
    printf("Binary: ");
    display_binary(bitwise_xor(a, b));
    printf("\n\n");

    printf("Bitwise NOT (~a): %d\n", bitwise_not(a));
    printf("Binary: ");
    display_binary(bitwise_not(a));
    printf("\n\n");

    printf("Left shift (a << 1): %d\n", left_shift(a, 1));
    printf("Binary: ");
    display_binary(left_shift(a, 1));
    printf("\n\n");

    printf("Right shift (a >> 1): %d\n", right_shift(a, 1));
    printf("Binary: ");
    display_binary(right_shift(a, 1));
    printf("\n\n");
}

int main() {
    int a, b;

    printf("Enter two integers (a and b): ");
    scanf("%d %d", &a, &b);

    demonstrate_bitwise_operations(a, b);

    // Additional testing with various values
    for (int i = 0; i < 5; i++) {
        printf("\n--- Testing with values a = %d and b = %d ---\n", i, i + 3); // Incrementing for variety
        demonstrate_bitwise_operations(i, i + 3);
    }

    // Another set of operations
    printf("\n--- Additional Testing ---\n");
    int test_values[5] = {12, 15, 7, 0, 9};
    
    for (int i = 0; i < 4; i++) {
        printf("\nTesting a = %d and b = %d\n", test_values[i], test_values[i + 1]);
        demonstrate_bitwise_operations(test_values[i], test_values[i + 1]);
    }

    return 0;
}