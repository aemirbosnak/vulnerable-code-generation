//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SUBNET_BITS 32

int main()
{
    int subnet_mask_bits;
    int host_bits;
    int num_hosts;
    int subnet_mask;
    int broadcast_address;
    int usable_hosts;

    printf("Enter the number of subnet mask bits: ");
    scanf("%d", &subnet_mask_bits);

    subnet_mask_bits = constrain(subnet_mask_bits, 1, MAX_SUBNET_BITS);

    subnet_mask = calculate_subnet_mask(subnet_mask_bits);

    host_bits = MAX_SUBNET_BITS - subnet_mask_bits;

    num_hosts = pow(2, host_bits) - 2;

    broadcast_address = calculate_broadcast_address(subnet_mask, num_hosts);

    usable_hosts = num_hosts - 2;

    printf("\nsubnet mask: %x", subnet_mask);
    printf("\nbroadcast address: %x", broadcast_address);
    printf("\nusable hosts: %d", usable_hosts);

    return 0;
}

int calculate_subnet_mask(int num_bits)
{
    int mask = 0;

    for (int i = 0; i < num_bits; i++)
    {
        mask |= 1 << (32 - 1 - i);
    }

    return mask;
}

int calculate_broadcast_address(int subnet_mask, int num_hosts)
{
    int broadcast_address = (subnet_mask & ~0xff) | (num_hosts - 1);

    return broadcast_address;
}

int constrain(int value, int min, int max)
{
    return fmin(fmax(value, min), max);
}