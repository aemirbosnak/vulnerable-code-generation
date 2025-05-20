//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBNETS 256

int main() {

  int numSubnets = 0;
  int subnetMask, hostMask, networkAddress, subnetNumber;
  char subnetMaskStr[MAX_SUBNETS];
  char hostMaskStr[MAX_SUBNETS];
  char networkAddressStr[MAX_SUBNETS];

  printf("Enter the subnet mask (in binary): ");
  scanf("%s", subnetMaskStr);

  subnetMask = convertSubnetMaskStrToNum(subnetMaskStr);
  hostMask = calculateHostMask(subnetMask);
  networkAddress = calculateNetworkAddress(subnetMask);
  subnetNumber = calculateSubnetNumber(subnetMask);

  printf("Number of subnets: %d\n", subnetNumber);
  printf("Subnet mask: %s\n", subnetMaskStr);
  printf("Host mask: %s\n", hostMaskStr);
  printf("Network address: %s\n", networkAddressStr);

  return 0;
}

int convertSubnetMaskStrToNum(char *str) {
  int num = 0;
  int i = 0;

  for (i = 0; str[i] != '\0'; i++) {
    num = num * 2 + str[i] - '0';
  }

  return num;
}

int calculateHostMask(int subnetMask) {
  int hostMask = 0;

  while (subnetMask > 0) {
    if (subnetMask & 1) {
      hostMask |= 1;
    }

    subnetMask >>= 1;
  }

  return hostMask;
}

int calculateNetworkAddress(int subnetMask) {
  int networkAddress = 0;

  while (subnetMask > 0) {
    if (subnetMask & 1) {
      networkAddress |= 1;
    }

    subnetMask >>= 1;
  }

  return networkAddress;
}

int calculateSubnetNumber(int subnetMask) {
  int subnetNumber = ( subnetMask & 0xffffff) >> 24;

  return subnetNumber;
}