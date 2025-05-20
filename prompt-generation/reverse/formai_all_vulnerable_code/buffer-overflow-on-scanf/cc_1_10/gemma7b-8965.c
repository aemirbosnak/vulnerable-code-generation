//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char subnet_mask[16] = "";
    char subnet_address[16] = "";
    int subnet_mask_bits = 0;
    int subnet_address_bits = 0;
    int host_bits = 0;
    int broadcast_address_bits = 0;
    int num_hosts = 0;

    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnet_mask);

    printf("Enter subnet address (e.g. 192.168.1.0): ");
    scanf("%s", subnet_address);

    subnet_mask_bits = count_bits(subnet_mask);
    subnet_address_bits = count_bits(subnet_address);

    host_bits = subnet_mask_bits - subnet_address_bits - 1;
    broadcast_address_bits = subnet_mask_bits - subnet_address_bits;
    num_hosts = pow(2, host_bits) - 2;

    printf("Subnet mask bits: %d\n", subnet_mask_bits);
    printf("Subnet address bits: %d\n", subnet_address_bits);
    printf("Host bits: %d\n", host_bits);
    printf("Broadcast address bits: %d\n", broadcast_address_bits);
    printf("Number of hosts: %d\n", num_hosts);

    return 0;
}

int count_bits(char *str)
{
    int num_bits = 0;
    char *p = str;
    while (*p)
    {
        if (*p >= 'A' && *p <= 'F')
        {
            num_bits++;
        }
        p++;
    }
    return num_bits;
}