//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct subnet_info {
    unsigned int ip_address;
    unsigned int subnet_mask;
    unsigned int network_address;
    unsigned int broadcast_address;
    unsigned int number_of_hosts;
    unsigned int number_of_subnets;
};

void calculate_subnet_info(struct subnet_info *info, unsigned int ip_address, unsigned int subnet_mask) {
    info->ip_address = ip_address;
    info->subnet_mask = subnet_mask;

    // Calculate the network address
    info->network_address = ip_address & subnet_mask;

    // Calculate the broadcast address
    info->broadcast_address = ip_address | ~subnet_mask;

    // Calculate the number of hosts
    info->number_of_hosts = pow(2, 32 - count_bits(subnet_mask)) - 2;

    // Calculate the number of subnets
    info->number_of_subnets = pow(2, count_bits(subnet_mask));
}

int count_bits(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void print_subnet_info(struct subnet_info *info) {
    printf("IP Address: %u\n", info->ip_address);
    printf("Subnet Mask: %u\n", info->subnet_mask);
    printf("Network Address: %u\n", info->network_address);
    printf("Broadcast Address: %u\n", info->broadcast_address);
    printf("Number of Hosts: %u\n", info->number_of_hosts);
    printf("Number of Subnets: %u\n", info->number_of_subnets);
}

int main() {
    // Define the IP address and subnet mask
    unsigned int ip_address = 192 << 24 | 168 << 16 | 0 << 8 | 1;
    unsigned int subnet_mask = 255 << 24 | 255 << 16 | 255 << 8 | 0;

    // Calculate the subnet information
    struct subnet_info info;
    calculate_subnet_info(&info, ip_address, subnet_mask);

    // Print the subnet information
    print_subnet_info(&info);

    return 0;
}