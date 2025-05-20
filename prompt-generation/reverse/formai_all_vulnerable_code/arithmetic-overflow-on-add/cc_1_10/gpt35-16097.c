//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: ephemeral
#include <stdio.h>

int main() {
    int ipAddr[4], subnetMask[4], cidrNotation, numSubnets, numHosts;

    printf("Enter IP Address: ");
    scanf("%d.%d.%d.%d", &ipAddr[0], &ipAddr[1], &ipAddr[2], &ipAddr[3]);

    printf("Enter Subnet Mask: ");
    scanf("%d.%d.%d.%d", &subnetMask[0], &subnetMask[1], &subnetMask[2], &subnetMask[3]);

    // Converting subnet mask from decimal to binary
    unsigned long int binarySubnetMask = subnetMask[0] * 256 * 256 * 256 + subnetMask[1] * 256 * 256 + subnetMask[2] * 256 + subnetMask[3];
    unsigned long int temp = binarySubnetMask;
    int binarySubnetMaskArray[32] = {0};
    int i = 31;
    while (temp > 0) {
        binarySubnetMaskArray[i] = temp % 2;
        temp = temp / 2;
        i--;
    }

    // Counting number of 1s in binary subnet mask to determine CIDR notation
    cidrNotation = 0;
    for (i = 0; i < 32; i++) {
        if (binarySubnetMaskArray[i] == 1) {
            cidrNotation++;
        } else {
            break;
        }
    }

    // Calculating number of subnets
    numSubnets = 1;
    for (i = cidrNotation; i < 32; i++) {
        if (binarySubnetMaskArray[i] == 0) {
            numSubnets *= 2;
        }
    }

    // Calculating number of hosts
    numHosts = 1;
    for (i = cidrNotation; i < 32; i++) {
        if (binarySubnetMaskArray[i] == 0) {
            numHosts *= 2;
        }
    }
    numHosts -= 2; // Subtracting network and broadcast addresses

    // Printing results
    printf("\nCIDR Notation: %d\n", cidrNotation);
    printf("Number of Subnets: %d\n", numSubnets);
    printf("Number of Hosts per Subnet: %d\n", numHosts);

    return 0;
}