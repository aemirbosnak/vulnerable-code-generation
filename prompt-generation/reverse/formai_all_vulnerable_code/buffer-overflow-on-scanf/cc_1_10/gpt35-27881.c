//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: retro
#include<stdio.h>
#include<string.h>

// Function to convert binary to decimal
int binaryToDecimal(int binaryNum)
{
    int decimalNum = 0, base = 1, rem;

    while (binaryNum > 0)
    {
        rem = binaryNum % 10;
        decimalNum += rem * base;
        binaryNum /= 10 ;
        base *= 2;
    }

    return decimalNum;
}

int main()
{
    int mask, subnetBits, numSubnets, numHosts, subnetMask, subnetSize;
    char firstClass[3], secondClass[3], thirdClass[3];

    printf("Welcome to Retro Style C Subnet Calculator!\n");

    // Taking input of network class
    printf("Enter the network class:\n");
    scanf("%s", thirdClass);

    // Third class subnetting
    if (thirdClass[0] == 'C')
    {
        mask = 255;
        subnetBits = 6;
        numSubnets = 64;
        numHosts = 30;
    }
    else if (thirdClass[0] == 'B')
    {
        mask = 65535;
        subnetBits = 14;
        numSubnets = 16384;
        numHosts = 254;
    }
    else if (thirdClass[0] == 'A')
    {
        mask = 16777215;
        subnetBits = 22;
        numSubnets = 4194304;
        numHosts = 1022;
    }
    else // invalid input
    {
        printf("Invalid Input!\n");
        return 0;
    }

    // Displaying Results
    printf("\n");
    printf("The subnet mask: 255.255.255.%d\n", mask & 0xff);
    printf("The number of subnets: %d\n", numSubnets);
    printf("The number of hosts per subnet: %d\n", numHosts);
    printf("\n");

    // Taking input of IP address
    printf("Enter the IP address: (example: 192.168.10.10)\n");
    int a, b, c, d;
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);

    // Calculating subnet mask
    subnetMask = binaryToDecimal(mask & 0xff);

    // Displaying subnet mask
    printf("\nThe subnet mask is: %d.%d.%d.%d\n", 
           subnetMask, subnetMask, subnetMask, subnetMask);

    // Calculating subnet size
    subnetSize = numHosts + 2; // adding 2 for network and broadcast addresses

    // Displaying subnet size
    printf("\nThe subnet size is: %d\n", subnetSize);
    printf("\n");

    printf("Calculations for each subnet:\n");
    printf("\nIP Address           Subnet Mask         First Host           Last Host            Broadcast\n");

    // Loop for calculation for each subnet
    for (int i=0; i<numSubnets; i++)
    {
        int subnetNum = i+1;

        // Calculating subnet mask using subnet bits
        int temp = 0;
        for (int j=0; j<subnetBits; j++) 
        {
            temp |= 1 << (31-j);
        }
        temp >>= subnetBits;

        int subnetMask = binaryToDecimal(temp);

        // Calculating network address
        int networkAddress = ((a & subnetMask) << 24) + ((b & subnetMask) << 16);
        networkAddress += ((c & subnetMask) << 8) + (d & subnetMask);

        // Calculating host range
        int firstHostAddress = networkAddress + 1;
        int lastHostAddress = (networkAddress | temp) - 1;

        // Calculating broadcast address
        int broadcastAddress = (networkAddress | temp);

        // Displaying Results
        printf("%d.%d.%d.%d     %d.%d.%d.%d     %d.%d.%d.%d     %d.%d.%d.%d     %d.%d.%d.%d\n",
               a,b,c,d,
               subnetMask,subnetMask,subnetMask,subnetMask,
               (firstHostAddress>>24)&0xff,(firstHostAddress>>16)&0xff,(firstHostAddress>>8)&0xff,firstHostAddress&0xff,
               (lastHostAddress>>24)&0xff,(lastHostAddress>>16)&0xff,(lastHostAddress>>8)&0xff,lastHostAddress&0xff,
               (broadcastAddress>>24)&0xff,(broadcastAddress>>16)&0xff,(broadcastAddress>>8)&0xff,broadcastAddress&0xff);
    }

    return 0;
}