//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Bitwise operations
int main() {
  // Declare variables
  int a = 5, b = 3, c;

  // Bitwise AND
  c = a & b;  // 0101 & 0011 = 0001
  printf("Bitwise AND (a & b): %d\n", c);

  // Bitwise OR
  c = a | b;  // 0101 | 0011 = 0111
  printf("Bitwise OR (a | b): %d\n", c);

  // Bitwise XOR
  c = a ^ b;  // 0101 ^ 0011 = 0110
  printf("Bitwise XOR (a ^ b): %d\n", c);

  // Bitwise NOT
  c = ~a;  // ~0101 = 1010
  printf("Bitwise NOT (~a): %d\n", c);

  // Bitwise left shift
  c = a << 1;  // 0101 << 1 = 1010
  printf("Bitwise left shift (a << 1): %d\n", c);

  // Bitwise right shift
  c = a >> 1;  // 0101 >> 1 = 0010
  printf("Bitwise right shift (a >> 1): %d\n", c);

  // Bitwise rotate left
  c = (a << 1) | (a >> 31);  // (0101 << 1) | (0101 >> 31) = 1010
  printf("Bitwise rotate left: %d\n", c);

  // Bitwise rotate right
  c = (a >> 1) | (a << 31);  // (0101 >> 1) | (0101 << 31) = 0010
  printf("Bitwise rotate right: %d\n", c);

  // Bitwise count set bits
  int count = 0;
  for (int i = 0; i < 32; i++) {
    if ((a >> i) & 1) {
      count++;
    }
  }
  printf("Bitwise count set bits: %d\n", count);

  // Bitwise swap numbers
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  printf("Bitwise swap numbers: a = %d, b = %d\n", a, b);

  // Bitwise check if power of 2
  if ((a & (a - 1)) == 0) {
    printf("Bitwise check if power of 2: True\n");
  } else {
    printf("Bitwise check if power of 2: False\n");
  }

  // Bitwise find maximum and minimum
  int max = a > b ? a : b;
  int min = a < b ? a : b;
  printf("Bitwise find maximum: %d\n", max);
  printf("Bitwise find minimum: %d\n", min);

  return 0;
}