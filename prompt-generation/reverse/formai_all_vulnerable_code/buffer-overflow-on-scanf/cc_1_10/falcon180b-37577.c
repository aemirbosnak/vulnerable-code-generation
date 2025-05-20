//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 30

typedef struct {
    char name[MAX_SUBNET_SIZE];
    int size;
    int numHosts;
    int firstIP;
    int lastIP;
} Subnet;

void printSubnet(Subnet subnet) {
    printf("Subnet Name: %s\n", subnet.name);
    printf("Subnet Size: %d\n", subnet.size);
    printf("Number of Hosts: %d\n", subnet.numHosts);
    printf("First IP: %d.%d.%d.%d\n", 
        subnet.firstIP >> 24 & 0xFF, 
        (subnet.firstIP >> 16) & 0xFF, 
        (subnet.firstIP >> 8) & 0xFF, 
        subnet.firstIP & 0xFF);
    printf("Last IP: %d.%d.%d.%d\n", 
        subnet.lastIP >> 24 & 0xFF, 
        (subnet.lastIP >> 16) & 0xFF, 
        (subnet.lastIP >> 8) & 0xFF, 
        subnet.lastIP & 0xFF);
}

void calculateSubnets(int numSubnets, Subnet subnets[]) {
    int i;
    for (i = 0; i < numSubnets; i++) {
        subnets[i].size = (int)pow(2, (double)i);
        subnets[i].numHosts = subnets[i].size - 2;
        subnets[i].firstIP = (192 << 24) | (168 << 16) | (i << 8) | 1;
        subnets[i].lastIP = (192 << 24) | (168 << 16) | (i << 8) | subnets[i].size - 1;
    }
}

int main() {
    int numSubnets;
    printf("Enter the number of subnets: ");
    scanf("%d", &numSubnets);

    Subnet subnets[MAX_SUBNETS];
    calculateSubnets(numSubnets, subnets);

    printf("Subnet Information:\n");
    for (int i = 0; i < numSubnets; i++) {
        printSubnet(subnets[i]);
    }

    return 0;
}