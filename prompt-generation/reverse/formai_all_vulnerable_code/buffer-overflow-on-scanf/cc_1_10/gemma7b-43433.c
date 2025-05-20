//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct NetworkInterface {
  char hostname[MAX_BUFFER_SIZE];
  int subnet_mask, broadcast_address, private_ip, subnet_prefix, network_class;
} NetworkInterface;

NetworkInterface networkInterface;

void calculateSubnetMask(int numBits) {
  int mask = 0;
  for (int i = 0; i < numBits; i++) {
    mask |= 1 << (32 - i - 1);
  }
  networkInterface.subnet_mask = mask;
}

void calculateBroadcastAddress(int subnetMask) {
  int broadcastAddress = networkInterface.subnet_mask & ~(networkInterface.subnet_mask - 1);
  networkInterface.broadcast_address = broadcastAddress;
}

void calculatePrivateIp(int subnetMask) {
  int networkAddress = networkInterface.subnet_mask & networkInterface.private_ip;
  networkInterface.private_ip = networkAddress | ~networkInterface.subnet_mask;
}

void calculateSubnetPrefix(int numBits) {
  networkInterface.subnet_prefix = numBits;
}

void calculateNetworkClass(int subnetMask) {
  int networkClass = (subnetMask & 0xF00) >> 8;
  networkInterface.network_class = networkClass;
}

int main() {
  printf("Enter the hostname: ");
  scanf("%s", networkInterface.hostname);

  printf("Enter the number of bits for the subnet mask: ");
  scanf("%d", &networkInterface.subnet_mask);

  calculateSubnetMask(networkInterface.subnet_mask);
  calculateBroadcastAddress(networkInterface.subnet_mask);
  calculatePrivateIp(networkInterface.subnet_mask);
  calculateSubnetPrefix(networkInterface.subnet_mask);
  calculateNetworkClass(networkInterface.subnet_mask);

  printf("Subnet Mask: %d\n", networkInterface.subnet_mask);
  printf("Broadcast Address: %d\n", networkInterface.broadcast_address);
  printf("Private IP Address: %d\n", networkInterface.private_ip);
  printf("Subnet Prefix: %d\n", networkInterface.subnet_prefix);
  printf("Network Class: %d\n", networkInterface.network_class);

  return 0;
}