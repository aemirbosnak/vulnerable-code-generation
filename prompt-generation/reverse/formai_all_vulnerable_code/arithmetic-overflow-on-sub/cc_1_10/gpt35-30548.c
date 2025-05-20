//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main() {
    int IP[4], prefix, subnet[4], subnetMask;
    printf("Enter IP Address (e.g. 192.168.1.0): ");
    scanf("%d.%d.%d.%d", &IP[0], &IP[1], &IP[2], &IP[3]);
    printf("Enter Prefix (e.g. 24): ");
    scanf("%d", &prefix);

    // Determine subnet mask
    int i;
    for (i = 0; i < 4; i++) {
        if (prefix >= 8) {
            subnet[i] = 255;
            prefix -= 8;
        } else {
            subnetMask = 256 - (1 << (8 - prefix));
            subnet[i] = subnetMask;
            prefix = 0;
        }
    }

    // Print Subnet Mask
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);

    // Print Network Address
    int networkAddress[4];
    for (i = 0; i < 4; i++) {
        networkAddress[i] = IP[i] & subnet[i];
    }
    printf("Network Address: %d.%d.%d.%d\n", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);

    // Print Broadcast Address
    int broadcastAddress[4];
    for (i = 0; i < 4; i++) {
        broadcastAddress[i] = IP[i] | (subnet[i] ^ 255);
    }
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddress[0], broadcastAddress[1], broadcastAddress[2], broadcastAddress[3]);

    // Print Number of Hosts
    int numberOfHosts = 1;
    for (i = 0; i < 4; i++) {
        if (subnet[i] != 255) {
            numberOfHosts *= (subnet[i] - 1);
        }
    }
    printf("Number of Hosts: %d", numberOfHosts);

    return 0;
}