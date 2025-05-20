//LLAMA2-13B DATASET v1.0 Category: Bitwise operations ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIT_MAGIC 0xDEADBEEF

int main() {
  int magic_number = BIT_MAGIC;
  int x = 0x12345678;
  int y = 0x87654321;

  // Bitwise AND
  int result = x & y;
  printf("Bitwise AND: %x\n", result);

  // Bitwise OR
  result = x | y;
  printf("Bitwise OR: %x\n", result);

  // Bitwise XOR
  result = x ^ y;
  printf("Bitwise XOR: %x\n", result);

  // Bitwise LEFT SHIFT
  result = x << y;
  printf("Bitwise LEFT SHIFT: %x\n", result);

  // Bitwise RIGHT SHIFT
  result = x >> y;
  printf("Bitwise RIGHT SHIFT: %x\n", result);

  // Bitwise ROTATE LEFT
  result = (x << y) | (x >> (32 - y));
  printf("Bitwise ROTATE LEFT: %x\n", result);

  // Bitwise ROTATE RIGHT
  result = (x >> y) | (x << (32 - y));
  printf("Bitwise ROTATE RIGHT: %x\n", result);

  // Bitwise SWAP
  int temp = x;
  x = y;
  y = temp;
  printf("Bitwise SWAP: %x %x\n", x, y);

  // Bitwise REVERSE
  int reversed = 0;
  for (int i = 0; i < 32; i++) {
    if ((magic_number >> i) & 1) {
      reversed |= (1 << i);
    }
  }
  printf("Bitwise REVERSE: %x\n", reversed);

  return 0;
}