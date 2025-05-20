//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char address[20];
    char subnetMask[20];
    char input[20];
    int addressOctets[4];
    int subnetOctets[4];
    int prefixLength;
    int subnetBits[32];
    int i, j;
    int numSubnets = 0;
    int numHostsPerSubnet = 0;

    printf("Enter IP address: ");
    fgets(input, 20, stdin);
    sscanf(input, "%s", address);

    printf("Enter subnet mask: ");
    fgets(input, 20, stdin);
    sscanf(input, "%s", subnetMask);

    // convert address and subnet mask strings to octet arrays
    sscanf(address, "%d.%d.%d.%d", &addressOctets[0], &addressOctets[1], &addressOctets[2], &addressOctets[3]);
    sscanf(subnetMask, "%d.%d.%d.%d", &subnetOctets[0], &subnetOctets[1], &subnetOctets[2], &subnetOctets[3]);

    // verify that the subnet mask is valid
    for (i = 0; i < 4; i++) {
        if (subnetOctets[i] != 0 && subnetOctets[i] != 128 && subnetOctets[i] != 192 && subnetOctets[i] != 224 && subnetOctets[i] != 240 && subnetOctets[i] != 248 && subnetOctets[i] != 252 && subnetOctets[i] != 254 && subnetOctets[i] != 255) {
            printf("Invalid subnet mask\n");
            return 1;
        }
    }

    // convert subnet mask to binary array
    for (i = 0; i < 4; i++) {
        int val = subnetOctets[i];
        for (j = 0; j < 8; j++) {
            if (val & 128) {
                subnetBits[i * 8 + j] = 1;
            } else {
                subnetBits[i * 8 + j] = 0;
            }
            val <<= 1;
        }
    }

    // determine prefix length (number of 1's in the subnet mask)
    prefixLength = 0;
    for (i = 0; i < 32; i++) {
        if (subnetBits[i]) {
            prefixLength++;
        } else {
            break;
        }
    }
    if (prefixLength == 0) {
        printf("Invalid subnet mask\n");
        return 1;
    }

    // calculate number of subnets and hosts per subnet
    numSubnets = 1;
    numHostsPerSubnet = 1;
    for (i = prefixLength; i < 32; i++) {
        numHostsPerSubnet *= 2;
        if (subnetBits[i] == 0) {
            numSubnets *= 2;
        }
    }

    // output results
    printf("IP address: %s\n", address);
    printf("Subnet mask: %s\n", subnetMask);
    printf("Prefix length: %d\n", prefixLength);
    printf("Number of subnets: %d\n", numSubnets);
    printf("Number of hosts per subnet: %d\n", numHostsPerSubnet);

    return 0;
}