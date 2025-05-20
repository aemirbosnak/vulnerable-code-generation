//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int ipAddress[4], subnetMask[4];
    int subnetBits, subnetBytes, i, j;

    printf("Enter IP Address (ex: 192.168.0.1): ");
    scanf("%d.%d.%d.%d", &ipAddress[0], &ipAddress[1], &ipAddress[2], &ipAddress[3]);

    printf("Enter Subnet Mask (ex: 255.255.255.0): ");
    scanf("%d.%d.%d.%d", &subnetMask[0], &subnetMask[1], &subnetMask[2], &subnetMask[3]);

    printf("\nCalculating...\n\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 7; j >= 0; j--)
        {
            if ((subnetMask[i] >> j) & 1)
                subnetBits++;
        }
    }

    subnetBytes = ceil(subnetBits / 8.0);

    printf("Subnet Mask in Bits: %d\n", subnetBits);
    printf("Subnet Mask in Bytes: %d\n", subnetBytes);

    int numSubnets = pow(2, subnetBits) - 2;
    int numHosts = pow(2, (32 - subnetBits)) - 2;

    printf("Number of Subnets: %d\n", numSubnets);
    printf("Number of Hosts: %d\n", numHosts);

    int networkAddress[4], broadcastAddress[4];

    for (i = 0; i < 4; i++)
    {
        networkAddress[i] = (ipAddress[i] & subnetMask[i]);
        broadcastAddress[i] = (ipAddress[i] | (~subnetMask[i] & 0xff));
    }

    printf("Network Address: %d.%d.%d.%d\n", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddress[0], broadcastAddress[1], broadcastAddress[2], broadcastAddress[3]);

    return 0;
}