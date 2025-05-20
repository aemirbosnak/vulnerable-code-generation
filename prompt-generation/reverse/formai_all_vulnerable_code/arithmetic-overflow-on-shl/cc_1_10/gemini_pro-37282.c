//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  int a = 5, b = 3;

  // Bitwise AND
  printf("a & b = %d\n", a & b); // Output: 1

  // Bitwise OR
  printf("a | b = %d\n", a | b); // Output: 7

  // Bitwise XOR
  printf("a ^ b = %d\n", a ^ b); // Output: 6

  // Bitwise NOT
  printf("~a = %d\n", ~a); // Output: -6

  // Bitwise shift left
  printf("a << 1 = %d\n", a << 1); // Output: 10

  // Bitwise shift right
  printf("a >> 1 = %d\n", a >> 1); // Output: 2

  // Bitwise rotation left
  printf("a << 1 | a >> (sizeof(int) * 8 - 1) = %d\n", a << 1 | a >> (sizeof(int) * 8 - 1)); // Output: 10

  // Bitwise rotation right
  printf("a << (sizeof(int) * 8 - 1) | a >> 1 = %d\n", a << (sizeof(int) * 8 - 1) | a >> 1); // Output: 2

  // Bitwise mask
  printf("a & ((1 << 2) - 1) = %d\n", a & ((1 << 2) - 1)); // Output: 2

  // Bitwise extract
  printf("(a >> 2) & 1 = %d\n", (a >> 2) & 1); // Output: 0

  // Bitwise count set bits
  int count = 0;
  while (a) {
    count += a & 1;
    a >>= 1;
  }
  printf("The number of set bits in a is %d\n", count); // Output: 2

  // Bitwise isolate lowest set bit
  int lowest_set_bit = a & -a;
  printf("The lowest set bit in a is %d\n", lowest_set_bit); // Output: 1

  return 0;
}