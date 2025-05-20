//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char subnetMask[16];
    char networkAddress[16];
    int subnetMaskLength;
    int networkAddressLength;
    int broadcastAddressLength;
    int hostBits;
    int numHosts;

    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnetMask);

    printf("Enter network address (e.g. 192.168.1.1): ");
    scanf("%s", networkAddress);

    subnetMaskLength = countBits(subnetMask);
    networkAddressLength = countBits(networkAddress);

    broadcastAddressLength = subnetMaskLength - networkAddressLength;
    hostBits = 32 - subnetMaskLength - networkAddressLength;
    numHosts = pow(2, hostBits) - 1;

    printf("Subnet Mask Length: %d\n", subnetMaskLength);
    printf("Network Address Length: %d\n", networkAddressLength);
    printf("Broadcast Address Length: %d\n", broadcastAddressLength);
    printf("Host Bits: %d\n", hostBits);
    printf("Number of Hosts: %d\n", numHosts);

    return 0;
}

int countBits(char *addr)
{
    int numBits = 0;
    while (*addr)
    {
        int mask = 1;
        for (int i = 0; i < 8; i++)
        {
            if ((*addr & mask) != 0)
            {
                numBits++;
            }
            mask <<= 1;
        }
        addr++;
    }
    return numBits;
}