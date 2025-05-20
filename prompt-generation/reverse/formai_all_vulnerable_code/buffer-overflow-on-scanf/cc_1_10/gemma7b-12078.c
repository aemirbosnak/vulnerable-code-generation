//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int network_address, subnet_mask, broadcast_address, host_address;

    printf("Enter the network address: ");
    scanf("%d", &network_address);

    printf("Enter the subnet mask: ");
    scanf("%d", &subnet_mask);

    subnet_mask_calculator(network_address, subnet_mask);

    broadcast_address = broadcast_address_calculator(network_address, subnet_mask);

    host_address = host_address_calculator(network_address, subnet_mask);

    printf("The broadcast address is: %d", broadcast_address);
    printf("\nThe host address is: %d", host_address);

    return 0;
}

int subnet_mask_calculator(int network_address, int subnet_mask)
{
    int subnet_mask_length = 0;

    while ((subnet_mask & 1) == 0)
    {
        subnet_mask >>= 1;
        subnet_mask_length++;
    }

    return subnet_mask_length;
}

int broadcast_address_calculator(int network_address, int subnet_mask)
{
    int broadcast_address = network_address | (~subnet_mask & 0xFFFFFFFF);

    return broadcast_address;
}

int host_address_calculator(int network_address, int subnet_mask)
{
    int host_address = (network_address & ~subnet_mask) | 1;

    return host_address;
}