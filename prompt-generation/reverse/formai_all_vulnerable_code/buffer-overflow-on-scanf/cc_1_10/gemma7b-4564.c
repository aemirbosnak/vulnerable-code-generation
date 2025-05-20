//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBNETS 256

int main()
{
    int numSubnets, subnetMask, minHosts, maxHosts, currentHosts = 0, i;
    char subnetAddress[32];

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please provide the subnet mask in CIDR notation:");
    scanf("%d", &subnetMask);

    printf("Please provide the subnet address:");
    scanf("%s", subnetAddress);

    numSubnets = calculateNumSubnets(subnetMask);
    minHosts = calculateMinHosts(subnetMask);
    maxHosts = calculateMaxHosts(subnetMask);

    printf("Number of subnets: %d\n", numSubnets);
    printf("Minimum hosts per subnet: %d\n", minHosts);
    printf("Maximum hosts per subnet: %d\n", maxHosts);

    currentHosts = calculateCurrentHosts(subnetAddress, subnetMask);
    printf("Current hosts: %d\n", currentHosts);

    return 0;
}

int calculateNumSubnets(int subnetMask)
{
    return (subnetMask & 0xFF) + 1;
}

int calculateMinHosts(int subnetMask)
{
    return (subnetMask & 0xFF) - 2;
}

int calculateMaxHosts(int subnetMask)
{
    return (subnetMask & 0xFF) - 2;
}

int calculateCurrentHosts(char *subnetAddress, int subnetMask)
{
    int address, mask, hosts = 0;

    address = translateAddress(subnetAddress);
    mask = translateMask(subnetMask);

    hosts = (address & mask) & ~mask;

    return hosts;
}

int translateAddress(char *address)
{
    return atoi(address) & 0xFF;
}

int translateMask(int mask)
{
    return 0xFF << (8 - numberOfOnes(mask)) & mask;
}

int numberOfOnes(int num)
{
    int count = 0;

    while (num)
    {
        if (num & 1)
            count++;

        num >>= 1;
    }

    return count;
}