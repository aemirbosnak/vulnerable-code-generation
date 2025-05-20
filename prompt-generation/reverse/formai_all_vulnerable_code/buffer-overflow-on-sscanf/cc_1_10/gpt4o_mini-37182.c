//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert IP address from string to integer array
void ipStringToIntArray(const char *ip, int ipArray[4]) {
    sscanf(ip, "%d.%d.%d.%d", &ipArray[0], &ipArray[1], &ipArray[2], &ipArray[3]);
}

// Function to convert subnet mask from string to integer array
void maskStringToIntArray(const char *mask, int maskArray[4]) {
    sscanf(mask, "%d.%d.%d.%d", &maskArray[0], &maskArray[1], &maskArray[2], &maskArray[3]);
}

// Function to calculate the network address
void calculateNetworkAddress(int ipArray[4], int maskArray[4], int networkArray[4]) {
    for (int i = 0; i < 4; i++) {
        networkArray[i] = ipArray[i] & maskArray[i];
    }
}

// Function to calculate the broadcast address
void calculateBroadcastAddress(int ipArray[4], int maskArray[4], int broadcastArray[4]) {
    for (int i = 0; i < 4; i++) {
        broadcastArray[i] = ipArray[i] | (~maskArray[i] & 0xFF);
    }
}

// Function to print the array containing IP address or subnet information
void printIP(const char *label, int ipArray[4]) {
    printf("%s: %d.%d.%d.%d\n", label, ipArray[0], ipArray[1], ipArray[2], ipArray[3]);
}

int main() {
    char ipInput[16];
    char maskInput[16];
    int ipArray[4] = {0};
    int maskArray[4] = {0};
    int networkArray[4] = {0};
    int broadcastArray[4] = {0};

    // Get user input for IP address
    printf("Enter IP address (e.g., 192.168.1.1): ");
    fgets(ipInput, sizeof(ipInput), stdin);
    ipInput[strcspn(ipInput, "\n")] = 0; // Remove newline character

    // Get user input for Subnet Mask
    printf("Enter Subnet Mask (e.g., 255.255.255.0): ");
    fgets(maskInput, sizeof(maskInput), stdin);
    maskInput[strcspn(maskInput, "\n")] = 0; // Remove newline character

    // Convert strings to integer arrays
    ipStringToIntArray(ipInput, ipArray);
    maskStringToIntArray(maskInput, maskArray);
    
    // Calculate Network Address
    calculateNetworkAddress(ipArray, maskArray, networkArray);
    
    // Calculate Broadcast Address
    calculateBroadcastAddress(ipArray, maskArray, broadcastArray);
    
    // Print Results
    printIP("IP Address", ipArray);
    printIP("Subnet Mask", maskArray);
    printIP("Network Address", networkArray);
    printIP("Broadcast Address", broadcastArray);
    
    return 0;
}