//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
#include <stdio.h>
#include <stdint.h>
#include <math.h>

// Forward declarations
uint8_t count_ones(uint64_t number);
uint64_t reverse_bits(uint64_t number, uint8_t num_bits);
uint64_t bitwise_swap(uint64_t number, uint8_t n1, uint8_t n2);
uint64_t set_bits(uint64_t number, uint8_t start, uint8_t end, uint8_t value);
uint64_t clear_bits(uint64_t number, uint8_t start, uint8_t end);
uint64_t toggle_bits(uint64_t number, uint8_t start, uint8_t end);

int main() {
    // Grab the user's input
    uint64_t number;
    printf("Enter a 64-bit unsigned integer: ");
    scanf("%llu", &number);

    // Count the number of ones in the binary representation of the number
    uint8_t ones_count = count_ones(number);
    printf("Number of ones in the binary representation: %u\n", ones_count);

    // Reverse the bits of the number
    uint64_t reversed_number = reverse_bits(number, 64);
    printf("Reversed bits: %llu\n", reversed_number);

    // Swap two bits in the number
    uint8_t n1, n2;
    printf("Enter two bit positions to swap (0-63): ");
    scanf("%hhu %hhu", &n1, &n2);
    uint64_t swapped_number = bitwise_swap(number, n1, n2);
    printf("Swapped bits: %llu\n", swapped_number);

    // Set a range of bits to a specified value
    uint8_t start, end, value;
    printf("Enter start and end positions of the range to set (0-63): ");
    scanf("%hhu %hhu", &start, &end);
    printf("Enter the value to set (0 or 1): ");
    scanf("%hhu", &value);
    uint64_t set_number = set_bits(number, start, end, value);
    printf("Set bits: %llu\n", set_number);

    // Clear a range of bits
    printf("Enter start and end positions of the range to clear (0-63): ");
    scanf("%hhu %hhu", &start, &end);
    uint64_t cleared_number = clear_bits(number, start, end);
    printf("Cleared bits: %llu\n", cleared_number);

    // Toggle a range of bits
    printf("Enter start and end positions of the range to toggle (0-63): ");
    scanf("%hhu %hhu", &start, &end);
    uint64_t toggled_number = toggle_bits(number, start, end);
    printf("Toggled bits: %llu\n", toggled_number);

    return 0;
}

// Count the number of ones in the binary representation of a number
uint8_t count_ones(uint64_t number) {
    uint8_t count = 0;
    while (number) {
        count += (number & 1);
        number >>= 1;
    }
    return count;
}

// Reverse the bits of a number
uint64_t reverse_bits(uint64_t number, uint8_t num_bits) {
    uint64_t reversed_number = 0;
    for (uint8_t i = 0; i < num_bits; i++) {
        reversed_number |= ((number >> i) & 1) << (num_bits - i - 1);
    }
    return reversed_number;
}

// Swap two bits in a number
uint64_t bitwise_swap(uint64_t number, uint8_t n1, uint8_t n2) {
    if (n1 == n2) {
        return number;
    }
    uint64_t mask1 = (1 << n1);
    uint64_t mask2 = (1 << n2);
    if ((number & mask1) == (number & mask2)) {
        return number;
    }
    number ^= (mask1 | mask2);
    return number;
}

// Set a range of bits to a specified value
uint64_t set_bits(uint64_t number, uint8_t start, uint8_t end, uint8_t value) {
    if (value == 0) {
        return clear_bits(number, start, end);
    }
    for (uint8_t i = start; i <= end; i++) {
        number |= (value << i);
    }
    return number;
}

// Clear a range of bits
uint64_t clear_bits(uint64_t number, uint8_t start, uint8_t end) {
    for (uint8_t i = start; i <= end; i++) {
        number &= ~(1 << i);
    }
    return number;
}

// Toggle a range of bits
uint64_t toggle_bits(uint64_t number, uint8_t start, uint8_t end) {
    for (uint8_t i = start; i <= end; i++) {
        number ^= (1 << i);
    }
    return number;
}