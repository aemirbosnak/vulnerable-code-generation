//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an IP address from string to unsigned long
unsigned long ipToLong(const char *ip) {
    unsigned long result = 0;
    unsigned int octet;
    char *token;
    char *ipCopy = strdup(ip); // Duplicate the string to avoid modifying the original

    token = strtok(ipCopy, ".");
    while (token) {
        octet = atoi(token);
        result = (result << 8) | (octet & 0xFF);
        token = strtok(NULL, ".");
    }

    free(ipCopy); // Free the allocated memory
    return result;
}

// Function to convert an unsigned long back to IP address string
void longToIp(unsigned long ip, char *buffer) {
    sprintf(buffer, "%lu.%lu.%lu.%lu",
            (ip >> 24) & 0xFF,
            (ip >> 16) & 0xFF,
            (ip >> 8) & 0xFF,
            ip & 0xFF);
}

// Function to calculate the subnet details
void calculateSubnet(const char *ip, int subnetMask) {
    unsigned long ipLong = ipToLong(ip);
    unsigned long subnetMaskLong = (0xFFFFFFFF << (32 - subnetMask)) & 0xFFFFFFFF;
    unsigned long network = ipLong & subnetMaskLong;
    unsigned long broadcast = network | ~subnetMaskLong;

    char networkIP[16];
    char broadcastIP[16];

    longToIp(network, networkIP);
    longToIp(broadcast, broadcastIP);

    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: /%d\n", subnetMask);
    printf("Network Address: %s\n", networkIP);
    printf("Broadcast Address: %s\n", broadcastIP);
}

// Function to display the menu and get user input
void displayMenu() {
    printf("\nC Subnet Calculator\n");
    printf("=====================\n");
    printf("1. Calculate Subnet\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

// Main driver function
int main() {
    int choice;
    char ipAddress[16];
    int subnetMask;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter IP Address (xxx.xxx.xxx.xxx): ");
            scanf("%s", ipAddress);
            printf("Enter Subnet Mask (1-30): ");
            scanf("%d", &subnetMask);

            if (subnetMask < 1 || subnetMask > 30) {
                printf("Invalid subnet mask. Please enter a value between 1 and 30.\n");
                continue;
            }

            calculateSubnet(ipAddress, subnetMask);
        } else if (choice == 2) {
            printf("Exiting...\n");
            exit(0);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}