//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBNET_ADDRESS 255

int main()
{
    int subnet_mask, host_address, network_address, broadcast_address;
    char subnet_mask_str[32], host_address_str[32], network_address_str[32], broadcast_address_str[32];

    printf("Enter subnet mask (in binary): ");
    scanf("%s", subnet_mask_str);

    subnet_mask = convert_subnet_mask_str_to_int(subnet_mask_str);

    printf("Enter host address (in decimal): ");
    scanf("%d", &host_address);

    network_address = calculate_network_address(subnet_mask, host_address);

    broadcast_address = calculate_broadcast_address(subnet_mask, network_address);

    printf("Network address: %s\n", network_address_str);
    printf("Broadcast address: %s\n", broadcast_address_str);

    return 0;
}

int convert_subnet_mask_str_to_int(char *subnet_mask_str)
{
    int subnet_mask = 0;
    int i = 0;

    for (i = 0; subnet_mask_str[i] != '\0'; i++)
    {
        int bit = subnet_mask_str[i] - '0';
        subnet_mask |= 1 << (3 - i) & (MAX_SUBNET_ADDRESS >> (3 - i));
    }

    return subnet_mask;
}

int calculate_network_address(int subnet_mask, int host_address)
{
    int network_address = (host_address & subnet_mask) >> (32 - num_bits(subnet_mask));

    return network_address;
}

int calculate_broadcast_address(int subnet_mask, int network_address)
{
    int broadcast_address = network_address | ~subnet_mask;

    return broadcast_address;
}

int num_bits(int n)
{
    int num_bits = 0;

    while (n)
    {
        n >>= 1;
        num_bits++;
    }

    return num_bits;
}