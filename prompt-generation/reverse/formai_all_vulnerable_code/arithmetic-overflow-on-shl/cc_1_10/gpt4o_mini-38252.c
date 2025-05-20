//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Function to print binary representation of an integer
void print_binary(uint32_t num) {
    for (int i = 31; i >= 0; i--) {
        putchar((num & (1 << i)) ? '1' : '0');
    }
    putchar('\n');
}

// Function to perform and display bitwise operations
void bitwise_operations(uint32_t a, uint32_t b) {
    uint32_t and_result = a & b;
    uint32_t or_result = a | b;
    uint32_t xor_result = a ^ b;
    uint32_t not_a = ~a;
    uint32_t not_b = ~b;
    uint32_t left_shift_a = a << 1;
    uint32_t right_shift_a = a >> 1;
    
    printf("Bitwise Operations on:\n");
    printf("a = ");
    print_binary(a);
    printf("b = ");
    print_binary(b);
    
    printf("\na AND b:\n");
    print_binary(and_result);
    
    printf("\na OR b:\n");
    print_binary(or_result);
    
    printf("\na XOR b:\n");
    print_binary(xor_result);
    
    printf("\nNOT a:\n");
    print_binary(not_a);
    
    printf("\nNOT b:\n");
    print_binary(not_b);
    
    printf("\na << 1:\n");
    print_binary(left_shift_a);
    
    printf("\na >> 1:\n");
    print_binary(right_shift_a);
}

// Function to count the number of `1`s in the binary representation of a number
int count_set_bits(uint32_t num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

// Function to check if a number is power of two
int is_power_of_two(uint32_t num) {
    return (num && !(num & (num - 1))) ? 1 : 0;
}

// Function to create a mask with 'n' bits set to 1
uint32_t create_mask(int n) {
    return (1U << n) - 1;
}

// Function to toggle the 'n-th' bit of a number
uint32_t toggle_nth_bit(uint32_t num, int n) {
    return num ^ (1U << n);
}

// Function to demonstrate bit manipulation techniques
void demonstrate_bit_manipulation() {
    uint32_t number = 0b10101010101010101010101010101010; // Example number
    int n = 3; // Bit position to toggle

    printf("Original number:\n");
    print_binary(number);

    printf("\nAttempting to toggle the %d-th bit:\n", n);
    uint32_t toggled_number = toggle_nth_bit(number, n);
    print_binary(toggled_number);

    printf("\nCount of `1`s in the original number: %d\n", count_set_bits(number));
    printf("Is the original number a power of two? %s\n", is_power_of_two(number) ? "Yes" : "No");

    int mask_bits = 8; // Create a mask with first 'mask_bits' bits set
    uint32_t mask = create_mask(mask_bits);
    printf("\nMask with the first %d bits set:\n", mask_bits);
    print_binary(mask);

    printf("\nApplying AND operation with the mask:\n");
    print_binary(number & mask);
}

// Main function to drive the program
int main() {
    printf("Welcome to the Bitwise Operation Demonstration Program!\n");

    uint32_t a = 0b11001100110011001100110011001100; // Example value for a
    uint32_t b = 0b10101010101010101010101010101010; // Example value for b

    bitwise_operations(a, b);
    demonstrate_bit_manipulation();

    return 0;
}