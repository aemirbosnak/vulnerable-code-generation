//Code Llama-13B DATASET v1.0 Category: Binary Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define the base conversion functions
uint32_t bin_to_dec(uint32_t bin) {
  uint32_t dec = 0;
  int i = 0;
  while (bin > 0) {
    dec += (bin % 10) * pow(2, i);
    bin /= 10;
    i++;
  }
  return dec;
}

uint32_t dec_to_bin(uint32_t dec) {
  uint32_t bin = 0;
  int i = 0;
  while (dec > 0) {
    bin += (dec % 2) * pow(10, i);
    dec /= 2;
    i++;
  }
  return bin;
}

// Define the main function
int main() {
  // Declare variables
  uint32_t bin, dec;

  // Get input from user
  printf("Enter a binary number: ");
  scanf("%u", &bin);

  // Convert binary to decimal
  dec = bin_to_dec(bin);

  // Print result
  printf("Decimal equivalent: %u\n", dec);

  // Convert decimal to binary
  bin = dec_to_bin(dec);

  // Print result
  printf("Binary equivalent: %u\n", bin);

  return 0;
}