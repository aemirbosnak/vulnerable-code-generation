//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char subnet_mask[16];
    char subnet_address[16];
    int subnet_mask_bits;
    int subnet_address_bits;
    int num_hosts;

    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnet_mask);

    printf("Enter subnet address (e.g. 192.168.1.0): ");
    scanf("%s", subnet_address);

    subnet_mask_bits = count_bits(subnet_mask);
    subnet_address_bits = count_bits(subnet_address);

    num_hosts = calculate_num_hosts(subnet_mask_bits, subnet_address_bits);

    printf("Number of hosts in the subnet: %d\n", num_hosts);

    return 0;
}

int count_bits(char *address)
{
    int num_bits = 0;
    int i = 0;

    while (address[i] != '\0')
    {
        int mask = 1 << 8 - i;
        if ((address[i] & mask) != 0)
        {
            num_bits++;
        }
        i++;
    }

    return num_bits;
}

int calculate_num_hosts(int subnet_mask_bits, int subnet_address_bits)
{
    int num_hosts = pow(2, 32 - subnet_mask_bits - subnet_address_bits) - 2;

    return num_hosts;
}