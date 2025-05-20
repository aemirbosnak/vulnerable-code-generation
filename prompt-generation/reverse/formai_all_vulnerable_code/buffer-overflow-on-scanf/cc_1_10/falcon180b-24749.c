//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: recursive
#include <stdio.h>

// Function to calculate the number of hosts in a subnet
int calculateHosts(int subnetBits) {
    // Base case: if the subnet has only one host, return 2 (one host and the network address)
    if (subnetBits == 1) {
        return 2;
    }

    // Recursive case: calculate the number of hosts in the next smaller subnet
    int hosts = 2;
    for (int i = 1; i < subnetBits; i++) {
        hosts *= 2;
    }
    return hosts;
}

// Function to calculate the number of subnets in a network
int calculateSubnets(int networkBits, int subnetBits) {
    // Base case: if the subnet is the same as the network, there is only one subnet
    if (subnetBits == networkBits) {
        return 1;
    }

    // Recursive case: calculate the number of subnets in the next larger network
    int subnets = 2;
    for (int i = subnetBits; i < networkBits; i++) {
        subnets *= 2;
    }
    return subnets;
}

int main() {
    // Get user input for network and subnet bits
    int networkBits, subnetBits;
    printf("Enter the number of bits in the network: ");
    scanf("%d", &networkBits);
    printf("Enter the number of bits in the subnet: ");
    scanf("%d", &subnetBits);

    // Calculate the number of hosts and subnets
    int hosts = calculateHosts(subnetBits);
    int subnets = calculateSubnets(networkBits, subnetBits);

    // Print the results
    printf("The number of hosts in the subnet is: %d\n", hosts);
    printf("The number of subnets in the network is: %d\n", subnets);

    return 0;
}