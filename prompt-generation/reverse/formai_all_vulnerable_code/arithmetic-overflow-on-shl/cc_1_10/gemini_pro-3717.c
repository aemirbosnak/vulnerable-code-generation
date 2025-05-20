//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Declare variables
  int a = 10; // Decimal 10
  int b = 0b1010; // Binary 1010
  int c = 0xABCDEF; // Hexadecimal ABCDEF

  // Perform bitwise operations
  printf("AND: %d\n", a & b); // Binary 1010 = Decimal 10
  printf("OR: %d\n", a | b); // Binary 1011 = Decimal 11
  printf("XOR: %d\n", a ^ b); // Binary 0001 = Decimal 1
  printf("NOT: %d\n", ~a); // Binary 1111111111111101 = Decimal -11

  // Shift operations
  printf("Left shift: %d\n", a << 2); // Binary 101000 = Decimal 40
  printf("Right shift: %d\n", a >> 2); // Binary 10 = Decimal 2

  // Bitwise rotation
  printf("Left rotation: %d\n", ((a << 2) | (a >> 30))); // Binary 10000101 = Decimal 133
  printf("Right rotation: %d\n", ((a >> 2) | (a << 30))); // Binary 00000010 = Decimal 2

  // Bitwise flags
  int flag = 1 << 3; // Set the third bit to 1
  printf("Bitwise flag: %d\n", flag); // Binary 00001000 = Decimal 8

  // Bitwise isolation
  int mask = 0b1111; // Create a mask for the last four bits
  printf("Bitwise isolation: %d\n", a & mask); // Binary 1010 = Decimal 10

  // Bitwise counting
  int count = 0;
  while (a) {
    count += a & 1;
    a >>= 1;
  }
  printf("Bitwise counting: %d\n", count); // Number of set bits in a

  // Bitwise manipulation in arrays
  int array[] = {1, 2, 3, 4, 5};
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum |= array[i]; // Set bits in sum corresponding to set bits in array elements
  }
  printf("Bitwise manipulation in arrays: %d\n", sum); // Binary 1111 = Decimal 15

  return 0;
}