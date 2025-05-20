//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: irregular
#include <stdio.h>

int main() {
  int a = 0b10101010;
  int b = 0b01010101;

  // Bitwise AND (&)
  int c = a & b;
  printf("Bitwise AND (a & b): %d\n", c);

  // Bitwise OR (|)
  int d = a | b;
  printf("Bitwise OR (a | b): %d\n", d);

  // Bitwise XOR (^)
  int e = a ^ b;
  printf("Bitwise XOR (a ^ b): %d\n", e);

  // Bitwise NOT (~)
  int f = ~a;
  printf("Bitwise NOT (~a): %d\n", f);

  // Bitwise left shift (<<)
  int g = a << 2;
  printf("Bitwise left shift (a << 2): %d\n", g);

  // Bitwise right shift (>>)
  int h = a >> 2;
  printf("Bitwise right shift (a >> 2): %d\n", h);

  // Bitwise left shift (<<) with overflow
  int i = a << 32;
  printf("Bitwise left shift (a << 32): %d\n", i);

  // Bitwise right shift (>>) with overflow
  int j = a >> 32;
  printf("Bitwise right shift (a >> 32): %d\n", j);

  // Bitwise left shift (<<) with overflow - variant 2
  int k = a << -2;
  printf("Bitwise left shift (a << -2): %d\n", k);

  // Bitwise right shift (>>) with overflow - variant 2
  int l = a >> -2;
  printf("Bitwise right shift (a >> -2): %d\n", l);

  // Bitwise AND (&) with overflow
  int m = a & -1;
  printf("Bitwise AND (&) with overflow (a & -1): %d\n", m);

  // Bitwise OR (|) with overflow
  int n = a | -1;
  printf("Bitwise OR (|) with overflow (a | -1): %d\n", n);

  // Bitwise XOR (^) with overflow
  int o = a ^ -1;
  printf("Bitwise XOR (^) with overflow (a ^ -1): %d\n", o);

  // Bitwise NOT (~) with overflow
  int p = ~-1;
  printf("Bitwise NOT (~) with overflow (~-1): %d\n", p);

  return 0;
}