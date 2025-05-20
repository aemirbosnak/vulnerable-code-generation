//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char subnetMask[16];
    char subnetAddress[16];
    int subnetMaskLen;
    int subnetAddressLen;

    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnetMask);

    printf("Enter subnet address (e.g. 192.168.1.1): ");
    scanf("%s", subnetAddress);

    subnetMaskLen = strlen(subnetMask) - 1;
    subnetAddressLen = strlen(subnetAddress) - 1;

    if (subnetMaskLen > 3 || subnetMaskLen < 0)
    {
        printf("Error: Invalid subnet mask length.\n");
        return 1;
    }

    if (subnetAddressLen > 3 || subnetAddressLen < 0)
    {
        printf("Error: Invalid subnet address length.\n");
        return 1;
    }

    // Calculate subnet prefix length
    int prefixLen = 0;
    for (int i = 0; i < subnetMaskLen; i++)
    {
        if (subnetMask[i] == '0')
        {
            prefixLen++;
        }
    }

    // Calculate subnet broadcast address
    char subnetBroadcast[16];
    subnetBroadcast[0] = subnetAddress[0] & ~((1 << (32 - prefixLen)) - 1);
    subnetBroadcast[1] = subnetAddress[1] & ~((1 << (32 - prefixLen)) - 1);
    subnetBroadcast[2] = subnetAddress[2] & ~((1 << (32 - prefixLen)) - 1);
    subnetBroadcast[3] = subnetAddress[3] & ~((1 << (32 - prefixLen)) - 1);

    // Print subnet prefix length and broadcast address
    printf("Subnet prefix length: %d\n", prefixLen);
    printf("Subnet broadcast address: %s\n", subnetBroadcast);

    return 0;
}