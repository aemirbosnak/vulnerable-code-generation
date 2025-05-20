//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define ADDR_LEN 16
#define MASK_LEN 16

void calculateSubnet(char *ipAddress, char *subnetMask) {
    struct sockaddr_in ip, mask, network, broadcast;

    // Convert IP and Subnet Mask to network format
    inet_pton(AF_INET, ipAddress, &(ip.sin_addr));
    inet_pton(AF_INET, subnetMask, &(mask.sin_addr));

    // Calculate Network Address
    network.sin_addr.s_addr = ip.sin_addr.s_addr & mask.sin_addr.s_addr;

    // Calculate Broadcast Address
    broadcast.sin_addr.s_addr = network.sin_addr.s_addr | ~mask.sin_addr.s_addr;

    // Print Results
    char networkAddr[ADDR_LEN], broadcastAddr[ADDR_LEN];

    inet_ntop(AF_INET, &(network.sin_addr), networkAddr, ADDR_LEN);
    inet_ntop(AF_INET, &(broadcast.sin_addr), broadcastAddr, ADDR_LEN);

    printf("IP Address: %s\n", ipAddress);
    printf("Subnet Mask: %s\n", subnetMask);
    printf("Network Address: %s\n", networkAddr);
    printf("Broadcast Address: %s\n", broadcastAddr);
}

void displayMenu() {
    printf("C Subnet Calculator\n");
    printf("====================\n");
    printf("1. Calculate Subnet\n");
    printf("2. Exit\n");
    printf("====================\n");
}

int main() {
    char ipAddress[ADDR_LEN];
    char subnetMask[MASK_LEN];
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter IP address: ");
                scanf("%s", ipAddress);
                printf("Enter Subnet Mask: ");
                scanf("%s", subnetMask);

                // Validate IP Address
                struct sockaddr_in sa;
                int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
                if (result == 0) {
                    printf("Invalid IP Address format!\n");
                    break;
                }

                // Validate Subnet Mask
                result = inet_pton(AF_INET, subnetMask, &(sa.sin_addr));
                if (result == 0) {
                    printf("Invalid Subnet Mask format!\n");
                    break;
                }

                calculateSubnet(ipAddress, subnetMask);
                break;
            case 2:
                printf("Exiting the Subnet Calculator...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}