//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNET_SIZE 256

int main()
{
    char subnet_address[MAX_SUBNET_SIZE];
    int subnet_mask_length;
    int network_address;
    int host_address;

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter the subnet address: ");
    scanf("%s", subnet_address);

    printf("Enter the subnet mask length (e.g. 24 for /24): ");
    scanf("%d", &subnet_mask_length);

    network_address = calculate_network_address(subnet_address, subnet_mask_length);
    host_address = calculate_host_address(network_address, subnet_mask_length);

    printf("The network address is: %d.%d.%d.%d\n", network_address & 0xff, (network_address & 0xff00) >> 8, (network_address & 0xff0000) >> 16, (network_address & 0xff000000) >> 24);

    printf("The host address is: %d\n", host_address);

    return 0;
}

int calculate_network_address(char *subnet_address, int subnet_mask_length)
{
    int network_address;
    int mask_length;
    int i;

    network_address = inet_addr(subnet_address);
    mask_length = subnet_mask_length;

    for (i = 0; i < mask_length; i++)
    {
        if ((network_address & (1 << i)) == 0)
        {
            network_address &= ~(1 << i);
        }
    }

    return network_address;
}

int calculate_host_address(int network_address, int subnet_mask_length)
{
    int host_address;
    int mask_length;
    int i;

    mask_length = subnet_mask_length;

    for (i = 0; i < mask_length; i++)
    {
        if ((network_address & (1 << i)) != 0)
        {
            host_address = network_address & ~(1 << i);
            break;
        }
    }

    return host_address;
}