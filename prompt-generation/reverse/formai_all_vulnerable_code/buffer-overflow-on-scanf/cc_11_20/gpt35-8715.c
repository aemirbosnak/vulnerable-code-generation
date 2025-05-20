//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ip[20], subnetMask[20], subnet[20], broadcast[20];
    int subnetBits, subnetSize, i, j, k, l;
    printf("Enter the IP Address: ");
    scanf("%s", ip);
    printf("Enter the Subnet Mask: ");
    scanf("%s", subnetMask);

    // Finding the subnet size
    for(i=0; i<strlen(subnetMask); i++)
    {
        if(subnetMask[i] == '.')
        {
            subnetBits = (subnetBits + 8);
        }
        else
        {
            subnetBits++;   
        }
    }
    subnetSize = (1 << (32 - subnetBits));

    // Finding the Subnet Address
    for(i=0; i<strlen(ip); i++)
    {
        if(ip[i] == '.')
        {
            subnet[i] = '.';
            break;
        }
        else
        {
            subnet[i] = ip[i];
        }
    }
    for(j=i+1,l=0; j<strlen(ip); j++, l++)
    {
        if(ip[j] == '.')
        {
            subnet[j] = '.';
            break;
        }
        else
        {
            subnet[j] = ip[j];
        }
    }
    for(k=j+1,l=0; k<strlen(ip); k++, l++)
    {
        if(ip[k] == '.')
        {
            subnet[k] = '.';
            break;
        }
        else
        {
            subnet[k] = '0';
        }
    }
    subnet[k+1] = '\0';

    // Finding the Broadcast Address
    for(i=0; i<strlen(subnet); i++)
    {
        broadcast[i] = subnet[i];
    }
    for(j=i+1,l=0; j<strlen(ip); j++, l++)
    {
        if(ip[j] == '.')
        {
            broadcast[j] = '.';
            break;
        }
        else
        {
            broadcast[j] = '255';
        }
    }
    for(k=j+1,l=0; k<strlen(ip); k++, l++)
    {
        if(ip[k] == '.')
        {
            broadcast[k] = '.';
            break;
        }
        else
        {
            broadcast[k] = '255';
        }
    }
    broadcast[k+1] = '\0';

    printf("\n\nSubnet size: %d\n", subnetSize);
    printf("Subnet Address: %s\n", subnet);
    printf("Broadcast Address: %s\n\n", broadcast);
    return 0;
}