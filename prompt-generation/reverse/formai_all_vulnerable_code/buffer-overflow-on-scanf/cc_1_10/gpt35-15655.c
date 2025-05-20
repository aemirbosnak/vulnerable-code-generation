//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subnet_info {
    char *subnet_mask_str;
    unsigned long subnet_mask;
    unsigned long network_addr;
    unsigned long broadcast_addr;
    unsigned long num_hosts;
};

void determine_subnet_mask(struct subnet_info *subnet) {
    int cidr_bits = 0;
    unsigned long subnet_mask = 0;

    printf("Enter the number of CIDR bits in the subnet mask: ");
    scanf("%d", &cidr_bits);

    // Calculate the binary representation of the subnet mask
    for (int i = 0; i < cidr_bits; i++) {
        subnet_mask |= 1UL << (31 - i);
    }

    subnet->subnet_mask = subnet_mask;
    subnet->subnet_mask_str = (char*) malloc(16);
    sprintf(subnet->subnet_mask_str, "%d.%d.%d.%d",
            (subnet_mask >> 24) & 0xFF, (subnet_mask >> 16) & 0xFF,
            (subnet_mask >> 8) & 0xFF, subnet_mask & 0xFF);

    printf("Subnet mask: %s\n", subnet->subnet_mask_str);
}

void determine_network_addr(struct subnet_info *subnet) {
    printf("Enter the network address in dotted decimal notation: ");
    scanf("%lu", &subnet->network_addr);
    subnet->network_addr &= subnet->subnet_mask;
    printf("Network address: %lu\n", subnet->network_addr);
}

void determine_broadcast_addr(struct subnet_info *subnet) {
    unsigned long broadcast_addr = subnet->network_addr;

    // Calculate the binary representation of the network ID
    for (int i = 0; i < 32; i++) {
        if ((subnet->subnet_mask >> i) & 1) {
            broadcast_addr |= 1UL << i;
        }
    }

    subnet->broadcast_addr = broadcast_addr;
    printf("Broadcast address: %lu\n", subnet->broadcast_addr);
}

void determine_num_hosts(struct subnet_info *subnet) {
    unsigned long num_bits_for_host = 32; // Start with all bits reserved for host ID
    unsigned long temp_mask = subnet->subnet_mask;

    // Determine the number of 0 bits in the subnet mask, which determines the number of bits available for host IDs
    while (temp_mask & 1) {
        num_bits_for_host--;
        temp_mask >>= 1;
    }

    // Subtract two for the network and broadcast addresses
    subnet->num_hosts = (1UL << num_bits_for_host) - 2;

    printf("Number of hosts: %lu\n", subnet->num_hosts);
}

int main() {
    struct subnet_info subnet;
    memset(&subnet, 0, sizeof(struct subnet_info));

    determine_subnet_mask(&subnet);
    determine_network_addr(&subnet);
    determine_broadcast_addr(&subnet);
    determine_num_hosts(&subnet);

    free(subnet.subnet_mask_str);

    return 0;
}