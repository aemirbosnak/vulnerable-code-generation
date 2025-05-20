//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void subnet_calculator()
{
    int subnet_mask, host_bits, network_bits, broadcast_address, usable_hosts;

    // Get the subnet mask from the user
    printf("Enter the subnet mask (e.g. 255.255.255.0): ");
    scanf("%d", &subnet_mask);

    // Calculate the number of host bits
    host_bits = 32 - numberOfBits(subnet_mask);

    // Calculate the number of network bits
    network_bits = numberOfBits(subnet_mask) - 1;

    // Calculate the broadcast address
    broadcast_address = pow(2, network_bits) - 1;

    // Calculate the usable hosts
    usable_hosts = pow(2, host_bits) - 2;

    // Print the results
    printf("\nSubnet Mask: %d.%d.%d.%d", (subnet_mask & 255) >> 8, (subnet_mask & 255) >> 16, (subnet_mask & 255) >> 24, subnet_mask & 255);
    printf("\nNumber of Network Bits: %d", network_bits);
    printf("\nNumber of Host Bits: %d", host_bits);
    printf("\nBroadcast Address: %d.%d.%d.%d", broadcast_address & 255, (broadcast_address & 255) >> 8, (broadcast_address & 255) >> 16, broadcast_address & 255);
    printf("\nUsable Hosts: %d", usable_hosts);
}

int numberOfBits(int mask)
{
    int num_bits = 0;

    while (mask)
    {
        if (mask & 1)
            num_bits++;

        mask >>= 1;
    }

    return num_bits;
}

int main()
{
    subnet_calculator();

    return 0;
}