//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char subnet_mask[16];
    char network_address[16];
    int subnet_mask_bits;
    int network_address_bits;
    int host_bits;
    int num_hosts;

    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnet_mask);

    printf("Enter network address (e.g. 192.168.1.0): ");
    scanf("%s", network_address);

    subnet_mask_bits = count_subnet_mask_bits(subnet_mask);
    network_address_bits = count_network_address_bits(subnet_mask);
    host_bits = 32 - subnet_mask_bits - network_address_bits;
    num_hosts = pow(2, host_bits) - 2;

    printf("Subnet mask bits: %d\n", subnet_mask_bits);
    printf("Network address bits: %d\n", network_address_bits);
    printf("Host bits: %d\n", host_bits);
    printf("Number of hosts: %d\n", num_hosts);

    return 0;
}

int count_subnet_mask_bits(char *subnet_mask)
{
    int bits = 0;
    char *ptr = subnet_mask;

    while (*ptr)
    {
        int num = *ptr - '0';
        bits += num / 8 + (num % 8) * 2;
        ptr++;
    }

    return bits;
}

int count_network_address_bits(char *subnet_mask)
{
    int bits = count_subnet_mask_bits(subnet_mask);
    return 32 - bits;
}