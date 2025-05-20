//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function to calculate the subnet mask based on CIDR notation
void calculateSubnetMask(int cidr, char *subnetMask) {
    unsigned int mask = 0xFFFFFFFF << (32 - cidr);
    snprintf(subnetMask, 16, "%d.%d.%d.%d",
             (mask >> 24) & 0xFF,
             (mask >> 16) & 0xFF,
             (mask >> 8) & 0xFF,
             mask & 0xFF);
}

// Function to calculate the network address
void calculateNetworkAddress(const char *ip, const char *subnetMask, char *networkAddress) {
    struct in_addr ipAddr, maskAddr, netAddr;
    
    inet_pton(AF_INET, ip, &ipAddr);
    inet_pton(AF_INET, subnetMask, &maskAddr);

    netAddr.s_addr = ipAddr.s_addr & maskAddr.s_addr;
    inet_ntop(AF_INET, &netAddr, networkAddress, INET_ADDRSTRLEN);
}

// Function to calculate the broadcast address
void calculateBroadcastAddress(const char *ip, const char *subnetMask, char *broadcastAddress) {
    struct in_addr ipAddr, maskAddr, netAddr;

    inet_pton(AF_INET, ip, &ipAddr);
    inet_pton(AF_INET, subnetMask, &maskAddr);

    netAddr.s_addr = (ipAddr.s_addr & maskAddr.s_addr) | ~maskAddr.s_addr;
    inet_ntop(AF_INET, &netAddr, broadcastAddress, INET_ADDRSTRLEN);
}

// Main function to display a gentle interface for subnet calculations
int main() {
    char ip[INET_ADDRSTRLEN];
    char subnetMask[INET_ADDRSTRLEN];
    char networkAddress[INET_ADDRSTRLEN];
    char broadcastAddress[INET_ADDRSTRLEN];
    int cidr;

    printf("Welcome to the Peaceful Subnet Calculator\n");
    printf("Please enter an IP address (e.g., 192.168.1.1): ");
    scanf("%s", ip);

    printf("Please enter the CIDR notation (e.g., 24): ");
    scanf("%d", &cidr);

    // Calculate the subnet mask from CIDR
    calculateSubnetMask(cidr, subnetMask);
    printf("The calculated subnet mask is: %s\n", subnetMask);

    // Calculate network address
    calculateNetworkAddress(ip, subnetMask, networkAddress);
    printf("The calculated network address is: %s\n", networkAddress);

    // Calculate broadcast address
    calculateBroadcastAddress(ip, subnetMask, broadcastAddress);
    printf("The calculated broadcast address is: %s\n", broadcastAddress);

    printf("Thank you for using the Peaceful Subnet Calculator. May your networks be harmonious!\n");
    return 0;
}