//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 256

// Function to calculate subnet details recursively
void calculateSubnets(unsigned char network[], unsigned char subnetMask[], int subnetCount, int currentSubnet) {
    if (currentSubnet >= subnetCount) return;

    unsigned char subnet[MAX_SUBNETS];
    unsigned char broadcast[MAX_SUBNETS];

    // Calculate the network address of the current subnet
    for (int i = 0; i < 4; i++) {
        subnet[i] = network[i] + (currentSubnet * (~subnetMask[i] + 1));  //calculate the subnet
        broadcast[i] = subnet[i] | ~subnetMask[i]; //calculate the broadcast address
    }

    printf("Subnet %d: ", currentSubnet + 1);
    for (int i = 0; i < 4; i++) {
        printf("%d", subnet[i]);
        if (i < 3) printf(".");
    }
    printf(" - Broadcast: ");
    for (int i = 0; i < 4; i++) {
        printf("%d", broadcast[i]);
        if (i < 3) printf(".");
    }
    printf("\n");

    // Recursive call for the next subnet
    calculateSubnets(network, subnetMask, subnetCount, currentSubnet + 1);
}

// Function to validate the IP address and subnet mask
int isValidIp(unsigned char ip[]) {
    for (int i = 0; i < 4; i++) {
        if (ip[i] > 255) {
            return 0; // Invalid IP
        }
    }
    return 1; // Valid IP
}

// Function to parse the IP address from a string to an array
void parseIp(const char *ipStr, unsigned char ip[]) {
    sscanf(ipStr, "%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);
}

// Function to calculate number of subnets based on a subnet mask
int calculateSubnetCount(unsigned char subnetMask[]) {
    int count = 1; // At least one subnet
    for (int i = 0; i < 4; i++) {
        count <<= 1; // Each bit in the mask can double the subnets
        if (subnetMask[i] == 255) {
            count = count >> 1; // Don't count this byte
        }
    }
    return count;
}

int main() {
    char networkStr[16];
    char subnetMaskStr[16];
    unsigned char network[4], subnetMask[4];

    // User Input
    printf("Enter the Network Address (eg. 192.168.1.0): ");
    fgets(networkStr, sizeof(networkStr), stdin);
    parseIp(networkStr, network);

    printf("Enter the Subnet Mask (eg. 255.255.255.0): ");
    fgets(subnetMaskStr, sizeof(subnetMaskStr), stdin);
    parseIp(subnetMaskStr, subnetMask);

    // Validate IP addresses
    if (!isValidIp(network) || !isValidIp(subnetMask)) {
        printf("Invalid network address or subnet mask. Please enter valid IPv4 addresses.\n");
        return 1;
    }

    // Calculate number of subnets
    int subnetCount = calculateSubnetCount(subnetMask);

    // Calculate and display subnets
    printf("\nCalculating Subnets...\n");
    calculateSubnets(network, subnetMask, subnetCount, 0);

    return 0;
}