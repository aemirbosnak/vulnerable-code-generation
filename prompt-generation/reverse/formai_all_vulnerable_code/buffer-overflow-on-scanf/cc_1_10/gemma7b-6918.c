//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    // Define variables
    char subnetMask[16] = "";
    char networkAddress[16] = "";
    int subnetMaskBits = 0;
    int networkAddressBits = 0;
    int broadcastAddressBits = 0;
    int usableHosts = 0;

    // Get subnet mask and network address from user
    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnetMask);

    // Calculate subnet mask bits
    subnetMaskBits = countSetBits(subnetMask);

    // Calculate network address bits
    networkAddressBits = subnetMaskBits - 3;

    // Calculate broadcast address bits
    broadcastAddressBits = subnetMaskBits - 1;

    // Calculate usable hosts
    usableHosts = pow(2, networkAddressBits) - 2;

    // Print results
    printf("\nSubnet Mask:** %s\n", subnetMask);
    printf("Number of Subnet Mask Bits:** %d\n", subnetMaskBits);
    printf("Number of Network Address Bits:** %d\n", networkAddressBits);
    printf("Number of Broadcast Address Bits:** %d\n", broadcastAddressBits);
    printf("Number of Usable Hosts:** %d\n", usableHosts);

    return 0;
}

int countSetBits(char *mask)
{
    int count = 0;
    int i = 0;

    while (mask[i] != '\0')
    {
        if (mask[i] & 0x80)
        {
            count++;
        }
        i++;
    }

    return count;
}