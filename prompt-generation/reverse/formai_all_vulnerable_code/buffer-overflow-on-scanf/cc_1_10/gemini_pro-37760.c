//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: brave
#include <stdio.h>
#include <stdint.h>

typedef uint32_t TT;

// left shift, n is the number of bits
#define LSHIFT(x, n) (x << n)

// right shift, n is the number of bits
#define RSHIFT(x, n) (x >> n)

// bitwise AND
#define AND(x, y) (x & y)

// bitwise OR
#define OR(x, y) (x | y)

// bitwise XOR
#define XOR(x, y) (x ^ y)

// bitwise NOT
#define NOT(x) (~x)

// check if a bit is set
#define CHECKBIT(x, n) ((x >> n) & 1)

int main() {
  TT x, y, result;

  // get inputs from the user
  printf("Enter the first number: ");
  scanf("%u", &x);
  printf("Enter the second number: ");
  scanf("%u", &y);

  // perform bitwise operations
  result = LSHIFT(x, 2);
  printf("Left shift by 2: %u\n", result);
  result = RSHIFT(x, 2);
  printf("Right shift by 2: %u\n", result);
  result = AND(x, y);
  printf("Bitwise AND: %u\n", result);
  result = OR(x, y);
  printf("Bitwise OR: %u\n", result);
  result = XOR(x, y);
  printf("Bitwise XOR: %u\n", result);
  result = NOT(x);
  printf("Bitwise NOT: %u\n", result);

  // check if a bit is set
  printf("Enter the bit position to check (0-31): ");
  int n;
  scanf("%d", &n);
  int bitSet = CHECKBIT(x, n);
  printf("Bit %d is %s\n", n, bitSet ? "set" : "not set");

  return 0;
}