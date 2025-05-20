#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char ip_addr[16] = "";
  char subnet_mask[16] = "";
  int subnet_mask_len = 0;
  int subnet_mask_bits = 0;

  printf("Enter IP address: ");
  scanf("%s", ip_addr);

  printf("Enter subnet mask: ");
  scanf("%s", subnet_mask);

  subnet_mask_len = strlen(subnet_mask);
  if (subnet_mask_len > 15) {
    printf("Error: Subnet mask too long.\n");
    return 1;
  }

  if (sscanf(subnet_mask, "/%d", &subnet_mask_bits) != 1) {
    printf("Error: Invalid subnet mask format.\n");
    return 1;
  }

  printf("Subnet mask bits: %d\n", subnet_mask_bits);

  return 0;
}
