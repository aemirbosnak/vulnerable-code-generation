//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subnets
#define MAX_SUBNETS 256

// Define the maximum number of hosts per subnet
#define MAX_HOSTS 256

// Define the structure of a subnet
typedef struct {
  unsigned int subnet_address;
  unsigned int subnet_mask;
  unsigned int number_of_hosts;
} subnet_t;

// Define the structure of a network
typedef struct {
  unsigned int network_address;
  unsigned int network_mask;
  unsigned int number_of_subnets;
  subnet_t subnets[MAX_SUBNETS];
} network_t;

// Function to calculate the subnet mask
unsigned int calculate_subnet_mask(unsigned int number_of_subnets) {
  unsigned int subnet_mask = 0xFFFFFFFF;
  while (number_of_subnets > 1) {
    subnet_mask = subnet_mask >> 1;
    number_of_subnets = number_of_subnets >> 1;
  }
  return subnet_mask;
}

// Function to calculate the number of hosts per subnet
unsigned int calculate_number_of_hosts(unsigned int subnet_mask) {
  unsigned int number_of_hosts = 0;
  while (subnet_mask != 0xFFFFFFFF) {
    subnet_mask = subnet_mask << 1;
    number_of_hosts = number_of_hosts + 1;
  }
  return number_of_hosts;
}

// Function to calculate the subnets
void calculate_subnets(network_t *network) {
  unsigned int subnet_address = network->network_address;
  unsigned int subnet_mask = calculate_subnet_mask(network->number_of_subnets);
  unsigned int number_of_hosts = calculate_number_of_hosts(subnet_mask);

  for (int i = 0; i < network->number_of_subnets; i++) {
    network->subnets[i].subnet_address = subnet_address;
    network->subnets[i].subnet_mask = subnet_mask;
    network->subnets[i].number_of_hosts = number_of_hosts;
    subnet_address = subnet_address + number_of_hosts;
  }
}

// Function to print the subnets
void print_subnets(network_t *network) {
  for (int i = 0; i < network->number_of_subnets; i++) {
    printf("Subnet %d: %u.%u.%u.%u/%u\n", i + 1,
           (network->subnets[i].subnet_address >> 24) & 0xFF,
           (network->subnets[i].subnet_address >> 16) & 0xFF,
           (network->subnets[i].subnet_address >> 8) & 0xFF,
           network->subnets[i].subnet_address & 0xFF,
           network->subnets[i].subnet_mask);
  }
}

// Function to get the network address from the user
unsigned int get_network_address() {
  unsigned int network_address;
  printf("Enter the network address: ");
  scanf("%u.%u.%u.%u", &network_address, &network_address, &network_address, &network_address);
  return network_address;
}

// Function to get the network mask from the user
unsigned int get_network_mask() {
  unsigned int network_mask;
  printf("Enter the network mask: ");
  scanf("%u.%u.%u.%u", &network_mask, &network_mask, &network_mask, &network_mask);
  return network_mask;
}

// Function to get the number of subnets from the user
unsigned int get_number_of_subnets() {
  unsigned int number_of_subnets;
  printf("Enter the number of subnets: ");
  scanf("%u", &number_of_subnets);
  return number_of_subnets;
}

// Main function
int main() {
  // Get the network address from the user
  unsigned int network_address = get_network_address();

  // Get the network mask from the user
  unsigned int network_mask = get_network_mask();

  // Get the number of subnets from the user
  unsigned int number_of_subnets = get_number_of_subnets();

  // Create a network object
  network_t network;

  // Set the network address
  network.network_address = network_address;

  // Set the network mask
  network.network_mask = network_mask;

  // Set the number of subnets
  network.number_of_subnets = number_of_subnets;

  // Calculate the subnets
  calculate_subnets(&network);

  // Print the subnets
  print_subnets(&network);

  return 0;
}