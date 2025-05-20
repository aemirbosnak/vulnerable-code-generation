//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    // Declare variables
    int subnetMask, broadcastAddress, networkAddress, hostAddress, subnetNumber;
    char subnetMaskStr[32], broadcastAddressStr[32], networkAddressStr[32], hostAddressStr[32];

    // Get subnet mask from user
    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnetMaskStr);

    // Convert subnet mask to integer
    subnetMask = atoi(subnetMaskStr);

    // Calculate subnet mask bits
    subnetNumber = countSetBits(subnetMask);

    // Calculate broadcast address
    broadcastAddress = pow(2, subnetNumber) - 1;

    // Calculate network address
    networkAddress = (subnetMask & ~broadcastAddress) >> subnetNumber;

    // Calculate host address
    hostAddress = broadcastAddress - networkAddress - 1;

    // Print results
    printf("Subnet Mask: %s\n", subnetMaskStr);
    printf("Broadcast Address: %s\n", broadcastAddressStr);
    printf("Network Address: %s\n", networkAddressStr);
    printf("Host Address: %s\n", hostAddressStr);

    return 0;
}

int countSetBits(int num) {
    int count = 0;

    while (num) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }

    return count;
}