//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>

// Function prototypes
int recursive_and(int a, int b);
int recursive_or(int a, int b);
int recursive_xor(int a, int b);
void print_binary(int n);
void bitwise_operations(int a, int b);

// Recursive function to calculate bitwise AND
int recursive_and(int a, int b) {
    if (b == 0) return a; // Base case
    return recursive_and(a & b, b - 1); // Recursive case
}

// Recursive function to calculate bitwise OR
int recursive_or(int a, int b) {
    if (b == 0) return a; // Base case
    return recursive_or(a | b, b - 1); // Recursive case
}

// Recursive function to calculate bitwise XOR
int recursive_xor(int a, int b) {
    if (b == 0) return a; // Base case
    return recursive_xor(a ^ b, b - 1); // Recursive case
}

// Helper function to print binary representation
void print_binary(int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

// Function to perform bitwise operations and display results
void bitwise_operations(int a, int b) {
    // Calculate results
    int and_result = recursive_and(a, b);
    int or_result = recursive_or(a, b);
    int xor_result = recursive_xor(a, b);
    
    // Output results
    printf("Bitwise Operations on %d and %d:\n", a, b);
    
    printf("AND Result: ");
    print_binary(and_result);
    
    printf("OR Result: ");
    print_binary(or_result);
    
    printf("XOR Result: ");
    print_binary(xor_result);
}

int main() {
    int a, b;

    // User input
    printf("Enter two integers:\n");
    scanf("%d %d", &a, &b);

    // Perform and display results of bitwise operations
    bitwise_operations(a, b);

    return 0;
}