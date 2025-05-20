//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void Fractalize(uint64_t x, uint64_t y, uint64_t z, uint64_t n) {
  if(n == 0) return;
  uint64_t part1 = x & 0xAAAAAAAA00000000;
  uint64_t part2 = x & 0x5555555500000000;
  part1 >>= 1;
  part2 <<= 1;
  x = part1 | part2;
  
  part1 = y & 0xCCCCCCCC00000000;
  part2 = y & 0x3333333300000000;
  part1 >>= 2;
  part2 <<= 2;
  y = part1 | part2;
  
  part1 = z & 0xF0F0F0F000000000;
  part2 = z & 0x0F0F0F0F00000000;
  part1 >>= 4;
  part2 <<= 4;
  z = part1 | part2;
  
  Fractalize(x, y, z, n - 1);
}

void UnFractalize(uint64_t x, uint64_t y, uint64_t z, uint64_t n) {
  if(n == 0) return;
  uint64_t part1 = x & 0xAAAAAAAA00000000;
  uint64_t part2 = x & 0x5555555500000000;
  part1 <<= 1;
  part2 >>= 1;
  x = part1 | part2;
  
  part1 = y & 0xCCCCCCCC00000000;
  part2 = y & 0x3333333300000000;
  part1 <<= 2;
  part2 >>= 2;
  y = part1 | part2;
  
  part1 = z & 0xF0F0F0F00000000;
  part2 = z & 0x0F0F0F0F00000000;
  part1 <<= 4;
  part2 >>= 4;
  z = part1 | part2;
  
  UnFractalize(x, y, z, n - 1);
}

int main() {
  uint64_t x, y, z, n;
  printf("Enter three positive integers separated by spaces: ");
  scanf("%llu %llu %llu", &x, &y, &z);
  printf("Enter the number of fractalization levels: ");
  scanf("%llu", &n);
  Fractalize(x, y, z, n);
  printf("Fractalized: %llu %llu %llu\n", x, y, z);
  UnFractalize(x, y, z, n);
  printf("Unfractalized: %llu %llu %llu\n", x, y, z);
  return 0;
}