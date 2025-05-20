//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 255

void subnet_calculator()
{

  // Variables for subnet calculator
  int network_address, subnet_mask, host_address, prefix_length, broadcast_address, usable_hosts;

  // Get the network address, subnet mask, and prefix length from the user
  printf("Enter the network address (in decimal): ");
  scanf("%d", &network_address);

  printf("Enter the subnet mask (in decimal): ");
  scanf("%d", &subnet_mask);

  printf("Enter the prefix length: ");
  scanf("%d", &prefix_length);

  // Calculate the broadcast address and usable hosts
  broadcast_address = network_address | ~subnet_mask;
  usable_hosts = (pow(2, 32 - prefix_length) - 2) / 2;

  // Print the results
  printf("\nSubnet Mask: ");
  for (int i = 0; i < prefix_length; i++)
  {
    printf("1");
  }
  for (int i = prefix_length; i < 32; i++)
  {
    printf("0");
  }
  printf("/%d", prefix_length);

  printf("\nBroadcast Address: ");
  printf("%d", broadcast_address);

  printf("\nUsable Hosts: ");
  printf("%d", usable_hosts);

  printf("\n");
}

int main()
{
  subnet_calculator();

  return 0;
}