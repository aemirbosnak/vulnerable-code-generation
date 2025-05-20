//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNET_MASK 32
#define MAX_IP_ADDRESS 16
#define MAX_BINARY_IP_ADDRESS 33

int getBitCount(int n) {
  int count = 0;
  while(n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

int isValidIpAddress(char* ipAddress) {
  int i = 0, num = 0, dots = 0;
  if(ipAddress == NULL)
    return 0;

  while(ipAddress[i] != '\0') {
    if(ipAddress[i] == '.') {
      dots++;
      if(num < 0 || num > 255 || dots > 3)
        return 0;
      num = 0;
    }
    else if(ipAddress[i] >= '0' && ipAddress[i] <= '9') {
      num = (num * 10) + (int)(ipAddress[i] - '0');
    } else {
      return 0;
    }
    i++;
  }

  if(num < 0 || num > 255 || dots != 3)
    return 0;

  return 1;
}

int isValidSubnetMask(char* subnetMask) {
  int i = 0, num = 0, count = 0;
  if(subnetMask == NULL)
    return 0;

  while(subnetMask[i] != '\0') {
    if(subnetMask[i] == '.') {
      if(num < 0 || num > 255)
        return 0;
      count += getBitCount(num);
      num = 0;
    }
    else if(subnetMask[i] >= '0' && subnetMask[i] <= '9') {
      num = (num * 10) + (int)(subnetMask[i] - '0');
    } else {
      return 0;
    }
    i++;
  }

  if(num < 0 || num > 255)
    return 0;

  count += getBitCount(num);

  return (count == MAX_SUBNET_MASK);
}

void convertIpAddressToBinary(char* ipAddress, char* binaryIpAddress) {
  int i, j, num, index = 0;
  char octet[4], binaryOctet[9];

  for(i = 0; ipAddress[i] != '\0'; i++) {
    if(ipAddress[i] == '.') {
      octet[index] = '\0';
      sscanf(octet, "%d", &num);
      index = 0;
      memset(binaryOctet, '0', 8);
      binaryOctet[8] = '\0';
      j = 7;
      while(num) {
        binaryOctet[j--] = (num & 1) + '0';
        num >>= 1;
      }
      strcat(binaryIpAddress, binaryOctet);
    }
    else {
      octet[index++] = ipAddress[i];
    }
  }

  octet[index] = '\0';
  sscanf(octet, "%d", &num);
  memset(binaryOctet, '0', 8);
  binaryOctet[8] = '\0';
  j = 7;
  while(num) {
    binaryOctet[j--] = (num & 1) + '0';
    num >>= 1;
  }
  strcat(binaryIpAddress, binaryOctet);
}

int main() {
  char ipAddress[MAX_IP_ADDRESS], subnetMask[MAX_IP_ADDRESS], binaryIpAddress[MAX_BINARY_IP_ADDRESS];
  int i, j, num, subnetBits;
  char networkAddress[MAX_IP_ADDRESS], binaryNetworkAddress[MAX_BINARY_IP_ADDRESS];

  printf("Enter the IP address: ");
  scanf("%s", ipAddress);

  if(!isValidIpAddress(ipAddress)) {
    printf("Invalid IP address!\n");
    return 1;
  }

  printf("Enter the subnet mask: ");
  scanf("%s", subnetMask);

  if(!isValidSubnetMask(subnetMask)) {
    printf("Invalid subnet mask!\n");
    return 1;
  }

  convertIpAddressToBinary(ipAddress, binaryIpAddress);
  memset(networkAddress, 0, MAX_IP_ADDRESS);
  memset(binaryNetworkAddress, 0, MAX_BINARY_IP_ADDRESS);

  subnetBits = getBitCount(atoi(strtok(subnetMask, ".")));

  for(i = 0; i < subnetBits; i++)
    binaryNetworkAddress[i] = binaryIpAddress[i];

  for(i = subnetBits; i < MAX_SUBNET_MASK; i++)
    binaryNetworkAddress[i] = '0';

  j = 7;
  num = 0;
  for(i = 0; i < MAX_BINARY_IP_ADDRESS; i++) {
    num = (num << 1) + (binaryNetworkAddress[i] - '0');
    if(i % 8 == 7) {
      sprintf(networkAddress, "%s%d", networkAddress, num);
      if(i < MAX_BINARY_IP_ADDRESS - 1)
        sprintf(networkAddress, "%s.", networkAddress);
      num = 0;
    }
  }

  printf("IP address:            %s\n", ipAddress);
  printf("Subnet mask:           %s\n", subnetMask);
  printf("Network address:       %s\n", networkAddress);

  return 0;
}