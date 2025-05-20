//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char subnetMask[16];
    char subnetAddress[16];
    int subnetMaskLength;
    int subnetAddressLength;
    int prefixLength;
    int hostBits;
    int broadcastAddress;
    int usableHosts;

    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnetMask);

    subnetMaskLength = countBits(subnetMask);

    printf("Enter subnet address (e.g. 192.168.1.1): ");
    scanf("%s", subnetAddress);

    subnetAddressLength = countBits(subnetAddress);

    prefixLength = subnetMaskLength - subnetAddressLength;

    hostBits = 32 - prefixLength - 1;

    broadcastAddress = (int)pow(2, hostBits) - 1;

    usableHosts = (int)pow(2, hostBits) - 2;

    printf("Prefix length: %d\n", prefixLength);
    printf("Broadcast address: %d\n", broadcastAddress);
    printf("Usable hosts: %d\n", usableHosts);

    return 0;
}

int countBits(char *address)
{
    int count = 0;
    int i = 0;

    while (address[i] != '\0')
    {
        int num = address[i] & 0xFF;
        int bits = 0;

        while (num > 0)
        {
            if (num % 2 == 1)
            {
                bits++;
            }
            num /= 2;
        }

        count += bits;
        i++;
    }

    return count;
}