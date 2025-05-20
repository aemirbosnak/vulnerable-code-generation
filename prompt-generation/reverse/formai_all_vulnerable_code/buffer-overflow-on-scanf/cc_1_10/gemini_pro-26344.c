//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Define constants
  const int MAX_IP_LENGTH = 15;
  const int MAX_SUBNET_MASK_LENGTH = 15;
  const int MIN_SUBNET_MASK_VALUE = 0;
  const int MAX_SUBNET_MASK_VALUE = 32;

  // Declare variables
  char ip_address[MAX_IP_LENGTH];
  char subnet_mask[MAX_SUBNET_MASK_LENGTH];
  int subnet_mask_value;
  int num_hosts;
  int num_subnets;
  int broadcast_address;
  int network_address;
  int first_host_address;
  int last_host_address;

  // Get input from the user
  printf("Enter the IP address: ");
  scanf("%s", ip_address);

  printf("Enter the subnet mask: ");
  scanf("%s", subnet_mask);

  // Convert the subnet mask to an integer
  subnet_mask_value = 0;
  for (int i = 0; i < strlen(subnet_mask); i++) {
    if (subnet_mask[i] == '/') {
      subnet_mask_value = atoi(&subnet_mask[i + 1]);
      break;
    }
  }

  // Calculate the number of hosts
  num_hosts = pow(2, 32 - subnet_mask_value) - 2;

  // Calculate the number of subnets
  num_subnets = pow(2, subnet_mask_value);

  // Calculate the broadcast address
  broadcast_address = (1 << (32 - subnet_mask_value)) - 1;

  // Calculate the network address
  network_address = 0;
  for (int i = 0; i < subnet_mask_value; i++) {
    network_address |= 1 << (31 - i);
  }

  // Calculate the first host address
  first_host_address = network_address + 1;

  // Calculate the last host address
  last_host_address = broadcast_address - 1;

  // Print the results
  printf("IP Address: %s\n", ip_address);
  printf("Subnet Mask: %s\n", subnet_mask);
  printf("Subnet Mask Value: %d\n", subnet_mask_value);
  printf("Number of Hosts: %d\n", num_hosts);
  printf("Number of Subnets: %d\n", num_subnets);
  printf("Broadcast Address: %d\n", broadcast_address);
  printf("Network Address: %d\n", network_address);
  printf("First Host Address: %d\n", first_host_address);
  printf("Last Host Address: %d\n", last_host_address);

  return 0;
}