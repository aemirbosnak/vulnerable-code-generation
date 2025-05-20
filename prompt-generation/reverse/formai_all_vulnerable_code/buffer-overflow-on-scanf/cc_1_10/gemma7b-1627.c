//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char subnet_mask[16];
    char subnet_address[16];
    int subnet_mask_bits;
    int subnet_address_bits;
    int network_address;
    int host_address;
    int num_hosts;

    printf("Enter the subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnet_mask);

    printf("Enter the subnet address (e.g. 192.168.1.1): ");
    scanf("%s", subnet_address);

    subnet_mask_bits = count_subnet_mask_bits(subnet_mask);
    subnet_address_bits = count_subnet_address_bits(subnet_mask);

    network_address = calculate_network_address(subnet_address, subnet_mask);
    host_address = calculate_host_address(network_address, subnet_mask);
    num_hosts = calculate_num_hosts(subnet_mask_bits, subnet_address_bits);

    printf("\nsubnet mask bits: %d", subnet_mask_bits);
    printf("\nsubnet address bits: %d", subnet_address_bits);
    printf("\nNetwork address: %d", network_address);
    printf("\nHost address: %d", host_address);
    printf("\nNumber of hosts: %d", num_hosts);

    return 0;
}

int count_subnet_mask_bits(char *subnet_mask)
{
    int bits = 0;
    char *mask = subnet_mask;

    while (*mask)
    {
        if (*mask & 1)
        {
            bits++;
        }
        mask++;
    }

    return bits;
}

int count_subnet_address_bits(char *subnet_mask)
{
    int bits = 0;
    char *mask = subnet_mask;

    while (*mask)
    {
        if (*mask & 1)
        {
            bits++;
        }
        mask++;
    }

    return 32 - bits;
}

int calculate_network_address(char *subnet_address, char *subnet_mask)
{
    int network_address = 0;
    char *address = subnet_address;
    char *mask = subnet_mask;

    for (int i = 0; i < 4; i++)
    {
        network_address += (address[i] & ~mask[i]) >> (32 - count_subnet_address_bits(subnet_mask));
    }

    return network_address;
}

int calculate_host_address(int network_address, char *subnet_mask)
{
    int host_address = network_address & ~calculate_subnet_mask(subnet_mask);

    return host_address;
}

int calculate_num_hosts(int subnet_mask_bits, int subnet_address_bits)
{
    int num_hosts = pow(2, 32 - subnet_mask_bits - subnet_address_bits) - 2;

    return num_hosts;
}

int calculate_subnet_mask(char *subnet_mask)
{
    int subnet_mask_int = inet_aton(subnet_mask, NULL);
    return subnet_mask_int & ~0xff;
}