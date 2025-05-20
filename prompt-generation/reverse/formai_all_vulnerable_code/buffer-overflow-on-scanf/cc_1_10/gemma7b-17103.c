//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int subnet_mask_bits, num_hosts, num_networks;
    char subnet_mask[16];

    printf("Enter the subnet mask in binary (e.g. 255.255.255.0 for /8): ");
    scanf("%s", subnet_mask);

    subnet_mask_bits = count_subnet_mask_bits(subnet_mask);
    num_hosts = calculate_num_hosts(subnet_mask_bits);
    num_networks = calculate_num_networks(subnet_mask_bits);

    printf("Subnet Mask Bits: %d\n", subnet_mask_bits);
    printf("Number of Hosts: %d\n", num_hosts);
    printf("Number of Networks: %d\n", num_networks);

    return 0;
}

int count_subnet_mask_bits(char *subnet_mask)
{
    int num_bits = 0;

    while (*subnet_mask)
    {
        if ((*subnet_mask & 1) == 1)
        {
            num_bits++;
        }

        subnet_mask++;
    }

    return num_bits;
}

int calculate_num_hosts(int subnet_mask_bits)
{
    int num_hosts = pow(2, 32 - subnet_mask_bits) - 2;

    return num_hosts;
}

int calculate_num_networks(int subnet_mask_bits)
{
    int num_networks = pow(2, 32 - subnet_mask_bits) - 2;

    return num_networks;
}