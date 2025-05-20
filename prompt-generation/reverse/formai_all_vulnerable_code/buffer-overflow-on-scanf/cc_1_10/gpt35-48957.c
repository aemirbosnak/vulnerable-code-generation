//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
  int network, mask, host, netmask, broadcast, subnet;
  
  printf("Enter the network address: ");
  scanf("%d", &network);
  
  printf("Enter the subnet mask: ");
  scanf("%d", &mask);
  
  if(mask == 24) {
    printf("\nCIDR Notation: /24");
    printf("\nNumber of Subnets: 1");
    printf("\nNumber of Hosts per Subnet: 254");
    printf("\nNetwork Address: %d.0.0", network);
    printf("\nSubnet Mask: 255.255.255.0");
    printf("\nBroadcast Address: %d.0.255", network);
    printf("\n");
  }
  else if(mask == 25) {
    printf("\nCIDR Notation: /25");
    printf("\nNumber of Subnets: 2");
    printf("\nNumber of Hosts per Subnet: 126");
    printf("\nNetwork Address: %d.0.0", network);
    printf("\nSubnet Mask: 255.255.255.128");
    printf("\nBroadcast Address: %d.0.127", network);
    printf("\n");
  }
  else if(mask == 26) {
    printf("\nCIDR Notation: /26");
    printf("\nNumber of Subnets: 4");
    printf("\nNumber of Hosts per Subnet: 62");
    printf("\nNetwork Address: %d.0.0", network);
    printf("\nSubnet Mask: 255.255.255.192");
    printf("\nBroadcast Address: %d.0.63", network);
    printf("\n");
  }
  else if(mask == 27) {
    printf("\nCIDR Notation: /27");
    printf("\nNumber of Subnets: 8");
    printf("\nNumber of Hosts per Subnet: 30");
    printf("\nNetwork Address: %d.0.0", network);
    printf("\nSubnet Mask: 255.255.255.224");
    printf("\nBroadcast Address: %d.0.31", network);
    printf("\n");
  }
  else if(mask == 28) {
    printf("\nCIDR Notation: /28");
    printf("\nNumber of Subnets: 16");
    printf("\nNumber of Hosts per Subnet: 14");
    printf("\nNetwork Address: %d.0.0", network);
    printf("\nSubnet Mask: 255.255.255.240");
    printf("\nBroadcast Address: %d.0.15", network);
    printf("\n");
  }
  else if(mask == 29) {
    printf("\nCIDR Notation: /29");
    printf("\nNumber of Subnets: 32");
    printf("\nNumber of Hosts per Subnet: 6");
    printf("\nNetwork Address: %d.0.0", network);
    printf("\nSubnet Mask: 255.255.255.248");
    printf("\nBroadcast Address: %d.0.7", network);
    printf("\n");
  }
  else if(mask == 30) {
    printf("\nCIDR Notation: /30");
    printf("\nNumber of Subnets: 64");
    printf("\nNumber of Hosts per Subnet: 2");
    printf("\nNetwork Address: %d.0.0", network);
    printf("\nSubnet Mask: 255.255.255.252");
    printf("\nBroadcast Address: %d.0.3", network);
    printf("\n");
  }
  else {
    printf("\nInvalid Subnet Mask!\n");
  }

  return 0;
}