//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBNETS 10

typedef struct {
    int subnetId;
    int subnetSize;
    int hostSize;
    int mask;
} Subnet;

Subnet subnets[MAX_SUBNETS];
int numSubnets = 0;

void addSubnet(int subnetId, int subnetSize) {
    if (numSubnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        exit(1);
    }

    subnets[numSubnets].subnetId = subnetId;
    subnets[numSubnets].subnetSize = subnetSize;
    subnets[numSubnets].hostSize = 32 - subnetSize;
    subnets[numSubnets].mask = (1 << subnetSize) - 1;

    numSubnets++;
}

void printSubnets() {
    printf("Subnets:\n");
    for (int i = 0; i < numSubnets; i++) {
        printf("Subnet ID: %d\n", subnets[i].subnetId);
        printf("Subnet Size: %d\n", subnets[i].subnetSize);
        printf("Host Size: %d\n", subnets[i].hostSize);
        printf("Mask: %d.%d.%d.%d\n", (subnets[i].mask >> 24) & 0xFF, (subnets[i].mask >> 16) & 0xFF, (subnets[i].mask >> 8) & 0xFF, subnets[i].mask & 0xFF);
        printf("\n");
    }
}

int main() {
    printf("Subnet Calculator\n");

    int subnetId = 0;
    printf("Enter the subnet ID: ");
    scanf("%d", &subnetId);

    int subnetSize = 0;
    printf("Enter the subnet size (1-30): ");
    scanf("%d", &subnetSize);

    addSubnet(subnetId, subnetSize);

    printSubnets();

    return 0;
}