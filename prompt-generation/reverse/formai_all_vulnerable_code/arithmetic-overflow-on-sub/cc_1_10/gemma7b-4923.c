//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: surprised
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
    int broadcast_address;
    int host_address;
    int num_hosts;

    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    fgets(subnet_mask, MAX_BUFFER_SIZE, stdin);

    printf("Enter subnet address (e.g. 192.168.1.1): ");
    fgets(subnet_address, MAX_BUFFER_SIZE, stdin);

    subnet_mask_bits = count_bits(subnet_mask);
    subnet_address_bits = count_bits(subnet_address);

    broadcast_address = calculate_broadcast_address(subnet_mask, subnet_address);
    host_address = calculate_host_address(subnet_mask, subnet_address);
    num_hosts = calculate_num_hosts(subnet_mask, subnet_address);

    printf("Subnet Mask:** %s\n", subnet_mask);
    printf("Subnet Address:** %s\n", subnet_address);
    printf("Broadcast Address:** %d\n", broadcast_address);
    printf("Host Address:** %d\n", host_address);
    printf("Number of Hosts:** %d\n", num_hosts);

    return 0;
}

int count_bits(char *address)
{
    int num_bits = 0;
    while (*address)
    {
        int mask_value = *address & 0xFF;
        num_bits += count_set_bits(mask_value);
        address++;
    }
    return num_bits;
}

int count_set_bits(int value)
{
    int num_bits = 0;
    while (value)
    {
        if (value & 1)
        {
            num_bits++;
        }
        value >>= 1;
    }
    return num_bits;
}

int calculate_broadcast_address(char *subnet_mask, char *subnet_address)
{
    int subnet_mask_bits = count_bits(subnet_mask);
    int broadcast_address = ((int)subnet_address & ~((int)subnet_mask)) | ((1 << (subnet_mask_bits - 1)) - 1);
    return broadcast_address;
}

int calculate_host_address(char *subnet_mask, char *subnet_address)
{
    int subnet_mask_bits = count_bits(subnet_mask);
    int host_address = (int)subnet_address & ~((int)subnet_mask);
    return host_address;
}

int calculate_num_hosts(char *subnet_mask, char *subnet_address)
{
    int subnet_mask_bits = count_bits(subnet_mask);
    int num_hosts = (int)pow(2, 32 - subnet_mask_bits) - 2;
    return num_hosts;
}