//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: satisfied
#include <stdio.h>

int main()
{
    int ip[4];
    int subnetBits;
    int subnetMask[4];
    int wildcardMask[4];
    int networkAddress[4];
    int broadcastAddress[4];
    int maxHosts;
    int i;

    printf("Enter IP address in dotted decimal format (e.g. 192.168.0.1): ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Enter number of subnet bits: ");
    scanf("%d", &subnetBits);

    // Calculate subnet mask
    for (i = 0; i < 4; i++) {
        if (subnetBits >= 8) {
            subnetMask[i] = 255;
            subnetBits -= 8;
        } else if (subnetBits > 0 && subnetBits < 8) {
            subnetMask[i] = 256 - (1 << (8 - subnetBits));
            subnetBits = 0;
        } else {
            subnetMask[i] = 0;
        }
    }

    // Calculate wildcard mask
    for (i = 0; i < 4; i++) {
        wildcardMask[i] = 255 - subnetMask[i];
    }

    // Calculate network address
    for (i = 0; i < 4; i++) {
        networkAddress[i] = ip[i] & subnetMask[i];
    }

    // Calculate broadcast address
    for (i = 0; i < 4; i++) {
        broadcastAddress[i] = networkAddress[i] | wildcardMask[i];
    }

    // Calculate maximum number of hosts
    maxHosts = (1 << (32 - subnetBits)) - 2;

    // Print results
    printf("\nSubnet mask: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
    printf("Wildcard mask: %d.%d.%d.%d\n", wildcardMask[0], wildcardMask[1], wildcardMask[2], wildcardMask[3]);
    printf("Network address: %d.%d.%d.%d\n", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcastAddress[0], broadcastAddress[1], broadcastAddress[2], broadcastAddress[3]);
    printf("Maximum number of hosts: %d\n", maxHosts);

    return 0;
}