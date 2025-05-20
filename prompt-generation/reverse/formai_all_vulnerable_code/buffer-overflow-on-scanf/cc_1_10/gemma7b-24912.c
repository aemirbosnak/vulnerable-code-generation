//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBNET_MASK_BITS 32

int main()
{
    int subnet_mask_bits, num_hosts, subnet_mask, network_address, broadcast_address, host_address;
    char subnet_mask_str[64];

    printf("Enter the number of subnet mask bits: ");
    scanf("%d", &subnet_mask_bits);

    if (subnet_mask_bits > MAX_SUBNET_MASK_BITS)
    {
        printf("Error: Subnet mask bits must be less than or equal to %d.\n", MAX_SUBNET_MASK_BITS);
        exit(1);
    }

    subnet_mask = 0;
    for (int i = 0; i < subnet_mask_bits; i++)
    {
        subnet_mask |= 1 << i;
    }

    subnet_mask_str[0] = ' ';
    for (int i = 0; i < 32; i++)
    {
        if (subnet_mask & (1 << i))
        {
            subnet_mask_str[i + 1] = '1';
        }
        else
        {
            subnet_mask_str[i + 1] = '0';
        }
    }

    subnet_mask_str[subnet_mask_bits + 1] = '\0';

    network_address = (subnet_mask & 0xffffff) >> 2;
    broadcast_address = network_address | ~subnet_mask;
    host_address = network_address + 1;

    printf("Subnet Mask: %s\n", subnet_mask_str);
    printf("Network Address: %d\n", network_address);
    printf("Broadcast Address: %d\n", broadcast_address);
    printf("Number of Hosts: %d\n", host_address - network_address);

    return 0;
}