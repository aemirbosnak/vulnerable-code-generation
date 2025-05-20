//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

// Define some useful macros
#define BIT(n) (1 << (n))
#define GET_BIT(n, val) ((val) & BIT(n)) ? 1 : 0
#define SET_BIT(n, val) ((val) | BIT(n))
#define CLR_BIT(n, val) ((val) & ~BIT(n))
#define FLIP_BIT(n, val) ((val) ^ BIT(n))

// Print the binary representation of a number
void print_binary(uint32_t val) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", GET_BIT(i, val));
    }
    printf("\n");
}

// Get the number of bits set in a number (Hamming weight)
uint32_t get_bit_count(uint32_t val) {
    uint32_t count = 0;
    for (int i = 0; i < 32; i++) {
        if (GET_BIT(i, val)) {
            count++;
        }
    }
    return count;
}

// Get the position of the least significant bit set in a number (least significant 1)
uint32_t get_lsb(uint32_t val) {
    for (int i = 0; i < 32; i++) {
        if (GET_BIT(i, val)) {
            return i;
        }
    }
    return -1;
}

// Get the position of the most significant bit set in a number (most significant 1)
uint32_t get_msb(uint32_t val) {
    for (int i = 31; i >= 0; i--) {
        if (GET_BIT(i, val)) {
            return i;
        }
    }
    return -1;
}

// Reverse the bits of a number
uint32_t reverse_bits(uint32_t val) {
    uint32_t reversed = 0;
    for (int i = 0; i < 32; i++) {
        if (GET_BIT(i, val)) {
            reversed |= BIT(31 - i);
        }
    }
    return reversed;
}

// Count the number of consecutive 1s in a number
uint32_t count_consecutive_1s(uint32_t val) {
    uint32_t count = 0;
    uint32_t prev = 0;
    for (int i = 0; i < 32; i++) {
        if (GET_BIT(i, val)) {
            if (prev == 0) {
                count++;
            }
            prev = 1;
        } else {
            prev = 0;
        }
    }
    return count;
}

// Find the longest run of consecutive 0s in a number
uint32_t find_longest_run_of_0s(uint32_t val) {
    uint32_t longest = 0;
    uint32_t current = 0;
    for (int i = 0; i < 32; i++) {
        if (GET_BIT(i, val)) {
            current = 0;
        } else {
            current++;
            if (current > longest) {
                longest = current;
            }
        }
    }
    return longest;
}

// Find the longest run of consecutive 1s in a number
uint32_t find_longest_run_of_1s(uint32_t val) {
    uint32_t longest = 0;
    uint32_t current = 0;
    for (int i = 0; i < 32; i++) {
        if (GET_BIT(i, val)) {
            current++;
            if (current > longest) {
                longest = current;
            }
        } else {
            current = 0;
        }
    }
    return longest;
}

int main() {
    // Define a sample number
    uint32_t val = 0b10110101101110111011101110111011;

    // Print the original number
    printf("Original number: ");
    print_binary(val);

    // Get the number of bits set in the number
    uint32_t bit_count = get_bit_count(val);
    printf("Number of bits set: %d\n", bit_count);

    // Get the position of the least significant bit set in the number
    uint32_t lsb = get_lsb(val);
    printf("Least significant bit set: %d\n", lsb);

    // Get the position of the most significant bit set in the number
    uint32_t msb = get_msb(val);
    printf("Most significant bit set: %d\n", msb);

    // Reverse the bits of the number
    uint32_t reversed = reverse_bits(val);
    printf("Reversed bits: ");
    print_binary(reversed);

    // Count the number of consecutive 1s in the number
    uint32_t consecutive_1s = count_consecutive_1s(val);
    printf("Number of consecutive 1s: %d\n", consecutive_1s);

    // Find the longest run of consecutive 0s in the number
    uint32_t longest_run_of_0s = find_longest_run_of_0s(val);
    printf("Longest run of consecutive 0s: %d\n", longest_run_of_0s);

    // Find the longest run of consecutive 1s in the number
    uint32_t longest_run_of_1s = find_longest_run_of_1s(val);
    printf("Longest run of consecutive 1s: %d\n", longest_run_of_1s);

    return 0;
}