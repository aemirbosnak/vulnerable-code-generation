//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <errno.h>

// Structure to hold subnet information
typedef struct {
    char ip[INET_ADDRSTRLEN];
    char subnet_mask[INET_ADDRSTRLEN];
    char network[INET_ADDRSTRLEN];
    char broadcast[INET_ADDRSTRLEN];
    unsigned int hosts;
    unsigned int valid_hosts;
} Subnet;

// Function to calculate the total number of hosts in a subnet
unsigned int calculate_hosts(int cidr) {
    return (1 << (32 - cidr)) - 2; // Subtract 2 for network and broadcast addresses
}

// Function to perform subnet calculations
void calculate_subnet(Subnet *subnet) {
    struct in_addr ip_addr, netmask_addr, network_addr, broadcast_addr;

    // Convert IP and subnet mask to binary
    if (inet_pton(AF_INET, subnet->ip, &ip_addr) != 1) {
        perror("Invalid IP address");
        exit(EXIT_FAILURE);
    }

    if (inet_pton(AF_INET, subnet->subnet_mask, &netmask_addr) != 1) {
        perror("Invalid subnet mask");
        exit(EXIT_FAILURE);
    }

    // Calculate network address
    network_addr.s_addr = ip_addr.s_addr & netmask_addr.s_addr;
    
    // Calculate broadcast address
    broadcast_addr.s_addr = network_addr.s_addr | ~netmask_addr.s_addr;

    // Convert back to string
    inet_ntop(AF_INET, &network_addr, subnet->network, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &broadcast_addr, subnet->broadcast, INET_ADDRSTRLEN);

    // Calculate total and valid hosts
    unsigned int cidr = 0;
    for (int i = 0; i < 32; i++) {
        if ((netmask_addr.s_addr & (1 << (31 - i))) != 0)
            cidr++;
    }

    subnet->hosts = calculate_hosts(cidr);
    subnet->valid_hosts = subnet->hosts - 2; // Valid hosts are hosts minus network and broadcast
}

// Function to display subnet information
void display_subnet_info(Subnet subnet) {
    printf("\n=== Subnet Information ===\n");
    printf("IP Address        : %s\n", subnet.ip);
    printf("Subnet Mask       : %s\n", subnet.subnet_mask);
    printf("Network Address    : %s\n", subnet.network);
    printf("Broadcast Address   : %s\n", subnet.broadcast);
    printf("Total Hosts       : %u\n", subnet.hosts);
    printf("Valid Hosts       : %u\n", subnet.valid_hosts);
    printf("=========================\n");
}

// Main function
int main() {
    Subnet subnet;

    printf("Welcome to the Mind-Bending C Subnet Calculator!\n");
    printf("Please enter the IP address (e.g., 192.168.1.1): ");
    fgets(subnet.ip, sizeof(subnet.ip), stdin);
    subnet.ip[strcspn(subnet.ip, "\n")] = 0; // Remove newline character

    printf("Please enter the subnet mask (e.g., 255.255.255.0): ");
    fgets(subnet.subnet_mask, sizeof(subnet.subnet_mask), stdin);
    subnet.subnet_mask[strcspn(subnet.subnet_mask, "\n")] = 0; // Remove newline character

    // Calculate subnet information
    calculate_subnet(&subnet);

    // Display the results
    display_subnet_info(subnet);

    return 0;
}