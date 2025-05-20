//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to hold subnet information
typedef struct subnet_info {
    unsigned int subnet_mask;
    unsigned int prefix_length;
    unsigned int num_hosts;
    unsigned int num_subnets;
    unsigned int first_host;
    unsigned int last_host;
    unsigned int broadcast_address;
} subnet_info;

// Function to calculate subnet information
subnet_info calculate_subnet(unsigned int ip_address, unsigned int subnet_mask) {
    subnet_info info;

    // Calculate prefix length
    info.prefix_length = 0;
    for (int i = 0; i < 32; i++) {
        if (subnet_mask & (1 << i)) {
            info.prefix_length++;
        }
    }

    // Calculate number of hosts
    info.num_hosts = (1 << (32 - info.prefix_length)) - 2;

    // Calculate number of subnets
    info.num_subnets = (1 << (info.prefix_length));

    // Calculate first host
    info.first_host = ip_address & subnet_mask;

    // Calculate last host
    info.last_host = info.first_host + info.num_hosts;

    // Calculate broadcast address
    info.broadcast_address = info.first_host + info.num_hosts - 1;

    // Return subnet information
    return info;
}

// Function to print subnet information
void print_subnet_info(subnet_info info) {
    printf("Subnet Information:\n");
    printf("Subnet Mask: %u\n", info.subnet_mask);
    printf("Prefix Length: %u\n", info.prefix_length);
    printf("Number of Hosts: %u\n", info.num_hosts);
    printf("Number of Subnets: %u\n", info.num_subnets);
    printf("First Host: %u.%u.%u.%u\n", (info.first_host >> 24) & 0xFF, (info.first_host >> 16) & 0xFF, (info.first_host >> 8) & 0xFF, (info.first_host) & 0xFF);
    printf("Last Host: %u.%u.%u.%u\n", (info.last_host >> 24) & 0xFF, (info.last_host >> 16) & 0xFF, (info.last_host >> 8) & 0xFF, (info.last_host) & 0xFF);
    printf("Broadcast Address: %u.%u.%u.%u\n", (info.broadcast_address >> 24) & 0xFF, (info.broadcast_address >> 16) & 0xFF, (info.broadcast_address >> 8) & 0xFF, (info.broadcast_address) & 0xFF);
}

// Main function
int main() {
    // Get IP address and subnet mask from user
    unsigned int ip_address, subnet_mask;
    printf("Enter IP address: ");
    scanf("%u", &ip_address);
    printf("Enter subnet mask: ");
    scanf("%u", &subnet_mask);

    // Calculate subnet information
    subnet_info info = calculate_subnet(ip_address, subnet_mask);

    // Print subnet information
    print_subnet_info(info);

    return 0;
}