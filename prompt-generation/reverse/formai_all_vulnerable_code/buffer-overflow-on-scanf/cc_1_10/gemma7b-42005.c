//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int subnet_mask, host_mask, broadcast_address, network_address, num_hosts;
    char subnet_mask_bin[32], host_mask_bin[32], broadcast_address_bin[32], network_address_bin[32];

    printf("Enter the subnet mask in decimal:");
    scanf("%d", &subnet_mask);

    subnet_mask_bin[0] = (subnet_mask & 0xFF000000) >> 24;
    subnet_mask_bin[1] = (subnet_mask & 0x0F0000) >> 16;
    subnet_mask_bin[2] = (subnet_mask & 0x00F000) >> 8;
    subnet_mask_bin[3] = (subnet_mask & 0x000F00) >> 0;

    printf("Subnet mask in binary: ");
    for(int i = 0; subnet_mask_bin[i] != '\0'; i++)
    {
        printf("%d ", subnet_mask_bin[i]);
    }

    printf("\n");

    printf("Enter the host mask in decimal:");
    scanf("%d", &host_mask);

    host_mask_bin[0] = (host_mask & 0xFF000000) >> 24;
    host_mask_bin[1] = (host_mask & 0x0F0000) >> 16;
    host_mask_bin[2] = (host_mask & 0x00F000) >> 8;
    host_mask_bin[3] = (host_mask & 0x000F00) >> 0;

    printf("Host mask in binary: ");
    for(int i = 0; host_mask_bin[i] != '\0'; i++)
    {
        printf("%d ", host_mask_bin[i]);
    }

    printf("\n");

    network_address = (subnet_mask & ~host_mask) & ~0xFF;

    network_address_bin[0] = (network_address & 0xFF000000) >> 24;
    network_address_bin[1] = (network_address & 0x0F0000) >> 16;
    network_address_bin[2] = (network_address & 0x00F000) >> 8;
    network_address_bin[3] = (network_address & 0x000F00) >> 0;

    printf("Network address in binary: ");
    for(int i = 0; network_address_bin[i] != '\0'; i++)
    {
        printf("%d ", network_address_bin[i]);
    }

    printf("\n");

    broadcast_address = network_address | host_mask;

    broadcast_address_bin[0] = (broadcast_address & 0xFF000000) >> 24;
    broadcast_address_bin[1] = (broadcast_address & 0x0F0000) >> 16;
    broadcast_address_bin[2] = (broadcast_address & 0x00F000) >> 8;
    broadcast_address_bin[3] = (broadcast_address & 0x000F00) >> 0;

    printf("Broadcast address in binary: ");
    for(int i = 0; broadcast_address_bin[i] != '\0'; i++)
    {
        printf("%d ", broadcast_address_bin[i]);
    }

    printf("\n");

    num_hosts = (pow(2, 32 - host_mask) - 2) / 2;

    printf("Number of hosts: %d", num_hosts);

    return 0;
}