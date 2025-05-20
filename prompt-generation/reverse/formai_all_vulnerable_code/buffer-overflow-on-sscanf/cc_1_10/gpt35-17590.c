//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printDecimalToBinary(unsigned int decimalNumber)
{
    for(int i = 31; i >= 0; i--)
    {
        printf("%d", (decimalNumber >> i) & 1);
    }
}

int main()
{
    char ipAddress[16];
    printf("Enter the IP Address: ");
    scanf("%s", ipAddress);
    
    int ipAddressSegments[4];
    sscanf(ipAddress, "%d.%d.%d.%d", &ipAddressSegments[0], &ipAddressSegments[1], &ipAddressSegments[2], &ipAddressSegments[3]);

    unsigned int decimalIpAddress = 0;
    for(int i = 0; i < 4; i++)
    {
        decimalIpAddress += ipAddressSegments[i] << (24 - (i * 8));
    }

    printf("Decimal IP address is: %u \n", decimalIpAddress);
    printf("Binary IP address is: ");
    printDecimalToBinary(decimalIpAddress);
    printf("\n");

    printf("Enter the subnet mask: ");
    char subnetMask[16];
    scanf("%s", subnetMask);

    int subnetMaskSegments[4];
    sscanf(subnetMask, "%d.%d.%d.%d", &subnetMaskSegments[0], &subnetMaskSegments[1], &subnetMaskSegments[2], &subnetMaskSegments[3]);

    unsigned int decimalSubnetMask = 0;
    for(int i = 0; i < 4; i++)
    {
        decimalSubnetMask += subnetMaskSegments[i] << (24 - (i * 8));
    }

    printf("Decimal subnet mask is: %u", decimalSubnetMask);
    printf("\nBinary subnet mask is: ");
    printDecimalToBinary(decimalSubnetMask);
    printf("\n");

    unsigned int networkAddress = decimalIpAddress & decimalSubnetMask;
    printf("Network Address is: %u", networkAddress);
    printf("\n");

    unsigned int hostAddress = decimalIpAddress & (~decimalSubnetMask);
    printf("Host Address is: %u", hostAddress);
    printf("\n");

    unsigned int maximumNumberOfHosts = ~decimalSubnetMask;
    printf("Maximum number of hosts is: %u", maximumNumberOfHosts);
    printf("\n");

    unsigned int numberOfSubnets = 1;
    int numberOfZeros = 0;
    for(int i = 31; i >= 0; i--)
    {
        if((decimalSubnetMask >> i) & 1)
        {
            break;
        }
        numberOfZeros++;
    }

    for(int i = 0; i < numberOfZeros; i++)
    {
        numberOfSubnets *= 2;
    }

    printf("Number of subnets is: %u", numberOfSubnets);
    printf("\n");
    
    return 0;
}