//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: excited
#include <stdio.h>
#include <math.h>

int main()
{
    int ipAddress[4];
    int subnetMask[4];
    int networkAddress[4];
    int subnetId[4];
    int noOfHosts;
    int subnetBits;
    int subnetCount;
    int i;
    int j;
    int tempCount = 0;

    printf("Welcome to the C Subnet Calculator!\n");

    //Take input for IP address
    printf("Enter IP Address (Format: x.x.x.x): ");
    scanf("%d.%d.%d.%d", &ipAddress[0], &ipAddress[1], &ipAddress[2], &ipAddress[3]);

    //Take input for subnet mask
    printf("\nEnter Subnet Mask (Format: x.x.x.x): ");
    scanf("%d.%d.%d.%d", &subnetMask[0], &subnetMask[1], &subnetMask[2], &subnetMask[3]);

    //Calculate network address
    for(i = 0; i < 4; i++)
    {
        networkAddress[i] = ipAddress[i] & subnetMask[i];
    }

    //Calculate Subnet ID
    for(i = 0; i < 4; i++)
    {
        subnetId[i] = networkAddress[i];
    }

    //Calculate number of hosts
    subnetBits = calculateSubnetBitCount(subnetMask);
    noOfHosts = pow(2, 32-subnetBits) - 2; //2^32 = total IPv4 addresses

    printf("\nNetwork Address: %d.%d.%d.%d", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);
    printf("\nSubnet ID: %d.%d.%d.%d", subnetId[0], subnetId[1], subnetId[2], subnetId[3]);
    printf("\nNumber of Hosts: %d", noOfHosts);

    //Calculate number of subnets and subnet addresses
    subnetCount = pow(2, subnetBits);
    printf("\nNumber of Subnets: %d\n", subnetCount);

    //Loop through subnets and print information
    for(i = 0; i < subnetCount; i++)
    {
        printf("Subnet %d Address: %d.%d.%d.%d", i+1, networkAddress[0], networkAddress[1], networkAddress[2], tempCount);
        printf("\nBroadcast Address: %d.%d.%d.%d", networkAddress[0], networkAddress[1], networkAddress[2], tempCount + pow(2, 32-subnetBits)-1);
        printf("\nSubnet Mask: %d.%d.%d.%d", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
        printf("\nNumber of Hosts: %d", noOfHosts);

        //Calculate next subnet address
        tempCount += pow(2, 32-subnetBits);
        for(j = 3; j >= 0; j--)
        {
            if(tempCount > 255)
            {
                tempCount -= 256;
                networkAddress[j]++;
            }
            else
            {
                break;
            }
        }
    }

}

//Calculate the number of bits in the subnet mask
int calculateSubnetBitCount(int subnetMask[])
{
    //Convert subnet mask to binary
    int binaryMask[32];
    int i;
    int j = 0;
    for(i = 0; i < 4; i++)
    {
        if(subnetMask[i] == 255)
        {
            binaryMask[j++] = 1;
            binaryMask[j++] = 1;
            binaryMask[j++] = 1;
            binaryMask[j++] = 1;
        }
        else if(subnetMask[i] == 0)
        {
            binaryMask[j++] = 0;
            binaryMask[j++] = 0;
            binaryMask[j++] = 0;
            binaryMask[j++] = 0;
        }
        else
        {
            int k;
            for(k = 0; k < 8; k++)
            {
                if(subnetMask[i] >= (int)pow(2, 7-k))
                {
                    binaryMask[j++] = 1;
                    subnetMask[i] -= pow(2, 7-k);
                }
                else
                {
                    binaryMask[j++] = 0;
                }
            }
        }
    }

    //Count the number of 1's in the binary subnet mask
    int subnetBits = 0;
    for(i = 0; i < 32; i++)
    {
        if(binaryMask[i] == 1)
        {
            subnetBits++;
        }
    }
    return subnetBits;
}