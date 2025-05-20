//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_IP_ADDR 16
#define MAX_SUBNET_MASK 3

typedef struct 
{
    int octet1;
    int octet2;
    int octet3;
    int octet4;
} ipAddress;

typedef struct
{
    int octet1;
    int octet2;
    int octet3;
    int octet4;
    int prefixLength;
} subnetMask;

ipAddress* inputIpAddress();
subnetMask* inputSubnetMask();
void printIpAddress(ipAddress* address);
void printSubnetMask(subnetMask* subnet);
int* calculateBinary(ipAddress* address);
void calculateSubnet(ipAddress* ip, subnetMask* subnet, int* network, int* broadcast);

int main()
{
    printf("\n--- C Subnet Calculator ---\n");
    ipAddress* ip = inputIpAddress();
    subnetMask* subnet = inputSubnetMask();
    printf("\nThe IP Address you entered: ");
    printIpAddress(ip);
    printf("The Subnet Mask you entered: ");
    printSubnetMask(subnet);

    int* binaryIp = calculateBinary(ip);
    int* binarySubnet = calculateBinary(subnet);

    int* network = (int*) malloc(sizeof(int)*MAX_IP_ADDR);
    int* broadcast = (int*) malloc(sizeof(int)*MAX_IP_ADDR);

    calculateSubnet(ip, subnet, network, broadcast);

    printf("\nNetwork Address: ");
    for(int i=0; i<MAX_IP_ADDR; i++)
        printf("%d.", network[i]);

    printf("\nBroadcast Address: ");
    for(int i=0; i<MAX_IP_ADDR; i++)
        printf("%d.", broadcast[i]);
    printf("\n");

    free(ip);
    free(subnet);
    free(binaryIp);
    free(binarySubnet);
    free(network);
    free(broadcast);

    return 0;
}

ipAddress* inputIpAddress()
{
    char address[MAX_IP_ADDR];
    ipAddress* ip = (ipAddress*) malloc(sizeof(ipAddress));

    printf("\nEnter IP Address (Format: X.X.X.X): ");
    scanf("%s", address);
    sscanf(address, "%d.%d.%d.%d", &ip->octet1, &ip->octet2, &ip->octet3, &ip->octet4);

    return ip;
}

subnetMask* inputSubnetMask()
{
    char mask[MAX_SUBNET_MASK];
    subnetMask* subnet = (subnetMask*) malloc(sizeof(subnetMask));

    printf("\nEnter Subnet Mask (Format: X.X.X.X/Y): ");
    scanf("%s", mask);
    sscanf(mask, "%d.%d.%d.%d/%d", &subnet->octet1, &subnet->octet2, &subnet->octet3, &subnet->octet4, &subnet->prefixLength);

    return subnet;
}

void printIpAddress(ipAddress* address)
{
    printf("%d.%d.%d.%d\n", address->octet1, address->octet2, address->octet3, address->octet4);
}

void printSubnetMask(subnetMask* subnet)
{
    printf("%d.%d.%d.%d/%d\n", subnet->octet1, subnet->octet2, subnet->octet3, subnet->octet4, subnet->prefixLength);
}

int* calculateBinary(ipAddress* address)
{
    static int binary[MAX_IP_ADDR];
    binary[0] = (address->octet1/128);
    binary[1] = (address->octet1%128)/64;
    binary[2] = (address->octet1%64)/32;
    binary[3] = (address->octet1%32)/16;
    binary[4] = (address->octet1%16)/8;
    binary[5] = (address->octet1%8)/4;
    binary[6] = (address->octet1%4)/2;
    binary[7] = (address->octet1%2);

    binary[8] = (address->octet2/128);
    binary[9] = (address->octet2%128)/64;
    binary[10] = (address->octet2%64)/32;
    binary[11] = (address->octet2%32)/16;
    binary[12] = (address->octet2%16)/8;
    binary[13] = (address->octet2%8)/4;
    binary[14] = (address->octet2%4)/2;
    binary[15] = (address->octet2%2);

    binary[16] = (address->octet3/128);
    binary[17] = (address->octet3%128)/64;
    binary[18] = (address->octet3%64)/32;
    binary[19] = (address->octet3%32)/16;
    binary[20] = (address->octet3%16)/8;
    binary[21] = (address->octet3%8)/4;
    binary[22] = (address->octet3%4)/2;
    binary[23] = (address->octet3%2);

    binary[24] = (address->octet4/128);
    binary[25] = (address->octet4%128)/64;
    binary[26] = (address->octet4%64)/32;
    binary[27] = (address->octet4%32)/16;
    binary[28] = (address->octet4%16)/8;
    binary[29] = (address->octet4%8)/4;
    binary[30] = (address->octet4%4)/2;
    binary[31] = (address->octet4%2);

    return binary;
}

void calculateSubnet(ipAddress* ip, subnetMask* subnet, int* network, int* broadcast)
{
    int* binaryIp = calculateBinary(ip);
    int* binarySubnet = calculateBinary(subnet);
    int prefixLength = subnet->prefixLength;
    int numHostBits = 32 - prefixLength;
    int lastNetworkBit = prefixLength;
    int lastHostBit = 31;

    for(int i=0; i<MAX_IP_ADDR; i++)
    {
        if(i%4 == 0)
            network[i] = ip->octet1 & binarySubnet[i];
        else if(i%4 == 1)
            network[i] = ip->octet2 & binarySubnet[i];
        else if(i%4 == 2)
            network[i] = ip->octet3 & binarySubnet[i];
        else
            network[i] = ip->octet4 & binarySubnet[i];
    }

    for(int i=0; i<MAX_IP_ADDR; i++)
    {
        if(i%4 == 0)
            broadcast[i] = network[i]|(255 - binarySubnet[i]);
        else if(i%4 == 1)
            broadcast[i] = network[i]|(255 - binarySubnet[i]);
        else if(i%4 == 2)
            broadcast[i] = network[i]|(255 - binarySubnet[i]);
        else
            broadcast[i] = network[i]|(255 - binarySubnet[i]);
    }

    if(numHostBits == 0)
        printf("\nHost Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    else
    {
        printf("\nRange of Valid Host Addresses: ");
        for(int i=lastNetworkBit+1; i<=lastHostBit-1; i++)
        {
            if(i%4 == 0)
                printf("%d.", binaryIp[i]*128 + binaryIp[i+1]*64 + binaryIp[i+2]*32 + binaryIp[i+3]*16);
        }
        printf("\b \b\n");
    }

    free(binaryIp);
    free(binarySubnet);
}