//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Paranoia is good for security!

// Check if a bit is set.
#define IS_BIT_SET(x, bit) (!!((x) & (1 << (bit))))

// Set a bit.
#define SET_BIT(x, bit) ((x) |= (1 << (bit)))

// Clear a bit.
#define CLEAR_BIT(x, bit) ((x) &= ~(1 << (bit)))

// Toggle a bit.
#define TOGGLE_BIT(x, bit) ((x) ^= (1 << (bit)))

// Get the least significant bit set.
#define LSB_INDEX(x) (__builtin_ffsll(x))

// Get the most significant bit set.
#define MSB_INDEX(x) (63 - __builtin_clzll(x))

// Get the number of bits set.
#define POPCOUNT(x) (__builtin_popcountll(x))

// Get the parity of a number.
#define PARITY(x) (((x) & 1) ^ ((x) >> 1 & 1) ^ ((x) >> 2 & 1) ^ ((x) >> 3 & 1) ^ ((x) >> 4 & 1) ^ ((x) >> 5 & 1) ^ ((x) >> 6 & 1) ^ ((x) >> 7 & 1))

// Reverse the bits of a number.
#define REVERSE_BITS(x) (__builtin_bswap64(x))

// Rotate a number left by n bits.
#define ROTL(x, n) (((x) << (n)) | ((x) >> (64 - (n))))

// Rotate a number right by n bits.
#define ROTR(x, n) (((x) >> (n)) | ((x) << (64 - (n))))

int main() {
  // Initialize a variable to 0xFFFFFFFFFFFFFFFF.
  unsigned long long x = 0xFFFFFFFFFFFFFFFF;

  // Check if the least significant bit is set.
  if (IS_BIT_SET(x, 0)) {
    printf("The least significant bit is set.\n");
  }

  // Set the 32nd bit.
  SET_BIT(x, 32);

  // Clear the 64th bit.
  CLEAR_BIT(x, 64);

  // Toggle the 128th bit.
  TOGGLE_BIT(x, 128);

  // Get the least significant bit set.
  int lsb_index = LSB_INDEX(x);

  // Get the most significant bit set.
  int msb_index = MSB_INDEX(x);

  // Get the number of bits set.
  int popcount = POPCOUNT(x);

  // Get the parity of the number.
  int parity = PARITY(x);

  // Reverse the bits of the number.
  unsigned long long reversed_x = REVERSE_BITS(x);

  // Rotate the number left by 32 bits.
  unsigned long long rotated_left_x = ROTL(x, 32);

  // Rotate the number right by 64 bits.
  unsigned long long rotated_right_x = ROTR(x, 64);

  // Print the results.
  printf("x: %llx\n", x);
  printf("lsb_index: %d\n", lsb_index);
  printf("msb_index: %d\n", msb_index);
  printf("popcount: %d\n", popcount);
  printf("parity: %d\n", parity);
  printf("reversed_x: %llx\n", reversed_x);
  printf("rotated_left_x: %llx\n", rotated_left_x);
  printf("rotated_right_x: %llx\n", rotated_right_x);

  return 0;
}