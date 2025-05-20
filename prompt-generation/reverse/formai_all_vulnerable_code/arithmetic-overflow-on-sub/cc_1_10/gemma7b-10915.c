//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int subnet_mask_bits = 0;
  int host_bits = 0;
  int network_address = 0;
  int subnet_address = 0;
  int broadcast_address = 0;

  // Get the subnet mask bits from the user
  printf("Enter the number of subnet mask bits: ");
  scanf("%d", &subnet_mask_bits);

  // Calculate the number of host bits
  host_bits = 32 - subnet_mask_bits;

  // Calculate the network address
  network_address = (subnet_mask_bits > 0) ? ((subnet_mask_bits & 3) << 3) : 0;

  // Calculate the subnet address
  subnet_address = (network_address) ? network_address : 0;

  // Calculate the broadcast address
  broadcast_address = (host_bits > 0) ? ((subnet_mask_bits & 3) << 3) + 2 : 0;

  // Print the subnet mask
  printf("Subnet Mask: ");
  for (int i = 0; i < subnet_mask_bits; i++)
  {
    printf("1");
  }
  printf("\n");

  // Print the network address
  printf("Network Address: ");
  printf("%d.%d.%d.%d", (network_address >> 24) & 0xff, (network_address >> 16) & 0xff, (network_address >> 8) & 0xff, network_address & 0xff);
  printf("\n");

  // Print the subnet address
  printf("Subnet Address: ");
  printf("%d.%d.%d.%d", (subnet_address >> 24) & 0xff, (subnet_address >> 16) & 0xff, (subnet_address >> 8) & 0xff, subnet_address & 0xff);
  printf("\n");

  // Print the broadcast address
  printf("Broadcast Address: ");
  printf("%d.%d.%d.%d", ((broadcast_address >> 24) & 0xff) + 1, (broadcast_address >> 16) & 0xff, (broadcast_address >> 8) & 0xff, broadcast_address & 0xff);
  printf("\n");

  return 0;
}