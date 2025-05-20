//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary string
void decimalToBinary(int num, char *binary) {
    for (int i = 31; i >= 0; i--) {
        binary[i] = (num % 2) + '0'; // Convert to character
        num /= 2;
    }
    binary[32] = '\0'; // Null-terminate the string
}

// Function to calculate subnet mask based on prefix length
void calculateSubnetMask(int prefix, char *subnetMask) {
    int mask = (0xFFFFFFFF << (32 - prefix)) & 0xFFFFFFFF; // Create subnet mask
    sprintf(subnetMask, "%d.%d.%d.%d", 
            (mask >> 24) & 255, 
            (mask >> 16) & 255, 
            (mask >> 8) & 255, 
            mask & 255);
}

// Function to calculate network address
void calculateNetworkAddress(char *ipAddress, char *subnetMask, char *networkAddress) {
    unsigned int ip[4], mask[4];
    sscanf(ipAddress, "%u.%u.%u.%u", &ip[0], &ip[1], &ip[2], &ip[3]);
    sscanf(subnetMask, "%u.%u.%u.%u", &mask[0], &mask[1], &mask[2], &mask[3]);
    
    sprintf(networkAddress, "%u.%u.%u.%u", 
            ip[0] & mask[0], 
            ip[1] & mask[1], 
            ip[2] & mask[2], 
            ip[3] & mask[3]);
}

// Function to calculate broadcast address
void calculateBroadcastAddress(char *networkAddress, char *subnetMask, char *broadcastAddress) {
    unsigned int net[4], mask[4];
    sscanf(networkAddress, "%u.%u.%u.%u", &net[0], &net[1], &net[2], &net[3]);
    sscanf(subnetMask, "%u.%u.%u.%u", &mask[0], &mask[1], &mask[2], &mask[3]);
    
    sprintf(broadcastAddress, "%u.%u.%u.%u",
            net[0] | (~mask[0] & 255), 
            net[1] | (~mask[1] & 255), 
            net[2] | (~mask[2] & 255), 
            net[3] | (~mask[3] & 255));
}

// Function to calculate the number of hosts
void calculateHosts(int prefix, int *numHosts) {
    *numHosts = (1 << (32 - prefix)) - 2; // Total number of usable hosts
}

// Main function - subnet calculator
int main() {
    char ipAddress[16];
    char subnetMask[16];
    char networkAddress[16];
    char broadcastAddress[16];
    int prefix, numHosts;

    // User input for IP address and subnet prefix
    printf("Enter IP Address (e.g., 192.168.1.1): ");
    fgets(ipAddress, sizeof(ipAddress), stdin);
    ipAddress[strcspn(ipAddress, "\n")] = 0; // Remove trailing newline

    printf("Enter Subnet Prefix (e.g., 24): ");
    scanf("%d", &prefix);
    
    // Validate prefix length
    if (prefix < 0 || prefix > 32) {
        fprintf(stderr, "Invalid prefix length. It must be between 0 and 32.\n");
        return EXIT_FAILURE;
    }

    // Calculate subnet mask
    calculateSubnetMask(prefix, subnetMask);
    printf("Subnet Mask: %s\n", subnetMask);

    // Calculate network address
    calculateNetworkAddress(ipAddress, subnetMask, networkAddress);
    printf("Network Address: %s\n", networkAddress);
    
    // Calculate broadcast address
    calculateBroadcastAddress(networkAddress, subnetMask, broadcastAddress);
    printf("Broadcast Address: %s\n", broadcastAddress);
    
    // Calculate number of usable hosts
    calculateHosts(prefix, &numHosts);
    printf("Number of Usable Hosts: %d\n", numHosts);

    return EXIT_SUCCESS;
}