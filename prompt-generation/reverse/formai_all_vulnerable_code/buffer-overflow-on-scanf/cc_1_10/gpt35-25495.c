//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculateSubnet(char *address, int mask) {
    char *octets[4];
    char *delim = ".";
    int i;
    int subnetMaskBits = 0;
    int subnetMask[4] = {0, 0, 0, 0};
    int networkAddress[4];
    int broadcastAddress[4];

    // Split IP address into octets
    octets[0] = strtok(address, delim);
    for (i = 1; i < 4; i++) {
        octets[i] = strtok(NULL, delim);
    }

    // Convert octets to integers
    int ipOctets[4];
    for (i = 0; i < 4; i++) {
        ipOctets[i] = atoi(octets[i]);
    }

    // Calculate subnet mask
    for (i = 0; i < mask; i++) {
        subnetMaskBits |= (1 << (31 - i));
    }
    subnetMask[0] = (subnetMaskBits >> 24) & 0xff;
    subnetMask[1] = (subnetMaskBits >> 16) & 0xff;
    subnetMask[2] = (subnetMaskBits >> 8) & 0xff;
    subnetMask[3] = subnetMaskBits & 0xff;

    // Calculate network address
    for (i = 0; i < 4; i++) {
        networkAddress[i] = ipOctets[i] & subnetMask[i];
    }

    // Calculate broadcast address
    int invertedSubnetMask[4];
    invertedSubnetMask[0] = 255 - subnetMask[0];
    invertedSubnetMask[1] = 255 - subnetMask[1];
    invertedSubnetMask[2] = 255 - subnetMask[2];
    invertedSubnetMask[3] = 255 - subnetMask[3];
    for (i = 0; i < 4; i++) {
        broadcastAddress[i] = networkAddress[i] | invertedSubnetMask[i];
    }

    // Print results
    printf("IP Address: %d.%d.%d.%d\n", ipOctets[0], ipOctets[1], ipOctets[2], ipOctets[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
    printf("Network Address: %d.%d.%d.%d\n", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddress[0], broadcastAddress[1], broadcastAddress[2], broadcastAddress[3]);
}

int main() {
    char address[16];
    int mask;

    // Get IP address and subnet mask from user
    printf("Enter IP Address in decimal format (e.g. 192.168.0.1): ");
    scanf("%s", address);
    printf("Enter Subnet Mask in CIDR notation (e.g. 24): ");
    scanf("%d", &mask);

    // Calculate subnet
    calculateSubnet(address, mask);

    return 0;
}