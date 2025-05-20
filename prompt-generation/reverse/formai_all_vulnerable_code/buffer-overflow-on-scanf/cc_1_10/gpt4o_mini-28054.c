//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

#define MAX_SUBNETS 10

typedef struct {
    char ip[16]; // Store IP address as string
    char subnet_mask[16]; // Store Subnet mask as string
    char network[16]; // Store Network address as string
    char broadcast[16]; // Store Broadcast address as string
    uint32_t total_hosts; // Total usable hosts in the subnet
} Subnet;

void calculate_subnet(Subnet* subnet) {
    struct sockaddr_in sa;
    inet_pton(AF_INET, subnet->ip, &(sa.sin_addr));
    
    // Calculate the network and broadcast addresses
    uint32_t ip_as_int = ntohl(sa.sin_addr.s_addr);
    inet_pton(AF_INET, subnet->subnet_mask, &sa.sin_addr);
    uint32_t mask_as_int = ntohl(sa.sin_addr.s_addr);
    
    subnet->network[0] = '\0';
    subnet->broadcast[0] = '\0';

    // Compute network address
    uint32_t network = ip_as_int & mask_as_int;
    // Compute broadcast address
    uint32_t broadcast = network | ~mask_as_int;

    // Prepare network and broadcast address strings
    sprintf(subnet->network, "%u.%u.%u.%u", (network >> 24) & 0xFF, (network >> 16) & 0xFF, (network >> 8) & 0xFF, network & 0xFF);
    sprintf(subnet->broadcast, "%u.%u.%u.%u", (broadcast >> 24) & 0xFF, (broadcast >> 16) & 0xFF, (broadcast >> 8) & 0xFF, broadcast & 0xFF);
    
    // Calculate total usable hosts (2^(32 - prefix_length) - 2)
    uint8_t prefix_length = 32 - __builtin_popcount(mask_as_int);
    subnet->total_hosts = (1 << prefix_length) - 2; // subtracting network and broadcast addresses
}

int main() {
    Subnet subnets[MAX_SUBNETS];
    int n;

    printf("Welcome to the C Subnet Calculator!\n");
    printf("You can enter up to %d subnets.\n", MAX_SUBNETS);
    printf("Please enter the number of subnets you wish to calculate: ");
    scanf("%d", &n);

    // Input validation for number of subnets
    if (n <= 0 || n > MAX_SUBNETS) {
        printf("Invalid number of subnets! Please enter a value between 1 and %d.\n", MAX_SUBNETS);
        return 1;
    }

    // Loop to get IP addresses and subnet masks
    for (int i = 0; i < n; i++) {
        printf("Enter IP address (e.g., 192.168.1.1): ");
        scanf("%s", subnets[i].ip);
        printf("Enter Subnet mask (e.g., 255.255.255.0): ");
        scanf("%s", subnets[i].subnet_mask);
        
        // Calculate subnet information
        calculate_subnet(&subnets[i]);
    }

    // Output details of each subnet
    printf("\nSubnet Information:\n");
    for (int i = 0; i < n; i++) {
        printf("\nSubnet %d:\n", i + 1);
        printf("IP Address: %s\n", subnets[i].ip);
        printf("Subnet Mask: %s\n", subnets[i].subnet_mask);
        printf("Network Address: %s\n", subnets[i].network);
        printf("Broadcast Address: %s\n", subnets[i].broadcast);
        printf("Total Usable Hosts: %u\n", subnets[i].total_hosts);
    }
  
    return 0;
}