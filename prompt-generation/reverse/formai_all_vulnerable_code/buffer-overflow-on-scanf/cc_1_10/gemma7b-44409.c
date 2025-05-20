//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
  int netmask, subnet, host, i, j, k, l, m, n;
  char subnet_mask[16], subnet_address[16], host_address[16];

  printf("Enter subnet mask in CIDR notation (e.g. 255.255.255.0/24): ");
  scanf("%s", subnet_mask);

  printf("Enter subnet address (e.g. 192.168.1.1): ");
  scanf("%s", subnet_address);

  printf("Enter host address (e.g. 192.168.1.10): ");
  scanf("%s", host_address);

  // Calculate subnet mask in binary
  netmask = atoi(subnet_mask);
  for (i = 0; i < 32; i++) {
    if (netmask & (1 << i)) {
      subnet_mask[i] = 1;
    } else {
      subnet_mask[i] = 0;
    }
  }

  // Calculate subnet address in binary
  subnet = atoi(subnet_address);
  for (i = 0; i < 32; i++) {
    if (subnet_mask[i] & subnet & (1 << i)) {
      subnet_address[i] = 1;
    } else {
      subnet_address[i] = 0;
    }
  }

  // Calculate host address in binary
  host = atoi(host_address);
  for (i = 0; i < 32; i++) {
    if (subnet_mask[i] & host & (1 << i)) {
      host_address[i] = 1;
    } else {
      host_address[i] = 0;
    }
  }

  // Print subnet mask, subnet address, and host address
  printf("Subnet mask: ");
  for (i = 0; i < 32; i++) {
    printf("%d ", subnet_mask[i]);
  }
  printf("\n");

  printf("Subnet address: ");
  for (i = 0; i < 32; i++) {
    printf("%d ", subnet_address[i]);
  }
  printf("\n");

  printf("Host address: ");
  for (i = 0; i < 32; i++) {
    printf("%d ", host_address[i]);
  }
  printf("\n");

  return 0;
}