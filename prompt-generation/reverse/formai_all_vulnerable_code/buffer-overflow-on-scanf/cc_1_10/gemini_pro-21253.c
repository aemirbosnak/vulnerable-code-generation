//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a valid IP address
int isValidIP(char *ip) {
  int octets = 0;
  int i;
  char *pch;

  pch = strtok(ip, ".");
  while (pch != NULL) {
    octets++;
    pch = strtok(NULL, ".");
  }

  if (octets != 4) {
    return 0;
  }

  pch = strtok(ip, ".");
  while (pch != NULL) {
    i = atoi(pch);
    if (i < 0 || i > 255) {
      return 0;
    }
    pch = strtok(NULL, ".");
  }

  return 1;
}

// Function to calculate the subnet mask
char *calculateSubnetMask(char *ip, int prefix) {
  int octets[4];
  int i;
  char *mask;

  mask = malloc(16);
  memset(mask, 0, 16);

  sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);

  for (i = 0; i < prefix / 8; i++) {
    mask[i] = 255;
  }

  if (prefix % 8 != 0) {
    mask[i] = (255 << (8 - (prefix % 8))) & 0xFF;
  }

  snprintf(mask, 16, "%d.%d.%d.%d", mask[0], mask[1], mask[2], mask[3]);

  return mask;
}

// Function to print the subnet details
void printSubnetDetails(char *ip, char *mask, int prefix) {
  int i;
  int subnet[4];
  int broadcast[4];

  printf("IP Address: %s\n", ip);
  printf("Subnet Mask: %s\n", mask);
  printf("Prefix: %d\n", prefix);

  sscanf(ip, "%d.%d.%d.%d", &subnet[0], &subnet[1], &subnet[2], &subnet[3]);
  sscanf(mask, "%d.%d.%d.%d", &subnet[0], &subnet[1], &subnet[2], &subnet[3]);

  for (i = 0; i < 4; i++) {
    broadcast[i] = subnet[i] | (~mask[i]);
  }

  printf("Subnet Address: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);
  printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
}

int main() {
  char ip[16];
  int prefix;
  char *mask;

  printf("Enter the IP address: ");
  scanf("%s", ip);

  if (!isValidIP(ip)) {
    printf("Invalid IP address!\n");
    return 1;
  }

  printf("Enter the prefix length: ");
  scanf("%d", &prefix);

  mask = calculateSubnetMask(ip, prefix);

  printSubnetDetails(ip, mask, prefix);

  return 0;
}