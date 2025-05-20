//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SUBNETS 256

int main()
{
    int num_subnets, i, subnet_size, mask_bits, prefix_length;
    char subnet_address[256];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++)
    {
        printf("Enter the subnet address: ");
        scanf("%s", subnet_address);

        subnet_size = subnet_size_calculator(subnet_address);
        mask_bits = mask_bits_calculator(subnet_address);
        prefix_length = prefix_length_calculator(subnet_address);

        printf("Subnet size: %d\n", subnet_size);
        printf("Mask bits: %d\n", mask_bits);
        printf("Prefix length: %d\n", prefix_length);
        printf("\n");
    }

    return 0;
}

int subnet_size_calculator(char *subnet_address)
{
    int address_bits, mask_bits, subnet_size;

    address_bits = count_bits(subnet_address);
    mask_bits = address_bits - prefix_length_calculator(subnet_address);
    subnet_size = pow(2, mask_bits) - 2;

    return subnet_size;
}

int mask_bits_calculator(char *subnet_address)
{
    int prefix_length, mask_bits;

    prefix_length = prefix_length_calculator(subnet_address);
    mask_bits = 32 - prefix_length;

    return mask_bits;
}

int prefix_length_calculator(char *subnet_address)
{
    int i, prefix_length = 0;

    for (i = 0; subnet_address[i] != '/'; i++)
    {
        prefix_length++;
    }

    return prefix_length;
}

int count_bits(char *address)
{
    int num_bits = 0;

    while (*address)
    {
        int bit = (*address & 0x80) >> 7;
        num_bits += bit;
        address++;
    }

    return num_bits;
}