//LLAMA2-13B DATASET v1.0 Category: Bitwise operations ; Style: genius
#include <stdio.h>
#include <stdint.h>

// Genius-level bitwise operations example program

// Function to reverse bits of a given integer
uint32_t reverse_bits(uint32_t num) {
    uint32_t rev = 0;
    for (int i = 0; i < 32; i++) {
        rev <<= 1;
        rev |= (num & (1 << i)) >> (32 - i);
    }
    return rev;
}

// Function to find the first set bit in a given integer
uint32_t first_set_bit(uint32_t num) {
    uint32_t bit = 0;
    for (int i = 0; i < 32; i++) {
        if (num & (1 << i)) {
            bit = i;
            break;
        }
    }
    return bit;
}

// Function to check if a given integer is a power of 2
uint32_t is_power_of_2(uint32_t num) {
    return num && (num & (num - 1)) == 0;
}

int main() {
    uint32_t num = 0xA1234567;

    // Reverse the bits of num
    num = reverse_bits(num);
    printf("Reversed bits of %08x: %08x\n", num, num);

    // Find the first set bit in num
    uint32_t bit = first_set_bit(num);
    printf("First set bit in %08x: %d\n", num, bit);

    // Check if num is a power of 2
    if (is_power_of_2(num)) {
        printf("num is a power of 2\n");
    } else {
        printf("num is not a power of 2\n");
    }

    return 0;
}