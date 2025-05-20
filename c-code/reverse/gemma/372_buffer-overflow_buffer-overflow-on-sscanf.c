#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char ip_address[256];
  char subnet_mask[256];
  int mask_bits;

  printf("Enter IP address: ");
  scanf("%s", ip_address);

  printf("Enter subnet mask: ");
  scanf("%s", subnet_mask);

  sscanf(subnet_mask, "/%d", &mask_bits);

  // Buffer overflow vulnerability - no bounds checking on mask_bits
  char subnet_mask_calc[mask_bits + 1];
  sprintf(subnet_mask_calc, "255.255.255.255/%d", mask_bits);

  printf("Subnet mask calculated: %s\n", subnet_mask_calc);

  return 0;
}
