//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SUBNETS 256

typedef struct subnet_t {
  int subnet_mask;
  int broadcast_address;
  int network_address;
  int host_bits;
  int num_hosts;
} subnet_t;

subnet_t subnet_calc(int cidr) {
  subnet_t subnet;

  subnet.subnet_mask = 0;
  subnet.broadcast_address = 0;
  subnet.network_address = 0;
  subnet.host_bits = 0;
  subnet.num_hosts = 0;

  switch (cidr) {
    case 0:
      subnet.subnet_mask = 0xFF;
      subnet.broadcast_address = 0xFF;
      subnet.network_address = 0x0;
      subnet.host_bits = 8;
      subnet.num_hosts = 256;
      break;
    case 1:
      subnet.subnet_mask = 0x7F;
      subnet.broadcast_address = 0x7F;
      subnet.network_address = 0x0;
      subnet.host_bits = 16;
      subnet.num_hosts = 65536;
      break;
    case 2:
      subnet.subnet_mask = 0x3F;
      subnet.broadcast_address = 0x3F;
      subnet.network_address = 0x0;
      subnet.host_bits = 24;
      subnet.num_hosts = 4294967296;
      break;
    default:
      printf("Error: Invalid CIDR value.\n");
      exit(1);
  }

  return subnet;
}

int main() {
  int cidr;

  printf("Enter CIDR: ");
  scanf("%d", &cidr);

  subnet_t subnet = subnet_calc(cidr);

  printf("Subnet Mask: %x\n", subnet.subnet_mask);
  printf("Broadcast Address: %x\n", subnet.broadcast_address);
  printf("Network Address: %x\n", subnet.network_address);
  printf("Host Bits: %d\n", subnet.host_bits);
  printf("Number of Hosts: %d\n", subnet.num_hosts);

  return 0;
}