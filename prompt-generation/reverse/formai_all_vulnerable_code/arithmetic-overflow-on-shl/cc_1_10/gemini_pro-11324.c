//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>

// Define a custom data type called "bitfield" that represents a collection of bits.
typedef struct bitfield {
    unsigned int bits: 32; // The bitfield contains 32 bits.
} bitfield;

// Define a function to set a specific bit in the bitfield to 1.
void set_bit(bitfield *field, unsigned int bit) {
    field->bits |= (1 << bit); // Use bitwise OR to set the specified bit to 1.
}

// Define a function to clear a specific bit in the bitfield to 0.
void clear_bit(bitfield *field, unsigned int bit) {
    field->bits &= ~(1 << bit); // Use bitwise AND with a complement to clear the specified bit to 0.
}

// Define a function to check if a specific bit in the bitfield is set to 1.
int is_bit_set(bitfield *field, unsigned int bit) {
    return (field->bits & (1 << bit)) != 0; // Use bitwise AND to check if the specified bit is set to 1.
}

// Define a function to toggle a specific bit in the bitfield.
void toggle_bit(bitfield *field, unsigned int bit) {
    field->bits ^= (1 << bit); // Use bitwise XOR to toggle the specified bit.
}

// Define a function to print the bitfield in binary representation.
void print_bitfield(bitfield *field) {
    for (int i = 31; i >= 0; i--) { // Iterate through the bits from MSB to LSB.
        printf("%d", is_bit_set(field, i)); // Print the bit value (0 or 1) for each bit.
    }
    printf("\n");
}

int main() {
    // Initialize a bitfield and set some bits to 1.
    bitfield my_field = {0};
    set_bit(&my_field, 3);
    set_bit(&my_field, 7);
    set_bit(&my_field, 15);
    
    // Print the bitfield in binary representation.
    printf("Initial bitfield: ");
    print_bitfield(&my_field);
    
    // Clear the 7th bit and toggle the 15th bit.
    clear_bit(&my_field, 7);
    toggle_bit(&my_field, 15);
    
    // Print the modified bitfield.
    printf("Modified bitfield: ");
    print_bitfield(&my_field);
    
    return 0;
}