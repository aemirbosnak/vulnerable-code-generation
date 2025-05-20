//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned char u8;
typedef unsigned int u32;

// Reverse the bits of a byte
u8 reverse_byte(u8 b) {
    u8 reversed = 0;
    for (int i = 0; i < 8; i++) {
        reversed |= ((b >> i) & 1) << (7 - i);
    }
    return reversed;
}

// Reverse the bits of a word
u32 reverse_word(u32 w) {
    u32 reversed = 0;
    for (int i = 0; i < 32; i++) {
        reversed |= ((w >> i) & 1) << (31 - i);
    }
    return reversed;
}

// Swap the two halves of a 32-bit word
u32 swap_halves(u32 w) {
    return ((w >> 16) & 0xFFFF) | ((w & 0xFFFF) << 16);
}

// Check if a number is a power of 2
bool is_power_of_2(u32 n) {
    return (n & (n - 1)) == 0;
}

// Count the number of set bits in a byte
int count_set_bits(u8 b) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if ((b >> i) & 1) {
            count++;
        }
    }
    return count;
}

// Count the number of set bits in a word
int count_set_bits_word(u32 w) {
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if ((w >> i) & 1) {
            count++;
        }
    }
    return count;
}

// Rotate a byte left by a specified number of bits
u8 rotate_left_byte(u8 b, int n) {
    return (b << n) | (b >> (8 - n));
}

// Rotate a word left by a specified number of bits
u32 rotate_left_word(u32 w, int n) {
    return (w << n) | (w >> (32 - n));
}

// Rotate a byte right by a specified number of bits
u8 rotate_right_byte(u8 b, int n) {
    return (b >> n) | (b << (8 - n));
}

// Rotate a word right by a specified number of bits
u32 rotate_right_word(u32 w, int n) {
    return (w >> n) | (w << (32 - n));
}

// Extract the specified bits from a byte
u8 extract_bits(u8 b, int start, int end) {
    return (b >> start) & ((1 << (end - start + 1)) - 1);
}

// Extract the specified bits from a word
u32 extract_bits_word(u32 w, int start, int end) {
    return (w >> start) & ((1 << (end - start + 1)) - 1);
}

// Insert the specified bits into a byte at the specified position
u8 insert_bits(u8 b, u8 bits, int start, int end) {
    u8 mask = ((1 << (end - start + 1)) - 1) << start;
    return (b & ~mask) | (bits << start);
}

// Insert the specified bits into a word at the specified position
u32 insert_bits_word(u32 w, u32 bits, int start, int end) {
    u32 mask = ((1 << (end - start + 1)) - 1) << start;
    return (w & ~mask) | (bits << start);
}

int main() {
    // Example usage of the bitwise operations functions
    u8 b = 0b10101010;
    printf("Reversed byte: %08b\n", reverse_byte(b));

    u32 w = 0xFFFFFFFF;
    printf("Reversed word: %08X\n", reverse_word(w));

    printf("Swapped halves of word: %08X\n", swap_halves(w));

    if (is_power_of_2(w)) {
        printf("Word is a power of 2\n");
    } else {
        printf("Word is not a power of 2\n");
    }

    printf("Number of set bits in byte: %d\n", count_set_bits(b));
    printf("Number of set bits in word: %d\n", count_set_bits_word(w));

    printf("Rotated byte left by 3: %08b\n", rotate_left_byte(b, 3));
    printf("Rotated word left by 7: %08X\n", rotate_left_word(w, 7));

    printf("Rotated byte right by 5: %08b\n", rotate_right_byte(b, 5));
    printf("Rotated word right by 11: %08X\n", rotate_right_word(w, 11));

    printf("Extracted bits 2-5 from byte: %04b\n", extract_bits(b, 2, 5));
    printf("Extracted bits 10-15 from word: %06X\n", extract_bits_word(w, 10, 15));

    printf("Inserted bits 0b1111 into byte at position 3-6: %08b\n", insert_bits(b, 0b1111, 3, 6));
    printf("Inserted bits 0xFFFFFFFF into word at position 16-31: %08X\n", insert_bits_word(w, 0xFFFFFFFF, 16, 31));

    return 0;
}