//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Romeo and Juliet
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000 //Maximum number of IP addresses in the network

struct IP{
    char IP[15];
    int Subnet;
    int Broadcast;
};

void SubnetCalc(struct IP *IPList, int numIPs, int subnetBits){
    int i;
    char subnetIP[15];
    for(i=0; i<numIPs; i++){
        strcpy(subnetIP, IPList[i].IP);
        int j;
        for(j=0; j<subnetBits-1; j++){
            int bit = (subnetIP[j] - '0');
            bit = bit | (1 << (7-j));
            subnetIP[j] = bit + '0';
        }
        IPList[i].Subnet = atoi(subnetIP);
        strcpy(subnetIP, IPList[i].IP);
        for(j=0; j<8-subnetBits; j++){
            subnetIP[j] = '255';
        }
        IPList[i].Broadcast = atoi(subnetIP);
    }
}

int main(){
    int numIPs, subnetBits;
    printf("Enter the number of IP addresses in the network: ");
    scanf("%d", &numIPs);
    struct IP IPList[MAX];
    printf("Enter the IP addresses:\n");
    int i;
    for(i=0; i<numIPs; i++){
        printf("IP address %d: ", i+1);
        scanf("%s", IPList[i].IP);
    }
    printf("Enter the number of bits in the subnet mask: ");
    scanf("%d", &subnetBits);
    SubnetCalc(IPList, numIPs, subnetBits);
    printf("\nSubnet IP\tBroadcast IP\n");
    int j;
    for(j=0; j<numIPs; j++){
        printf("%s\t\t%s\n", IPList[j].Subnet, IPList[j].Broadcast);
    }
    return 0;
}