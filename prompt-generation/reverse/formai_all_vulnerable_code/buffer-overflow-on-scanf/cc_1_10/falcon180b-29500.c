//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define IP_ADDRESS_SIZE 16
#define SUBNET_MASK_SIZE 16

typedef struct {
    char ipAddress[IP_ADDRESS_SIZE];
    char subnetMask[SUBNET_MASK_SIZE];
} Subnet;

void printSubnet(Subnet subnet) {
    printf("IP Address: %s\n", subnet.ipAddress);
    printf("Subnet Mask: %s\n", subnet.subnetMask);
}

void generateSubnet(Subnet subnet, int numSubnets) {
    char ipAddress[IP_ADDRESS_SIZE];
    char subnetMask[SUBNET_MASK_SIZE];
    strcpy(ipAddress, subnet.ipAddress);
    strcpy(subnetMask, subnet.subnetMask);

    int subnetSize = atoi(subnetMask + strcspn(subnetMask, "."));
    int numHostsPerSubnet = pow(2, 8 - subnetSize);
    int numSubnetsPerOctet = numSubnets / numHostsPerSubnet;

    for (int i = 0; i < numSubnets; i++) {
        int octet = i / numSubnetsPerOctet;
        int host = i % numSubnetsPerOctet;

        int subnetOctet = (atoi(ipAddress + strcspn(ipAddress, ".")) & ~(subnetSize - 1)) | (host << (8 - subnetSize));
        sprintf(subnetMask + strcspn(subnetMask, "."), "%d", subnetSize);
        sprintf(ipAddress + strcspn(ipAddress, "."), "%d", subnetOctet);

        printf("Subnet %d:\n", i + 1);
        printSubnet(subnet);
    }
}

int main() {
    Subnet subnet;
    printf("Enter IP Address: ");
    scanf("%s", subnet.ipAddress);
    printf("Enter Subnet Mask: ");
    scanf("%s", subnet.subnetMask);

    int numSubnets;
    printf("Enter number of subnets: ");
    scanf("%d", &numSubnets);

    if (numSubnets > MAX_SUBNETS) {
        printf("Error: Maximum number of subnets is %d.\n", MAX_SUBNETS);
        return 1;
    }

    generateSubnet(subnet, numSubnets);

    return 0;
}