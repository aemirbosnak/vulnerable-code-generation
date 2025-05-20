//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
// C Subnet Calculator Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store network and subnet mask information
typedef struct {
  unsigned long network;
  unsigned long subnet;
} NetworkInfo;

// Function to calculate the subnet mask based on the given subnet size
unsigned long calculate_subnet_mask(unsigned long subnet_size) {
  // Convert the subnet size to binary
  char *subnet_size_binary = (char *) malloc(sizeof(char) * 33);
  sprintf(subnet_size_binary, "%32d", subnet_size);

  // Count the number of leading zeros
  int leading_zeros = 0;
  for (int i = 0; i < 32; i++) {
    if (subnet_size_binary[i] == '0') {
      leading_zeros++;
    } else {
      break;
    }
  }

  // Calculate the subnet mask
  unsigned long subnet_mask = 0;
  for (int i = 0; i < 32; i++) {
    if (i < leading_zeros) {
      subnet_mask |= 1 << (31 - i);
    }
  }

  free(subnet_size_binary);
  return subnet_mask;
}

// Function to calculate the network and subnet mask based on the given IP address and subnet size
void calculate_network_info(unsigned long ip_address, unsigned long subnet_size, NetworkInfo *network_info) {
  // Calculate the subnet mask
  unsigned long subnet_mask = calculate_subnet_mask(subnet_size);

  // Calculate the network and subnet address
  network_info->network = ip_address & subnet_mask;
  network_info->subnet = ip_address & ~subnet_mask;
}

// Function to print the network and subnet address
void print_network_info(NetworkInfo network_info) {
  printf("Network address: %ld\n", network_info.network);
  printf("Subnet address: %ld\n", network_info.subnet);
}

int main() {
  // Get the IP address and subnet size from the user
  printf("Enter the IP address: ");
  unsigned long ip_address;
  scanf("%ld", &ip_address);

  printf("Enter the subnet size: ");
  unsigned long subnet_size;
  scanf("%ld", &subnet_size);

  // Calculate the network and subnet address
  NetworkInfo network_info;
  calculate_network_info(ip_address, subnet_size, &network_info);

  // Print the network and subnet address
  print_network_info(network_info);

  return 0;
}