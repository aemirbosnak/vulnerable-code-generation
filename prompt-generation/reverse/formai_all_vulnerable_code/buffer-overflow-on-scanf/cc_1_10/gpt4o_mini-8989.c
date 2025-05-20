//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 16
#define MAX_SUBNET_LENGTH 3

void convertToBinary(uint32_t num, char *binary) {
    for (int i = 31; i >= 0; --i) {
        binary[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
    binary[32] = '\0';
}

void printSubnetInfo(const char *ip, const char *subnet_mask) {
    struct sockaddr_in sa_ip, sa_mask;
    inet_pton(AF_INET, ip, &(sa_ip.sin_addr));
    inet_pton(AF_INET, subnet_mask, &(sa_mask.sin_addr));

    uint32_t ip_addr = ntohl(sa_ip.sin_addr.s_addr);
    uint32_t mask_addr = ntohl(sa_mask.sin_addr.s_addr);
    uint32_t network_addr = ip_addr & mask_addr;
    uint32_t broadcast_addr = network_addr | ~mask_addr;

    char binary_ip[33], binary_mask[33], binary_network[33], binary_broadcast[33];
    convertToBinary(ip_addr, binary_ip);
    convertToBinary(mask_addr, binary_mask);
    convertToBinary(network_addr, binary_network);
    convertToBinary(broadcast_addr, binary_broadcast);

    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Binary IP: %s\n", binary_ip);
    printf("Binary Mask: %s\n", binary_mask);
    printf("Network Address: %s\n", inet_ntoa((struct in_addr){htonl(network_addr)}));
    printf("Binary Network: %s\n", binary_network);
    printf("Broadcast Address: %s\n", inet_ntoa((struct in_addr){htonl(broadcast_addr)}));
    printf("Binary Broadcast: %s\n", binary_broadcast);
}

void calculateSubnet() {
    char ip[MAX_IP_LENGTH];
    char subnet_mask[MAX_SUBNET_LENGTH];

    printf("Enter an IP Address (e.g., 192.168.1.1): ");
    fgets(ip, MAX_IP_LENGTH, stdin);
    ip[strcspn(ip, "\n")] = 0; // Remove trailing newline

    printf("Enter Subnet Mask (e.g., 255.255.255.0): ");
    fgets(subnet_mask, MAX_SUBNET_LENGTH, stdin);
    subnet_mask[strcspn(subnet_mask, "\n")] = 0; // Remove trailing newline

    printSubnetInfo(ip, subnet_mask);
}

void displayMenu() {
    printf("\n--- C Subnet Calculator ---\n");
    printf("1. Calculate Subnet\n");
    printf("2. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                getchar(); // Clear the newline left in buffer
                calculateSubnet();
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}