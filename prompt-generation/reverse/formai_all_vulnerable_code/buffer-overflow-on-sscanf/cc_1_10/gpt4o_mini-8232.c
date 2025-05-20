//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void calculate_subnet(char *ip, char *mask) {
    unsigned int ip_parts[4], mask_parts[4], network_parts[4];
    
    // Split the IP address and subnet mask
    sscanf(ip, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);
    sscanf(mask, "%u.%u.%u.%u", &mask_parts[0], &mask_parts[1], &mask_parts[2], &mask_parts[3]);

    // Calculate the network address
    for (int i = 0; i < 4; i++) {
        network_parts[i] = ip_parts[i] & mask_parts[i];
    }

    // Output network address
    printf("Network Address: %u.%u.%u.%u\n", network_parts[0], network_parts[1], network_parts[2], network_parts[3]);

    // Calculate broadcast address
    unsigned int broadcast_parts[4];
    for (int i = 0; i < 4; i++) {
        broadcast_parts[i] = network_parts[i] | (~mask_parts[i] & 0xFF);
    }

    // Output broadcast address
    printf("Broadcast Address: %u.%u.%u.%u\n", broadcast_parts[0], broadcast_parts[1], broadcast_parts[2], broadcast_parts[3]);

    // Calculate number of valid hosts
    unsigned long num_hosts = (1UL << (32 - __builtin_popcount(mask_parts[0] << 24 | mask_parts[1] << 16 | mask_parts[2] << 8 | mask_parts[3]))) - 2;
    printf("Number of Valid Hosts: %lu\n", num_hosts);

    // Calculate subnet class
    char *subnet_class;
    if (ip_parts[0] < 128) {
        subnet_class = "A";
    } else if (ip_parts[0] < 192) {
        subnet_class = "B";
    } else {
        subnet_class = "C";
    }
    printf("Subnet Class: %s\n", subnet_class);

    // Calculate CIDR notation
    int cidr_notation = 0;
    for (int i = 0; i < 4; i++) {
        cidr_notation += __builtin_popcount(mask_parts[i]);
    }
    printf("CIDR Notation: /%d\n", cidr_notation);
}

int main() {
    char ip_address[16];
    char subnet_mask[16];

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter an IPv4 address (e.g., 192.168.1.10): ");
    fgets(ip_address, sizeof(ip_address), stdin);
    ip_address[strcspn(ip_address, "\n")] = 0; // remove newline character

    printf("Please enter a subnet mask (e.g., 255.255.255.0): ");
    fgets(subnet_mask, sizeof(subnet_mask), stdin);
    subnet_mask[strcspn(subnet_mask, "\n")] = 0; // remove newline character

    calculate_subnet(ip_address, subnet_mask);

    return 0;
}