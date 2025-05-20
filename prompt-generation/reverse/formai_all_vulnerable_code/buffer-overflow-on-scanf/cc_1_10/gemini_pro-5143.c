//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of bits in an IPv4 address
#define MAX_BITS 32

// Define the structure of an IPv4 address
typedef struct {
    unsigned int octets[4];
} IPv4Address;

// Define the structure of a subnet mask
typedef struct {
    unsigned int bits;
} SubnetMask;

// Define the structure of a subnet calculator result
typedef struct {
    IPv4Address networkAddress;
    IPv4Address broadcastAddress;
    unsigned int numberOfHosts;
} SubnetCalculatorResult;

// Function to convert an IPv4 address from dotted-decimal notation to binary
void convertIPv4AddressToBinary(IPv4Address *address, char *dottedDecimalNotation) {
    // Split the dotted-decimal notation into four octets
    char *octets[4];
    int i;
    for (i = 0; i < 4; i++) {
        octets[i] = strtok(dottedDecimalNotation, ".");
        if (octets[i] == NULL) {
            printf("Invalid IPv4 address: %s\n", dottedDecimalNotation);
            exit(EXIT_FAILURE);
        }
    }

    // Convert each octet to binary
    for (i = 0; i < 4; i++) {
        address->octets[i] = atoi(octets[i]);
    }
}

// Function to convert a subnet mask from dotted-decimal notation to binary
void convertSubnetMaskToBinary(SubnetMask *mask, char *dottedDecimalNotation) {
    // Split the dotted-decimal notation into four octets
    char *octets[4];
    int i;
    for (i = 0; i < 4; i++) {
        octets[i] = strtok(dottedDecimalNotation, ".");
        if (octets[i] == NULL) {
            printf("Invalid subnet mask: %s\n", dottedDecimalNotation);
            exit(EXIT_FAILURE);
        }
    }

    // Convert each octet to binary
    for (i = 0; i < 4; i++) {
        mask->bits |= atoi(octets[i]) << (24 - (i * 8));
    }
}

// Function to calculate the network address
void calculateNetworkAddress(IPv4Address *networkAddress, IPv4Address *ipAddress, SubnetMask *mask) {
    // Perform bitwise AND operation between the IP address and the subnet mask
    int i;
    for (i = 0; i < 4; i++) {
        networkAddress->octets[i] = ipAddress->octets[i] & mask->bits;
    }
}

// Function to calculate the broadcast address
void calculateBroadcastAddress(IPv4Address *broadcastAddress, IPv4Address *networkAddress, SubnetMask *mask) {
    // Perform bitwise OR operation between the network address and the inverse of the subnet mask
    int i;
    for (i = 0; i < 4; i++) {
        broadcastAddress->octets[i] = networkAddress->octets[i] | ~mask->bits;
    }
}

// Function to calculate the number of hosts
unsigned int calculateNumberOfHosts(SubnetMask *mask) {
    // Return 2^(32 - mask->bits) - 2
    return (unsigned int)(pow(2, (32 - mask->bits)) - 2);
}

// Function to print the subnet calculator result
void printSubnetCalculatorResult(SubnetCalculatorResult *result) {
    // Print the network address
    printf("Network Address: %u.%u.%u.%u\n", result->networkAddress.octets[0], result->networkAddress.octets[1], result->networkAddress.octets[2], result->networkAddress.octets[3]);

    // Print the broadcast address
    printf("Broadcast Address: %u.%u.%u.%u\n", result->broadcastAddress.octets[0], result->broadcastAddress.octets[1], result->broadcastAddress.octets[2], result->broadcastAddress.octets[3]);

    // Print the number of hosts
    printf("Number of Hosts: %u\n", result->numberOfHosts);
}

int main() {
    // Get the IP address from the user
    char ipAddress[MAX_BITS];
    printf("Enter the IP address: ");
    scanf("%s", ipAddress);

    // Get the subnet mask from the user
    char subnetMask[MAX_BITS];
    printf("Enter the subnet mask: ");
    scanf("%s", subnetMask);

    // Convert the IP address and subnet mask to binary
    IPv4Address ipAddressBinary;
    convertIPv4AddressToBinary(&ipAddressBinary, ipAddress);

    SubnetMask subnetMaskBinary;
    convertSubnetMaskToBinary(&subnetMaskBinary, subnetMask);

    // Calculate the network address, broadcast address, and number of hosts
    SubnetCalculatorResult result;
    calculateNetworkAddress(&result.networkAddress, &ipAddressBinary, &subnetMaskBinary);
    calculateBroadcastAddress(&result.broadcastAddress, &result.networkAddress, &subnetMaskBinary);
    result.numberOfHosts = calculateNumberOfHosts(&subnetMaskBinary);

    // Print the subnet calculator result
    printSubnetCalculatorResult(&result);

    return 0;
}