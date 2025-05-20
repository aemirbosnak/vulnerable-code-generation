//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of bits in an IPv4 address
#define MAX_BITS 32

// Define the structure of an IPv4 address
typedef struct {
    unsigned int address;
    unsigned int mask;
} IPv4Address;

// Print the IPv4 address in dotted-decimal notation
void printAddress(IPv4Address address) {
    // Initialize the string to store the dotted-decimal notation
    char dottedDecimal[16];

    // Convert the address to dotted-decimal notation
    sprintf(dottedDecimal, "%d.%d.%d.%d",
            (address.address >> 24) & 0xFF,
            (address.address >> 16) & 0xFF,
            (address.address >> 8) & 0xFF,
            address.address & 0xFF);

    // Print the dotted-decimal notation
    printf("%s", dottedDecimal);
}

// Print the IPv4 mask in dotted-decimal notation
void printMask(IPv4Address mask) {
    // Initialize the string to store the dotted-decimal notation
    char dottedDecimal[16];

    // Convert the mask to dotted-decimal notation
    sprintf(dottedDecimal, "%d.%d.%d.%d",
            (mask.mask >> 24) & 0xFF,
            (mask.mask >> 16) & 0xFF,
            (mask.mask >> 8) & 0xFF,
            mask.mask & 0xFF);

    // Print the dotted-decimal notation
    printf("%s", dottedDecimal);
}

// Calculate the network address
IPv4Address calculateNetworkAddress(IPv4Address address, IPv4Address mask) {
    // Initialize the network address
    IPv4Address networkAddress;

    // Perform the bitwise AND operation between the address and the mask
    networkAddress.address = address.address & mask.mask;

    // Return the network address
    return networkAddress;
}

// Calculate the broadcast address
IPv4Address calculateBroadcastAddress(IPv4Address address, IPv4Address mask) {
    // Initialize the broadcast address
    IPv4Address broadcastAddress;

    // Perform the bitwise OR operation between the address and the inverted mask
    broadcastAddress.address = address.address | ~mask.mask;

    // Return the broadcast address
    return broadcastAddress;
}

// Calculate the number of hosts in the subnet
unsigned int calculateNumberOfHosts(IPv4Address mask) {
    // Calculate the number of bits in the mask
    unsigned int numberOfBits = 0;
    for (unsigned int i = 0; i < MAX_BITS; i++) {
        if ((mask.mask >> i) & 1) {
            numberOfBits++;
        }
    }

    // Calculate the number of hosts in the subnet
    unsigned int numberOfHosts = pow(2, MAX_BITS - numberOfBits) - 2;

    // Return the number of hosts
    return numberOfHosts;
}

// Print the subnet information
void printSubnetInformation(IPv4Address address, IPv4Address mask) {
    // Calculate the network address
    IPv4Address networkAddress = calculateNetworkAddress(address, mask);

    // Calculate the broadcast address
    IPv4Address broadcastAddress = calculateBroadcastAddress(address, mask);

    // Calculate the number of hosts in the subnet
    unsigned int numberOfHosts = calculateNumberOfHosts(mask);

    // Print the subnet information
    printf("Network address: ");
    printAddress(networkAddress);
    printf("\n");
    printf("Broadcast address: ");
    printAddress(broadcastAddress);
    printf("\n");
    printf("Number of hosts: %u\n", numberOfHosts);
}

// Main function
int main() {
    // Initialize the IPv4 address
    IPv4Address address;

    // Get the IPv4 address from the user
    printf("Enter the IPv4 address: ");
    scanf("%s", address.address);

    // Initialize the IPv4 mask
    IPv4Address mask;

    // Get the IPv4 mask from the user
    printf("Enter the IPv4 mask: ");
    scanf("%s", mask.mask);

    // Print the subnet information
    printSubnetInformation(address, mask);

    return 0;
}