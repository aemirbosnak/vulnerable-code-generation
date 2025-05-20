//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int network_address, subnet_mask, broadcast_address, host_address;

    printf("Welcome to the Galactic Subnet Calculator!\n");
    printf("Please enter the network address in the format of xx.xx.xx.xx:");
    scanf("%d", &network_address);

    printf("Enter the subnet mask in the format of xx.xx.xx.xxx:");
    scanf("%d", &subnet_mask);

    subnet_mask_calculator(network_address, subnet_mask);

    broadcast_address = calculate_broadcast_address(network_address, subnet_mask);
    host_address = calculate_host_address(network_address, subnet_mask);

    printf("The broadcast address is: %d.%d.%d.%d\n", broadcast_address);
    printf("The host address is: %d.%d.%d.%d\n", host_address);

    return 0;
}

int subnet_mask_calculator(int network_address, int subnet_mask)
{
    int num_bits = 0;

    while (subnet_mask & 1)
    {
        subnet_mask >>= 1;
        num_bits++;
    }

    printf("The number of subnet bits is: %d\n", num_bits);

    return num_bits;
}

int calculate_broadcast_address(int network_address, int subnet_mask)
{
    int broadcast_address = network_address & ~subnet_mask;

    return broadcast_address;
}

int calculate_host_address(int network_address, int subnet_mask)
{
    int host_address = (network_address & subnet_mask) + 1;

    return host_address;
}