//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    system("clear");
    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter the network address: ");
    char network_address[16];
    scanf("%s", network_address);

    printf("Please enter the subnet mask: ");
    char subnet_mask[16];
    scanf("%s", subnet_mask);

    int network_bits = 0;
    int subnet_bits = 0;
    int host_bits = 0;

    for (int i = 0; network_address[i] != '\0'; i++)
    {
        if (network_address[i] == '/')
        {
            network_bits = atoi(&network_address[i + 1]);
            break;
        }
    }

    for (int i = 0; subnet_mask[i] != '\0'; i++)
    {
        if (subnet_mask[i] == '/')
        {
            subnet_bits = atoi(&subnet_mask[i + 1]);
            break;
        }
    }

    host_bits = 32 - network_bits - subnet_bits;

    printf("The number of network bits is: %d\n", network_bits);
    printf("The number of subnet bits is: %d\n", subnet_bits);
    printf("The number of host bits is: %d\n", host_bits);

    printf("The subnet mask in binary is: ");
    for (int i = 0; subnet_mask[i] != '\0'; i++)
    {
        if (subnet_mask[i] == '/')
        {
            break;
        }
        printf("%d ", subnet_mask[i]);
    }

    printf("\nThe broadcast address is: ");
    char broadcast_address[16];
    sprintf(broadcast_address, "%s", network_address);
    broadcast_address[network_bits - 1] = 255;
    for (int i = network_bits - 1; broadcast_address[i] != '\0'; i++)
    {
        printf("%d ", broadcast_address[i]);
    }

    printf("\nThe usable host range is: ");
    char usable_host_range[16];
    sprintf(usable_host_range, "%s", network_address);
    usable_host_range[network_bits - 1] = 254;
    for (int i = network_bits - 1; usable_host_range[i] != '\0'; i++)
    {
        printf("%d ", usable_host_range[i]);
    }

    return 0;
}