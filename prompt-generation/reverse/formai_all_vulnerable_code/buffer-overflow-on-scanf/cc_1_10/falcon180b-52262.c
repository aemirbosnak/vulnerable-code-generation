//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>

// Function to check if a number is a power of 2
int isPowerOfTwo(int num) {
    if (num <= 0) {
        return 0;
    }

    while (num % 2 == 0) {
        num /= 2;
    }

    if (num == 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to calculate the subnet mask
void calculateSubnetMask(int numHosts, int numSubnets) {
    int numBits = 0;

    // Calculate the number of bits needed for the subnet mask
    while (numSubnets > 1) {
        numSubnets /= 2;
        numBits++;
    }

    // Calculate the subnet mask
    int subnetMask = 0;
    for (int i = 0; i < 32 - numBits; i++) {
        subnetMask |= (1 << i);
    }

    // Print the subnet mask
    printf("Subnet mask: %d.%d.%d.%d\n", (subnetMask >> 24) & 0xFF, (subnetMask >> 16) & 0xFF, (subnetMask >> 8) & 0xFF, subnetMask & 0xFF);
}

int main() {
    int numHosts, numSubnets;

    // Get the number of hosts and subnets from the user
    printf("Enter the number of hosts: ");
    scanf("%d", &numHosts);

    printf("Enter the number of subnets: ");
    scanf("%d", &numSubnets);

    // Check if the number of subnets is a power of 2
    if (!isPowerOfTwo(numSubnets)) {
        printf("Error: The number of subnets must be a power of 2.\n");
        return 1;
    }

    // Calculate the subnet mask
    calculateSubnetMask(numHosts, numSubnets);

    return 0;
}