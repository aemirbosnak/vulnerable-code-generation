//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char subnet_mask[16] = "";
    char subnet_address[16] = "";
    int subnet_mask_bits = 0;
    int subnet_address_bits = 0;
    int usable_hosts = 0;

    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnet_mask);

    printf("Enter subnet address (e.g. 192.168.1.1): ");
    scanf("%s", subnet_address);

    subnet_mask_bits = count_subnet_mask_bits(subnet_mask);
    subnet_address_bits = count_subnet_address_bits(subnet_mask, subnet_address);
    usable_hosts = calculate_usable_hosts(subnet_mask_bits, subnet_address_bits);

    printf("Subnet mask bits: %d\n", subnet_mask_bits);
    printf("Subnet address bits: %d\n", subnet_address_bits);
    printf("Usable hosts: %d\n", usable_hosts);

    return 0;
}

int count_subnet_mask_bits(char *subnet_mask)
{
    int bits = 0;
    char *mask_ptr = subnet_mask;

    while (*mask_ptr)
    {
        if (*mask_ptr & 0x80)
        {
            bits++;
        }
        mask_ptr++;
    }

    return bits;
}

int count_subnet_address_bits(char *subnet_mask, char *subnet_address)
{
    int bits = 0;
    char *mask_ptr = subnet_mask;
    char *addr_ptr = subnet_address;

    while (*mask_ptr)
    {
        if (*mask_ptr & 0x80)
        {
            bits++;
        }
        mask_ptr++;
    }

    while (*addr_ptr)
    {
        if (*addr_ptr & 0x80)
        {
            bits++;
        }
        addr_ptr++;
    }

    return bits;
}

int calculate_usable_hosts(int subnet_mask_bits, int subnet_address_bits)
{
    int usable_hosts = pow(2, 32 - subnet_mask_bits - subnet_address_bits) - 2;

    return usable_hosts;
}