//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_OCTET_VALUE 255
#define MAX_SUBNET_MASK 32

void calculateSubnet(char* ip, int subnetMask) {
    unsigned char octets[4];
    int i;

    // Convert IP address from string to individual octet integers
    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &octets[0], &octets[1], &octets[2], &octets[3]);

    // Calculate the network address
    unsigned char network[4] = {0};
    unsigned char broadcast[4] = {0};

    for(i = 0; i < 4; i++) {
        // Check if we are still within the subnet mask
        if(subnetMask >= (i + 1) * 8) {
            network[i] = octets[i]; // Use whole octet for network
            broadcast[i] = octets[i]; // Same for broadcast in full subnet
        } else {
            // Use mask bits to determine network and broadcast addresses
            int maskBits = 8 - (subnetMask - (i * 8));
            network[i] = octets[i] & (~((1 << maskBits) - 1));
            broadcast[i] = octets[i] | ((1 << maskBits) - 1);
        }
    }

    // Calculate valid hosts
    int validHosts = (1 << (MAX_SUBNET_MASK - subnetMask)) - 2; // Minus 2 for network and broadcast
    if(validHosts < 0) validHosts = 0; // No valid hosts in some subnets

    // Display results
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %d\n", subnetMask);

    printf("Network Address: %hhu.%hhu.%hhu.%hhu\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast Address: %hhu.%hhu.%hhu.%hhu\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Total Valid Hosts: %d\n", validHosts);
    printf("\n");
}

int main() {
    char ip[16];
    int subnetMask;

    printf("Subnet Calculator\n");
    printf("===================\n");

    while(1) {
        printf("Enter IP address (or 'exit' to quit): ");
        fgets(ip, sizeof(ip), stdin);
        
        // Remove newline character from input
        ip[strcspn(ip, "\n")] = 0;

        // Exit condition
        if (strcmp(ip, "exit") == 0) {
            break;
        }

        printf("Enter Subnet Mask (0-32): ");
        scanf("%d", &subnetMask);
        while(getchar() != '\n'); // Clear input buffer

        if(subnetMask < 0 || subnetMask > MAX_SUBNET_MASK) {
            printf("Invalid subnet mask. Please enter a value between 0 and 32.\n");
            continue;
        }

        calculateSubnet(ip, subnetMask);
    }

    printf("Exiting Subnet Calculator. Goodbye!\n");
    return 0;
}