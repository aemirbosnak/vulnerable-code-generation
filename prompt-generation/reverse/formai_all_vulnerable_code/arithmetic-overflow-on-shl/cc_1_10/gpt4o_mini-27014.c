//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// A structure to hold subnet information
typedef struct {
    char ip[16];      // To hold the IPv4 address as a string
    char subnet[16];  // To hold the subnet mask as a string
    char network[16]; // To hold the network address as a string
    char broadcast[16]; // To hold the broadcast address as a string
    int hosts;        // To hold the total number of hosts
} SubnetInfo;

// Function to calculate the network address
void calculateNetworkAddress(SubnetInfo* subnetInfo) {
    struct in_addr ip_addr, subnet_addr, network_addr;
    inet_pton(AF_INET, subnetInfo->ip, &ip_addr);
    inet_pton(AF_INET, subnetInfo->subnet, &subnet_addr);
    
    network_addr.s_addr = ip_addr.s_addr & subnet_addr.s_addr;
    inet_ntop(AF_INET, &network_addr, subnetInfo->network, sizeof(subnetInfo->network));
}

// Function to calculate the broadcast address
void calculateBroadcastAddress(SubnetInfo* subnetInfo) {
    struct in_addr ip_addr, subnet_addr, broadcast_addr;
    inet_pton(AF_INET, subnetInfo->ip, &ip_addr);
    inet_pton(AF_INET, subnetInfo->subnet, &subnet_addr);
    
    broadcast_addr.s_addr = (ip_addr.s_addr & subnet_addr.s_addr) | ~subnet_addr.s_addr;
    inet_ntop(AF_INET, &broadcast_addr, subnetInfo->broadcast, sizeof(subnetInfo->broadcast));
}

// Function to calculate the number of hosts in the subnet
void calculateHosts(SubnetInfo* subnetInfo) {
    // Convert subnet mask to CIDR notation
    uint32_t mask;
    inet_pton(AF_INET, subnetInfo->subnet, &mask);
    
    int count = 0;
    while (mask > 0) {
        mask &= (mask - 1);
        count++;
    }

    subnetInfo->hosts = (1 << (32 - count)) - 2; // Total hosts = 2^(32 - bits) - 2 (for network and broadcast)
}

// Function to display the subnet info
void displaySubnetInfo(const SubnetInfo* subnetInfo) {
    printf("\n");
    printf("Wow! Here are the details of your subnetwork:\n");
    printf(" - IP Address: %s\n", subnetInfo->ip);
    printf(" - Subnet Mask: %s\n", subnetInfo->subnet);
    printf(" - Network Address: %s\n", subnetInfo->network);
    printf(" - Broadcast Address: %s\n", subnetInfo->broadcast);
    printf(" - Total Hosts: %d\n", subnetInfo->hosts);
}

// Main Function
int main() {
    SubnetInfo subnetInfo;

    printf("🚀 Surprise! Let's calculate your subnet details! 🚀\n");
    
    // Input IP Address
    printf("Enter an IP Address (e.g., 192.168.1.1): ");
    fgets(subnetInfo.ip, sizeof(subnetInfo.ip), stdin);
    strtok(subnetInfo.ip, "\n"); // Remove newline character

    // Input Subnet Mask
    printf("Enter a Subnet Mask (e.g., 255.255.255.0): ");
    fgets(subnetInfo.subnet, sizeof(subnetInfo.subnet), stdin);
    strtok(subnetInfo.subnet, "\n"); // Remove newline character

    // Calculate Network Address
    calculateNetworkAddress(&subnetInfo);

    // Calculate Broadcast Address
    calculateBroadcastAddress(&subnetInfo);

    // Calculate Total Hosts
    calculateHosts(&subnetInfo);

    // Display the subnet information
    displaySubnetInfo(&subnetInfo);
    
    return 0;
}