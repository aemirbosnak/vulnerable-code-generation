//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This is a subnet calculator program written in C language.
 * It's designed to help network administrators with their IP addressing plans.
 * The program takes an IP address and a subnet mask as input, and calculates the subnet ID, broadcast address,
 * host range and the number of hosts in the subnet.
 * Let's get started!
 */

int main() {
  char ip_addr[20]; // an array to store the IP address
  char subnet_mask[20]; // an array to store the subnet mask
  int octet[4]; // an array to store the octets of the IP address
  int subnet_octet[4]; // an array to store the octets of the subnet mask
  int mask_bits; // number of bits in the subnet mask
  int subnet_bits; // number of bits used for the subnet ID
  int host_bits; // number of bits used for the host ID
  int subnet_id[4]; // an array to store the subnet ID
  int broadcast[4]; // an array to store the broadcast address
  int host_range[2]; // an array to store the host range

  printf("Welcome to the Subnet Calculator program!\n");

  // get the IP address from the user
  printf("Please enter the IP address: ");
  scanf("%s", ip_addr);

  // get the subnet mask from the user
  printf("Please enter the subnet mask: ");
  scanf("%s", subnet_mask);

  // parse the IP address into octets
  sscanf(ip_addr, "%d.%d.%d.%d", &octet[0], &octet[1], &octet[2], &octet[3]);

  // parse the subnet mask into octets
  sscanf(subnet_mask, "%d.%d.%d.%d", &subnet_octet[0], &subnet_octet[1], &subnet_octet[2], &subnet_octet[3]);

  // calculate the number of bits in the subnet mask
  for (int i = 0; i < 4; i++) {
    switch(subnet_octet[i]) {
      case 0:
        mask_bits += 0;
        break;
      case 128:
        mask_bits += 1;
        break;
      case 192:
        mask_bits += 2;
        break;
      case 224:
        mask_bits += 3;
        break;
      case 240:
        mask_bits += 4;
        break;
      case 248:
        mask_bits += 5;
        break;
      case 252:
        mask_bits += 6;
        break;
      case 254:
        mask_bits += 7;
        break;
      case 255:
        mask_bits += 8;
        break;
    }
  }

  // calculate the number of bits used for the subnet ID and the host ID
  subnet_bits = mask_bits;
  host_bits = 32 - mask_bits;

  // calculate the subnet ID
  for (int i = 0; i < 4; i++) {
    subnet_id[i] = octet[i] & subnet_octet[i];
  }

  // calculate the broadcast address
  for (int i = 0; i < 4; i++) {
    broadcast[i] = subnet_id[i] | (~subnet_octet[i] & 255);
  }

  // calculate the host range
  host_range[0] = (subnet_id[0] << 24) + (subnet_id[1] << 16) + (subnet_id[2] << 8) + subnet_id[3] + 1;
  host_range[1] = (broadcast[0] << 24) + (broadcast[1] << 16) + (broadcast[2] << 8) + broadcast[3] - 1;

  // print out the results
  printf("\nSubnet ID: %d.%d.%d.%d\n", subnet_id[0], subnet_id[1], subnet_id[2], subnet_id[3]);
  printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
  printf("Host Range: %d.%d.%d.%d - %d.%d.%d.%d\n", (host_range[0] >> 24) & 0xff, (host_range[0] >> 16) & 0xff, (host_range[0] >> 8) & 0xff, host_range[0] & 0xff, (host_range[1] >> 24) & 0xff, (host_range[1] >> 16) & 0xff, (host_range[1] >> 8) & 0xff, host_range[1] & 0xff);
  printf("Number of Hosts: %d\n", (1 << host_bits) - 2);

  return 0;
}