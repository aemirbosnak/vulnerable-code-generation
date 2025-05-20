//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function to calculate subnet mask from CIDR notation
void calculateSubnetMask(int cidr, char *subnetMask) {
    int mask = 0xFFFFFFFF << (32 - cidr);
    sprintf(subnetMask, "%d.%d.%d.%d", 
            (mask >> 24) & 0xFF, 
            (mask >> 16) & 0xFF, 
            (mask >> 8) & 0xFF, 
            mask & 0xFF);
}

// Function to calculate network address
void calculateNetworkAddress(const char *ipAddress, const char *subnetMask, char *networkAddress) {
    struct in_addr ip, mask;
    inet_aton(ipAddress, &ip);
    inet_aton(subnetMask, &mask);
    
    struct in_addr network;
    network.s_addr = ip.s_addr & mask.s_addr;
    sprintf(networkAddress, "%s", inet_ntoa(network));
}

// Function to calculate broadcast address
void calculateBroadcastAddress(const char *ipAddress, const char *subnetMask, char *broadcastAddress) {
    struct in_addr ip, mask;
    inet_aton(ipAddress, &ip);
    inet_aton(subnetMask, &mask);
    
    struct in_addr broadcast;
    broadcast.s_addr = (ip.s_addr & mask.s_addr) | ~mask.s_addr;
    sprintf(broadcastAddress, "%s", inet_ntoa(broadcast));
}

// Function to calculate number of usable IPs
int calculateUsableIPs(int cidr) {
    return (1 << (32 - cidr)) - 2; // Exclude network and broadcast addresses
}

// Function to validate IP address format
int validateIPAddress(const char *ipAddress) {
    struct in_addr addr;
    return inet_aton(ipAddress, &addr);
}

// Function to validate CIDR notation
int validateCIDR(int cidr) {
    return cidr >= 0 && cidr <= 32;
}

int main() {
    char ipAddress[16];
    int cidr;
    char subnetMask[16], networkAddress[16], broadcastAddress[16];

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter an IPv4 address: ");
    fgets(ipAddress, sizeof(ipAddress), stdin);
    ipAddress[strcspn(ipAddress, "\n")] = 0;  // Remove newline character

    if (!validateIPAddress(ipAddress)) {
        fprintf(stderr, "Error: Invalid IP address format.\n");
        return 1;
    }

    printf("Please enter CIDR notation (0-32): ");
    scanf("%d", &cidr);

    if (!validateCIDR(cidr)) {
        fprintf(stderr, "Error: CIDR must be between 0 and 32.\n");
        return 1;
    }

    // Calculate subnet mask
    calculateSubnetMask(cidr, subnetMask);
    
    // Calculate network and broadcast address
    calculateNetworkAddress(ipAddress, subnetMask, networkAddress);
    calculateBroadcastAddress(ipAddress, subnetMask, broadcastAddress);

    // Number of usable IPs
    int usableIPs = calculateUsableIPs(cidr);
    
    // Display results
    printf("\nSubnet Calculator Results:\n");
    printf("IP Address: %s\n", ipAddress);
    printf("CIDR: /%d\n", cidr);
    printf("Subnet Mask: %s\n", subnetMask);
    printf("Network Address: %s\n", networkAddress);
    printf("Broadcast Address: %s\n", broadcastAddress);
    printf("Usable IP Addresses: %d\n", usableIPs);

    return 0;
}