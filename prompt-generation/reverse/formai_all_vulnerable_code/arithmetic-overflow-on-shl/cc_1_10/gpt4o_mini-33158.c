//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 16
#define MAX_MASK_LENGTH 4

void printSubnetDetails(const char *ip_address, const char *subnet_mask) {
    struct in_addr ip, mask, network, broadcast;
    
    if (inet_pton(AF_INET, ip_address, &ip) != 1 || inet_pton(AF_INET, subnet_mask, &mask) != 1) {
        printf("Invalid IP address or subnet mask\n");
        return;
    }

    // Calculate network address (ip & mask)
    network.s_addr = ip.s_addr & mask.s_addr;
    // Calculate broadcast address (network | ~mask)
    broadcast.s_addr = network.s_addr | ~mask.s_addr;

    printf("Network address: %s\n", inet_ntoa(network));
    printf("Broadcast address: %s\n", inet_ntoa(broadcast));

    // Calculate number of usable hosts
    unsigned int host_bits = 32 - __builtin_popcount(mask.s_addr);
    unsigned int usable_hosts = (1 << host_bits) - 2; // -2 for network and broadcast

    printf("Total usable hosts: %u\n\n", usable_hosts);
}

int checkValidIP(const char *ip_address) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip_address, &(sa.sin_addr)) == 1;
}

int checkValidSubnetMask(const char *subnet_mask) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, subnet_mask, &(sa.sin_addr)) == 1;
}

void showMenu() {
    printf("--------------------------------------------------\n");
    printf("Welcome to the Brave Subnet Calculator!\n");
    printf("1. Calculate Subnet\n");
    printf("2. Exit\n");
    printf("--------------------------------------------------\n");
}

int main() {
    char ip_address[MAX_IP_LENGTH];
    char subnet_mask[MAX_MASK_LENGTH];

    while (1) {
        showMenu();
        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 2) {
            printf("Exiting...\n");
            break;
        }

        if (choice != 1) {
            printf("Invalid selection. Please try again.\n");
            continue;
        }

        printf("Enter an IP address (e.g., 192.168.1.1): ");
        scanf("%s", ip_address);
        printf("Enter a Subnet Mask (e.g., 255.255.255.0): ");
        scanf("%s", subnet_mask);

        if (!checkValidIP(ip_address)) {
            printf("Invalid IP address. Please try again.\n");
            continue;
        }

        if (!checkValidSubnetMask(subnet_mask)) {
            printf("Invalid subnet mask. Please try again.\n");
            continue;
        }

        printf("\nCalculating subnet details...\n");
        printSubnetDetails(ip_address, subnet_mask);
    }
    
    return 0;
}