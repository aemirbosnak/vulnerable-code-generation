//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void calculateSubnet(unsigned int ip, unsigned int mask) {
    unsigned int networkAddress = ip & mask;
    unsigned int broadcastAddress = networkAddress | ~mask;
    unsigned int totalHosts = (1 << (32 - __builtin_popcount(mask))) - 2; // 2 for network and broadcast

    printf("Network Address: %u.%u.%u.%u\n", 
            (networkAddress >> 24) & 0xFF, 
            (networkAddress >> 16) & 0xFF, 
            (networkAddress >> 8) & 0xFF, 
            networkAddress & 0xFF);
    
    printf("Broadcast Address: %u.%u.%u.%u\n", 
            (broadcastAddress >> 24) & 0xFF, 
            (broadcastAddress >> 16) & 0xFF, 
            (broadcastAddress >> 8) & 0xFF, 
            broadcastAddress & 0xFF);
    
    printf("Usable Hosts: %u\n", totalHosts);
}

unsigned int convertToBinary(char *ipAddress) {
    struct in_addr ip;
    if (inet_pton(AF_INET, ipAddress, &ip) != 1) {
        fprintf(stderr, "Invalid IP address format.\n");
        exit(EXIT_FAILURE);
    }
    return ntohl(ip.s_addr);
}

unsigned int convertSubnetMask(char *subnetMask) {
    if (strchr(subnetMask, '.')) {
        // If the input is in decimal format
        return convertToBinary(subnetMask);
    } else {
        // If the input is in CIDR format
        int prefixLength = atoi(subnetMask);
        if (prefixLength < 0 || prefixLength > 32) {
            fprintf(stderr, "Invalid subnet mask length. Must be between 0 and 32.\n");
            exit(EXIT_FAILURE);
        }
        return htonl(~((1 << (32 - prefixLength)) - 1));
    }
}

int main() {
    char ipAddress[16];
    char subnetMask[16];

    printf("Welcome to the Dynamic Subnet Calculator!\n");
    printf("Please enter an IP address (e.g. 192.168.0.1): ");
    fgets(ipAddress, sizeof(ipAddress), stdin);
    ipAddress[strcspn(ipAddress, "\n")] = 0; // Remove newline

    printf("Please enter a subnet mask (either CIDR e.g. 24 or decimal e.g. 255.255.255.0): ");
    fgets(subnetMask, sizeof(subnetMask), stdin);
    subnetMask[strcspn(subnetMask, "\n")] = 0; // Remove newline

    unsigned int ip = convertToBinary(ipAddress);
    unsigned int mask = convertSubnetMask(subnetMask);

    printf("\nCalculating subnet information...\n\n");
    calculateSubnet(ip, mask);

    return 0;
}