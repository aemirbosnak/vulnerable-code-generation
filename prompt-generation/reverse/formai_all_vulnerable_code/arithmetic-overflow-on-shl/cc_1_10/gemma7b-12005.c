//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNET_MASK_BITS 32

int main()
{
    char subnet_mask[MAX_SUBNET_MASK_BITS / 8 + 1];
    int subnet_mask_bits, network_address, host_address, broadcast_address;

    // Get the subnet mask from the user
    printf("Enter the subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnet_mask);

    // Convert the subnet mask to a number of bits
    subnet_mask_bits = count_subnet_mask_bits(subnet_mask);

    // Calculate the network address, host address, and broadcast address
    network_address = calculate_network_address(subnet_mask_bits, subnet_mask);
    host_address = calculate_host_address(subnet_mask_bits, network_address);
    broadcast_address = calculate_broadcast_address(subnet_mask_bits, network_address);

    // Print the results
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Network Address: %d.%d.%d.%d\n", network_address >> 24, (network_address & 0xff0000) >> 16, (network_address & 0xff00) >> 8, network_address & 0xff);
    printf("Host Address: %d.%d.%d.%d\n", host_address >> 24, (host_address & 0xff0000) >> 16, (host_address & 0xff00) >> 8, host_address & 0xff);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_address >> 24, (broadcast_address & 0xff0000) >> 16, (broadcast_address & 0xff00) >> 8, broadcast_address & 0xff);

    return 0;
}

int count_subnet_mask_bits(char *subnet_mask)
{
    int num_bits = 0;

    // Iterate over the subnet mask and count the number of ones
    for (int i = 0; subnet_mask[i] != '\0'; i++)
    {
        int mask_bit = subnet_mask[i] & 0x80;
        if (mask_bit)
        {
            num_bits++;
        }
    }

    return num_bits;
}

int calculate_network_address(int subnet_mask_bits, char *subnet_mask)
{
    int network_address = 0;

    // Calculate the number of bits to clear
    int num_bits_to_clear = MAX_SUBNET_MASK_BITS - subnet_mask_bits;

    // Clear the specified number of bits
    network_address = (~((~0) << num_bits_to_clear)) & 0xffffff;

    return network_address;
}

int calculate_host_address(int subnet_mask_bits, int network_address)
{
    int host_address = 0;

    // Calculate the number of bits for the host address
    int num_host_bits = subnet_mask_bits - 1;

    // Set the host address bits to 1
    host_address = (1 << num_host_bits) - 1;

    return network_address | host_address;
}

int calculate_broadcast_address(int subnet_mask_bits, int network_address)
{
    int broadcast_address = network_address | (1 << (subnet_mask_bits - 1)) - 1;

    return broadcast_address;
}