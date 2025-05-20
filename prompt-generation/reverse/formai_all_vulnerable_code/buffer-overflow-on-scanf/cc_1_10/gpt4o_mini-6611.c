//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function prototypes
void calculateSubnet(char *ip, char *mask);
void printSubnetDetails(struct in_addr subnet, struct in_addr broadcast, int hostCount);

int main() {
    char ip[16];
    char mask[16];
    char choice;

    printf("Welcome to the Subnet Calculator!\n");

    do {
        printf("Please enter an IP address (e.g., 192.168.1.1): ");
        scanf("%15s", ip);
        
        printf("Please enter a subnet mask (e.g., 255.255.255.0): ");
        scanf("%15s", mask);

        calculateSubnet(ip, mask);

        printf("Do you want to calculate another subnet? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Subnet Calculator. Goodbye!\n");

    return 0;
}

void calculateSubnet(char *ip, char *mask) {
    struct in_addr ipAddr, maskAddr, subnetAddr, broadcastAddr;
    
    // Convert IP and mask to in_addr structure
    if (inet_pton(AF_INET, ip, &ipAddr) <= 0) {
        printf("Invalid IP address format. Please try again.\n");
        return;
    }
    if (inet_pton(AF_INET, mask, &maskAddr) <= 0) {
        printf("Invalid subnet mask format. Please try again.\n");
        return;
    }

    // Calculate subnet and broadcast addresses
    subnetAddr.s_addr = ipAddr.s_addr & maskAddr.s_addr;
    broadcastAddr.s_addr = subnetAddr.s_addr | ~maskAddr.s_addr;

    // Calculate number of hosts
    int hostCount = (ntohl(maskAddr.s_addr) ^ 0xFFFFFFFF) + 1;

    // Printing the results
    printSubnetDetails(subnetAddr, broadcastAddr, hostCount);
}

void printSubnetDetails(struct in_addr subnet, struct in_addr broadcast, int hostCount) {
    char subnetStr[INET_ADDRSTRLEN];
    char broadcastStr[INET_ADDRSTRLEN];

    // Convert back to string for easier display
    inet_ntop(AF_INET, &subnet, subnetStr, sizeof(subnetStr));
    inet_ntop(AF_INET, &broadcast, broadcastStr, sizeof(broadcastStr));

    printf("\n--- Subnet Details ---\n");
    printf("Subnet Address: %s\n", subnetStr);
    printf("Broadcast Address: %s\n", broadcastStr);
    printf("Total number of hosts: %d\n", hostCount);
    printf("----------------------\n");
}