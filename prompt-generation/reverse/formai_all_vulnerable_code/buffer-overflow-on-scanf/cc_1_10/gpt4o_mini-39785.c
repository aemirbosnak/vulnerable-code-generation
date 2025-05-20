//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function to calculate the subnet
void calculateSubnet(char *ip, char *mask) {
    struct in_addr ip_addr, mask_addr, network_addr;
    // Convert IP string to binary form
    if (inet_pton(AF_INET, ip, &ip_addr) <= 0) {
        fprintf(stderr, "Error converting IP address\n");
        return;
    }
    // Convert subnet mask string to binary form
    if (inet_pton(AF_INET, mask, &mask_addr) <= 0) {
        fprintf(stderr, "Error converting subnet mask\n");
        return;
    }
    // Calculate the network address
    network_addr.s_addr = ip_addr.s_addr & mask_addr.s_addr;

    // Convert network address back to string form
    char network_str[INET_ADDRSTRLEN];
    if (inet_ntop(AF_INET, &network_addr, network_str, sizeof(network_str)) == NULL) {
        fprintf(stderr, "Error converting network address\n");
        return;
    }

    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", mask);
    printf("Network Address: %s\n", network_str);
}

// Function to print the menu
void printMenu() {
    printf("Surprising Subnet Calculator\n");
    printf("============================\n");
    printf("1. Calculate Subnet\n");
    printf("2. Exit\n");
    printf("============================\n");
}

// Function to handle user input
void handleInput() {
    char ip[INET_ADDRSTRLEN];
    char mask[INET_ADDRSTRLEN];

    while (1) {
        printMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter IP Address (e.g., 192.168.1.1): ");
                scanf("%s", ip);
                printf("Enter Subnet Mask (e.g., 255.255.255.0): ");
                scanf("%s", mask);
                calculateSubnet(ip, mask);
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    }
}

// Main function
int main() {
    printf("Welcome to the Surprising Subnet Calculator!\n");
    printf("Prepare yourself to unveil the secrets of networking!\n");
    handleInput();
    return 0;
}