//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: interoperable
#include <stdio.h>

int main() {
  // Get IP address and number of hosts from user
  printf("Enter IP address: ");
  char ip[15];
  fgets(ip, 15, stdin);
  ip[strcspn(ip, "\n")] = '\0';
  
  printf("Enter number of hosts: ");
  int hosts;
  scanf("%d", &hosts);
  
  // Calculate subnet mask
  int subnet_mask = 0;
  int network_mask = 32;
  
  while (network_mask > 0) {
    int host_mask = (1 << hosts) - 1;
    int mask = host_mask << (network_mask - 1);
    int last_bit = 0;
    
    for (int i = 0; i < 8; i++) {
      int bit = (1 << i) & mask;
      
      if (bit!= 0) {
        subnet_mask |= (1 << (8 - i - 1));
        last_bit = 1;
      }
    }
    
    if (last_bit == 0) {
      network_mask--;
    } else {
      break;
    }
  }
  
  // Print subnet mask
  printf("Subnet mask: ");
  for (int i = 0; i < 8; i++) {
    if (subnet_mask & (1 << i)) {
      printf("%d", i + 1);
    } else {
      printf("0");
    }
  }
  printf("\n");
  
  return 0;
}