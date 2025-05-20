//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mask, net_addr, subnet_mask, host_addr, cidr_mask;
    char subnet_mask_str[12];

    printf("Welcome to the Retro Subnet Calculator!\n");

    // Get the subnet mask in binary
    printf("Enter the subnet mask in binary (e.g. 255.255.255.0): ");
    scanf("%d", &mask);

    // Convert the subnet mask to a decimal string
    subnet_mask_str[0] = (mask >> 24) & 0xFF;
    subnet_mask_str[1] = (mask >> 16) & 0xFF;
    subnet_mask_str[2] = (mask >> 8) & 0xFF;
    subnet_mask_str[3] = mask & 0xFF;
    subnet_mask_str[4] = '\0';

    // Print the subnet mask in decimal
    printf("Subnet mask in decimal: %s\n", subnet_mask_str);

    // Get the network address
    printf("Enter the network address: ");
    scanf("%d", &net_addr);

    // Calculate the subnet address
    subnet_mask = mask & net_addr;
    net_addr &= ~subnet_mask;

    // Print the subnet address
    printf("Subnet address: %d\n", net_addr);

    // Get the host address
    printf("Enter the host address: ");
    scanf("%d", &host_addr);

    // Calculate the host address
    host_addr &= subnet_mask;

    // Print the host address
    printf("Host address: %d\n", host_addr);

    // Get the CIDR mask
    cidr_mask = 32 - ((mask & 0xFFFFFFFF) / 32);

    // Print the CIDR mask
    printf("CIDR mask: /%d\n", cidr_mask);

    return 0;
}