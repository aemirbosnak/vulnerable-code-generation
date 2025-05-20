//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num_hosts, subnet_mask, broadcast_addr, network_addr, i, subnet_mask_bits, host_bits;
    char subnet_mask_str[32], broadcast_addr_str[32], network_addr_str[32];

    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    subnet_mask_bits = (int)log2(num_hosts) + 3;
    subnet_mask = ~(~0 << subnet_mask_bits) & 0xFFF;
    broadcast_addr = subnet_mask & ~0x0;
    network_addr = (subnet_mask & ~0xFFF) | 0x0;

    subnet_mask_str[0] = ' ';
    for(i = 0; i < subnet_mask_bits; i++)
    {
        if((subnet_mask & (1 << i)) != 0)
        {
            subnet_mask_str[i + 1] = '1';
        }
        else
        {
            subnet_mask_str[i + 1] = '0';
        }
    }

    broadcast_addr_str[0] = ' ';
    for(i = 0; i < subnet_mask_bits; i++)
    {
        if((broadcast_addr & (1 << i)) != 0)
        {
            broadcast_addr_str[i + 1] = '1';
        }
        else
        {
            broadcast_addr_str[i + 1] = '0';
        }
    }

    network_addr_str[0] = ' ';
    for(i = 0; i < subnet_mask_bits; i++)
    {
        if((network_addr & (1 << i)) != 0)
        {
            network_addr_str[i + 1] = '1';
        }
        else
        {
            network_addr_str[i + 1] = '0';
        }
    }

    printf("Subnet Mask: %s\n", subnet_mask_str);
    printf("Broadcast Address: %s\n", broadcast_addr_str);
    printf("Network Address: %s\n", network_addr_str);

    return 0;
}