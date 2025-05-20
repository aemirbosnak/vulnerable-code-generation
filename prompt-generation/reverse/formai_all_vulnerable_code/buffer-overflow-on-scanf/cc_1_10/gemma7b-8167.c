//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SUBNETS 256

int main() {
  int numSubnets, subnetMask, broadcastAddress, usableHosts;
  char subnetMaskStr[32];

  printf("Enter the number of subnets: ");
  scanf("%d", &numSubnets);

  printf("Enter the subnet mask (in binary): ");
  scanf("%s", subnetMaskStr);

  subnetMask = parseSubnetMask(subnetMaskStr);

  broadcastAddress = calculateBroadcastAddress(subnetMask);

  usableHosts = calculateUsableHosts(subnetMask);

  printf("Subnet Mask: %s\n", subnetMaskStr);
  printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddress);
  printf("Usable Hosts: %d\n", usableHosts);

  return 0;
}

int parseSubnetMask(char *subnetMaskStr) {
  int subnetMask = 0;
  int i = 0;

  while (subnetMaskStr[i] != '\0') {
    int bit = atoi(&subnetMaskStr[i]) & 1;
    subnetMask |= bit << (3 - i) * 8;
    i++;
  }

  return subnetMask;
}

int calculateBroadcastAddress(int subnetMask) {
  int broadcastAddress = (subnetMask & ~0xFF) | 0xFF;
  return broadcastAddress;
}

int calculateUsableHosts(int subnetMask) {
  int usableHosts = (subnetMask & 0xFF) - 2;
  return usableHosts;
}