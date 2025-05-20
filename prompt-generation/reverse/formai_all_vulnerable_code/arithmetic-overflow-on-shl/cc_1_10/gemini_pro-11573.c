//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: minimalist
#include <stdio.h>

int main() {
  // Declare variables
  unsigned int a = 0x1234, b = 0x5678, c;

  // Perform bitwise AND operation
  c = a & b;
  printf("Bitwise AND (a & b): %x\n", c);

  // Perform bitwise OR operation
  c = a | b;
  printf("Bitwise OR (a | b): %x\n", c);

  // Perform bitwise XOR operation
  c = a ^ b;
  printf("Bitwise XOR (a ^ b): %x\n", c);

  // Perform bitwise NOT operation on a
  c = ~a;
  printf("Bitwise NOT (~a): %x\n", c);

  // Perform bitwise left shift operation on a
  c = a << 4;
  printf("Bitwise left shift (a << 4): %x\n", c);

  // Perform bitwise right shift operation on a
  c = a >> 4;
  printf("Bitwise right shift (a >> 4): %x\n", c);

  // Perform bitwise rotate left operation on a
  c = (a << 4) | (a >> (32 - 4));
  printf("Bitwise rotate left (<< 4 | >> 28): %x\n", c);

  // Perform bitwise rotate right operation on a
  c = (a >> 4) | (a << (32 - 4));
  printf("Bitwise rotate right (>> 4 | << 28): %x\n", c);

  // Check if a is a power of 2
  if (a & (a - 1) == 0) printf("%x is a power of 2\n", a);
  else printf("%x is not a power of 2\n", a);

  // Count the number of set bits in a
  int count = 0;
  while (a) {
    count += a & 1;
    a >>= 1;
  }
  printf("Number of set bits in %x: %d\n", a, count);

  // Swap two numbers using bitwise operations
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  printf("Swapped values: a = %x, b = %x\n", a, b);

  // Reverse the bits of a number
  c = 0;
  for (int i = 0; i < 32; i++) {
    c |= (a & (1 << i)) << (31 - i);
  }
  printf("Reversed bits: %x\n", c);

  return 0;
}