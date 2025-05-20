//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants (remember, the wasteland is a lawless place)
#define MAX_IP_LEN 16
#define MAX_MASK_LEN 3

// Functions (because in the wasteland, you need to be resourceful)
unsigned long ip_to_long(char *ip);
unsigned long mask_to_long(char *mask);
unsigned long calc_network_address(unsigned long ip, unsigned long mask);
unsigned long calc_broadcast_address(unsigned long ip, unsigned long mask);
unsigned long calc_total_hosts(unsigned long mask);
void print_results(unsigned long ip, unsigned long mask, unsigned long network, unsigned long broadcast, unsigned long hosts);

int main(int argc, char **argv) {
  // Welcome to the wasteland, scavenger!
  printf("Welcome to the Subnet Calculator, scavenger!\n");

  // Get the IP address and subnet mask from the user
  char ip[MAX_IP_LEN];
  char mask[MAX_MASK_LEN];
  printf("Enter the IP address (e.g., 192.168.1.0): ");
  scanf("%s", ip);
  printf("Enter the subnet mask (e.g., 255.255.255.0): ");
  scanf("%s", mask);

  // Convert the IP and mask to long integers
  unsigned long ip_long = ip_to_long(ip);
  unsigned long mask_long = mask_to_long(mask);

  // Calculate the network address, broadcast address, and total number of hosts
  unsigned long network_address = calc_network_address(ip_long, mask_long);
  unsigned long broadcast_address = calc_broadcast_address(ip_long, mask_long);
  unsigned long total_hosts = calc_total_hosts(mask_long);

  // Print the results
  print_results(ip_long, mask_long, network_address, broadcast_address, total_hosts);

  // Farewell, scavenger! May your journey be filled with loot!
  printf("Farewell, scavenger! May your journey be filled with loot!\n");

  return 0;
}

// Convert an IP address to a long integer
unsigned long ip_to_long(char *ip) {
  unsigned long ip_long = 0;
  char *octet;

  // Split the IP address into octets
  octet = strtok(ip, ".");
  while (octet != NULL) {
    // Convert the octet to an integer and add it to the IP address
    ip_long = (ip_long << 8) | atoi(octet);
    octet = strtok(NULL, ".");
  }

  return ip_long;
}

// Convert a subnet mask to a long integer
unsigned long mask_to_long(char *mask) {
  unsigned long mask_long = 0;
  char *octet;

  // Split the subnet mask into octets
  octet = strtok(mask, ".");
  while (octet != NULL) {
    // Convert the octet to an integer and add it to the subnet mask
    mask_long = (mask_long << 8) | atoi(octet);
    octet = strtok(NULL, ".");
  }

  return mask_long;
}

// Calculate the network address
unsigned long calc_network_address(unsigned long ip, unsigned long mask) {
  return ip & mask;
}

// Calculate the broadcast address
unsigned long calc_broadcast_address(unsigned long ip, unsigned long mask) {
  return ip | ~mask;
}

// Calculate the total number of hosts
unsigned long calc_total_hosts(unsigned long mask) {
  return ~mask - 1;
}

// Print the results
void print_results(unsigned long ip, unsigned long mask, unsigned long network, unsigned long broadcast, unsigned long hosts) {
  // Print the IP address, subnet mask, and class
  printf("IP Address: %lu.%lu.%lu.%lu\n", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
  printf("Subnet Mask: %lu.%lu.%lu.%lu\n", (mask >> 24) & 0xFF, (mask >> 16) & 0xFF, (mask >> 8) & 0xFF, mask & 0xFF);

  // Print the network address, broadcast address, and total number of hosts
  printf("Network Address: %lu.%lu.%lu.%lu\n", (network >> 24) & 0xFF, (network >> 16) & 0xFF, (network >> 8) & 0xFF, network & 0xFF);
  printf("Broadcast Address: %lu.%lu.%lu.%lu\n", (broadcast >> 24) & 0xFF, (broadcast >> 16) & 0xFF, (broadcast >> 8) & 0xFF, broadcast & 0xFF);
  printf("Total Hosts: %lu\n", hosts);
}