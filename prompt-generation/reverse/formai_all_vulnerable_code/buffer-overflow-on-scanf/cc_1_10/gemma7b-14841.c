//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char subnet_mask[16];
    char subnet_address[16];
    int num_hosts, num_networks;
    int subnet_mask_bits;

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter the subnet mask in the format '255.255.255.0': ");
    scanf("%s", subnet_mask);

    printf("Please enter the subnet address in the format '192.168.1.1': ");
    scanf("%s", subnet_address);

    subnet_mask_bits = count_subnet_mask_bits(subnet_mask);

    num_hosts = calculate_num_hosts(subnet_mask_bits);

    num_networks = calculate_num_networks(subnet_mask_bits);

    printf("The number of hosts in this subnet is: %d\n", num_hosts);

    printf("The number of networks in this subnet is: %d\n", num_networks);

    return 0;
}

int count_subnet_mask_bits(char *subnet_mask)
{
    int num_bits = 0;
    char *mask_ptr = subnet_mask;

    while (*mask_ptr)
    {
        int mask_byte = *mask_ptr & 255;
        num_bits += 8 - num_bits_set(mask_byte);
        mask_ptr++;
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

int num_bits_set(int num)
{
    int num_bits = 0;

    while (num)
    {
        if (num & 1)
        {
            num_bits++;
        }
        num >>= 1;
    }

    return num_bits;
}