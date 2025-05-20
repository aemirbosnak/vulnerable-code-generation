//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate the subnet mask
unsigned int calculateSubnetMask(unsigned int cidr) {
  // Check if the CIDR is valid
  if (cidr > 32) {
    printf("Error: Invalid CIDR");
    exit(1);
  }

  // Calculate the subnet mask
  unsigned int subnetMask = 0xFFFFFFFF << (32 - cidr);

  // Return the subnet mask
  return subnetMask;
}

// Function to calculate the network address
unsigned int calculateNetworkAddress(unsigned int ipAddress, unsigned int subnetMask) {
  // Calculate the network address
  unsigned int networkAddress = ipAddress & subnetMask;

  // Return the network address
  return networkAddress;
}

// Function to calculate the broadcast address
unsigned int calculateBroadcastAddress(unsigned int ipAddress, unsigned int subnetMask) {
  // Calculate the broadcast address
  unsigned int broadcastAddress = ipAddress | ~subnetMask;

  // Return the broadcast address
  return broadcastAddress;
}

// Function to print the subnet information
void printSubnetInformation(unsigned int ipAddress, unsigned int subnetMask, unsigned int networkAddress, unsigned int broadcastAddress) {
  // Print the subnet information
  printf("IP Address: %u.%u.%u.%u\n", (ipAddress >> 24) & 0xFF, (ipAddress >> 16) & 0xFF, (ipAddress >> 8) & 0xFF, ipAddress & 0xFF);
  printf("Subnet Mask: %u.%u.%u.%u\n", (subnetMask >> 24) & 0xFF, (subnetMask >> 16) & 0xFF, (subnetMask >> 8) & 0xFF, subnetMask & 0xFF);
  printf("Network Address: %u.%u.%u.%u\n", (networkAddress >> 24) & 0xFF, (networkAddress >> 16) & 0xFF, (networkAddress >> 8) & 0xFF, networkAddress & 0xFF);
  printf("Broadcast Address: %u.%u.%u.%u\n", (broadcastAddress >> 24) & 0xFF, (broadcastAddress >> 16) & 0xFF, (broadcastAddress >> 8) & 0xFF, broadcastAddress & 0xFF);
}

// Main function
int main() {
  // Get the IP address and CIDR from the user
  unsigned int ipAddress;
  unsigned int cidr;
  printf("Enter the IP address: ");
  scanf("%u", &ipAddress);
  printf("Enter the CIDR: ");
  scanf("%u", &cidr);

  // Calculate the subnet mask, network address, and broadcast address
  unsigned int subnetMask = calculateSubnetMask(cidr);
  unsigned int networkAddress = calculateNetworkAddress(ipAddress, subnetMask);
  unsigned int broadcastAddress = calculateBroadcastAddress(ipAddress, subnetMask);

  // Print the subnet information
  printSubnetInformation(ipAddress, subnetMask, networkAddress, broadcastAddress);

  return 0;
}