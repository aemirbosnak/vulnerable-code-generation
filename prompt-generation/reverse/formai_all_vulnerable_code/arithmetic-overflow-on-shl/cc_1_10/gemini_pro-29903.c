//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: futuristic
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// Define the number of bits in a byte
#define BITS_PER_BYTE 8

// Define the number of bytes in a word
#define BYTES_PER_WORD 4

// Define the number of bits in a word
#define BITS_PER_WORD (BITS_PER_BYTE * BYTES_PER_WORD)

// Define the maximum value of a word
#define MAX_WORD_VALUE ((1 << BITS_PER_WORD) - 1)

// Define the minimum value of a word
#define MIN_WORD_VALUE 0

// Define the mask for the least significant bit
#define LSB_MASK (1 << 0)

// Define the mask for the most significant bit
#define MSB_MASK (1 << (BITS_PER_WORD - 1))

// Define the mask for all bits
#define ALL_BITS_MASK ((1 << BITS_PER_WORD) - 1)

// Define the function to set a bit
#define SET_BIT(word, bit) ((word) |= (1 << (bit)))

// Define the function to clear a bit
#define CLEAR_BIT(word, bit) ((word) &= ~(1 << (bit)))

// Define the function to toggle a bit
#define TOGGLE_BIT(word, bit) ((word) ^= (1 << (bit)))

// Define the function to check if a bit is set
#define IS_BIT_SET(word, bit) (((word) & (1 << (bit))) != 0)

// Define the function to check if a bit is clear
#define IS_BIT_CLEAR(word, bit) (((word) & (1 << (bit))) == 0)

// Define the function to rotate a word left by one bit
#define ROTATE_LEFT(word) (((word) << 1) | ((word) >> (BITS_PER_WORD - 1)))

// Define the function to rotate a word right by one bit
#define ROTATE_RIGHT(word) (((word) >> 1) | ((word) << (BITS_PER_WORD - 1)))

// Define the function to reverse the bits in a word
#define REVERSE_BITS(word) (((word) >> (BITS_PER_WORD - 1)) | ((word) << (BITS_PER_WORD - 1)))

// Define the function to count the number of bits set in a word
#define COUNT_BITS_SET(word) (__builtin_popcount(word))

// Define the function to count the number of bits clear in a word
#define COUNT_BITS_CLEAR(word) (BITS_PER_WORD - __builtin_popcount(word))

// Define the function to print a word in binary
#define PRINT_BINARY(word) do { \
    for (int i = BITS_PER_WORD - 1; i >= 0; i--) { \
        putchar(IS_BIT_SET(word, i) ? '1' : '0'); \
    } \
    putchar('\n'); \
} while (0)

int main() {
    // Initialize a word
    uint32_t word = 0xDEADBEEF;

    // Print the word in binary
    printf("Original word: ");
    PRINT_BINARY(word);

    // Set the least significant bit
    SET_BIT(word, 0);

    // Print the word in binary
    printf("After setting the least significant bit: ");
    PRINT_BINARY(word);

    // Clear the most significant bit
    CLEAR_BIT(word, 31);

    // Print the word in binary
    printf("After clearing the most significant bit: ");
    PRINT_BINARY(word);

    // Toggle the 16th bit
    TOGGLE_BIT(word, 15);

    // Print the word in binary
    printf("After toggling the 16th bit: ");
    PRINT_BINARY(word);

    // Check if the 10th bit is set
    if (IS_BIT_SET(word, 9)) {
        printf("The 10th bit is set\n");
    } else {
        printf("The 10th bit is clear\n");
    }

    // Check if the 20th bit is clear
    if (IS_BIT_CLEAR(word, 19)) {
        printf("The 20th bit is clear\n");
    } else {
        printf("The 20th bit is set\n");
    }

    // Rotate the word left by one bit
    word = ROTATE_LEFT(word);

    // Print the word in binary
    printf("After rotating the word left by one bit: ");
    PRINT_BINARY(word);

    // Rotate the word right by one bit
    word = ROTATE_RIGHT(word);

    // Print the word in binary
    printf("After rotating the word right by one bit: ");
    PRINT_BINARY(word);

    // Reverse the bits in the word
    word = REVERSE_BITS(word);

    // Print the word in binary
    printf("After reversing the bits in the word: ");
    PRINT_BINARY(word);

    // Count the number of bits set in the word
    int num_bits_set = COUNT_BITS_SET(word);

    // Print the number of bits set
    printf("Number of bits set: %d\n", num_bits_set);

    // Count the number of bits clear in the word
    int num_bits_clear = COUNT_BITS_CLEAR(word);

    // Print the number of bits clear
    printf("Number of bits clear: %d\n", num_bits_clear);

    return 0;
}