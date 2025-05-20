//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    unsigned int ip_address;
    unsigned int subnet_mask;
    unsigned int network_address;
    unsigned int broadcast_address;
    unsigned int host_min;
    unsigned int host_max;
    unsigned int num_hosts;
    int cidr_notation;

    // Get the IP address from the user
    printf("Enter the IP address: ");
    scanf("%u", &ip_address);

    // Get the subnet mask from the user
    printf("Enter the subnet mask: ");
    scanf("%u", &subnet_mask);

    // Calculate the network address
    network_address = ip_address & subnet_mask;

    // Calculate the broadcast address
    broadcast_address = network_address | ~subnet_mask;

    // Calculate the host min
    host_min = network_address + 1;

    // Calculate the host max
    host_max = broadcast_address - 1;

    // Calculate the number of hosts
    num_hosts = broadcast_address - network_address - 1;

    // Calculate the CIDR notation
    cidr_notation = 32 - __builtin_clz(subnet_mask);

    // Print the results
    printf("Network address: %u\n", network_address);
    printf("Broadcast address: %u\n", broadcast_address);
    printf("Host min: %u\n", host_min);
    printf("Host max: %u\n", host_max);
    printf("Number of hosts: %u\n", num_hosts);
    printf("CIDR notation: /%d\n", cidr_notation);

    return 0;
}