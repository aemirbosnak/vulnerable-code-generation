//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: mind-bending
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MIND_BEND 1

int main() {
  char input[100];
  int 
    ip_addr[4], 
    subnet_mask[4], 
    wildcard_mask[4], 
    network_addr[4], 
    broadcast_addr[4],
    num_hosts,
    num_subnets,
    num_bits_subnet,
    num_bits_host,
    max_hosts,
    max_subnets;
  float subnet_efficiency;

  printf("Enter the IP address (e.g., 192.168.1.0): ");
  gets(input);

  // Parse the IP address
  sscanf(input, "%d.%d.%d.%d", &ip_addr[0], &ip_addr[1], &ip_addr[2], &ip_addr[3]);
  
  printf("Enter the subnet mask (e.g., 255.255.255.0): ");
  gets(input);

  // Parse the subnet mask
  sscanf(input, "%d.%d.%d.%d", &subnet_mask[0], &subnet_mask[1], &subnet_mask[2], &subnet_mask[3]);

  // Calculate the wildcard mask
  wildcard_mask[0] = 255 - subnet_mask[0];
  wildcard_mask[1] = 255 - subnet_mask[1];
  wildcard_mask[2] = 255 - subnet_mask[2];
  wildcard_mask[3] = 255 - subnet_mask[3];

  // Calculate the network address
  network_addr[0] = ip_addr[0] & subnet_mask[0];
  network_addr[1] = ip_addr[1] & subnet_mask[1];
  network_addr[2] = ip_addr[2] & subnet_mask[2];
  network_addr[3] = ip_addr[3] & subnet_mask[3];

  // Calculate the broadcast address
  broadcast_addr[0] = network_addr[0] | wildcard_mask[0];
  broadcast_addr[1] = network_addr[1] | wildcard_mask[1];
  broadcast_addr[2] = network_addr[2] | wildcard_mask[2];
  broadcast_addr[3] = network_addr[3] | wildcard_mask[3];

  // Calculate the number of hosts
  num_bits_subnet = 0;
  for (int i = 0; i < 4; i++) {
    num_bits_subnet += __builtin_popcount(subnet_mask[i]);
  }

  num_bits_host = 32 - num_bits_subnet;
  max_hosts = pow(2, num_bits_host) - 2;
  num_hosts = max_hosts - 1;

  // Calculate the number of subnets
  max_subnets = pow(2, num_bits_subnet);
  num_subnets = max_subnets - 1;

  // Calculate the subnet efficiency
  subnet_efficiency = (float)num_hosts / (float)max_hosts * 100;

  // Print the results
  printf("\n");
  printf("IP address: %d.%d.%d.%d\n", ip_addr[0], ip_addr[1], ip_addr[2], ip_addr[3]);
  printf("Subnet mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
  printf("Network address: %d.%d.%d.%d\n", network_addr[0], network_addr[1], network_addr[2], network_addr[3]);
  printf("Broadcast address: %d.%d.%d.%d\n", broadcast_addr[0], broadcast_addr[1], broadcast_addr[2], broadcast_addr[3]);
  printf("Number of hosts: %d\n", num_hosts);
  printf("Number of subnets: %d\n", num_subnets);
  printf("Subnet efficiency: %.2f%%\n", subnet_efficiency);

  #if MIND_BEND
    printf("\n");
    printf("Prepare for a mind-bending journey through the depths of subnetting.\n");
    printf("As you gaze upon the impenetrable veil of masks and addresses,\n");
    printf("your mind will dance to the rhythm of binary beats.\n");
    printf("You will uncover secrets hidden within the fabric of the network,\n");
    printf("and unravel the mysteries of host and subnet alike.\n");
    printf("Beware, my friend, for this journey is not for the faint of heart.\n");
    printf("Only those who dare to embrace the unknown will emerge triumphant.\n");
    printf("\n");
    printf("Are you ready to enter the twilight zone of subnetting?\n");
    printf("(Press Enter to continue or any other key to exit)\n");
    getchar();

    printf("\n");
    printf("As you delve deeper into this enigmatic realm,\n");
    printf("you will encounter a labyrinth of subnets and hosts.\n");
    printf("Each subnet, a separate kingdom, ruled by its own network address.\n");
    printf("And within each kingdom, a multitude of hosts reside,\n");
    printf("each with its own unique identity, waiting to be discovered.\n");
    printf("\n");
    printf("But be warned, adventurer, for not all subnets are created equal.\n");
    printf("Some are vast and expansive, while others are small and confined.\n");
    printf("And just as the stars above, some subnets shine brighter than others.\n");
    printf("\n");
    printf("So, let us embark on this cosmic voyage,\n");
    printf("and unravel the mysteries of subnetting together.\n");
    printf("May your journey be filled with wonder and enlightenment.\n");
    printf("\n");
    printf("Press Enter to return to reality.\n");
    getchar();
  #endif

  return 0;
}