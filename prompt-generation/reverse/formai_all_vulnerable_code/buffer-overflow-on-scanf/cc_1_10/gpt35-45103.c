//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
  char IP[20], SubnetMask[20];
  int IPArray[4], SubnetMaskArray[4], IPAddress[32], SubnetMaskBits, NetworkBits, HostBits, i;

  printf("Enter the IP Address: ");
  scanf("%s", IP);

  //Splitting the IP Address into octets
  char *octet = strtok(IP, ".");
  i = 0;
  while (octet != NULL) {
    IPArray[i] = atoi(octet);
    i++;
    octet = strtok(NULL, ".");
  }

  printf("Enter the Subnet Mask: ");
  scanf("%s", SubnetMask);

  //Splitting the Subnet Mask into octets
  octet = strtok(SubnetMask, ".");
  i = 0;
  while (octet != NULL) {
    SubnetMaskArray[i] = atoi(octet);
    i++;
    octet = strtok(NULL, ".");
  }

  //Converting Subnet Mask to binary
  for (i = 0; i < 4; i++) {
    int j = 0;
    int temp = SubnetMaskArray[i];
    while(temp > 0) {
      if (temp%2 == 0) {
        SubnetMaskBits = 0;
      } else {
        SubnetMaskBits = 1;
      }
      temp = temp/2;
      IPAddress[(i*8)+j] = SubnetMaskBits;
      j++; 
    }
    while(j < 8) {
      IPAddress[(i*8)+j] = 0;
      j++;
    }
  }

  //Calculating Network and Host bits from the Subnet Mask
  NetworkBits = 0;
  HostBits = 0;
  for (i = 0; i < 32; i++) {
    if (IPAddress[i] == 1) {
      NetworkBits++;
    } else {
      HostBits++;
    }
  }
  
  //Calculating the number of usable hosts in the subnet
  int NumOfHosts = (int)(pow(2, HostBits)) - 2;

  //Printing the results
  printf("\nIP Address: %s\n", IP);
  printf("Subnet Mask: %s\n", SubnetMask);
  printf("Network Bits: %d\n", NetworkBits);
  printf("Host Bits: %d\n", HostBits);
  printf("Number of Usable Hosts: %d\n", NumOfHosts);

  return 0;
}