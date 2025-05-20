#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int ip[4];
  scanf("%d.%d.%d.%d", ip);
  int subnet_mask = 255 - (ip[3] & 0b11111111);
  int subnet_prefix_length = 32 - __builtin_popcount(subnet_mask);
  printf("Subnet mask: %d\n", subnet_mask);
  printf("Subnet prefix length: %d\n", subnet_prefix_length);
  return 0;
}
