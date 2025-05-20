//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_IP_ADDRESS_LENGTH 20
#define MAX_CIDR_LENGTH 3
#define MAX_BINARY_LENGTH 9

typedef struct{
    int octet1;
    int octet2;
    int octet3;
    int octet4;
    int cidr;
}IpAddress;

void printIpAddress(IpAddress ip);
void getBinarySubnetMask(IpAddress ip, char* binarySubnetMask);

int main(){
    IpAddress ip;
    char binarySubnetMask[MAX_IP_ADDRESS_LENGTH];

    printf("Enter IP address: ");
    scanf("%d.%d.%d.%d", &ip.octet1, &ip.octet2, &ip.octet3, &ip.octet4);

    printf("Enter CIDR: ");
    scanf("%d", &ip.cidr);

    getBinarySubnetMask(ip, binarySubnetMask);

    printf("\nIP Address:\n");
    printIpAddress(ip);
    printf("\nSubnet Mask:\n%s", binarySubnetMask);

    return 0;
}

void printIpAddress(IpAddress ip){
    printf("%d.%d.%d.%d/%d\n",ip.octet1,ip.octet2,ip.octet3,ip.octet4,ip.cidr);
}

void getBinarySubnetMask(IpAddress ip, char* binarySubnetMask){
    int i;
    char subnetMask[MAX_IP_ADDRESS_LENGTH];
    memset(subnetMask,0,sizeof(subnetMask));

    //Subnet mask calculation
    for(i = 0; i < ip.cidr; i++){
        subnetMask[i] = '1';
    }
    for(i = ip.cidr; i < MAX_BINARY_LENGTH; i++){
        subnetMask[i] = '0';
    }

    //Binary representation of subnet mask
    for(i = 0; i < MAX_IP_ADDRESS_LENGTH; i++){
        if(subnetMask[i*MAX_CIDR_LENGTH] == '1')
            binarySubnetMask[i] = '2';
        else if(subnetMask[i*MAX_CIDR_LENGTH+1] == '1')
            binarySubnetMask[i] = '3';
        else if(subnetMask[i*MAX_CIDR_LENGTH+2] == '1')
            binarySubnetMask[i] = '6';
        else if(subnetMask[i*MAX_CIDR_LENGTH+3] == '1')
            binarySubnetMask[i] = '7';
        else if(subnetMask[i*MAX_CIDR_LENGTH+4] == '1')
            binarySubnetMask[i] = 'e';
        else if(subnetMask[i*MAX_CIDR_LENGTH+5] == '1')
            binarySubnetMask[i] = 'f';
        else if(subnetMask[i*MAX_CIDR_LENGTH+6] == '1')
            binarySubnetMask[i] = 'g';
        else if(subnetMask[i*MAX_CIDR_LENGTH+7] == '1')
            binarySubnetMask[i] = 'h';
        else
            binarySubnetMask[i] = '0';
    }
    binarySubnetMask[MAX_IP_ADDRESS_LENGTH-1] = '\0';
}