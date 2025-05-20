//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function to calculate network address and broadcast address
void calculateSubnet(const char *ip, const char *subnetMask, char *networkAddr, char *broadcastAddr) {
    struct in_addr ipAddr, maskAddr, netAddr, bcastAddr;

    // Convert IP and subnet mask from string to in_addr struct
    inet_pton(AF_INET, ip, &ipAddr);
    inet_pton(AF_INET, subnetMask, &maskAddr);

    // Calculate network address
    netAddr.s_addr = ipAddr.s_addr & maskAddr.s_addr;
    inet_ntop(AF_INET, &netAddr, networkAddr, INET_ADDRSTRLEN);

    // Calculate broadcast address
    bcastAddr.s_addr = netAddr.s_addr | ~maskAddr.s_addr;
    inet_ntop(AF_INET, &bcastAddr, broadcastAddr, INET_ADDRSTRLEN);
}

// Function to count usable addresses
int countUsableAddresses(const char *subnetMask) {
    int maskBits = 0;
    unsigned long mask = inet_addr(subnetMask);

    // Count the number of bits in the mask
    while (mask) {
        mask &= (mask - 1);
        maskBits++;
    }
    // Calculate the number of usable addresses (2^(32 - maskBits) - 2)
    return (1 << (32 - maskBits)) - 2;
}

// Function to validate the IP address and subnet mask
int validateInput(const char *ip, const char *subnetMask) {
    struct in_addr addr;
    if (inet_pton(AF_INET, ip, &addr) != 1) {
        printf("Invalid IP address format.\n");
        return 0;
    }
    if (inet_pton(AF_INET, subnetMask, &addr) != 1) {
        printf("Invalid subnet mask format.\n");
        return 0;
    }
    return 1;
}

int main() {
    char ip[INET_ADDRSTRLEN];
    char subnetMask[INET_ADDRSTRLEN];
    char networkAddr[INET_ADDRSTRLEN];
    char broadcastAddr[INET_ADDRSTRLEN];

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter the IP address (in IPv4 format): ");
    scanf("%s", ip);
    printf("Please enter the subnet mask (in IPv4 format): ");
    scanf("%s", subnetMask);

    // Validate input
    if (!validateInput(ip, subnetMask)) {
        return EXIT_FAILURE;
    }

    // Calculate network and broadcast addresses
    calculateSubnet(ip, subnetMask, networkAddr, broadcastAddr);

    // Print results
    printf("\nResults:\n");
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", subnetMask);
    printf("Network Address: %s\n", networkAddr);
    printf("Broadcast Address: %s\n", broadcastAddr);
    printf("Usable IP Addresses: %d\n", countUsableAddresses(subnetMask));

    return EXIT_SUCCESS;
}