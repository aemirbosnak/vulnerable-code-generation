//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate subnet mask
void calculateSubnetMask(int subnetBits, char *subnetMask) {
    unsigned long mask = 0xFFFFFFFF << (32 - subnetBits);
    snprintf(subnetMask, 16, "%u.%u.%u.%u",
             (mask >> 24) & 0xFF,
             (mask >> 16) & 0xFF,
             (mask >> 8) & 0xFF,
             mask & 0xFF);
}

// Function to calculate the number of hosts in a subnet
int calculateHosts(int subnetBits) {
    return pow(2, (32 - subnetBits)) - 2; // Subtracting 2 for network and broadcast addresses
}

// Function to calculate network address
void calculateNetworkAddress(char *ipAddress, char *subnetMask, char *networkAddress) {
    unsigned int ipParts[4];
    unsigned int maskParts[4];
    
    sscanf(ipAddress, "%u.%u.%u.%u", &ipParts[0], &ipParts[1], &ipParts[2], &ipParts[3]);
    sscanf(subnetMask, "%u.%u.%u.%u", &maskParts[0], &maskParts[1], &maskParts[2], &maskParts[3]);
    
    sprintf(networkAddress, "%u.%u.%u.%u",
            ipParts[0] & maskParts[0],
            ipParts[1] & maskParts[1],
            ipParts[2] & maskParts[2],
            ipParts[3] & maskParts[3]);
}

// Function to calculate broadcast address
void calculateBroadcastAddress(char *networkAddress, char *subnetMask, char *broadcastAddress) {
    unsigned int netParts[4];
    unsigned int maskParts[4];
    unsigned int bcastParts[4];

    sscanf(networkAddress, "%u.%u.%u.%u", &netParts[0], &netParts[1], &netParts[2], &netParts[3]);
    sscanf(subnetMask, "%u.%u.%u.%u", &maskParts[0], &maskParts[1], &maskParts[2], &maskParts[3]);

    for(int i = 0; i < 4; i++) {
        bcastParts[i] = netParts[i] | (~maskParts[i] & 0xFF);
    }
    
    sprintf(broadcastAddress, "%u.%u.%u.%u", bcastParts[0], bcastParts[1], bcastParts[2], bcastParts[3]);
}

// Main function
int main() {
    printf("🎉 Welcome to the Cheerful C Subnet Calculator! 🎉\n\n");

    char ipAddress[16];
    int subnetBits;
    char subnetMask[16];
    char networkAddress[16];
    char broadcastAddress[16];
    
    // Asking for user input
    printf("Please enter an IP address (e.g., 192.168.1.1): ");
    fgets(ipAddress, sizeof(ipAddress), stdin);
    strtok(ipAddress, "\n");  // Remove newline character from the string

    printf("Please enter the subnet bits (e.g., /24): ");
    scanf(" /%d", &subnetBits);
    
    // Validating subnet bits
    if (subnetBits < 0 || subnetBits > 32) {
        printf("⚠️  Oops! Please enter a valid subnet bit between 0 and 32.\n");
        return 1;
    }

    // Calculating the subnet mask, network address, and broadcast address
    calculateSubnetMask(subnetBits, subnetMask);
    calculateNetworkAddress(ipAddress, subnetMask, networkAddress);
    calculateBroadcastAddress(networkAddress, subnetMask, broadcastAddress);

    // Displaying the results
    int hostCount = calculateHosts(subnetBits);
    printf("\n🎊 Here are your results! 🎊\n");
    printf("🌐 IP Address: %s\n", ipAddress);
    printf("📡 Subnet Mask: %s\n", subnetMask);
    printf("🏠 Network Address: %s\n", networkAddress);
    printf("📣 Broadcast Address: %s\n", broadcastAddress);
    printf("🏡 Number of Usable Hosts: %d\n", hostCount);
    
    printf("\nThank you for using the Cheerful C Subnet Calculator! 🎈\n");
    return 0;
}