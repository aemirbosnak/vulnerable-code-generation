//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store subnet information
typedef struct {
    unsigned int ip;
    unsigned int subnet_mask;
    unsigned int network_address;
    unsigned int broadcast_address;
    unsigned int usable_hosts;
} subnet_info;

// Function to calculate subnet information
subnet_info calculate_subnet(unsigned int ip, unsigned int subnet_mask) {
    subnet_info info;

    // Calculate network address
    info.network_address = ip & subnet_mask;

    // Calculate broadcast address
    info.broadcast_address = info.network_address | ~subnet_mask;

    // Calculate usable hosts
    info.usable_hosts = (1 << (32 - count_bits(subnet_mask))) - 2;

    return info;
}

// Function to count the number of bits set in a 32-bit number
int count_bits(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// Function to print subnet information
void print_subnet_info(subnet_info info) {
    printf("IP Address: %u\n", info.ip);
    printf("Subnet Mask: %u\n", info.subnet_mask);
    printf("Network Address: %u\n", info.network_address);
    printf("Broadcast Address: %u\n", info.broadcast_address);
    printf("Usable Hosts: %u\n", info.usable_hosts);
}

// Main function
int main() {
    // Get user input
    unsigned int ip, subnet_mask;
    printf("Enter IP address (in dotted decimal notation): ");
    scanf("%u", &ip);
    printf("Enter subnet mask (in dotted decimal notation): ");
    scanf("%u", &subnet_mask);

    // Calculate subnet information
    subnet_info info = calculate_subnet(ip, subnet_mask);

    // Print subnet information
    print_subnet_info(info);

    return 0;
}