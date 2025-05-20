//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  char input[16];
  int CIDR_mask, i, j;
  int Oct1=0, Oct2=0, Oct3=0, Oct4=0;
  int SubnetMask[32];
  int subnetOctet[4];
  int subnet[4][8];
  
  printf("Enter IP Address in dot decimal format: ");
  scanf("%s", input);
  printf("Enter CIDR Subnet Mask: ");
  scanf("%d", &CIDR_mask);


  // Split the IP Address
  sscanf(input, "%d.%d.%d.%d", &Oct1, &Oct2, &Oct3, &Oct4);

  // Store Subnet Mask in Binary Format
  for(i=0; i<CIDR_mask; i++)
    SubnetMask[i] = 1;
  for(; i<32; i++)
    SubnetMask[i] = 0;

  // Convert Binary to Decimal Format
  for(i=0; i<4; i++){
    for(j=0; j<8; j++){
      subnet[i][j] = SubnetMask[(i*8)+j];
    }
  }
  for(i=0; i<4; i++){
    for(j=0; j<8; j++){
      subnetOctet[i] += subnet[i][j]*pow(2, 7-j);
    }
  }

  // Calculate Subnet ID and Broadcast Address
  int subnetID[4], broadcastID[4];
  subnetID[0] = (Oct1 & subnetOctet[0]);
  subnetID[1] = (Oct2 & subnetOctet[1]);
  subnetID[2] = (Oct3 & subnetOctet[2]);
  subnetID[3] = (Oct4 & subnetOctet[3]);

  broadcastID[0] = subnetID[0] | (~subnetOctet[0] & 0xFF);
  broadcastID[1] = subnetID[1] | (~subnetOctet[1] & 0xFF);
  broadcastID[2] = subnetID[2] | (~subnetOctet[2] & 0xFF);
  broadcastID[3] = subnetID[3] | (~subnetOctet[3] & 0xFF);

  // Print Subnet ID and Broadcast Address
  printf("\nSubnet ID: %d.%d.%d.%d\n", subnetID[0], subnetID[1], subnetID[2], subnetID[3]);
  printf("Broadcast Address: %d.%d.%d.%d\n", broadcastID[0], broadcastID[1], broadcastID[2], broadcastID[3]);

  return 0;
}