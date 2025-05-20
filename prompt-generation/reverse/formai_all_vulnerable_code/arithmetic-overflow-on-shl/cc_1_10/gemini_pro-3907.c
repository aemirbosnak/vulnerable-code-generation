//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <network address> <subnet mask> <number of hosts>\n", argv[0]);
        return 1;
    }

    char *network_address = argv[1];
    char *subnet_mask = argv[2];
    int num_hosts = atoi(argv[3]);

    // Convert the network address and subnet mask to binary
    unsigned int network_address_binary = 0;
    unsigned int subnet_mask_binary = 0;

    for (int i = 0; i < 32; i++)
    {
        if (network_address[i] == '1')
        {
            network_address_binary |= (1 << (31 - i));
        }

        if (subnet_mask[i] == '1')
        {
            subnet_mask_binary |= (1 << (31 - i));
        }
    }

    // Calculate the broadcast address
    unsigned int broadcast_address_binary = network_address_binary | ~subnet_mask_binary;

    // Convert the broadcast address to decimal
    char broadcast_address[33];
    for (int i = 0; i < 32; i++)
    {
        broadcast_address[i] = (broadcast_address_binary & (1 << (31 - i))) ? '1' : '0';
    }

    broadcast_address[32] = '\0';

    // Calculate the number of hosts
    int num_hosts_calculated = (1 << (32 - strlen(subnet_mask)));

    // Print the results
    printf("Network Address: %s\n", network_address);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Broadcast Address: %s\n", broadcast_address);
    printf("Number of Hosts: %d\n", num_hosts_calculated);

    return 0;
}