//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of bits in an IPv4 address
#define MAX_BITS 32

// Define the structure of an IPv4 address
typedef struct {
    unsigned char octets[4];
} IPv4Address;

// Define the structure of a subnet mask
typedef struct {
    unsigned char octets[4];
} SubnetMask;

// Define the structure of a subnet calculation result
typedef struct {
    IPv4Address networkAddress;
    IPv4Address broadcastAddress;
    unsigned int numHosts;
} SubnetCalculationResult;

// Function to convert an IPv4 address string to an IPv4 address structure
IPv4Address stringToIPv4Address(char *str) {
    IPv4Address address;
    int i;

    // Split the string into four octets
    char *octets[4];
    char *ptr = strtok(str, ".");
    for (i = 0; i < 4; i++) {
        octets[i] = ptr;
        ptr = strtok(NULL, ".");
    }

    // Convert each octet to an integer
    for (i = 0; i < 4; i++) {
        address.octets[i] = atoi(octets[i]);
    }

    // Return the IPv4 address structure
    return address;
}

// Function to convert a subnet mask string to a subnet mask structure
SubnetMask stringToSubnetMask(char *str) {
    SubnetMask mask;
    int i;

    // Split the string into four octets
    char *octets[4];
    char *ptr = strtok(str, ".");
    for (i = 0; i < 4; i++) {
        octets[i] = ptr;
        ptr = strtok(NULL, ".");
    }

    // Convert each octet to an integer
    for (i = 0; i < 4; i++) {
        mask.octets[i] = atoi(octets[i]);
    }

    // Return the subnet mask structure
    return mask;
}

// Function to calculate the network address of a subnet
IPv4Address calculateNetworkAddress(IPv4Address address, SubnetMask mask) {
    IPv4Address networkAddress;
    int i;

    // Perform a bitwise AND operation between the address and the mask
    for (i = 0; i < 4; i++) {
        networkAddress.octets[i] = address.octets[i] & mask.octets[i];
    }

    // Return the network address
    return networkAddress;
}

// Function to calculate the broadcast address of a subnet
IPv4Address calculateBroadcastAddress(IPv4Address networkAddress, SubnetMask mask) {
    IPv4Address broadcastAddress;
    int i;

    // Perform a bitwise OR operation between the network address and the inverse of the mask
    for (i = 0; i < 4; i++) {
        broadcastAddress.octets[i] = networkAddress.octets[i] | ~mask.octets[i];
    }

    // Return the broadcast address
    return broadcastAddress;
}

// Function to calculate the number of hosts in a subnet
unsigned int calculateNumHosts(SubnetMask mask) {
    // Count the number of 1 bits in the mask
    unsigned int numOnes = 0;
    int i;
    for (i = 0; i < 4; i++) {
        numOnes += __builtin_popcount(mask.octets[i]);
    }

    // Calculate the number of hosts
    unsigned int numHosts = pow(2, MAX_BITS - numOnes) - 2;

    // Return the number of hosts
    return numHosts;
}

// Function to print the subnet calculation result
void printSubnetCalculationResult(SubnetCalculationResult result) {
    printf("Network address: %d.%d.%d.%d\n", result.networkAddress.octets[0], result.networkAddress.octets[1], result.networkAddress.octets[2], result.networkAddress.octets[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", result.broadcastAddress.octets[0], result.broadcastAddress.octets[1], result.broadcastAddress.octets[2], result.broadcastAddress.octets[3]);
    printf("Number of hosts: %u\n", result.numHosts);
}

// Main function
int main() {
    // Get the IPv4 address and subnet mask from the user
    char ipAddressStr[16];
    char subnetMaskStr[16];
    printf("Enter the IPv4 address: ");
    scanf("%s", ipAddressStr);
    printf("Enter the subnet mask: ");
    scanf("%s", subnetMaskStr);

    // Convert the IPv4 address and subnet mask strings to structures
    IPv4Address ipAddress = stringToIPv4Address(ipAddressStr);
    SubnetMask subnetMask = stringToSubnetMask(subnetMaskStr);

    // Calculate the network address, broadcast address, and number of hosts
    SubnetCalculationResult result;
    result.networkAddress = calculateNetworkAddress(ipAddress, subnetMask);
    result.broadcastAddress = calculateBroadcastAddress(result.networkAddress, subnetMask);
    result.numHosts = calculateNumHosts(subnetMask);

    // Print the subnet calculation result
    printSubnetCalculationResult(result);

    return 0;
}