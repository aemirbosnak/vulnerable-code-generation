//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Variable Declarations
    int subnetMask, hostBits, networkBits, subnetAddress, hostAddress, broadcastAddress;
    char subnetMaskStr[16], hostBitsStr[16], networkBitsStr[16];

    // Get Subnet Mask
    printf("Enter Subnet Mask (e.g. 255.255.255.0): ");
    scanf("%s", subnetMaskStr);

    // Convert Subnet Mask to Integer
    subnetMask = atoi(subnetMaskStr);

    // Calculate Network Bits
    networkBits = 32 - numberOfLeadingZeros(subnetMask);

    // Calculate Host Bits
    hostBits = 32 - networkBits - 1;

    // Calculate Subnet Address
    subnetAddress = (subnetMask & ~0xFF) >> 8;

    // Calculate Host Address
    hostAddress = (subnetMask & 0xFF) & ~0;

    // Calculate Broadcast Address
    broadcastAddress = subnetAddress | (hostBits - 1);

    // Display Results
    printf("\nSubnet Mask: %s", subnetMaskStr);
    printf("\nNetwork Bits: %s", networkBitsStr);
    printf("\nHost Bits: %s", hostBitsStr);
    printf("\nSubnet Address: %d", subnetAddress);
    printf("\nHost Address: %d", hostAddress);
    printf("\nBroadcast Address: %d", broadcastAddress);

    return 0;
}

int numberOfLeadingZeros(int num)
{
    int count = 0;

    while (num & 1 == 0)
    {
        num >>= 1;
        count++;
    }

    return count;
}