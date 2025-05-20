//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char subnet_mask[MAX_BUFFER_SIZE];
    char subnet_address[MAX_BUFFER_SIZE];
    int subnet_mask_bits;
    int subnet_address_bits;
    int broadcast_address[4];
    int host_address[4];
    int num_hosts;

    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnet_mask);

    printf("Enter subnet address (e.g. 192.168.1.1): ");
    scanf("%s", subnet_address);

    subnet_mask_bits = count_subnet_mask_bits(subnet_mask);
    subnet_address_bits = count_subnet_address_bits(subnet_mask);

    broadcast_address[0] = subnet_address[0] & ~((1 << (subnet_mask_bits - 1)) >> (subnet_mask_bits - 1));
    broadcast_address[1] = subnet_address[1] & ~((1 << (subnet_mask_bits - 1)) >> (subnet_mask_bits - 1));
    broadcast_address[2] = subnet_address[2] & ~((1 << (subnet_mask_bits - 1)) >> (subnet_mask_bits - 1));
    broadcast_address[3] = subnet_address[3] & ~((1 << (subnet_mask_bits - 1)) >> (subnet_mask_bits - 1));

    host_address[0] = subnet_address[0] & ~((1 << subnet_mask_bits) - 1);
    host_address[1] = subnet_address[1] & ~((1 << subnet_mask_bits) - 1);
    host_address[2] = subnet_address[2] & ~((1 << subnet_mask_bits) - 1);
    host_address[3] = subnet_address[3] & ~((1 << subnet_mask_bits) - 1);

    num_hosts = pow(2, 32 - subnet_mask_bits) - 2;

    printf("Broadcast address: ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d.", broadcast_address[i]);
    }

    printf("\nHost address: ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d.", host_address[i]);
    }

    printf("\nNumber of hosts: %d", num_hosts);

    return 0;
}

int count_subnet_mask_bits(char *subnet_mask)
{
    int num_bits = 0;
    while (*subnet_mask)
    {
        if (*subnet_mask & 1)
        {
            num_bits++;
        }
        subnet_mask++;
    }
    return num_bits;
}

int count_subnet_address_bits(char *subnet_mask)
{
    int num_bits = 0;
    int mask_bits = count_subnet_mask_bits(subnet_mask);
    while (*subnet_mask)
    {
        if (*subnet_mask & 1)
        {
            num_bits++;
        }
        subnet_mask++;
    }
    return num_bits - mask_bits;
}