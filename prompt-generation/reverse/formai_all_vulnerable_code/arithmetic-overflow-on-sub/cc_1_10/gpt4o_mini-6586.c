//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function prototypes
void calculateSubnet(const char *ipAddress, const char *subnetMask);
void printSubnetInfo(const char *ipAddress, const char *subnetMask, const char *networkAddress, const char *broadcastAddress, int hostCount);

int main() {
    char ipAddress[16];
    char subnetMask[16];

    // Welcome message
    printf("Welcome to the C Subnet Calculator!\n");
    printf("This program will help you calculate the subnet, broadcast address, and number of hosts available.\n");
    
    // Prompt for user input
    printf("Enter an IP address (e.g., 192.168.1.1): ");
    fgets(ipAddress, sizeof(ipAddress), stdin);
    ipAddress[strcspn(ipAddress, "\n")] = '\0'; // Remove newline character

    // Validate IP address format
    if (inet_pton(AF_INET, ipAddress, &(struct in_addr){0}) != 1) {
        printf("Invalid IP address format.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the subnet mask (e.g., 255.255.255.0): ");
    fgets(subnetMask, sizeof(subnetMask), stdin);
    subnetMask[strcspn(subnetMask, "\n")] = '\0'; // Remove newline character

    // Validate subnet mask format
    if (inet_pton(AF_INET, subnetMask, &(struct in_addr){0}) != 1) {
        printf("Invalid subnet mask format.\n");
        return EXIT_FAILURE;
    }

    // Calculate subnet information
    calculateSubnet(ipAddress, subnetMask);

    return EXIT_SUCCESS;
}

void calculateSubnet(const char *ipAddress, const char *subnetMask) {
    struct in_addr ip, mask, network, broadcast;
    // Convert IP and subnet mask to in_addr structure
    inet_pton(AF_INET, ipAddress, &ip);
    inet_pton(AF_INET, subnetMask, &mask);

    // Calculate network address
    network.s_addr = ip.s_addr & mask.s_addr;

    // Calculate broadcast address
    broadcast.s_addr = network.s_addr | ~mask.s_addr;

    // Calculate number of hosts
    int maskBits = __builtin_popcount(mask.s_addr);
    int hostCount = (1 << (32 - maskBits)) - 2; // 2 hosts are reserved

    char networkAddress[INET_ADDRSTRLEN];
    char broadcastAddress[INET_ADDRSTRLEN];

    // Convert addresses back to string format
    inet_ntop(AF_INET, &network, networkAddress, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &broadcast, broadcastAddress, INET_ADDRSTRLEN);

    // Print the results
    printSubnetInfo(ipAddress, subnetMask, networkAddress, broadcastAddress, hostCount);
}

void printSubnetInfo(const char *ipAddress, const char *subnetMask, const char *networkAddress, const char *broadcastAddress, int hostCount) {
    printf("\n--- Subnet Information ---\n");
    printf("IP Address: %s\n", ipAddress);
    printf("Subnet Mask: %s\n", subnetMask);
    printf("Network Address: %s\n", networkAddress);
    printf("Broadcast Address: %s\n", broadcastAddress);
    printf("Number of Usable Hosts: %d\n", hostCount);
    printf("---------------------------\n");
}