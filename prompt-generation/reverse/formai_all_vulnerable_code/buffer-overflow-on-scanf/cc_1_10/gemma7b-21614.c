//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int netmask, subnet, host, prefix_length, network_address, broadcast_address;
    char subnet_mask_str[32];

    // Get the subnet mask in binary
    printf("Enter the subnet mask in binary (e.g. 255.255.255.0): ");
    scanf("%d", &netmask);

    // Convert the subnet mask to a subnet mask string
    subnet_mask_str[0] = '\0';
    for (int i = 0; i < 32; i++)
    {
        if ((netmask & (1 << i)) != 0)
        {
            subnet_mask_str[i] = '1';
        }
        else
        {
            subnet_mask_str[i] = '0';
        }
    }

    // Get the subnet
    printf("Enter the subnet number (e.g. 10.0.0.0): ");
    scanf("%d", &subnet);

    // Get the host
    printf("Enter the host number (e.g. 1): ");
    scanf("%d", &host);

    // Get the prefix length
    printf("Enter the prefix length (e.g. 8): ");
    scanf("%d", &prefix_length);

    // Calculate the network address
    network_address = (subnet & ~netmask) | (prefix_length - 1) << 32 - prefix_length;

    // Calculate the broadcast address
    broadcast_address = network_address | netmask;

    // Print the results
    printf("Network Address: %d.%d.%d.%d\n", network_address & 0xFF, (network_address & 0xFF00) >> 8, (network_address & 0xFF0000) >> 16, (network_address & 0xFF000000) >> 24);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_address & 0xFF, (broadcast_address & 0xFF00) >> 8, (broadcast_address & 0xFF0000) >> 16, (broadcast_address & 0xFF000000) >> 24);
    printf("Subnet Mask: %s\n", subnet_mask_str);

    return 0;
}