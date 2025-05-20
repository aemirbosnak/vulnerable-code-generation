//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ip_address[20], subnet_mask[20];
    int i, n = 0, k, octet, bits;
    int subnet[4] = {0, 0, 0, 0};

    printf("Enter IP Address: ");
    scanf("%s", ip_address);
    printf("Enter Subnet Mask: ");
    scanf("%s", subnet_mask);

    for (i = 0; i < strlen(subnet_mask); i++)
    {
        if (subnet_mask[i] == '.')
        {
            n++;
        }
    }

    if (n != 3)
    {
        printf("Invalid Subnet Mask!\n");
        return 0;
    }

    n = 0;
    k = 0;
    for (i = 0; i <= strlen(subnet_mask); i++)
    {
        if (subnet_mask[i] == '.' || i == strlen(subnet_mask))
        {
            octet = atoi(subnet_mask + k);
            if (octet < 0 || octet > 255)
            {
                printf("Invalid Subnet Mask!\n");
                return 0;
            }
            subnet[n++] = octet;
            k = i + 1;
        }
    }

    bits = subnet[0]*256*256*256 + subnet[1]*256*256 + subnet[2]*256 + subnet[3];
    for (i = 31; i >= 0; i--)
    {
        if (((bits >> i) & 1) == 1)
        {
            break;
        }
    }

    int total_hosts = (1 << (32-i)) - 2;
    int wildcard[4];
    wildcard[0] = 255 - subnet[0];
    wildcard[1] = 255 - subnet[1];
    wildcard[2] = 255 - subnet[2];
    wildcard[3] = 255 - subnet[3];

    printf("\nSubnet Information:\n");
    printf("IP Address: %s\n", ip_address);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Wildcard Mask: %d.%d.%d.%d\n", wildcard[0], wildcard[1], wildcard[2], wildcard[3]);
    printf("Network Address: %d.%d.%d.%d\n", (int)(subnet[0] & (int)ip_address[0]), (int)(subnet[1] & (int)ip_address[1]), (int)(subnet[2]
            & (int)ip_address[2]), (int)(subnet[3] & (int)ip_address[3]));
    printf("Broadcast Address: %d.%d.%d.%d\n", ((subnet[0] & (int)ip_address[0]) + wildcard[0]), ((subnet[1] & (int)ip_address[1]) + wildcard[1]), (
           (subnet[2] & (int)ip_address[2]) + wildcard[2]), ((subnet[3] & (int)ip_address[3]) + wildcard[3]));
    printf("Total Hosts: %d\n", total_hosts);
    
    return 0;
}