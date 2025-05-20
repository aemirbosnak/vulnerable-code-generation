//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int isValidIP(char *ip) {
    char *ptr;
    int i = 0;
    int num = 0;

    for (ptr = strtok(ip, "."); ptr!= NULL; ptr = strtok(NULL, ".")) {
        if (i > 3) {
            return FALSE;
        }
        num = atoi(ptr);
        if (num < 0 || num > 255) {
            return FALSE;
        }
        i++;
    }

    if (i!= 4) {
        return FALSE;
    }

    return TRUE;
}

int isValidSubnet(char *subnet) {
    char *ptr;
    int i = 0;
    int num = 0;

    for (ptr = strtok(subnet, "."); ptr!= NULL; ptr = strtok(NULL, ".")) {
        if (i > 3) {
            return FALSE;
        }
        num = atoi(ptr);
        if (num < 0 || num > 255) {
            return FALSE;
        }
        i++;
    }

    if (i!= 4) {
        return FALSE;
    }

    return TRUE;
}

int getNumberOfSubnets(int numHosts) {
    int numSubnets = 0;
    int i = 0;

    while (numHosts > 0) {
        numSubnets++;
        numHosts -= (int) pow(2, i);
        i++;
    }

    return numSubnets;
}

void printSubnetInfo(char *ip, char *subnet, int numSubnets) {
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", subnet);
    printf("Number of Subnets: %d\n", numSubnets);
}

int main() {
    char ip[16];
    char subnet[16];
    int numHosts;
    int numSubnets = 0;

    printf("Enter IP Address: ");
    scanf("%s", ip);

    printf("Enter Subnet Mask: ");
    scanf("%s", subnet);

    printf("Enter Number of Hosts: ");
    scanf("%d", &numHosts);

    if (!isValidIP(ip) ||!isValidSubnet(subnet)) {
        printf("Invalid IP Address or Subnet Mask\n");
        return 1;
    }

    numSubnets = getNumberOfSubnets(numHosts);

    printSubnetInfo(ip, subnet, numSubnets);

    return 0;
}