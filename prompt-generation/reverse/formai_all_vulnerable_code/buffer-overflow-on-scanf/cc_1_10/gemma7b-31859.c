//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char subnet_mask[16];
    char subnet_address[16];
    int subnet_mask_bits, subnet_address_bits, prefix_length;

    printf("Enter the subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnet_mask);

    printf("Enter the subnet address (e.g. 192.168.1.1): ");
    scanf("%s", subnet_address);

    subnet_mask_bits = count_subnet_mask_bits(subnet_mask);
    subnet_address_bits = count_subnet_address_bits(subnet_mask, subnet_address);
    prefix_length = subnet_mask_bits - subnet_address_bits;

    printf("Prefix length: %d\n", prefix_length);

    return 0;
}

int count_subnet_mask_bits(char *subnet_mask)
{
    int bits = 0;
    char *mask = subnet_mask;

    while (*mask)
    {
        if ((*mask & 0x80) == 0x80)
        {
            bits++;
            mask++;
        }
    }

    return bits;
}

int count_subnet_address_bits(char *subnet_mask, char *subnet_address)
{
    int bits = 0;
    char *mask = subnet_mask;
    char *address = subnet_address;

    while (*mask && *address)
    {
        if ((*mask & 0x80) == 0x80)
        {
            bits++;
            mask++;
            address++;
        }
    }

    return bits;
}