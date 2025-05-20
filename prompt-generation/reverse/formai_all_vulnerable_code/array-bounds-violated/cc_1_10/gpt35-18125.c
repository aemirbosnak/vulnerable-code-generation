//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function for calculating subnet addresses
void calculateSubnet(char ipAddress[], int subnetMask)
{
    char subnetAddress[15];
    char decimalSubnet[4];
    char decimalIP[4];
    int i, j, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0;

    for (i = 0; i < strlen(ipAddress); i++)
    {
        if (ipAddress[i] != '.')
        {
            decimalIP[k++] = ipAddress[i];
        }
        else
        {
            if (l == 0)
                n = k;
            else if (l == 1)
                o = k;
            else if (l == 2)
                p = k;
            k = 0;
            l++;
        }
    }
    q = k;

    int octet1 = atoi(decimalIP);
    int octet2 = atoi(decimalIP + n);
    int octet3 = atoi(decimalIP + o);
    int octet4 = atoi(decimalIP + p);

    int subnetOctet = subnetMask / 8;
    int remainingBits = subnetMask % 8;

    for (i = 0; i < subnetOctet; i++)
    {
        subnetAddress[m++] = decimalIP[n];
        subnetAddress[m++] = '.';
        n = o;
        o = p;
        p++;
    }

    for (i = 0; i < remainingBits; i++)
    {
        q--;
        subnetAddress[m++] = decimalIP[n + q];
    }

    if (remainingBits == 0)
        subnetAddress[m - 1] = '\0';
    else
        subnetAddress[m] = '\0';

    printf("\nIP address: %s\n", ipAddress);
    printf("Subnet mask: %d\n", subnetMask);
    printf("Subnet address: %s", subnetAddress);

    //Calculating and displaying the broadcast address, network address, usable IP range
    int numHostBits = 32 - subnetMask;
    int numSubnets = 1;
    int numHosts = 1;

    for (i = 0; i < remainingBits; i++)
    {
        numSubnets *= 2;
    }

    for (i = 0; i < numHostBits; i++)
    {
        numHosts *= 2;
    }

    if (remainingBits == 0)
    {
        printf("\nNetwork address: %d.%d.%d.%d\n", octet1, octet2, octet3, octet4);
        printf("Broadcast address: %d.%d.%d.%d\n", octet1, octet2, octet3 + (numSubnets - 1), octet4 + (numHosts - 1));
        printf("Usable IP range: %d.%d.%d.%d - %d.%d.%d.%d", octet1, octet2, octet3, octet4 + 1, octet1, octet2, octet3 + (numSubnets - 1), octet4 + (numHosts - 2));
    }
    else
    {
        int netMaskOctet = 0;
        for (i = 0; i < subnetOctet; i++)
        {
            netMaskOctet = 255;
            printf("%d.", netMaskOctet);
        }
        netMaskOctet = 0;
        for (i = 0; i < remainingBits; i++)
        {
            netMaskOctet = netMaskOctet | 1 << 7 - i;
        }
        printf("%d\n", netMaskOctet);
        int netAddrByte = octet4 & (netMaskOctet ^ 255);
        printf("Network address: %d.%d.%d.%d\n", octet1, octet2, octet3, netAddrByte);
        int hostByte = 255 ^ netMaskOctet;
        printf("Broadcast address: %d.%d.%d.%d\n", octet1, octet2, octet3 + (numSubnets - 1), octet4 | hostByte);
        printf("Usable IP range: %d.%d.%d.%d - %d.%d.%d.%d", octet1, octet2, octet3, netAddrByte + 1, octet1, octet2, octet3 + (numSubnets - 1), (octet4 | hostByte) - 1);
    }
}

int main()
{
    char ipAddress[15];
    int subnetMask;

    printf("Enter IP address in dotted decimal format: ");
    scanf("%s", ipAddress);
    printf("Enter subnet mask in integer format: ");
    scanf("%d", &subnetMask);

    calculateSubnet(ipAddress, subnetMask);
    return 0;
}