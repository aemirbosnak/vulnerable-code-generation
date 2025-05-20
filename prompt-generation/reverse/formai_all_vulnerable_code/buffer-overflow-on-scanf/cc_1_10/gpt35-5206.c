//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNetworkAddress(unsigned long int ipAddress, unsigned long int subnetMask, char* networkAddress)
{
    unsigned long int temp = 0;
    int i;
    
    for(i=0; i<4; ++i)
    {
        temp = (ipAddress & subnetMask) >> ((3-i)*8);
        sprintf(networkAddress+strlen(networkAddress), "%d", temp);
        if(i<3)
           strcat(networkAddress, ".");
        ipAddress <<= 8;
        subnetMask <<= 8;
    }
}

void getSubnetMask(int subnetMaskCIDR, char* subnetMask)
{
    int i;
    for(i=0; i<4; ++i)
    {
        if(subnetMaskCIDR >= 8)
        {
            subnetMask[i] = 255;
            subnetMaskCIDR -= 8;
        }
        else if(subnetMaskCIDR > 0)
        {
            subnetMask[i] = 255<<(8-subnetMaskCIDR);
            subnetMaskCIDR = 0;
        }
        else
            subnetMask[i] = 0;
    }
}

int main()
{
    char ipAddress[15];
    int subnetMaskCIDR;
    unsigned long int subnetMask, ipAddressDecimal;
    char subnetMaskString[15], networkAddress[15];
    
    printf("Enter the IP address: ");
    scanf("%s", ipAddress);
    
    printf("Enter the subnet mask CIDR: ");
    scanf("%d", &subnetMaskCIDR);
    
    getSubnetMask(subnetMaskCIDR, subnetMaskString);
    subnetMask = (subnetMaskString[0]<<24) | (subnetMaskString[1]<<16) | (subnetMaskString[2]<<8) | (subnetMaskString[3]<<0);
    
    ipAddressDecimal = (atoi(strtok(ipAddress, "."))<<24) | (atoi(strtok(NULL, "."))<<16) | (atoi(strtok(NULL, "."))<<8) | (atoi(strtok(NULL, "."))<<0);
    
    getNetworkAddress(ipAddressDecimal, subnetMask, networkAddress);
    
    printf("\nNetwork Address: %s\n", networkAddress);
    printf("Subnet Mask: %s\n", subnetMaskString);
    printf("Subnet Mask Decimal: %lu\n", subnetMask);
    
    return 0;
}