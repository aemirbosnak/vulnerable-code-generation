//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main() {
  int subnet_mask_length, host_bits, network_bits;
  unsigned int subnet_mask, network_address, host_address;
  char subnet_mask_string[32];

  printf("Enter subnet mask length (e.g. 24, 16): ");
  scanf("%d", &subnet_mask_length);

  subnet_mask = 0;
  network_bits = 0;
  host_bits = 0;

  switch (subnet_mask_length) {
    case 32:
      subnet_mask = 0xFFFFFFFF;
      network_bits = 32;
      host_bits = 0;
      break;
    case 24:
      subnet_mask = 0xFF0000;
      network_bits = 24;
      host_bits = 8;
      break;
    case 16:
      subnet_mask = 0xFF00;
      network_bits = 16;
      host_bits = 16;
      break;
    case 8:
      subnet_mask = 0xFF000000;
      network_bits = 8;
      host_bits = 24;
      break;
    default:
      printf("Invalid subnet mask length.\n");
      exit(1);
  }

  subnet_mask_string[0] = '\0';
  for (int i = 0; i < network_bits; i++) {
    subnet_mask_string[i] = '1';
  }
  subnet_mask_string[network_bits] = '/';

  network_address = (subnet_mask & 0xFF) << 24;
  host_address = (subnet_mask & 0xFFFFFF) >> host_bits;

  printf("Subnet mask: %s\n", subnet_mask_string);
  printf("Network address: %u\n", network_address);
  printf("Host address: %u\n", host_address);

  return 0;
}