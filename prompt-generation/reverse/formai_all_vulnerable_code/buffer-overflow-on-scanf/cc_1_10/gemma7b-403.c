//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num_hosts, subnet_mask, broadcast_address, network_address;
    char subnet_mask_str[32];

    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    printf("Enter the subnet mask in binary: ");
    scanf("%s", subnet_mask_str);

    subnet_mask = convert_subnet_mask(subnet_mask_str);

    network_address = calculate_network_address(subnet_mask, num_hosts);

    broadcast_address = calculate_broadcast_address(subnet_mask, network_address);

    printf("Network Address: %d.%d.%d.%d\n", network_address & subnet_mask);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_address & subnet_mask);

    return 0;
}

int convert_subnet_mask(char *subnet_mask_str)
{
    int subnet_mask = 0;
    int i = 0;

    while (subnet_mask_str[i] != '\0')
    {
        int bit = subnet_mask_str[i] - '0';
        subnet_mask |= 1 << (3 - i) * bit;
        i++;
    }

    return subnet_mask;
}

int calculate_network_address(int subnet_mask, int num_hosts)
{
    int network_address = (num_hosts & subnet_mask) >> (3 - popcount(subnet_mask)) | 1;

    return network_address;
}

int calculate_broadcast_address(int subnet_mask, int network_address)
{
    int broadcast_address = network_address | ~subnet_mask;

    return broadcast_address;
}

int popcount(int num)
{
    int count = 0;

    while (num)
    {
        if (num & 1)
            count++;

        num >>= 1;
    }

    return count;
}