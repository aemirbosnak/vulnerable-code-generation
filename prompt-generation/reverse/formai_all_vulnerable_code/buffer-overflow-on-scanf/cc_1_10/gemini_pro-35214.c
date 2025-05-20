//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
  // Declare variables
  char ip_address[16];
  char subnet_mask[16];
  int prefix_length;
  struct in_addr ip_addr;
  struct in_addr subnet_addr;
  struct in_addr broadcast_addr;
  struct in_addr network_addr;
  struct in_addr hostmin_addr;
  struct in_addr hostmax_addr;
  unsigned int host_count;

  // Get input from user
  printf("Enter the IP address: ");
  scanf("%s", ip_address);
  printf("Enter the subnet mask: ");
  scanf("%s", subnet_mask);

  // Convert IP address and subnet mask to binary
  inet_aton(ip_address, &ip_addr);
  inet_aton(subnet_mask, &subnet_addr);

  // Calculate prefix length
  prefix_length = 0;
  for (int i = 0; i < 32; i++) {
    if ((subnet_addr.s_addr >> i) & 1) {
      prefix_length++;
    }
  }

  // Calculate network address
  network_addr.s_addr = ip_addr.s_addr & subnet_addr.s_addr;

  // Calculate broadcast address
  broadcast_addr.s_addr = network_addr.s_addr | ~subnet_addr.s_addr;

  // Calculate hostmin address
  hostmin_addr.s_addr = network_addr.s_addr + 1;

  // Calculate hostmax address
  hostmax_addr.s_addr = broadcast_addr.s_addr - 1;

  // Calculate host count
  host_count = (unsigned int)(broadcast_addr.s_addr - network_addr.s_addr + 1);

  // Print subnet information
  printf("\nSubnet Information:\n");
  printf("IP Address: %s\n", ip_address);
  printf("Subnet Mask: %s\n", subnet_mask);
  printf("Prefix Length: %d\n", prefix_length);
  printf("Network Address: %s\n", inet_ntoa(network_addr));
  printf("Broadcast Address: %s\n", inet_ntoa(broadcast_addr));
  printf("Hostmin Address: %s\n", inet_ntoa(hostmin_addr));
  printf("Hostmax Address: %s\n", inet_ntoa(hostmax_addr));
  printf("Host Count: %u\n", host_count);

  return 0;
}