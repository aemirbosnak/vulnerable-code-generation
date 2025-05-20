//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  // Declare variables
  char subnetMask[12];
  int subnetMaskLen;
  char networkAddress[16];
  int networkAddressLen;
  char broadcastAddress[16];
  int broadcastAddressLen;

  // Get subnet mask and network address from the user
  printf("Enter the subnet mask (e.g. 255.255.255.0): ");
  scanf("%s", subnetMask);

  // Calculate the subnet mask length
  subnetMaskLen = calculateSubnetMaskLen(subnetMask);

  // Calculate the network address
  networkAddressLen = calculateNetworkAddressLen(subnetMaskLen);
  networkAddress[0] = (subnetMaskLen - 1) / 8;
  networkAddress[1] = (subnetMaskLen - 1) % 8;
  networkAddress[2] = 0;

  // Calculate the broadcast address
  broadcastAddressLen = calculateBroadcastAddressLen(subnetMaskLen);
  broadcastAddress[0] = networkAddress[0] + 1;
  broadcastAddress[1] = networkAddress[1] + 1;
  broadcastAddress[2] = broadcastAddressLen - 1;

  // Print the subnet mask, network address, and broadcast address
  printf("Subnet Mask: %s\n", subnetMask);
  printf("Network Address: %s\n", networkAddress);
  printf("Broadcast Address: %s\n", broadcastAddress);

  return 0;
}

int calculateSubnetMaskLen(char *subnetMask) {
  int len = 0;
  while (subnetMask[len] != '\0') {
    len++;
  }
  return len;
}

int calculateNetworkAddressLen(int subnetMaskLen) {
  return (subnetMaskLen - 1) / 8;
}

int calculateBroadcastAddressLen(int subnetMaskLen) {
  return (subnetMaskLen - 1) / 8 + 1;
}