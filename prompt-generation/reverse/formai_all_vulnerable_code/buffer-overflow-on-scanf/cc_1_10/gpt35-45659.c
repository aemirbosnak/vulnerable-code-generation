//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    char ipAddress[15]; //to store IP address
    char netMask[15]; //to store network mask
    int numBits; //to store number of bits in the subnet mask
    int network[4]; //to store binary network address
    int mask[4]; //to store binary subnet mask
    int i;

    printf("Enter the IP address: ");
    scanf("%s", ipAddress);

    printf("Enter the subnet mask: ");
    scanf("%s", netMask);

    //to calculate number of bits in subnet mask
    numBits = 0;
    for (i = 0; i < strlen(netMask); i++)
    {
        if (netMask[i] == '1')
            numBits++;
    }

    //to convert IP address to binary and store in network array
    sscanf(ipAddress, "%d.%d.%d.%d", &network[0], &network[1], &network[2], &network[3]);
    for (i = 0; i < 4; i++)
        network[i] = network[i] & 255;

    //to convert subnet mask to binary and store in mask array
    sscanf(netMask, "%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);
    for (i = 0; i < 4; i++)
        mask[i] = mask[i] & 255;

    //to calculate network address
    for (i = 0; i < 4; i++)
        network[i] = network[i] & mask[i];

    //to print network address
    printf("Network address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);

    //to print subnet mask in decimal and binary format
    printf("Subnet mask: %s = %d.%d.%d.%d\n", netMask, mask[0], mask[1], mask[2], mask[3]);
    printf("            ");
    for (i = 0; i < strlen(netMask); i++)
    {
        if (netMask[i] == '1')
            printf("1");
        else
            printf("0");
    }
    printf("\n");

    //to print number of bits in subnet mask
    printf("Number of bits in subnet mask: %d\n", numBits);

    //to calculate number of hosts in subnet
    printf("Number of hosts in subnet: %d\n", pow(2, 32 - numBits) - 2);

    return 0;
}