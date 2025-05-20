//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define IP_LENGTH 16
#define MASK_LENGTH 3
#define SUBNET_LENGTH 16

void calculateSubnet(const char* ip, const char* mask) {
    uint8_t ipParts[4], maskParts[4], subnetParts[4], broadcastParts[4];
    uint32_t hostBits, subnetBits;
    
    // Parse IP address
    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &ipParts[0], &ipParts[1], &ipParts[2], &ipParts[3]);
    
    // Parse subnet mask
    sscanf(mask, "%hhu.%hhu.%hhu.%hhu", &maskParts[0], &maskParts[1], &maskParts[2], &maskParts[3]);
    
    // Calculate subnet and broadcast addresses
    for (int i = 0; i < 4; i++) {
        subnetParts[i] = ipParts[i] & maskParts[i];
        broadcastParts[i] = subnetParts[i] | (~maskParts[i] & 0xFF);
    }
    
    // Calculate number of host bits
    hostBits = 32;
    subnetBits = 0;
    for (int i = 0; i < 4; i++) {
        while (maskParts[i] > 0) {
            maskParts[i] >>= 1;
            subnetBits++;
        }
    }
    hostBits -= subnetBits;

    // Display results
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", mask);
    printf("Subnet Address: %d.%d.%d.%d\n", subnetParts[0], subnetParts[1], subnetParts[2], subnetParts[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastParts[0], broadcastParts[1], broadcastParts[2], broadcastParts[3]);
    printf("Number of Hosts: %d\n", (1 << hostBits) - 2);
}

void getInput(char* ip, char* mask) {
    printf("Enter IP Address (format: x.x.x.x): ");
    fgets(ip, IP_LENGTH, stdin);
    ip[strcspn(ip, "\n")] = '\0'; // Remove the newline character

    printf("Enter Subnet Mask (format: x.x.x.x): ");
    fgets(mask, MASK_LENGTH, stdin);
    mask[strcspn(mask, "\n")] = '\0'; // Remove the newline character
}

int main() {
    char ip[IP_LENGTH];
    char mask[IP_LENGTH];

    printf("=== C Subnet Calculator ===\n");
    getInput(ip, mask);
    calculateSubnet(ip, mask);

    return 0;
}