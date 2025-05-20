#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char ip_address[16];
  scanf("%s", ip_address);

  // Calculate subnet details
  int subnet_mask_length = 32 - ((ip_address[3] & 0xf0) >> 8) - 1;
  int subnet_mask = ~(~0 << (32 - subnet_mask_length));
  int broadcast_address = ip_address[0] << 24 | ip_address[1] << 16 | ip_address[2] << 8 | ip_address[3] & subnet_mask;

  // Print subnet details
  printf("Subnet mask: %x\n", subnet_mask);
  printf("Broadcast address: %x\n", broadcast_address);

  return 0;
}
