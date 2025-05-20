//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: introspective
#include <stdio.h>

// Function to demonstrate basic bitwise operations
void bitwise_operations(int a, int b) {
    printf("Bitwise Operations:\n");
    printf("A = %d (in binary: ", a);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (a >> i) & 1);
    }
    printf(")\n");
    
    printf("B = %d (in binary: ", b);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (b >> i) & 1);
    }
    printf(")\n");

    // Bitwise AND
    int and_result = a & b;
    printf("A & B = %d (in binary: ", and_result);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (and_result >> i) & 1);
    }
    printf(")\n");
    
    // Bitwise OR
    int or_result = a | b;
    printf("A | B = %d (in binary: ", or_result);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (or_result >> i) & 1);
    }
    printf(")\n");

    // Bitwise XOR
    int xor_result = a ^ b;
    printf("A ^ B = %d (in binary: ", xor_result);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (xor_result >> i) & 1);
    }
    printf(")\n");

    // Bitwise NOT
    int not_a = ~a;
    printf("~A = %d (in binary: ", not_a);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (not_a >> i) & 1);
    }
    printf(")\n");

    // Left Shift
    int left_shift_a = a << 1;
    printf("A << 1 = %d (in binary: ", left_shift_a);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (left_shift_a >> i) & 1);
    }
    printf(")\n");

    // Right Shift
    int right_shift_a = a >> 1;
    printf("A >> 1 = %d (in binary: ", right_shift_a);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (right_shift_a >> i) & 1);
    }
    printf(")\n");
}

// Function to read an integer
int read_integer(const char *prompt) {
    int num;
    printf("%s", prompt);
    scanf("%d", &num);
    return num;
}

// Main function
int main() {
    printf("Welcome to the Bitwise Operations Demonstration!\n");
    
    int a = read_integer("Please enter the first integer (A): ");
    int b = read_integer("Please enter the second integer (B): ");
    
    bitwise_operations(a, b);
    
    printf("\nThank you for using the Bitwise Operations Demonstration. Goodbye!\n");
    return 0;
}