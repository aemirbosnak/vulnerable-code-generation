//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int network_address, subnet_mask, host_address, network_bits, subnet_bits, host_bits;
    char subnet_mask_string[16];

    printf("Welcome to the C Subnet Calculator!\n");

    printf("Enter the network address: ");
    scanf("%d", &network_address);

    printf("Enter the subnet mask: ");
    scanf("%d", &subnet_mask);

    subnet_mask_string[0] = '\0';
    for (int i = 0; i < 32; i++)
    {
        if ((subnet_mask & (1 << i)) != 0)
        {
            subnet_mask_string[i] = '1';
        }
        else
        {
            subnet_mask_string[i] = '0';
        }
    }

    network_bits = count_set_bits(subnet_mask);
    subnet_bits = 32 - network_bits;
    host_bits = subnet_bits - 1;

    printf("Network address: %d\n", network_address);
    printf("Subnet mask: %s\n", subnet_mask_string);
    printf("Number of network bits: %d\n", network_bits);
    printf("Number of subnet bits: %d\n", subnet_bits);
    printf("Number of host bits: %d\n", host_bits);

    return 0;
}

int count_set_bits(int mask)
{
    int count = 0;

    while (mask)
    {
        if (mask & 1)
        {
            count++;
        }
        mask >>= 1;
    }

    return count;
}