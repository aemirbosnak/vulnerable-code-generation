//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Structure to store subnet information
struct subnet {
  unsigned int address;  // Subnet address
  unsigned int mask;     // Subnet mask
  unsigned int prefix;   // Subnet prefix length
  unsigned int hosts;    // Number of hosts on the subnet
  unsigned int broadcast;// Broadcast address
  unsigned int network;  // Network address
  unsigned int wildcard; // Wildcard mask
};

// Function to calculate subnet information
void calculate_subnet(struct subnet *subnet, unsigned int address, unsigned int mask) {
  // Set subnet address
  subnet->address = address;

  // Set subnet mask
  subnet->mask = mask;

  // Calculate subnet prefix length
  subnet->prefix = 32 - __builtin_clz(mask);

  // Calculate number of hosts on the subnet
  subnet->hosts = (1 << (32 - subnet->prefix)) - 2;

  // Calculate broadcast address
  subnet->broadcast = address | ~mask;

  // Calculate network address
  subnet->network = address & mask;

  // Calculate wildcard mask
  subnet->wildcard = ~mask;
}

// Function to print subnet information
void print_subnet(struct subnet *subnet) {
  printf("Subnet Address: %u.%u.%u.%u\n",
         (subnet->address >> 24) & 0xFF,
         (subnet->address >> 16) & 0xFF,
         (subnet->address >> 8) & 0xFF,
         subnet->address & 0xFF);

  printf("Subnet Mask: %u.%u.%u.%u\n",
         (subnet->mask >> 24) & 0xFF,
         (subnet->mask >> 16) & 0xFF,
         (subnet->mask >> 8) & 0xFF,
         subnet->mask & 0xFF);

  printf("Subnet Prefix Length: %u\n", subnet->prefix);

  printf("Number of Hosts: %u\n", subnet->hosts);

  printf("Broadcast Address: %u.%u.%u.%u\n",
         (subnet->broadcast >> 24) & 0xFF,
         (subnet->broadcast >> 16) & 0xFF,
         (subnet->broadcast >> 8) & 0xFF,
         subnet->broadcast & 0xFF);

  printf("Network Address: %u.%u.%u.%u\n",
         (subnet->network >> 24) & 0xFF,
         (subnet->network >> 16) & 0xFF,
         (subnet->network >> 8) & 0xFF,
         subnet->network & 0xFF);

  printf("Wildcard Mask: %u.%u.%u.%u\n",
         (subnet->wildcard >> 24) & 0xFF,
         (subnet->wildcard >> 16) & 0xFF,
         (subnet->wildcard >> 8) & 0xFF,
         subnet->wildcard & 0xFF);
}

// Main function
int main() {
  // Declare subnet structure
  struct subnet subnet;

  // Get subnet address and mask from user
  unsigned int address, mask;
  printf("Enter subnet address: ");
  scanf("%u", &address);
  printf("Enter subnet mask: ");
  scanf("%u", &mask);

  // Calculate subnet information
  calculate_subnet(&subnet, address, mask);

  // Print subnet information
  print_subnet(&subnet);

  return 0;
}