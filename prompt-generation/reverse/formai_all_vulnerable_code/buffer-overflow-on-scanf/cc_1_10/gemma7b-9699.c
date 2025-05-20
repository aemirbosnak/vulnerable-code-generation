//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int subnetMaskLength = 0;
    int subnetMask = 0;
    int hostBits = 0;
    int broadcastAddress = 0;
    char subnetMaskStr[32] = "";

    printf("Enter the subnet mask in binary (e.g. 255.255.255.0 for /8): ");
    scanf("%s", subnetMaskStr);

    // Convert the subnet mask string to an integer
    subnetMask = convertSubnetMaskStrToInt(subnetMaskStr);

    // Calculate the subnet mask length
    subnetMaskLength = calculateSubnetMaskLength(subnetMask);

    // Calculate the number of host bits
    hostBits = calculateHostBits(subnetMaskLength);

    // Calculate the broadcast address
    broadcastAddress = calculateBroadcastAddress(subnetMask, hostBits);

    // Print the results
    printf("Subnet mask length: %d\n", subnetMaskLength);
    printf("Number of host bits: %d\n", hostBits);
    printf("Broadcast address: %d\n", broadcastAddress);

    return 0;
}

int convertSubnetMaskStrToInt(char *subnetMaskStr)
{
    int subnetMask = 0;
    int i = 0;

    while (subnetMaskStr[i] != '\0')
    {
        int digit = subnetMaskStr[i] - '0';
        subnetMask = subnetMask << 8 | digit;
        i++;
    }

    return subnetMask;
}

int calculateSubnetMaskLength(int subnetMask)
{
    int length = 0;

    while (subnetMask >> length)
    {
        length++;
    }

    return length;
}

int calculateHostBits(int subnetMaskLength)
{
    return 32 - subnetMaskLength;
}

int calculateBroadcastAddress(int subnetMask, int hostBits)
{
    int broadcastAddress = (subnetMask & (~0 << hostBits)) | 0;

    return broadcastAddress;
}