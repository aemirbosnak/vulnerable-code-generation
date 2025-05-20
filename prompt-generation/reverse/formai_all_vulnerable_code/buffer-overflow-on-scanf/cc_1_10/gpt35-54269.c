//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>

int main() {
  int ipOctet1, ipOctet2, ipOctet3, ipOctet4, prefixLength, subnetMask[4], wildcardMask[4], networkAddress[4], broadcastAddress[4], numberOfHosts;
  
  printf("Welcome to Curious Subnet Calculator!\n\n");

  // Inputting IP Address and Prefix Length
  printf("Please enter the IP Address:\n");
  scanf("%d.%d.%d.%d", &ipOctet1, &ipOctet2, &ipOctet3, &ipOctet4);

  printf("\nPlease enter the Prefix Length (Valid Range: 1-30):\n");
  scanf("%d", &prefixLength);

  // Calculating Subnet Mask
  int i, j, temp, countOnes = 0;
  for (i = 0; i < 4; i++) {
    subnetMask[i] = 0;
    wildcardMask[i] = 0;
    networkAddress[i] = 0;
    broadcastAddress[i] = 0;
    temp = 128;

    for (j = 0; j < 8; j++) {
      if (countOnes < prefixLength) {
        subnetMask[i] += temp;
        countOnes++;
      }
      wildcardMask[i] += (temp - (subnetMask[i] & temp));
      temp /= 2;
    }
  }

  // Calculating Network Address and Broadcast Address
  for (i = 0; i < 4; i++) {
    networkAddress[i] = ipOctet1 & subnetMask[i];
    broadcastAddress[i] = ipOctet1 | wildcardMask[i];
    
    if (i == 0) {
      networkAddress[i] = broadcastAddress[i] = ipOctet1 & subnetMask[i];
    }
    if (i == 1) {
      networkAddress[i] = broadcastAddress[i] = ipOctet2 & subnetMask[i];
    }
    if (i == 2) {
      networkAddress[i] = broadcastAddress[i] = ipOctet3 & subnetMask[i];
    }
    if (i == 3) {
      networkAddress[i] = broadcastAddress[i] = ipOctet4 & subnetMask[i];
    }
  }

  // Calculating Number of Hosts
  numberOfHosts = (1 << (32 - prefixLength)) - 2;

  // Printing Results
  printf("\nSubnet Mask: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
  printf("Wildcard Mask: %d.%d.%d.%d\n", wildcardMask[0], wildcardMask[1], wildcardMask[2], wildcardMask[3]);
  printf("Network Address: %d.%d.%d.%d\n", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);
  printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddress[0], broadcastAddress[1], broadcastAddress[2], broadcastAddress[3]);
  printf("Number of Hosts: %d\n", numberOfHosts);

  printf("\nThank you for using Curious Subnet Calculator!\n");

  return 0;
}