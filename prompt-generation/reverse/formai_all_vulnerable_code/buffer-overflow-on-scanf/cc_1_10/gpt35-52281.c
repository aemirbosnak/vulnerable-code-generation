//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
  int a, b, c, d, e, mask;
  printf("Enter IP Address: ");
  scanf("%d.%d.%d.%d", &a, &b, &c, &d);
  printf("Enter Subnet Mask: ");
  scanf("%d.%d.%d.%d", &e, &e, &e, &mask);

  int maskBits[32];
  for(int i=31; i>=0; i--) {
    if(mask>0) {
      maskBits[i] = 1;
      mask--;
    }
    else {
      maskBits[i] = 0;
    }
  }

  printf("\n- - - - - - - - - - - - - - - -\n");
  printf("IP Address: %d.%d.%d.%d\n", a, b, c, d);
  printf("Subnet Mask: %d.%d.%d.%d\n", e, e, e, mask);
  printf("Mask Bits: ");
  for(int i=0; i<32; i++) {
    printf("%d", maskBits[i]);
    if((i+1)%8==0) {
      printf(".");
    }
  }

  int subnetMask[4];
  subnetMask[0] = subnetMask[1] = subnetMask[2] = subnetMask[3] = 0;
  for(int i=31, j=0; i>=0 && j<4; i-=8, j++) {
    for(int k=i; k>i-8; k--) {
      subnetMask[j] += maskBits[k]*pow(2, 7-(i-k));
    }
  }

  printf("\nSubnet Mask (Decimal): %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);

  int subnetBits = 0;
  for(int i=0; i<32; i++) {
    if(maskBits[i]==1) {
      subnetBits++;
    }
  }

  int hosts = pow(2, 32-subnetBits)-2;
  printf("Number of Hosts per Subnet: %d\n", hosts);

  int maxSubnets = pow(2, subnetBits);
  printf("Maximum Number of Subnets: %d\n", maxSubnets);

  int hostBits = 32-subnetBits;
  int networkAddr[4];
  networkAddr[0] = a & subnetMask[0];
  networkAddr[1] = b & subnetMask[1];
  networkAddr[2] = c & subnetMask[2];
  networkAddr[3] = d & subnetMask[3];

  printf("Network Address: %d.%d.%d.%d\n", networkAddr[0], networkAddr[1], networkAddr[2], networkAddr[3]);

  int broadcastAddr[4];
  broadcastAddr[0] = networkAddr[0] | ~subnetMask[0];
  broadcastAddr[1] = networkAddr[1] | ~subnetMask[1];
  broadcastAddr[2] = networkAddr[2] | ~subnetMask[2];
  broadcastAddr[3] = networkAddr[3] | ~subnetMask[3];

  printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddr[0], broadcastAddr[1], broadcastAddr[2], broadcastAddr[3]);

  return 0;
}