//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our main function, where the magic happens!
int main() {
  // Let's declare our variables for a thrilling subnet calculation adventure!
  unsigned long ip_address, subnet_mask, network_address, broadcast_address, first_host, last_host;
  int cidr_notation, num_hosts, num_subnets;
  char ip_address_str[16], subnet_mask_str[16];

  // Let's greet our users with a warm welcome to our subnet calculator extravaganza!
  printf("\n\nWelcome to the Subnet Calculator Extravaganza! Brace yourself for a thrilling journey into the world of IP addressing.\n\n");

  // Time to gather the IP address and subnet mask from our eager users.
  printf("Enter the IP address (e.g., 192.168.1.0): ");
  scanf("%s", ip_address_str);
  printf("Enter the subnet mask (e.g., 255.255.255.0): ");
  scanf("%s", subnet_mask_str);

  // Parse the IP address and subnet mask for a seamless calculation experience.
  ip_address = inet_addr(ip_address_str);
  subnet_mask = inet_addr(subnet_mask_str);

  // Let's determine the CIDR notation for a concise representation.
  cidr_notation = 0;
  for (int i = 0; i < 32; i++) {
    if ((subnet_mask >> i) & 1) {
      cidr_notation++;
    }
  }

  // Now, let's calculate the network address, a crucial step in our subnet exploration.
  network_address = ip_address & subnet_mask;

  // Next, we'll compute the broadcast address, the boundary of our subnet.
  broadcast_address = network_address | ~subnet_mask;

  // Time to find the first and last hosts, the endpoints of our subnet.
  first_host = network_address + 1;
  last_host = broadcast_address - 1;

  // Calculate the number of hosts and subnets for insights into subnet utilization.
  num_hosts = (1 << (32 - cidr_notation)) - 2;
  num_subnets = 1 << (cidr_notation - 24);

  // Let's display the results of our subnet calculation, bringing clarity to the IP addressing maze.
  printf("\n\nSubnet Calculation Results:\n");
  printf("-----------------------------------------\n");
  printf("IP Address: %s\n", ip_address_str);
  printf("Subnet Mask: %s\n", subnet_mask_str);
  printf("CIDR Notation: %d\n", cidr_notation);
  printf("Network Address: %s\n", inet_ntoa(network_address));
  printf("Broadcast Address: %s\n", inet_ntoa(broadcast_address));
  printf("First Host: %s\n", inet_ntoa(first_host));
  printf("Last Host: %s\n", inet_ntoa(last_host));
  printf("Number of Hosts: %d\n", num_hosts);
  printf("Number of Subnets: %d\n", num_subnets);

  // A final message to wrap up our subnet calculation adventure with a touch of enthusiasm.
  printf("\n\nCongratulations! You've successfully navigated the world of IP addressing. May your subnets be optimized and your networks flourish.\n\n");

  return 0;
}