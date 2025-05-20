//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int network_number;
    int subnet_mask;
    int host_number;
    int broadcast_address;
    int usable_hosts;

    printf("Enter the network number: ");
    scanf("%d", &network_number);

    printf("Enter the subnet mask: ");
    scanf("%d", &subnet_mask);

    printf("Enter the host number: ");
    scanf("%d", &host_number);

    subnet_mask_to_broadcast_address(network_number, subnet_mask, &broadcast_address);
    usable_hosts_from_subnet_mask(subnet_mask, &usable_hosts);

    printf("The broadcast address is: %d", broadcast_address);
    printf("\nThe usable hosts are: %d", usable_hosts);

    return 0;
}

int subnet_mask_to_broadcast_address(int network_number, int subnet_mask, int *broadcast_address)
{
    int mask_length;
    int i;

    mask_length = subnet_mask_length(subnet_mask);

    *broadcast_address = network_number | ((1 << mask_length) - 1);

    return 0;
}

int usable_hosts_from_subnet_mask(int subnet_mask, int *usable_hosts)
{
    int mask_length;

    mask_length = subnet_mask_length(subnet_mask);

    *usable_hosts = (1 << mask_length) - 2;

    return 0;
}

int subnet_mask_length(int subnet_mask)
{
    int length = 0;

    while (subnet_mask & (1 << length))
    {
        length++;
    }

    return length;
}