//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: realistic
// Subnet Calculator
#include <stdio.h>
#include <stdlib.h>

// Function to calculate subnet mask
void calculateSubnetMask(char *ip, char *subnetMask) {
    int ipOctets[4];
    int subnetMaskOctets[4];

    // Split IP address into octets
    sscanf(ip, "%d.%d.%d.%d", &ipOctets[0], &ipOctets[1], &ipOctets[2], &ipOctets[3]);

    // Calculate subnet mask
    subnetMaskOctets[0] = 255 - ipOctets[0];
    subnetMaskOctets[1] = 255 - ipOctets[1];
    subnetMaskOctets[2] = 255 - ipOctets[2];
    subnetMaskOctets[3] = 255 - ipOctets[3];

    // Convert octets to subnet mask
    sprintf(subnetMask, "%d.%d.%d.%d", subnetMaskOctets[0], subnetMaskOctets[1], subnetMaskOctets[2], subnetMaskOctets[3]);
}

// Function to calculate network address
void calculateNetworkAddress(char *ip, char *subnetMask, char *networkAddress) {
    int ipOctets[4];
    int subnetMaskOctets[4];
    int networkAddressOctets[4];

    // Split IP address into octets
    sscanf(ip, "%d.%d.%d.%d", &ipOctets[0], &ipOctets[1], &ipOctets[2], &ipOctets[3]);

    // Split subnet mask into octets
    sscanf(subnetMask, "%d.%d.%d.%d", &subnetMaskOctets[0], &subnetMaskOctets[1], &subnetMaskOctets[2], &subnetMaskOctets[3]);

    // Calculate network address
    networkAddressOctets[0] = ipOctets[0] & subnetMaskOctets[0];
    networkAddressOctets[1] = ipOctets[1] & subnetMaskOctets[1];
    networkAddressOctets[2] = ipOctets[2] & subnetMaskOctets[2];
    networkAddressOctets[3] = ipOctets[3] & subnetMaskOctets[3];

    // Convert octets to network address
    sprintf(networkAddress, "%d.%d.%d.%d", networkAddressOctets[0], networkAddressOctets[1], networkAddressOctets[2], networkAddressOctets[3]);
}

// Function to calculate broadcast address
void calculateBroadcastAddress(char *ip, char *subnetMask, char *broadcastAddress) {
    int ipOctets[4];
    int subnetMaskOctets[4];
    int broadcastAddressOctets[4];

    // Split IP address into octets
    sscanf(ip, "%d.%d.%d.%d", &ipOctets[0], &ipOctets[1], &ipOctets[2], &ipOctets[3]);

    // Split subnet mask into octets
    sscanf(subnetMask, "%d.%d.%d.%d", &subnetMaskOctets[0], &subnetMaskOctets[1], &subnetMaskOctets[2], &subnetMaskOctets[3]);

    // Calculate broadcast address
    broadcastAddressOctets[0] = ipOctets[0] | (~subnetMaskOctets[0] & 0xFF);
    broadcastAddressOctets[1] = ipOctets[1] | (~subnetMaskOctets[1] & 0xFF);
    broadcastAddressOctets[2] = ipOctets[2] | (~subnetMaskOctets[2] & 0xFF);
    broadcastAddressOctets[3] = ipOctets[3] | (~subnetMaskOctets[3] & 0xFF);

    // Convert octets to broadcast address
    sprintf(broadcastAddress, "%d.%d.%d.%d", broadcastAddressOctets[0], broadcastAddressOctets[1], broadcastAddressOctets[2], broadcastAddressOctets[3]);
}

int main() {
    char ip[16];
    char subnetMask[16];
    char networkAddress[16];
    char broadcastAddress[16];

    // Get IP address and subnet mask from user
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter subnet mask: ");
    scanf("%s", subnetMask);

    // Calculate subnet mask, network address, and broadcast address
    calculateSubnetMask(ip, subnetMask);
    calculateNetworkAddress(ip, subnetMask, networkAddress);
    calculateBroadcastAddress(ip, subnetMask, broadcastAddress);

    // Print results
    printf("Subnet mask: %s\n", subnetMask);
    printf("Network address: %s\n", networkAddress);
    printf("Broadcast address: %s\n", broadcastAddress);

    return 0;
}