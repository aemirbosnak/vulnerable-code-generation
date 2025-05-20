//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

//Function to convert binary to decimal
int binToDec(int bin)
{
    int dec = 0, i = 0, rem;
    while (bin != 0)
    {
        rem = bin % 10;
        bin /= 10;
        dec += rem * (1 << i);
        ++i;
    }
    return dec;
}

int main()
{
    int ip[4], subnetMask[4], networkAddress[4], broadcastAddress[4];
    int subnetBits, hostsCount, i;

    //Getting IP address from user
    printf("Enter IP address (4 octets): ");
    for (i = 0; i < 4; ++i)
    {
        scanf("%d", &ip[i]);
    }

    //Getting subnet mask from user
    printf("Enter subnet mask (4 octets): ");
    for (i = 0; i < 4; ++i)
    {
        scanf("%d", &subnetMask[i]);
    }

    //Calculating number of subnet bits and host bits
    for (i = 0; i < 4; ++i)
    {
        subnetBits += __builtin_popcount(subnetMask[i]);
    }
    hostsCount = 32 - subnetBits;

    //Calculating network address and broadcast address
    for (i = 0; i < 4; ++i)
    {
        networkAddress[i] = ip[i] & subnetMask[i];
        broadcastAddress[i] = networkAddress[i] | ~subnetMask[i];
    }

    //Printing the results
    printf("\nThe network address is: ");
    for (i = 0; i < 4; ++i)
    {
        printf("%d", networkAddress[i]);
        if (i != 3)
            printf(".");
    }

    printf("\nThe broadcast address is: ");
    for (i = 0; i < 4; ++i)
    {
        printf("%d", broadcastAddress[i]);
        if (i != 3)
            printf(".");
    }

    //Calculating number of usable hosts
    printf("\nNumber of usable hosts in subnet: %d", 1 << hostsCount);

    //Calculating first and last usable addresses
    int firstAddress[4], lastAddress[4];
    for (i = 0; i < 4; ++i)
    {
        if (i == 3)
        {
            firstAddress[i] = networkAddress[i] + 1;
            lastAddress[i] = broadcastAddress[i] - 1;
        }
        else
        {
            firstAddress[i] = networkAddress[i];
            lastAddress[i] = broadcastAddress[i];
        }
    }

    //Printing first and last usable addresses
    printf("\nFirst usable address: ");
    for (i = 0; i < 4; ++i)
    {
        printf("%d", firstAddress[i]);
        if (i != 3)
            printf(".");
    }

    printf("\nLast usable address: ");
    for (i = 0; i < 4; ++i)
    {
        printf("%d", lastAddress[i]);
        if (i != 3)
            printf(".");
    }

    return 0;
}