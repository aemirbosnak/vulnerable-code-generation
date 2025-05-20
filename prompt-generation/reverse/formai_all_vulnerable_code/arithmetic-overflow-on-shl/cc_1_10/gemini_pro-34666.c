//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store subnet information
typedef struct subnet {
  unsigned int address;  // Network address
  unsigned int mask;     // Subnet mask
  unsigned int size;    // Number of hosts in the subnet
} subnet_t;

// Function to calculate subnet information
subnet_t calculate_subnet(unsigned int address, unsigned int mask) {
  subnet_t subnet;

  // Calculate network address
  subnet.address = address & mask;

  // Calculate subnet mask
  subnet.mask = mask;

  // Calculate number of hosts in the subnet
  subnet.size = (1 << (32 - __builtin_clz(mask))) - 2;

  return subnet;
}

// Function to print subnet information
void print_subnet(subnet_t subnet) {
  // Convert network address to dotted-decimal notation
  char network_address[16];
  sprintf(network_address, "%u.%u.%u.%u",
          (subnet.address >> 24) & 0xFF,
          (subnet.address >> 16) & 0xFF,
          (subnet.address >> 8) & 0xFF,
          subnet.address & 0xFF);

  // Convert subnet mask to dotted-decimal notation
  char subnet_mask[16];
  sprintf(subnet_mask, "%u.%u.%u.%u",
          (subnet.mask >> 24) & 0xFF,
          (subnet.mask >> 16) & 0xFF,
          (subnet.mask >> 8) & 0xFF,
          subnet.mask & 0xFF);

  // Print subnet information
  printf("Network address: %s\n", network_address);
  printf("Subnet mask: %s\n", subnet_mask);
  printf("Number of hosts: %u\n", subnet.size);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if enough arguments are provided
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <network address> <subnet mask>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse network address and subnet mask
  unsigned int address = inet_addr(argv[1]);
  unsigned int mask = inet_addr(argv[2]);

  // Calculate subnet information
  subnet_t subnet = calculate_subnet(address, mask);

  // Print subnet information
  print_subnet(subnet);

  return EXIT_SUCCESS;
}