//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  system("clear");
  system("color 2");
  printf("Welcome to the Cybernetic Subnet Calculator!\n");
  printf("Please enter the network address in the format 'x.x.x.x': ");

  char network_address[16];
  scanf("%s", network_address);

  int network_address_length = strlen(network_address);
  if (network_address_length != 16) {
    printf("Error: Invalid network address length.\n");
    return 1;
  }

  int subnet_mask_length = 0;
  char subnet_mask[32];
  printf("Please enter the subnet mask in the format 'x.x.x.x': ");
  scanf("%s", subnet_mask);

  subnet_mask_length = strlen(subnet_mask);
  if (subnet_mask_length != 32) {
    printf("Error: Invalid subnet mask length.\n");
    return 1;
  }

  int broadcast_address_length = 0;
  char broadcast_address[16];
  printf("Please enter the broadcast address in the format 'x.x.x.x': ");
  scanf("%s", broadcast_address);

  broadcast_address_length = strlen(broadcast_address);
  if (broadcast_address_length != 16) {
    printf("Error: Invalid broadcast address length.\n");
    return 1;
  }

  int num_hosts = 0;
  printf("Please enter the number of hosts in the subnet: ");
  scanf("%d", &num_hosts);

  int subnet_mask_bits = 0;
  for (int i = 0; i < subnet_mask_length; i++) {
    if (subnet_mask[i] == '1') {
      subnet_mask_bits++;
    }
  }

  int usable_hosts = num_hosts - 2;
  int usable_hosts_percentage = (usable_hosts * 100) / num_hosts;

  printf("Network Address:** %s\n", network_address);
  printf("Subnet Mask:** %s\n", subnet_mask);
  printf("Broadcast Address:** %s\n", broadcast_address);
  printf("Number of Hosts:** %d\n", num_hosts);
  printf("Usable Hosts:** %d (%d%%)\n", usable_hosts, usable_hosts_percentage);

  return 0;
}