//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char ip_address[16];
    int subnet_mask;
    int octets[4];
    int subnet_octets[4];
    int wildcard_octets[4];
    int network_octets[4];
    int broadcast_octets[4];

    printf("Enter your IP Address (e.g., 192.168.1.1): ");
    scanf("%s", ip_address);

    printf("Enter your Subnet Mask in CIDR notation (e.g., /24): ");
    scanf("%d", &subnet_mask);

    // Split the IP address into octets
    sscanf(ip_address, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);

    // Calculate the subnet mask
    memset(subnet_octets, 0, sizeof(subnet_octets));
    int i;
    for(i = 0; i < subnet_mask; ++i)
    {
        subnet_octets[i/8] |= 1 << (7 - (i % 8));
    }

    // Calculate the wildcard mask
    for(i = 0; i < 4; ++i)
    {
        wildcard_octets[i] = 255 - subnet_octets[i];
    }

    // Calculate the network address
    for(i = 0; i < 4; ++i)
    {
        network_octets[i] = octets[i] & subnet_octets[i];
    }

    // Calculate the broadcast address
    for(i = 0; i < 4; ++i)
    {
        broadcast_octets[i] = network_octets[i] | wildcard_octets[i];
    }

    // Display the results
    printf("IP Address: %s\n", ip_address);
    printf("Subnet Mask: /%d\n", subnet_mask);
    printf("Network Address: %d.%d.%d.%d\n", network_octets[0], network_octets[1], network_octets[2], network_octets[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_octets[0], broadcast_octets[1], broadcast_octets[2], broadcast_octets[3]);
    printf("Host Range: %d.%d.%d.%d - %d.%d.%d.%d\n", network_octets[0], network_octets[1], network_octets[2], network_octets[3]+1, broadcast_octets[0], broadcast_octets[1], broadcast_octets[2], broadcast_octets[3]-1);

    return 0;
}