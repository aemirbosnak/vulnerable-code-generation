//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the subnet calculator function
int subnet_calculator(int network_address, int subnet_mask)
{
    int subnet_mask_bits, usable_bits, broadcast_address, network_address_mask;
    int host_address_max;

    // Calculate the number of subnet mask bits
    subnet_mask_bits = 32 - __builtin_popcount(subnet_mask);

    // Calculate the number of usable bits
    usable_bits = subnet_mask_bits - 2;

    // Calculate the broadcast address
    broadcast_address = network_address | (~subnet_mask) & 0xFFFFFFFF;

    // Calculate the network address mask
    network_address_mask = subnet_mask & network_address;

    // Calculate the maximum number of hosts
    host_address_max = pow(2, usable_bits) - 1;

    // Return the results
    return subnet_mask_bits, usable_bits, broadcast_address, network_address_mask, host_address_max;
}

int main()
{
    int network_address, subnet_mask;
    int subnet_mask_bits, usable_bits, broadcast_address, network_address_mask, host_address_max;

    // Get the network address and subnet mask
    printf("Enter the network address: ");
    scanf("%d", &network_address);

    printf("Enter the subnet mask: ");
    scanf("%d", &subnet_mask);

    // Calculate the subnet mask bits, usable bits, broadcast address, and network address mask
    subnet_mask_bits, usable_bits, broadcast_address, network_address_mask, host_address_max = subnet_calculator(network_address, subnet_mask);

    // Print the results
    printf("\nSubnet Mask Bits: %d", subnet_mask_bits);
    printf("\nUsable Bits: %d", usable_bits);
    printf("\nBroadcast Address: %d", broadcast_address);
    printf("\nNetwork Address Mask: %d", network_address_mask);
    printf("\nMaximum Number of Hosts: %d", host_address_max);

    return 0;
}