//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: safe
#include <stdio.h>
#include <stdint.h>

#define MAX_BITS 32

// Function to print the binary representation of an integer
void print_binary(uint32_t num) {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

// Function to demonstrate bitwise operations
void bitwise_operations_demo(uint32_t a, uint32_t b) {
    printf("Bitwise Operations on A: %u and B: %u\n", a, b);
    printf("-----------------------------------\n");

    // Bitwise AND
    uint32_t and_result = a & b;
    printf("A & B: %u (Binary: ", and_result);
    print_binary(and_result);
    
    // Bitwise OR
    uint32_t or_result = a | b;
    printf("A | B: %u (Binary: ", or_result);
    print_binary(or_result);
    
    // Bitwise XOR
    uint32_t xor_result = a ^ b;
    printf("A ^ B: %u (Binary: ", xor_result);
    print_binary(xor_result);
    
    // Bitwise NOT on A
    uint32_t not_a_result = ~a;
    printf("~A: %u (Binary: ", not_a_result);
    print_binary(not_a_result);
    
    // Bitwise NOT on B
    uint32_t not_b_result = ~b;
    printf("~B: %u (Binary: ", not_b_result);
    print_binary(not_b_result);

    // Left shift
    uint32_t left_shift_a = a << 1;
    printf("A << 1: %u (Binary: ", left_shift_a);
    print_binary(left_shift_a);
    
    // Right shift
    uint32_t right_shift_a = a >> 1;
    printf("A >> 1: %u (Binary: ", right_shift_a);
    print_binary(right_shift_a);
    
    // Check if bits are set using masks
    uint32_t mask = 0x00000003; // Example mask for the least significant 2 bits
    if (a & mask) {
        printf("Bits in the mask (0x00000003) are set in A.\n");
    } else {
        printf("Bits in the mask (0x00000003) are NOT set in A.\n");
    }

    // Toggling specific bits
    uint32_t toggle_bits = 0x00000002; // Toggle the second least significant bit
    uint32_t toggled_result = a ^ toggle_bits;
    printf("Toggle second bit of A: %u (Binary: ", toggled_result);
    print_binary(toggled_result);
    
    // Setting specific bits
    uint32_t set_bits = 0x00000004; // Set the third least significant bit
    uint32_t set_result = a | set_bits;
    printf("Set third bit of A: %u (Binary: ", set_result);
    print_binary(set_result);
}

// Function to read a 32-bit unsigned integer from user
uint32_t read_integer() {
    uint32_t value;
    printf("Enter a 32-bit unsigned integer: ");
    while (scanf("%u", &value) != 1) {
        printf("Invalid input. Please enter a valid 32-bit unsigned integer: ");
        while(getchar() != '\n'); // Clear the buffer
    }
    return value;
}

int main() {
    printf("Bitwise Operations Example Program\n");
    printf("===================================\n");

    // Read user input
    uint32_t a = read_integer();
    uint32_t b = read_integer();

    // Call demonstration function for bitwise operations
    bitwise_operations_demo(a, b);

    return 0;
}