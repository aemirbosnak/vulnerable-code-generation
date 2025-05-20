//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNET_SIZE 256

int main()
{
    char subnet_mask[MAX_SUBNET_SIZE];
    char subnet_address[MAX_SUBNET_SIZE];
    int subnet_mask_bits;
    int subnet_address_bits;
    int num_hosts;

    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnet_mask);

    printf("Enter subnet address (e.g. 192.168.1.1): ");
    scanf("%s", subnet_address);

    subnet_mask_bits = count_subnet_mask_bits(subnet_mask);
    subnet_address_bits = count_subnet_address_bits(subnet_mask);
    num_hosts = calculate_num_hosts(subnet_mask_bits, subnet_address_bits);

    printf("\nSubnet Mask Bits: %d", subnet_mask_bits);
    printf("\nSubnet Address Bits: %d", subnet_address_bits);
    printf("\nNumber of Hosts: %d", num_hosts);

    return 0;
}

int count_subnet_mask_bits(char *subnet_mask)
{
    int num_bits = 0;
    char mask_byte = atoi(subnet_mask);

    while (mask_byte > 0)
    {
        if (mask_byte & 1)
        {
            num_bits++;
        }
        mask_byte >>= 1;
    }

    return num_bits;
}

int count_subnet_address_bits(char *subnet_mask)
{
    int num_bits = 0;
    char mask_byte = atoi(subnet_mask);

    while (mask_byte > 0)
    {
        if (mask_byte & 1)
        {
            num_bits++;
        }
        mask_byte >>= 1;
    }

    return num_bits;
}

int calculate_num_hosts(int subnet_mask_bits, int subnet_address_bits)
{
    int num_hosts = pow(2, 32 - subnet_mask_bits - subnet_address_bits) - 2;

    return num_hosts;
}