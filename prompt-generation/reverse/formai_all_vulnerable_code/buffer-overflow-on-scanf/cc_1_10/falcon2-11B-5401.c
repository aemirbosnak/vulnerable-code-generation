//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the subnet mask
int calculateSubnetMask(int netmask) {
    int subnetMask = 0;
    for (int i = 0; i < 32; i++) {
        subnetMask |= (1 << (31 - i));
    }
    return subnetMask;
}

// Function to calculate the broadcast address
int calculateBroadcastAddress(int netmask, int subnetMask) {
    int broadcastAddress = 0;
    for (int i = 0; i < 32; i++) {
        if (i < netmask) {
            broadcastAddress |= (1 << (31 - i));
        } else {
            broadcastAddress &= ~(1 << (31 - i));
        }
    }
    return broadcastAddress;
}

// Function to calculate the number of hosts in a subnet
int calculateHosts(int subnetMask) {
    int hosts = 0;
    for (int i = 0; i < 32; i++) {
        hosts += (subnetMask & (1 << i))? 2 : 0;
    }
    return hosts;
}

int main() {
    int netmask;
    printf("Enter the netmask: ");
    scanf("%d", &netmask);

    int subnetMask = calculateSubnetMask(netmask);
    int broadcastAddress = calculateBroadcastAddress(netmask, subnetMask);
    int hosts = calculateHosts(subnetMask);

    printf("Subnet Mask: %d\n", subnetMask);
    printf("Broadcast Address: %d\n", broadcastAddress);
    printf("Number of Hosts: %d\n", hosts);

    return 0;
}