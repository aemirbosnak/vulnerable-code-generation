//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    // Declare variables
    char ip_address[16];
    int prefix_length;
    unsigned int ip_int;
    unsigned int subnet_mask_int;
    unsigned int network_address_int;
    unsigned int broadcast_address_int;
    unsigned int num_hosts;
    char subnet_mask[16];
    char network_address[16];
    char broadcast_address[16];

    // Get user input
    printf("Enter an IP address: ");
    scanf("%s", ip_address);
    printf("Enter a prefix length: ");
    scanf("%d", &prefix_length);

    // Convert IP address to integer
    ip_int = inet_addr(ip_address);

    // Convert prefix length to subnet mask
    subnet_mask_int = 0xFFFFFFFF << (32 - prefix_length);

    // Calculate network address
    network_address_int = ip_int & subnet_mask_int;

    // Calculate broadcast address
    broadcast_address_int = network_address_int | ~subnet_mask_int;

    // Calculate number of hosts
    num_hosts = (1 << (32 - prefix_length)) - 2;

    // Convert integers to strings
    inet_ntop(AF_INET, &subnet_mask_int, subnet_mask, sizeof(subnet_mask));
    inet_ntop(AF_INET, &network_address_int, network_address, sizeof(network_address));
    inet_ntop(AF_INET, &broadcast_address_int, broadcast_address, sizeof(broadcast_address));

    // Print results
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Network Address: %s\n", network_address);
    printf("Broadcast Address: %s\n", broadcast_address);
    printf("Number of Hosts: %u\n", num_hosts);

    return 0;
}