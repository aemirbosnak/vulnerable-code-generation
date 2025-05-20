//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ip[16], subnetMask[16];
    int subnetBits, octet1, octet2, octet3, octet4, subnetOctet1, subnetOctet2, subnetOctet3, subnetOctet4;
    int subnetMaskBits[32], i, j;

    printf("Enter IP Address(XXX.XXX.XXX.XXX): ");
    scanf("%s", ip);

    printf("Enter Subnet Mask(XXX.XXX.XXX.XXX): ");
    scanf("%s", subnetMask);

    printf("Enter Number of Bits in Subnet Mask: ");
    scanf("%d", &subnetBits);

    sscanf(ip, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);
    sscanf(subnetMask, "%d.%d.%d.%d", &subnetOctet1, &subnetOctet2, &subnetOctet3, &subnetOctet4);

    for(i=0;i<subnetBits;i++)
    {
        subnetMaskBits[i] = 1;
    }

    for(;i<32;i++)
    {
        subnetMaskBits[i] = 0;
    }

    printf("\n\nSubnet Calculator\n\n");
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", subnetMask);
    printf("Number of Bits in Subnet Mask: %d\n\n", subnetBits);

    printf("Subnet Mask in Binary: ");
    for(i=0;i<32;i++)
    {
        printf("%d", subnetMaskBits[i]);
        if(i%8==7)
        {
            printf(".");
        }
    }

    printf("\n");

    printf("\nNetwork Address: %d.%d.%d.%d\n", octet1 & subnetOctet1, octet2 & subnetOctet2, octet3 & subnetOctet3, octet4 & subnetOctet4);

    printf("\nFirst Host Address: %d.%d.%d.%d\n", octet1 & subnetOctet1, octet2 & subnetOctet2, octet3 & subnetOctet3, (octet4 & subnetOctet4) + 1);

    printf("\nLast Host Address: %d.%d.%d.%d\n", octet1 | (~subnetOctet1 & 0xff), octet2 | (~subnetOctet2 & 0xff), octet3 | (~subnetOctet3 & 0xff), (octet4 | (~subnetOctet4 & 0xff)) - 1);

    printf("\nBroadcast Address: %d.%d.%d.%d\n", octet1 | (~subnetOctet1 & 0xff), octet2 | (~subnetOctet2 & 0xff), octet3 | (~subnetOctet3 & 0xff), octet4 | (~subnetOctet4 & 0xff));

    int totalAddresses = 1;
    for(i=0;i<32;i++)
    {
        if(subnetMaskBits[i]==0)
            totalAddresses *= 2;
    }
    if(totalAddresses<2)
        totalAddresses = 2;

    printf("\nNumber of Valid Hosts per Subnet: %d\n", totalAddresses-2);
    printf("\nTotal Number of Valid Hosts for %d Subnets: %d\n", totalAddresses, totalAddresses);

    return 0;
}