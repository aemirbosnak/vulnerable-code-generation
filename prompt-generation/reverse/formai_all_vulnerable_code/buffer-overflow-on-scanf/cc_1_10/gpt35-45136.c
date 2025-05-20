//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include<stdio.h>
#include<math.h>

int main()
{
    printf("Welcome to the curious C Subnet Calculator!\n\n");

    int ip[4], subnetBits;
    printf("Please enter the IP Address (4 numbers separated by spaces):\n");
    scanf("%d %d %d %d", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Please enter the number of subnet bits:\n");
    scanf("%d", &subnetBits);

    int subnetMask[4];
    int i;
    for(i=0; i<4; i++)
    {
        if(subnetBits >= 8)
        {
            subnetMask[i] = 255;
            subnetBits -= 8;
        }
        else if(subnetBits > 0)
        {
            subnetMask[i] = pow(2, 8-subnetBits) - 1;
            subnetBits = 0;
        }
        else
        {
            subnetMask[i] = 0;
        }
    }

    printf("\nThe Subnet mask is: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);

    int hostBits = 32 - subnetBits;
    int numHosts = pow(2, hostBits) - 2;
    int networkAddress[4], broadcastAddress[4];
  
    for(i=0; i<4; i++)
    {
        networkAddress[i] = ip[i] & subnetMask[i];
        broadcastAddress[i] = networkAddress[i] | ~subnetMask[i];
    }

    printf("\nThe Network Address is: %d.%d.%d.%d\n", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);

    printf("The Broadcast Address is: %d.%d.%d.%d\n", broadcastAddress[0], broadcastAddress[1], broadcastAddress[2], broadcastAddress[3]);

    printf("The number of Hosts per subnet is: %d\n", numHosts);

    printf("Thank you for using the Curious C Subnet Calculator!\n");

    return 0;
}