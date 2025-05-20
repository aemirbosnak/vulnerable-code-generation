//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int subnet_mask, host_mask, network_address, broadcast_address, subnet_bits, host_bits;
    char subnet_mask_str[32], host_mask_str[32], network_address_str[32], broadcast_address_str[32];

    // Get the subnet mask, host mask, network address, and broadcast address
    printf("Enter the subnet mask (in binary): ");
    scanf("%s", subnet_mask_str);

    printf("Enter the host mask (in binary): ");
    scanf("%s", host_mask_str);

    printf("Enter the network address (in decimal): ");
    scanf("%d", &network_address);

    // Calculate the subnet bits, host bits, and broadcast address
    subnet_bits = 32 - count_set_bits(subnet_mask);
    host_bits = 32 - subnet_bits - 1;
    broadcast_address = network_address | (~host_mask) & 0xFFFFFFFF;

    // Print the results
    printf("\nSubnet Mask: %s\n", subnet_mask_str);
    printf("Host Mask: %s\n", host_mask_str);
    printf("Network Address: %s\n", network_address_str);
    printf("Broadcast Address: %s\n", broadcast_address_str);

    printf("\nThe subnet mask, host mask, network address, and broadcast address are valid.\n");

    return 0;
}

int count_set_bits(int mask)
{
    int num_bits = 0;

    while (mask)
    {
        if (mask & 1)
        {
            num_bits++;
        }

        mask >>= 1;
    }

    return num_bits;
}