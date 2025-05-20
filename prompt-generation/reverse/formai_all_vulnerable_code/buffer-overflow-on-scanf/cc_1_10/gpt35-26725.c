//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the subnet
void subnetCalculator(int ipv4[], int subnet) {
    int subnetMask[4] = {0, 0, 0, 0};
    int subnetBits = 0;
    int i, j;

    // Calculate the subnet mask
    for (i = 0; i < 4; i++) {
        for (j = 7; j >= 0; j--) {
            if (subnetBits < subnet) {
                subnetMask[i] |= (1 << j);
                subnetBits++;
            }
        }
    }

    printf("\nSubnet mask is: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);

    // Calculate the network address
    int network[4] = {0, 0, 0, 0};
    for (i = 0; i < 4; i++) {
        network[i] = ipv4[i] & subnetMask[i];
    }

    printf("Network address is: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);

    // Calculate the broadcast address
    int broadcast[4] = {0, 0, 0, 0};
    for (i = 0; i < 4; i++) {
        broadcast[i] = network[i] | ~subnetMask[i];
    }

    printf("Broadcast address is: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);

    // Calculate the total number of hosts
    int numHosts = (1 << (32 - subnet)) - 2;

    printf("Number of hosts is: %d\n\n", numHosts);
}

int main() {
    int ipv4[4];
    int subnet;

    // Take input IPv4 address
    printf("Enter IPv4 address (with dots): ");
    scanf("%d.%d.%d.%d", &ipv4[0], &ipv4[1], &ipv4[2], &ipv4[3]);

    // Take input subnet
    printf("\nEnter subnet (e.g. 24 for /24): ");
    scanf("%d", &subnet);

    // Call the subnetCalculator function
    subnetCalculator(ipv4, subnet);

    return 0;
}