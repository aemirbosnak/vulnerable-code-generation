//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~ Cyberpunks Subnet Calculator ~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    char ip_address[16];
    int subnet_mask;

    printf("Enter the IP address in a.b.c.d format: ");
    scanf("%s", ip_address);

    printf("Enter the subnet mask in CIDR notation: ");
    scanf("%d", &subnet_mask);

    // Split the IP address into four octets
    char *token = strtok(ip_address, ".");
    int octet[4];
    int i = 0;

    while(token != NULL)
    {
        octet[i++] = atoi(token);
        token = strtok(NULL, ".");
    }

    // Determine the subnet mask
    int mask[4];
    memset(mask, 0, sizeof(mask));
    int j;
    for(j = 0; j < 4; j++)
    {
        if(subnet_mask >= 8)
        {
            mask[j] = 255;
            subnet_mask -= 8;
        }
        else if(subnet_mask > 0)
        {
            int power = 8 - subnet_mask;
            int value = 1;
            while(power--)
            {
                value *= 2;
            }
            mask[j] = 256 - value;
            subnet_mask = 0;
        }
    }

    // Determine the network and broadcast addresses
    int network[4];
    int broadcast[4];

    for(j = 0; j < 4; j++)
    {
        network[j] = octet[j] & mask[j];
        broadcast[j] = octet[j] | (255 - mask[j]);
    }

    printf("\nNetwork Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);

    int hosts = 0;
    for(j = 0; j < 4; j++)
    {
        if(mask[j] != 255)  // If it's not a full octet, there are hosts
        {
            int power = 8;
            int value = mask[j];
            while(value < 256)
            {
                hosts += value;
                value *= 2;
                power--;
            }
            hosts -= mask[j];
        }
    }
    printf("Number of Hosts: %d\n", hosts);
    printf("Subnet Mask: %d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    return 0;
}