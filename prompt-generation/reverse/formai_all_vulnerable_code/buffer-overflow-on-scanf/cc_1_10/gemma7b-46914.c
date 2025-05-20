//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int subnet_mask, host_bits, subnet_address, host_address, num_hosts, total_hosts;
    char subnet_mask_bin[32], host_bits_bin[32], subnet_address_bin[32], host_address_bin[32];

    printf("Enter subnet mask (in decimal): ");
    scanf("%d", &subnet_mask);

    subnet_mask_bin[0] = '\0';
    for (int i = 0; i < 32; i++)
    {
        if ((subnet_mask & (1 << i)) != 0)
        {
            subnet_mask_bin[i] = '1';
        }
        else
        {
            subnet_mask_bin[i] = '0';
        }
    }

    printf("Enter number of host bits: ");
    scanf("%d", &host_bits);

    host_bits_bin[0] = '\0';
    for (int i = 0; i < 32; i++)
    {
        if ((host_bits & (1 << i)) != 0)
        {
            host_bits_bin[i] = '1';
        }
        else
        {
            host_bits_bin[i] = '0';
        }
    }

    subnet_address = (subnet_mask & ~(-1 << host_bits)) >> host_bits;
    subnet_address_bin[0] = '\0';
    for (int i = 0; i < 32; i++)
    {
        if ((subnet_address & (1 << i)) != 0)
        {
            subnet_address_bin[i] = '1';
        }
        else
        {
            subnet_address_bin[i] = '0';
        }
    }

    host_address = (((~subnet_mask & -1) & (1 << host_bits)) >> host_bits) - 1;
    host_address_bin[0] = '\0';
    for (int i = 0; i < 32; i++)
    {
        if ((host_address & (1 << i)) != 0)
        {
            host_address_bin[i] = '1';
        }
        else
        {
            host_address_bin[i] = '0';
        }
    }

    num_hosts = (pow(2, host_bits) - 2) / 2;
    total_hosts = num_hosts + 2;

    printf("Subnet Mask (Binary): %s\n", subnet_mask_bin);
    printf("Number of Host Bits: %s\n", host_bits_bin);
    printf("Subnet Address (Binary): %s\n", subnet_address_bin);
    printf("Host Address (Binary): %s\n", host_address_bin);
    printf("Number of Hosts: %d\n", num_hosts);
    printf("Total Hosts: %d\n", total_hosts);

    return 0;
}