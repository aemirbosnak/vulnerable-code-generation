//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 255

void subnet_calculator()
{
    int network_address, subnet_mask, host_address, prefix_length;
    char subnet_mask_binary[MAX], host_address_binary[MAX];

    printf("Enter the network address: ");
    scanf("%d", &network_address);

    printf("Enter the subnet mask: ");
    scanf("%d", &subnet_mask);

    printf("Enter the host address: ");
    scanf("%d", &host_address);

    printf("Enter the prefix length: ");
    scanf("%d", &prefix_length);

    // Calculate the subnet mask in binary
    subnet_mask_binary[0] = (subnet_mask & 0xFF0000) >> 16;
    subnet_mask_binary[1] = (subnet_mask & 0x0F0000) >> 8;
    subnet_mask_binary[2] = (subnet_mask & 0x00F000) >> 4;
    subnet_mask_binary[3] = (subnet_mask & 0x000F00) >> 0;

    // Calculate the host address in binary
    host_address_binary[0] = (host_address & 0xFF0000) >> 16;
    host_address_binary[1] = (host_address & 0x0F0000) >> 8;
    host_address_binary[2] = (host_address & 0x00F000) >> 4;
    host_address_binary[3] = (host_address & 0x000F00) >> 0;

    // Print the subnet mask and host address in binary
    printf("Subnet mask in binary: ");
    for (int i = 0; subnet_mask_binary[i] != '\0'; i++)
    {
        printf("%d ", subnet_mask_binary[i]);
    }

    printf("\nHost address in binary: ");
    for (int i = 0; host_address_binary[i] != '\0'; i++)
    {
        printf("%d ", host_address_binary[i]);
    }

    printf("\nNumber of hosts in subnet: ");
    int num_hosts = pow(2, 32 - prefix_length) - 2;
    printf("%d", num_hosts);
}

int main()
{
    subnet_calculator();

    return 0;
}