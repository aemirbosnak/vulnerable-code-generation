//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: introspective
/* This is a C Subnet Calculator program. 
   It takes an IPv4 address and subnet mask as input and outputs the network address,
   broadcast address and maximum number of hosts for the given subnet. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip_address[16], subnet_mask[16];
    unsigned int ip, mask, network, broadcast;
    int num_hosts, num_bits;

    // Prompt user for input
    printf("Enter IP address: ");
    scanf("%s", ip_address);

    printf("Enter subnet mask: ");
    scanf("%s", subnet_mask);

    // Parse IP address as unsigned integer
    if (sscanf(ip_address, "%u", &ip) != 1) {
        printf("Invalid IP address\n");
        exit(EXIT_FAILURE);
    }

    // Parse subnet mask as unsigned integer
    if (sscanf(subnet_mask, "%u", &mask) != 1) {
        printf("Invalid subnet mask\n");
        exit(EXIT_FAILURE);
    }

    // Validate IP address and subnet mask
    if (ip > 0xffffffff || mask > 0xffffffff) {
        printf("Invalid IP address or subnet mask\n");
        exit(EXIT_FAILURE);
    }

    // Calculate network address
    network = ip & mask;

    // Calculate broadcast address
    broadcast = network | ~mask;

    // Count number of 1 bits in subnet mask
    num_bits = 0;
    while (mask != 0) {
        if ((mask & 1) == 1) {
            num_bits++;
        }
        mask >>= 1;
    }

    // Calculate maximum number of hosts
    num_hosts = (1 << (32 - num_bits)) - 2;

    // Output results
    printf("Network address: %u.%u.%u.%u\n", (network >> 24) & 0xff, (network >> 16) & 0xff, (network >> 8) & 0xff, network & 0xff);
    printf("Broadcast address: %u.%u.%u.%u\n", (broadcast >> 24) & 0xff, (broadcast >> 16) & 0xff, (broadcast >> 8) & 0xff, broadcast & 0xff);
    printf("Maximum number of hosts: %d\n", num_hosts);

    return 0;
}