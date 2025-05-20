//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char subnetMask[16];
    char subnetAddress[16];
    int maskLength, addressLength, prefixLength, address, subnet, broadcastAddress;

    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnetMask);

    printf("Enter subnet address (e.g. 192.168.1.1): ");
    scanf("%s", subnetAddress);

    maskLength = calculateMaskLength(subnetMask);
    addressLength = calculateAddressLength(subnetMask);
    prefixLength = maskLength - addressLength;

    address = convertSubNetAddressToInteger(subnetAddress);
    subnet = calculateSubnet(address, subnetMask);
    broadcastAddress = calculateBroadcastAddress(address, subnetMask);

    printf("Subnet mask: %s\n", subnetMask);
    printf("Subnet address: %s\n", subnetAddress);
    printf("Prefix length: %d\n", prefixLength);
    printf("Subnet: %d\n", subnet);
    printf("Broadcast address: %d\n", broadcastAddress);

    return 0;
}

int calculateMaskLength(char *subnetMask)
{
    int maskLength = 0;

    while (subnetMask[maskLength] != '\0')
    {
        maskLength++;
    }

    return maskLength;
}

int calculateAddressLength(char *subnetMask)
{
    int addressLength = 0;

    while (subnetMask[addressLength] != '/')
    {
        addressLength++;
    }

    return addressLength;
}

int convertSubNetAddressToInteger(char *subnetAddress)
{
    int address = 0;
    int i = 0;

    for (i = 0; subnetAddress[i] != '\0'; i++)
    {
        address += (subnetAddress[i] - '0') * pow(2, 3 - i) ;
    }

    return address;
}

int calculateSubnet(int address, char *subnetMask)
{
    int subnet = 0;
    int maskLength = calculateMaskLength(subnetMask);

    subnet = (address & ~(~0 << maskLength)) >> maskLength;

    return subnet;
}

int calculateBroadcastAddress(int address, char *subnetMask)
{
    int broadcastAddress = address | ~((~0 << calculateMaskLength(subnetMask)) & ~0);

    return broadcastAddress;
}