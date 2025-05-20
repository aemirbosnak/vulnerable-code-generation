//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define the SHA-256 hash function
uint32_t sha256(const uint8_t *data, size_t len) {
  // Initialize the hash state
  uint32_t h0 = 0x6A09E667;
  uint32_t h1 = 0xBB67AE85;
  uint32_t h2 = 0x3C6EF372;
  uint32_t h3 = 0xA54FF53A;
  uint32_t h4 = 0x510E527F;
  uint32_t h5 = 0x9B05688C;
  uint32_t h6 = 0x1F83D9AB;
  uint32_t h7 = 0x5BE0CD19;

  // Process the data in blocks of 512 bits
  for (size_t i = 0; i < len; i += 64) {
    // Create a 512-bit block from the data
    uint32_t w[16];
    for (size_t j = 0; j < 16; j++) {
      w[j] = (data[i + j * 4] << 24) | (data[i + j * 4 + 1] << 16) | (data[i + j * 4 + 2] << 8) | data[i + j * 4 + 3];
    }

    // Extend the 512-bit block to 800 bits
    for (size_t j = 16; j < 80; j++) {
      w[j] = (w[j - 3] ^ w[j - 8] ^ w[j - 14] ^ w[j - 16]) << 1 | (w[j - 3] ^ w[j - 8] ^ w[j - 14] ^ w[j - 16]) >> 31;
    }

    // Initialize the working variables
    uint32_t a = h0;
    uint32_t b = h1;
    uint32_t c = h2;
    uint32_t d = h3;
    uint32_t e = h4;
    uint32_t f = h5;
    uint32_t g = h6;
    uint32_t h = h7;

    // Perform the SHA-256 compression function
    for (size_t j = 0; j < 80; j++) {
      uint32_t s0 = (a >> 2 | a << 30) ^ (a >> 13 | a << 19) ^ (a >> 22 | a << 10);
      uint32_t s1 = (e >> 6 | e << 26) ^ (e >> 11 | e << 21) ^ (e >> 25 | e << 7);
      uint32_t ch = (e & f) ^ (~e & g);
      uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
      uint32_t temp1 = h + s1 + ch + w[j] + 0x428a2f98;
      uint32_t temp2 = s0 + maj;

      h = g;
      g = f;
      f = e;
      e = d + temp1;
      d = c;
      c = b;
      b = a;
      a = temp1 + temp2;
    }

    // Update the hash state
    h0 += a;
    h1 += b;
    h2 += c;
    h3 += d;
    h4 += e;
    h5 += f;
    h6 += g;
    h7 += h;
  }

  // Return the hash value
  return h0;
}

// Main function
int main() {
  // Get the input string
  char input[1024];
  printf("Enter the string to hash: ");
  scanf("%s", input);

  // Compute the SHA-256 hash of the input string
  uint32_t hash = sha256((const uint8_t *)input, strlen(input));

  // Print the hash value
  printf("SHA-256 hash: %08x\n", hash);

  return 0;
}