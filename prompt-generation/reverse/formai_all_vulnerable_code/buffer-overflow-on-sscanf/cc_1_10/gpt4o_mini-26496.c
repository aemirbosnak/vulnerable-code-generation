//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LENGTH 15
#define MAX_SUBNET_LENGTH 2

void calculateSubnet(const char *ipAddress, int subnetMask) {
    unsigned int ipParts[4] = {0};
    unsigned int subnetParts[4] = {0};
    unsigned int networkParts[4] = {0};
    unsigned int broadcastParts[4] = {0};
    unsigned int numberOfHosts;

    // Parse the IP address
    sscanf(ipAddress, "%u.%u.%u.%u", &ipParts[0], &ipParts[1], &ipParts[2], &ipParts[3]);

    // Calculate subnet mask
    for (int i = 0; i < 4; i++) {
        if (subnetMask >= 8) {
            subnetParts[i] = 255;
            subnetMask -= 8;
        } else {
            subnetParts[i] = 256 - (1 << (8 - subnetMask));
            subnetMask = 0;
        }
    }

    // Calculate network address
    for (int i = 0; i < 4; i++) {
        networkParts[i] = ipParts[i] & subnetParts[i];
    }

    // Calculate broadcast address
    for (int i = 0; i < 4; i++) {
        broadcastParts[i] = networkParts[i] | ~subnetParts[i] & 255;
    }

    // Calculate number of hosts
    numberOfHosts = (1 << (32 - (subnetParts[0] == 255 ? 0 : subnetMask))) - 2;

    printf("IP Address: %u.%u.%u.%u\n", ipParts[0], ipParts[1], ipParts[2], ipParts[3]);
    printf("Subnet Mask: %u.%u.%u.%u\n", subnetParts[0], subnetParts[1], subnetParts[2], subnetParts[3]);
    printf("Network Address: %u.%u.%u.%u\n", networkParts[0], networkParts[1], networkParts[2], networkParts[3]);
    printf("Broadcast Address: %u.%u.%u.%u\n", broadcastParts[0], broadcastParts[1], broadcastParts[2], broadcastParts[3]);
    printf("Number of Hosts: %u\n", numberOfHosts);
}

int main() {
    char ipAddress[MAX_IP_LENGTH + 1];
    int subnetMask;

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter an IP address (e.g., 192.168.1.1): ");
    fgets(ipAddress, sizeof(ipAddress), stdin);
    ipAddress[strcspn(ipAddress, "\n")] = '\0'; // Remove the newline character

    printf("Please enter a subnet mask in CIDR notation (e.g., 24): ");
    scanf("%d", &subnetMask);

    if (subnetMask < 0 || subnetMask > 32) {
        printf("Invalid subnet mask. Please enter a value between 0 and 32.\n");
        return EXIT_FAILURE;
    }
    
    calculateSubnet(ipAddress, subnetMask);

    return 0;
}