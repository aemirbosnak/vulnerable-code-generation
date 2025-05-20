//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Subnet Calculator! Let's get started.\n");
    printf("Please enter a valid IP address in the format of xxx.xxx.xxx.xxx: ");

    char ip[16];
    scanf("%s", ip);

    char octet[4][4];
    int index = 0;
    int temp = 0;

    for(int i = 0; i < strlen(ip); i++)
    {
        if(ip[i] == '.')
        {
            octet[index][temp] = '\0';
            index++;
            temp = 0;
        }
        else
        {
            octet[index][temp] = ip[i];
            temp++;
        }
    }
    octet[index][temp] = '\0';

    int mask;
    printf("Please enter the subnet mask in the format of xx: ");
    scanf("%d", &mask);

    int subnetOctet = mask/8;
    int hostBits = mask%8;
    int numSubnets = 1 << hostBits;
    int numHostsSubnet = 256-numSubnets;

    printf("IP address entered: %s\n", ip);
    printf("Subnet mask entered: /%d\n", mask);

    char subnet[16]; 
    sprintf(subnet, "%s", ip);

    if(subnetOctet == 1)
    {
        int subnet_int = atoi(octet[0]);
        subnet_int = subnet_int & (255- numSubnets+1); 
        sprintf(subnet, "%d.%d.%d.%d", subnet_int, 0, 0, 0);
    }
    else if(subnetOctet == 2)
    {
        int subnet_int = atoi(octet[1]);
        subnet_int = subnet_int & (255- numSubnets+1); 
        sprintf(subnet, "%s.%d.%d.%d", octet[0], subnet_int, 0, 0);
    }
    else if(subnetOctet == 3)
    {
        int subnet_int = atoi(octet[2]);
        subnet_int = subnet_int & (255- numSubnets+1); 
        sprintf(subnet, "%s.%s.%d.%d", octet[0], octet[1], subnet_int, 0);
    }
    else
    {
        int subnet_int = atoi(octet[3]);
        subnet_int = subnet_int & (255- numSubnets+1); 
        sprintf(subnet, "%s.%s.%s.%d", octet[0], octet[1], octet[2], subnet_int);
    }

    printf("The subnet address is: %s\n", subnet);
    printf("Number of subnets: %d\n", numSubnets);
    printf("Number of hosts per subnet: %d\n", numHostsSubnet);

    return 0;
}