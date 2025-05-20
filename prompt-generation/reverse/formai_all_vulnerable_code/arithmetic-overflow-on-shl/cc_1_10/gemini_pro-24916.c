//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    // Initialize two 32-bit unsigned integers
    uint32_t a = 0xABCDEF01;
    uint32_t b = 0x56789ABC;

    // Bitwise AND operation (&)
    uint32_t and_result = a & b;
    printf("Bitwise AND (a & b): 0x%08X\n", and_result);

    // Bitwise OR operation (|)
    uint32_t or_result = a | b;
    printf("Bitwise OR (a | b): 0x%08X\n", or_result);

    // Bitwise XOR operation (^)
    uint32_t xor_result = a ^ b;
    printf("Bitwise XOR (a ^ b): 0x%08X\n", xor_result);

    // Bitwise NOT operation (~)
    uint32_t not_result = ~a;
    printf("Bitwise NOT (~a): 0x%08X\n", not_result);

    // Bitwise left shift operation (<<)
    uint32_t left_shift_result = a << 4;
    printf("Bitwise left shift (a << 4): 0x%08X\n", left_shift_result);

    // Bitwise right shift operation (>>)
    uint32_t right_shift_result = a >> 4;
    printf("Bitwise right shift (a >> 4): 0x%08X\n", right_shift_result);

    // Check if a is a power of 2 using bitwise AND (&) with 0x1
    int is_power_of_2 = (a & (a - 1)) == 0;
    printf("Is a a power of 2? %s\n", is_power_of_2 ? "Yes" : "No");

    // Check if a and b have at least one bit set in common using bitwise OR (|)
    int have_common_bit_set = (a | b) != 0;
    printf("Do a and b have at least one bit set in common? %s\n", have_common_bit_set ? "Yes" : "No");

    // Count the number of bits set to 1 in a using bitwise AND (&) and bit shift (<<)
    int num_bits_set = 0;
    for (int i = 0; i < 32; i++) {
        num_bits_set += (a & (1 << i)) != 0;
    }
    printf("Number of bits set in a: %d\n", num_bits_set);

    // Check if a is divisible by 4 using bitwise AND (&) with 0x3
    int is_divisible_by_4 = (a & 0x3) == 0;
    printf("Is a divisible by 4? %s\n", is_divisible_by_4 ? "Yes" : "No");

    // Extract the least significant 4 bits of a using bitwise AND (&) with 0xF
    uint32_t least_4_bits = a & 0xF;
    printf("Least significant 4 bits of a: 0x%04X\n", least_4_bits);

    return 0;
}