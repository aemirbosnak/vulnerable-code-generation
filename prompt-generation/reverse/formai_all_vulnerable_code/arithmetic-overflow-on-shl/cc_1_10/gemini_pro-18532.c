//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the network address
unsigned long long int calculateNetworkAddress(unsigned long long int ipAddress, unsigned int subnetMask) {
  return ipAddress & subnetMask;
}

// Function to calculate the broadcast address
unsigned long long int calculateBroadcastAddress(unsigned long long int ipAddress, unsigned int subnetMask) {
  return ipAddress | ~subnetMask;
}

// Function to calculate the number of hosts
unsigned long long int calculateNumberOfHosts(unsigned int subnetMask) {
  return (1 << (32 - subnetMask)) - 2;
}

// Function to print the results
void printResults(unsigned long long int networkAddress, unsigned long long int broadcastAddress, unsigned long long int numberOfHosts) {
  printf("Network Address: %llu\n", networkAddress);
  printf("Broadcast Address: %llu\n", broadcastAddress);
  printf("Number of Hosts: %llu\n", numberOfHosts);
}

int main() {
  // Declare variables
  unsigned long long int ipAddress;
  unsigned int subnetMask;
  unsigned long long int networkAddress;
  unsigned long long int broadcastAddress;
  unsigned long long int numberOfHosts;

  // Get the IP address from the user
  printf("Enter the IP address: ");
  scanf("%llu", &ipAddress);

  // Get the subnet mask from the user
  printf("Enter the subnet mask: ");
  scanf("%u", &subnetMask);

  // Calculate the network address
  networkAddress = calculateNetworkAddress(ipAddress, subnetMask);

  // Calculate the broadcast address
  broadcastAddress = calculateBroadcastAddress(ipAddress, subnetMask);

  // Calculate the number of hosts
  numberOfHosts = calculateNumberOfHosts(subnetMask);

  // Print the results
  printResults(networkAddress, broadcastAddress, numberOfHosts);

  return 0;
}