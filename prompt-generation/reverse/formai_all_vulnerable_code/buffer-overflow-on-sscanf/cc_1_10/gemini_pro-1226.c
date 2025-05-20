//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum number of octets in an IP address */
#define MAX_OCTETS 4

/* Define the maximum number of bits in an octet */
#define MAX_BITS 8

/* Define the structure of an IP address */
typedef struct {
  unsigned char octets[MAX_OCTETS];
} IPAddress;

/* Define the structure of a subnet mask */
typedef struct {
  unsigned char bits[MAX_OCTETS];
} SubnetMask;

/* Define the structure of a subnet calculator */
typedef struct {
  IPAddress ipAddress;
  SubnetMask subnetMask;
  unsigned int subnetId;
  unsigned int broadcastAddress;
  unsigned int networkAddress;
  unsigned int usableHosts;
} SubnetCalculator;

/* Function to initialize a subnet calculator */
void initializeSubnetCalculator(SubnetCalculator *subnetCalculator, IPAddress ipAddress, SubnetMask subnetMask) {
  memcpy(subnetCalculator->ipAddress.octets, ipAddress.octets, sizeof(ipAddress.octets));
  memcpy(subnetCalculator->subnetMask.bits, subnetMask.bits, sizeof(subnetMask.bits));
  subnetCalculator->subnetId = 0;
  subnetCalculator->broadcastAddress = 0;
  subnetCalculator->networkAddress = 0;
  subnetCalculator->usableHosts = 0;
}

/* Function to calculate the subnet ID */
void calculateSubnetId(SubnetCalculator *subnetCalculator) {
  for (int i = 0; i < MAX_OCTETS; i++) {
    subnetCalculator->subnetId |= subnetCalculator->ipAddress.octets[i] & subnetCalculator->subnetMask.bits[i];
  }
}

/* Function to calculate the broadcast address */
void calculateBroadcastAddress(SubnetCalculator *subnetCalculator) {
  for (int i = 0; i < MAX_OCTETS; i++) {
    subnetCalculator->broadcastAddress |= subnetCalculator->ipAddress.octets[i] | ~subnetCalculator->subnetMask.bits[i];
  }
}

/* Function to calculate the network address */
void calculateNetworkAddress(SubnetCalculator *subnetCalculator) {
  for (int i = 0; i < MAX_OCTETS; i++) {
    subnetCalculator->networkAddress |= subnetCalculator->ipAddress.octets[i] & subnetCalculator->subnetMask.bits[i];
  }
}

/* Function to calculate the number of usable hosts */
void calculateUsableHosts(SubnetCalculator *subnetCalculator) {
  for (int i = 0; i < MAX_OCTETS; i++) {
    subnetCalculator->usableHosts |= ~subnetCalculator->subnetMask.bits[i];
  }
  subnetCalculator->usableHosts = (subnetCalculator->usableHosts >> 1) - 1;
}

/* Function to print the subnet calculator results */
void printSubnetCalculatorResults(SubnetCalculator *subnetCalculator) {
  printf("Subnet ID: %u\n", subnetCalculator->subnetId);
  printf("Broadcast Address: %u\n", subnetCalculator->broadcastAddress);
  printf("Network Address: %u\n", subnetCalculator->networkAddress);
  printf("Usable Hosts: %u\n", subnetCalculator->usableHosts);
}

/* Function to main */
int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <ip address> <subnet mask>\n", argv[0]);
    return 1;
  }

  /* Parse the IP address */
  IPAddress ipAddress;
  if (sscanf(argv[1], "%hhu.%hhu.%hhu.%hhu", &ipAddress.octets[0], &ipAddress.octets[1], &ipAddress.octets[2], &ipAddress.octets[3]) != 4) {
    printf("Invalid IP address: %s\n", argv[1]);
    return 1;
  }

  /* Parse the subnet mask */
  SubnetMask subnetMask;
  if (sscanf(argv[2], "%hhu.%hhu.%hhu.%hhu", &subnetMask.bits[0], &subnetMask.bits[1], &subnetMask.bits[2], &subnetMask.bits[3]) != 4) {
    printf("Invalid subnet mask: %s\n", argv[2]);
    return 1;
  }

  /* Initialize the subnet calculator */
  SubnetCalculator subnetCalculator;
  initializeSubnetCalculator(&subnetCalculator, ipAddress, subnetMask);

  /* Calculate the subnet ID, broadcast address, network address, and usable hosts */
  calculateSubnetId(&subnetCalculator);
  calculateBroadcastAddress(&subnetCalculator);
  calculateNetworkAddress(&subnetCalculator);
  calculateUsableHosts(&subnetCalculator);

  /* Print the subnet calculator results */
  printSubnetCalculatorResults(&subnetCalculator);

  return 0;
}