//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int bits, subnet_mask, host_mask, network_address, broadcast_address, hosts_per_subnet;
    char subnet_mask_str[32], host_mask_str[32], network_address_str[32], broadcast_address_str[32];

    printf("Welcome to the C Subnet Calculator!\n");

    // Get the number of bits for the subnet mask
    printf("Enter the number of bits for the subnet mask: ");
    scanf("%d", &bits);

    // Calculate the subnet mask
    subnet_mask = ~(~0 << bits) & 0xFFF;
    subnet_mask_str[0] = (subnet_mask & 0xFF) >> 8;
    subnet_mask_str[1] = (subnet_mask & 0xFF) >> 16;
    subnet_mask_str[2] = (subnet_mask & 0xFF) >> 24;
    subnet_mask_str[3] = subnet_mask & 0xFF;

    // Calculate the host mask
    host_mask = ~(~0 << bits) & 0xFFF;
    host_mask_str[0] = (host_mask & 0xFF) >> 8;
    host_mask_str[1] = (host_mask & 0xFF) >> 16;
    host_mask_str[2] = (host_mask & 0xFF) >> 24;
    host_mask_str[3] = host_mask & 0xFF;

    // Calculate the network address
    network_address = (subnet_mask & 0xFFF) >> 8;
    network_address_str[0] = (network_address & 0xFF) >> 8;
    network_address_str[1] = (network_address & 0xFF) >> 16;
    network_address_str[2] = (network_address & 0xFF) >> 24;
    network_address_str[3] = network_address & 0xFF;

    // Calculate the broadcast address
    broadcast_address = (network_address & 0xFFF) | 0xFF;
    broadcast_address_str[0] = (broadcast_address & 0xFF) >> 8;
    broadcast_address_str[1] = (broadcast_address & 0xFF) >> 16;
    broadcast_address_str[2] = (broadcast_address & 0xFF) >> 24;
    broadcast_address_str[3] = broadcast_address & 0xFF;

    // Calculate the number of hosts per subnet
    hosts_per_subnet = (host_mask & 0xFFF) + 1;

    // Print the results
    printf("Subnet Mask: %s\n", subnet_mask_str);
    printf("Host Mask: %s\n", host_mask_str);
    printf("Network Address: %s\n", network_address_str);
    printf("Broadcast Address: %s\n", broadcast_address_str);
    printf("Number of Hosts per Subnet: %d\n", hosts_per_subnet);

    return 0;
}