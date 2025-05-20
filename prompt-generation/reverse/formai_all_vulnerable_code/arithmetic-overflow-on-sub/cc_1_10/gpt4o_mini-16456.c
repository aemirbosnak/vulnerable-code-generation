//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate the subnet mask
void calculateSubnetMask(int subnetBits, char* subnetMask) {
    unsigned long mask = (0xFFFFFFFF >> (32 - subnetBits)) << (32 - subnetBits);
    sprintf(subnetMask, "%d.%d.%d.%d", 
            (mask >> 24) & 0xFF, 
            (mask >> 16) & 0xFF, 
            (mask >> 8) & 0xFF, 
            mask & 0xFF);
}

// Function to calculate network address
void calculateNetworkAddress(const char* ipAddress, const char* subnetMask, char* networkAddress) {
    unsigned char ip[4], mask[4];
    sscanf(ipAddress, "%hhd.%hhd.%hhd.%hhd", &ip[0], &ip[1], &ip[2], &ip[3]);
    sscanf(subnetMask, "%hhd.%hhd.%hhd.%hhd", &mask[0], &mask[1], &mask[2], &mask[3]);
    
    sprintf(networkAddress, "%d.%d.%d.%d", 
            ip[0] & mask[0], 
            ip[1] & mask[1], 
            ip[2] & mask[2], 
            ip[3] & mask[3]);
}

// Function to calculate broadcast address
void calculateBroadcastAddress(const char* networkAddress, const char* subnetMask, char* broadcastAddress) {
    unsigned char net[4], mask[4];
    sscanf(networkAddress, "%hhd.%hhd.%hhd.%hhd", &net[0], &net[1], &net[2], &net[3]);
    sscanf(subnetMask, "%hhd.%hhd.%hhd.%hhd", &mask[0], &mask[1], &mask[2], &mask[3]);
    
    sprintf(broadcastAddress, "%d.%d.%d.%d", 
            net[0] | (~mask[0] & 0xFF), 
            net[1] | (~mask[1] & 0xFF), 
            net[2] | (~mask[2] & 0xFF), 
            net[3] | (~mask[3] & 0xFF));
}

// Function to calculate the number of usable hosts
int calculateUsableHosts(int subnetBits) {
    return (1 << (32 - subnetBits)) - 2; // Total hosts minus network and broadcast
}

// Function that displays the result
void displayResults(const char* ipAddress, int subnetBits) {
    char subnetMask[16];
    char networkAddress[16];
    char broadcastAddress[16];
    int usableHosts;

    calculateSubnetMask(subnetBits, subnetMask);
    calculateNetworkAddress(ipAddress, subnetMask, networkAddress);
    calculateBroadcastAddress(networkAddress, subnetMask, broadcastAddress);
    usableHosts = calculateUsableHosts(subnetBits);

    printf("\n--- Subnet Information ---\n");
    printf("IP Address: %s\n", ipAddress);
    printf("Subnet Mask: %s\n", subnetMask);
    printf("Network Address: %s\n", networkAddress);
    printf("Broadcast Address: %s\n", broadcastAddress);
    printf("Usable Hosts: %d\n", usableHosts);
    printf("--------------------------\n");
}

int main() {
    char ipAddress[16];
    int subnetBits;

    printf("Welcome to the Retro Subnet Calculator!\n");
    printf("-------------------------------------\n");
    printf("Please enter an IP address (e.g., 192.168.1.10): ");
    scanf("%15s", ipAddress);

    printf("Please enter subnet bits (e.g., 24): ");
    scanf("%d", &subnetBits);

    // Validate input
    if (subnetBits < 0 || subnetBits > 32) {
        printf("Invalid subnet bits! Please enter a value between 0 and 32.\n");
        return 1;
    }

    // Display results
    displayResults(ipAddress, subnetBits);
    
    printf("Thank you for using the Retro Subnet Calculator!\n");
    printf("-------------------------------------\n");
    return 0;
}