//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include <stdio.h>

// Function to perform bitwise AND operation
void bitwise_and(int a, int b) {
    int result = a & b;
    printf("Bitwise AND of %d and %d is %d\n", a, b, result);
}

// Function to perform bitwise OR operation
void bitwise_or(int a, int b) {
    int result = a | b;
    printf("Bitwise OR of %d and %d is %d\n", a, b, result);
}

// Function to perform bitwise XOR operation
void bitwise_xor(int a, int b) {
    int result = a ^ b;
    printf("Bitwise XOR of %d and %d is %d\n", a, b, result);
}

// Function to perform bitwise NOT operation
void bitwise_not(int a) {
    int result = ~a;
    printf("Bitwise NOT of %d is %d\n", a, result);
}

// Function to perform left shift operation
void left_shift(int a, int positions) {
    int result = a << positions;
    printf("%d left shifted by %d positions is %d\n", a, positions, result);
}

// Function to perform right shift operation
void right_shift(int a, int positions) {
    int result = a >> positions;
    printf("%d right shifted by %d positions is %d\n", a, positions, result);
}

// Function to display binary representation of a number
void display_binary(int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    int a, b, positions;

    // Get user input for a and b
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Perform various bitwise operations
    printf("\nPerforming bitwise operations on %d and %d:\n", a, b);
    
    bitwise_and(a, b);
    bitwise_or(a, b);
    bitwise_xor(a, b);
    bitwise_not(a);
    bitwise_not(b);

    // Get user input for shift operations
    printf("\nEnter number of positions to shift (for %d): ", a);
    scanf("%d", &positions);
    left_shift(a, positions);
    right_shift(a, positions);

    printf("Binary representation of %d: ", a);
    display_binary(a);
    
    printf("Binary representation of %d: ", b);
    display_binary(b);

    // Creating a simple mask and applying it
    int mask = 0x0F; // binary 0000 1111
    printf("\nMasking %d with %d (mask): ", a, mask);
    int masked_result = a & mask;
    display_binary(mask);
    display_binary(masked_result);

    printf("Masked result is %d\n", masked_result);

    // Example using masks to toggle bits
    printf("Toggling bits of %d using mask %d\n", a, mask);
    int toggled_result = a ^ mask;
    display_binary(toggled_result);
    printf("Toggled result is %d\n", toggled_result);

    // Demonstrate chaining of operations
    int combined_result = (a & mask) | (b ^ mask);
    printf("\nCombining operations for %d and %d with mask %d:\n", a, b, mask);
    printf("Combined result is %d\n", combined_result);
    
    return 0;
}