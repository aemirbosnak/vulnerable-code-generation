//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the number of subnets
int calculateSubnets(int numHosts, int numBits) {
    int subnets = 1;
    int i = 0;
    while (i < numBits) {
        subnets *= 2;
        i++;
    }
    return subnets;
}

// Function to calculate the number of hosts per subnet
int calculateHostsPerSubnet(int numHosts, int numBits) {
    int hostsPerSubnet = 1;
    int i = 0;
    while (i < numBits - 1) {
        hostsPerSubnet *= 2;
        i++;
    }
    return hostsPerSubnet;
}

// Function to calculate the subnet mask
void calculateSubnetMask(int numBits, char *subnetMask) {
    int i = 0;
    for (i = 0; i < numBits; i++) {
        if (i == numBits - 1) {
            sprintf(subnetMask + i, "1");
        } else {
            sprintf(subnetMask + i, "0");
        }
    }
    sprintf(subnetMask + i, ".0");
}

int main() {
    int numHosts;
    int numBits;
    char subnetMask[16];
    printf("Enter the number of hosts: ");
    scanf("%d", &numHosts);
    printf("Enter the number of bits for subnetting: ");
    scanf("%d", &numBits);
    calculateSubnets(numHosts, numBits);
    calculateHostsPerSubnet(numHosts, numBits);
    calculateSubnetMask(numBits, subnetMask);
    printf("Number of subnets: %d\n", calculateSubnets(numHosts, numBits));
    printf("Number of hosts per subnet: %d\n", calculateHostsPerSubnet(numHosts, numBits));
    printf("Subnet mask: %s\n", subnetMask);
    return 0;
}