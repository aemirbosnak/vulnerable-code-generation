//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  // Declare variables
  int subnetMask, broadcastAddress, networkAddress, hostAddress, subnetCalc;
  char subnetMaskStr[32], broadcastAddressStr[32], networkAddressStr[32], hostAddressStr[32];

  // Get subnet mask from the user
  printf("Enter the subnet mask (e.g. 255.255.255.0): ");
  scanf("%s", subnetMaskStr);

  // Convert subnet mask to an integer
  subnetMask = atoi(subnetMaskStr);

  // Calculate the broadcast address
  broadcastAddress = subnetMask & ~0;
  broadcastAddressStr[0] = (broadcastAddress & 0xFF000000) >> 24;
  broadcastAddressStr[1] = (broadcastAddress & 0x0F000000) >> 16;
  broadcastAddressStr[2] = (broadcastAddress & 0x00F00000) >> 8;
  broadcastAddressStr[3] = (broadcastAddress & 0x000F0000) >> 0;
  broadcastAddressStr[4] = (broadcastAddress & 0x0000F000) >> 0;
  broadcastAddressStr[5] = (broadcastAddress & 0x00000F00) >> 0;
  broadcastAddressStr[6] = (broadcastAddress & 0x000000F0) >> 0;
  broadcastAddressStr[7] = '\0';

  // Calculate the network address
  networkAddress = (subnetMask & ~0) & (subnetMask & 0xFFF00000) >> 24;
  networkAddressStr[0] = (networkAddress & 0xFF000000) >> 24;
  networkAddressStr[1] = (networkAddress & 0x0F000000) >> 16;
  networkAddressStr[2] = (networkAddress & 0x00F00000) >> 8;
  networkAddressStr[3] = (networkAddress & 0x000F0000) >> 0;
  networkAddressStr[4] = '\0';

  // Calculate the host address
  hostAddress = (subnetMask & ~0) & ~(subnetMask & 0xFFF00000) & 0x0FFFFFFF;
  hostAddressStr[0] = (hostAddress & 0xFF000000) >> 24;
  hostAddressStr[1] = (hostAddress & 0x0F000000) >> 16;
  hostAddressStr[2] = (hostAddress & 0x00F00000) >> 8;
  hostAddressStr[3] = (hostAddress & 0x000F0000) >> 0;
  hostAddressStr[4] = '\0';

  // Print the results
  printf("Subnet Mask: %s\n", subnetMaskStr);
  printf("Broadcast Address: %s\n", broadcastAddressStr);
  printf("Network Address: %s\n", networkAddressStr);
  printf("Host Address: %s\n", hostAddressStr);

  return 0;
}