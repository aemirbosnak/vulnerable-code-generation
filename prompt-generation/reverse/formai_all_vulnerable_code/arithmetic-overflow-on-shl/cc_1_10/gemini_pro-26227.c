//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// A subnet mask is a 32-bit number that masks a portion of an IP address to indicate the subnet to which a particular host belongs.
// This program calculates the subnet mask and other network information for a given IP address and subnet prefix length.

// Returns the subnet mask for the given IP address and subnet prefix length.
unsigned int calculateSubnetMask(unsigned int ipAddress, unsigned int prefixLength) {
  // Create a subnet mask with all 1s in the first prefixLength bits and all 0s in the remaining bits.
  unsigned int subnetMask = 0;
  for (int i = 0; i < prefixLength; i++) {
    subnetMask |= (1 << (31 - i));
  }

  // Return the subnet mask.
  return subnetMask;
}

// Returns the network address for the given IP address and subnet mask.
unsigned int calculateNetworkAddress(unsigned int ipAddress, unsigned int subnetMask) {
  // Perform a bitwise AND operation between the IP address and the subnet mask to get the network address.
  unsigned int networkAddress = ipAddress & subnetMask;

  // Return the network address.
  return networkAddress;
}

// Returns the broadcast address for the given IP address and subnet mask.
unsigned int calculateBroadcastAddress(unsigned int ipAddress, unsigned int subnetMask) {
  // Perform a bitwise OR operation between the network address and the inverse of the subnet mask to get the broadcast address.
  unsigned int broadcastAddress = ipAddress | (~subnetMask);

  // Return the broadcast address.
  return broadcastAddress;
}

// Returns the number of hosts that can be accommodated in the given subnet.
unsigned int calculateNumberOfHosts(unsigned int subnetMask) {
  // The number of hosts that can be accommodated in a subnet is 2^(32 - prefixLength) - 2.
  unsigned int numberOfHosts = pow(2, (32 - subnetMask)) - 2;

  // Return the number of hosts.
  return numberOfHosts;
}

// Prints the subnet mask, network address, broadcast address, and number of hosts for the given IP address and subnet prefix length.
void printSubnetInformation(unsigned int ipAddress, unsigned int prefixLength) {
  // Calculate the subnet mask.
  unsigned int subnetMask = calculateSubnetMask(ipAddress, prefixLength);

  // Calculate the network address.
  unsigned int networkAddress = calculateNetworkAddress(ipAddress, subnetMask);

  // Calculate the broadcast address.
  unsigned int broadcastAddress = calculateBroadcastAddress(ipAddress, subnetMask);

  // Calculate the number of hosts.
  unsigned int numberOfHosts = calculateNumberOfHosts(subnetMask);

  // Print the subnet information.
  printf("Subnet Mask: %u\n", subnetMask);
  printf("Network Address: %u\n", networkAddress);
  printf("Broadcast Address: %u\n", broadcastAddress);
  printf("Number of Hosts: %u\n", numberOfHosts);
}

int main() {
  // Get the IP address from the user.
  unsigned int ipAddress;
  printf("Enter the IP address: ");
  scanf("%u", &ipAddress);

  // Get the subnet prefix length from the user.
  unsigned int prefixLength;
  printf("Enter the subnet prefix length: ");
  scanf("%u", &prefixLength);

  // Print the subnet information.
  printSubnetInformation(ipAddress, prefixLength);

  return 0;
}