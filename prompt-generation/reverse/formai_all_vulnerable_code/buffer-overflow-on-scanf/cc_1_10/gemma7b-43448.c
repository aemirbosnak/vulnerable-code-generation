//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNET_MASK_BITS 32

int main()
{
    char subnet_mask[MAX_SUBNET_MASK_BITS / 8 + 1];
    char subnet_address[16];
    int subnet_mask_bits;
    int network_address_bits;
    int host_address_bits;
    int num_hosts;

    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnet_mask);

    subnet_mask_bits = count_subnet_mask_bits(subnet_mask);
    network_address_bits = subnet_mask_bits - 1;
    host_address_bits = MAX_SUBNET_MASK_BITS - subnet_mask_bits;
    num_hosts = pow(2, host_address_bits) - 2;

    printf("Subnet Mask:** %s\n", subnet_mask);
    printf("Number of Network Addresses:** %d\n", network_address_bits);
    printf("Number of Hosts:** %d\n", num_hosts);

    return 0;
}

int count_subnet_mask_bits(char *subnet_mask)
{
    int num_bits = 0;
    int i = 0;

    while (subnet_mask[i] != '\0')
    {
        int mask_value = subnet_mask[i] & 0xFF;
        num_bits += count_set_bits(mask_value);
        i++;
    }

    return num_bits;
}

int count_set_bits(int number)
{
    int num_bits = 0;

    while (number > 0)
    {
        if (number & 1)
        {
            num_bits++;
        }
        number >>= 1;
    }

    return num_bits;
}