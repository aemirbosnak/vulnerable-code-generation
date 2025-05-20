//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SUBNETS 256

int main() {

    int numSubnets = 0;
    int maskLength = 0;
    int subnetMask = 0;
    char subnetAddress[32] = "";

    printf("Welcome to the C Subnet Calculator!\n");

    // Get the subnet address from the user
    printf("Enter the subnet address: ");
    scanf("%s", subnetAddress);

    // Calculate the number of subnets
    numSubnets = calculateNumSubnets(subnetAddress);

    // Calculate the mask length
    maskLength = calculateMaskLength(subnetAddress);

    // Calculate the subnet mask
    subnetMask = calculateSubnetMask(maskLength);

    // Print the results
    printf("Number of subnets: %d\n", numSubnets);
    printf("Mask length: %d\n", maskLength);
    printf("Subnet mask: %x\n", subnetMask);

    return 0;
}

int calculateNumSubnets(char *subnetAddress) {

    int numSubnets = 0;
    int addressBits = countAddressBits(subnetAddress);

    numSubnets = (pow(2, addressBits) - 1) / 2;

    return numSubnets;
}

int calculateMaskLength(char *subnetAddress) {

    int maskLength = 0;
    int addressBits = countAddressBits(subnetAddress);

    maskLength = 32 - addressBits;

    return maskLength;
}

int calculateSubnetMask(int maskLength) {

    int subnetMask = 0;

    subnetMask = ~(~0 << maskLength) & 0xFFFFFFFF;

    return subnetMask;
}

int countAddressBits(char *subnetAddress) {

    int numBits = 0;
    char *addr = subnetAddress;

    while (*addr) {
        numBits += 8;
        addr++;
    }

    return numBits;
}