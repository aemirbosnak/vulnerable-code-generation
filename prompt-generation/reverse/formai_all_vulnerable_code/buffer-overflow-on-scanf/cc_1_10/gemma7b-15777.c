//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SUBNET_CALCULATOR_LINES 100

int main()
{
    int subnetMask, hostBits, networkBits;
    long ipAddress;
    char subnetMaskString[32];
    char ipAddressString[16];

    printf("Welcome to the Subnet Calculator!\n");

    // Get the IP address and subnet mask from the user
    printf("Enter the IP address: ");
    scanf("%ld.%ld.%ld.%ld", &ipAddress);

    printf("Enter the subnet mask: ");
    scanf("%x", &subnetMask);

    // Calculate the network bits and host bits
    networkBits = 32 - __builtin_popcount(subnetMask);
    hostBits = 32 - networkBits;

    // Convert the subnet mask to a string
    subnetMaskString[0] = ' ';
    for (int i = 1; i <= networkBits; i++)
    {
        subnetMaskString[i] = '1';
    }
    subnetMaskString[networkBits + 1] = '\0';

    // Convert the IP address to a string
    ipAddressString[0] = ' ';
    for (int i = 1; i <= 3; i++)
    {
        ipAddressString[i] = (ipAddress & (1 << (3 - i))) >> (3 - i);
    }
    ipAddressString[3] = '.';
    ipAddressString[4] = '0';

    // Print the results
    printf("The subnet mask is: %s\n", subnetMaskString);
    printf("The number of network bits is: %d\n", networkBits);
    printf("The number of host bits is: %d\n", hostBits);
    printf("The IP address is: %s\n", ipAddressString);

    return 0;
}