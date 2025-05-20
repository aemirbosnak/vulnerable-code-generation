//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int ip_address;
    unsigned int subnet_mask;
    unsigned int wildcard_mask;
    unsigned int network_address;
    unsigned int broadcast_address;
    unsigned int host_min_address;
    unsigned int host_max_address;
    unsigned int num_hosts;
} subnet_info;

int main() {
    // Initialize the subnet info structure
    subnet_info subnet;
    subnet.ip_address = 0;
    subnet.subnet_mask = 0;
    subnet.wildcard_mask = 0;
    subnet.network_address = 0;
    subnet.broadcast_address = 0;
    subnet.host_min_address = 0;
    subnet.host_max_address = 0;
    subnet.num_hosts = 0;

    // Get the IP address from the user
    printf("Enter the IP address: ");
    scanf("%u", &subnet.ip_address);

    // Get the subnet mask from the user
    printf("Enter the subnet mask: ");
    scanf("%u", &subnet.subnet_mask);

    // Calculate the wildcard mask
    subnet.wildcard_mask = ~subnet.subnet_mask;

    // Calculate the network address
    subnet.network_address = subnet.ip_address & subnet.subnet_mask;

    // Calculate the broadcast address
    subnet.broadcast_address = subnet.network_address | subnet.wildcard_mask;

    // Calculate the minimum host address
    subnet.host_min_address = subnet.network_address + 1;

    // Calculate the maximum host address
    subnet.host_max_address = subnet.broadcast_address - 1;

    // Calculate the number of hosts
    subnet.num_hosts = subnet.wildcard_mask & 0x00FFFFFF;

    // Print the subnet information
    printf("IP Address: %u\n", subnet.ip_address);
    printf("Subnet Mask: %u\n", subnet.subnet_mask);
    printf("Wildcard Mask: %u\n", subnet.wildcard_mask);
    printf("Network Address: %u\n", subnet.network_address);
    printf("Broadcast Address: %u\n", subnet.broadcast_address);
    printf("Minimum Host Address: %u\n", subnet.host_min_address);
    printf("Maximum Host Address: %u\n", subnet.host_max_address);
    printf("Number of Hosts: %u\n", subnet.num_hosts);

    return 0;
}