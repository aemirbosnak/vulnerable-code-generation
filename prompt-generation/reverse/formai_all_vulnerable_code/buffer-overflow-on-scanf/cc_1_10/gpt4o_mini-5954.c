//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: ultraprecise
#include <stdio.h>
#include <stdint.h>

#define MAX_BITS 32

// Function to print binary representation of a number
void printBinary(uint32_t num) {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" "); // For readability
    }
    printf("\n");
}

// Function to perform basic bitwise operations
void bitwiseOperations(uint32_t a, uint32_t b) {
    printf("Input A: ");
    printBinary(a);
    printf("Input B: ");
    printBinary(b);

    uint32_t and_result = a & b;
    uint32_t or_result = a | b;
    uint32_t xor_result = a ^ b;
    uint32_t not_a = ~a;
    uint32_t not_b = ~b;
    uint32_t left_shift_a = a << 1; // Left shift A
    uint32_t right_shift_b = b >> 1; // Right shift B

    printf("A & B:      ");
    printBinary(and_result);
    
    printf("A | B:      ");
    printBinary(or_result);
    
    printf("A ^ B:      ");
    printBinary(xor_result);
    
    printf("~A:         ");
    printBinary(not_a);
    
    printf("~B:         ");
    printBinary(not_b);
    
    printf("A << 1:     ");
    printBinary(left_shift_a);
    
    printf("B >> 1:     ");
    printBinary(right_shift_b);
}

// Main function
int main() {
    uint32_t a = 0xF0F0F0F0; // Example hex number
    uint32_t b = 0x0F0F0F0F; // Example hex number

    printf("Bitwise Operations Demonstration\n");
    printf("===================================\n");
    
    bitwiseOperations(a, b);
    
    printf("\nInteractive Bitwise Operation Section\n");
    printf("======================================\n");
    
    uint32_t num1, num2;
    
    // Interactive section for user input
    printf("Enter first number (in hex format, e.g., 0x1A): ");
    scanf("%x", &num1);
    
    printf("Enter second number (in hex format, e.g., 0x1A): ");
    scanf("%x", &num2);

    bitwiseOperations(num1, num2);
    
    printf("===================================\n");
    return 0;
}