//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate subnet mask
int calculateSubnetMask(int netmask, int network)
{
    // Calculate subnet mask
    int subnetMask = network << netmask;

    return subnetMask;
}

// Function to calculate broadcast address
int calculateBroadcast(int network)
{
    // Calculate broadcast address
    int broadcast = network | (~network + 1);

    return broadcast;
}

// Function to calculate network address
int calculateNetwork(int network)
{
    // Calculate network address
    int networkAddress = network & ~255;

    return networkAddress;
}

int main()
{
    int network;
    int netmask;
    int subnetMask;
    int broadcast;
    int networkAddress;

    // Prompt user to enter network address
    printf("Enter network address: ");
    scanf("%d", &network);

    // Prompt user to enter netmask
    printf("Enter netmask: ");
    scanf("%d", &netmask);

    // Calculate subnet mask
    subnetMask = calculateSubnetMask(netmask, network);

    // Calculate broadcast address
    broadcast = calculateBroadcast(network);

    // Calculate network address
    networkAddress = calculateNetwork(network);

    // Print results
    printf("Network address: %d\n", networkAddress);
    printf("Subnet mask: %d\n", subnetMask);
    printf("Broadcast address: %d\n", broadcast);

    return 0;
}