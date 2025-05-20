//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void printSubnetInfo(const char *ip, const char *mask) {
    struct sockaddr_in ip_addr, mask_addr, net_addr;

    inet_pton(AF_INET, ip, &(ip_addr.sin_addr));
    inet_pton(AF_INET, mask, &(mask_addr.sin_addr));

    // Calculate network address
    net_addr.sin_addr.s_addr = ip_addr.sin_addr.s_addr & mask_addr.sin_addr.s_addr;

    char net_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(net_addr.sin_addr), net_str, INET_ADDRSTRLEN);

    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", mask);
    printf("Network Address: %s\n", net_str);
    
    // Calculate the number of usable addresses
    unsigned int host_bits = 32 - __builtin_popcount(mask_addr.sin_addr.s_addr);
    unsigned int total_addresses = (1 << host_bits);
    unsigned int usable_addresses = total_addresses - 2; // Exclude network and broadcast addresses

    printf("Total Addresses: %u\n", total_addresses);
    printf("Usable Addresses: %u\n", usable_addresses);

    // Calculate the broadcast address
    struct sockaddr_in broadcast_addr;
    broadcast_addr.sin_addr.s_addr = net_addr.sin_addr.s_addr | ~mask_addr.sin_addr.s_addr;
    char broadcast_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(broadcast_addr.sin_addr), broadcast_str, INET_ADDRSTRLEN);

    printf("Broadcast Address: %s\n", broadcast_str);
}

int checkValidIP(const char *ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) != 0;
}

int checkValidMask(const char *mask) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, mask, &(sa.sin_addr)) != 0;
}

void displayMenu() {
    printf("\n--- C Subnet Calculator ---\n");
    printf("1. Calculate Subnet\n");
    printf("2. Exit\n");
}

int main() {
    char ip[INET_ADDRSTRLEN];
    char mask[INET_ADDRSTRLEN];
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter IP Address (e.g., 192.168.1.1): ");
            scanf("%s", ip);

            if (!checkValidIP(ip)) {
                printf("Invalid IP Address format.\n");
                continue;
            }

            printf("Enter Subnet Mask (e.g., 255.255.255.0): ");
            scanf("%s", mask);

            if (!checkValidMask(mask)) {
                printf("Invalid Subnet Mask format.\n");
                continue;
            }

            printSubnetInfo(ip, mask);
        } else if (choice == 2) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}