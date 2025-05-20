//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  
  char ip[20];
  int maskBits;
  int mask[4];
  int subnetMask[4];
  int network[4];
  int broadcast[4];
  int numHosts;

  printf("Welcome to the Subnet Calculator!\n");
  printf("Please enter the IP Address: ");
  scanf("%s", ip);

  printf("Please enter the number of Mask Bits: ");
  scanf("%d", &maskBits);

  // Calculate subnet mask
  int i;
  for (i = 0; i < 4; i++) {
    if (maskBits >= 8) {
      subnetMask[i] = 255;
      maskBits -= 8;
    } else {
      int val = (int)pow(2, 8-maskBits);
      subnetMask[i] = 256 - val;
      maskBits = 0;
    }
  }

  // Store mask and calculate network and broadcast addresses
  char *token;
  token = strtok(ip, ".");
  i = 0;
  while (token != NULL) {
    int octet = atoi(token);
    mask[i] = subnetMask[i];
    network[i] = octet & subnetMask[i];
    broadcast[i] = network[i] | ~subnetMask[i];
    token = strtok(NULL, ".");
    i++;
  }

  // Calculate number of hosts
  numHosts = pow(2, 32-(mask[0]+mask[1]+mask[2]+mask[3]));

  // Print results
  printf("\nIP Address: %s\n", ip);
  printf("Subnet Mask: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
  printf("Network Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
  printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
  printf("Number of Hosts: %d\n", numHosts);

  printf("\nThank you for using the Subnet Calculator!\n");

  return 0;
}