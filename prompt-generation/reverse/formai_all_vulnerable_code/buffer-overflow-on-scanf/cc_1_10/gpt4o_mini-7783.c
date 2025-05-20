//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

void displayMenu() {
    printf("\n--- C Subnet Calculator ---\n");
    printf("1. Calculate Subnet\n");
    printf("2. Exit\n");
}

void calculateSubnet(const char *ip_str, const char *subnet_mask_str) {
    struct sockaddr_in sa_ip, sa_mask;
    
    // Convert IP and subnet mask to binary form
    if (inet_pton(AF_INET, ip_str, &(sa_ip.sin_addr)) <= 0) {
        printf("Invalid IP address: %s\n", ip_str);
        return;
    }
    
    if (inet_pton(AF_INET, subnet_mask_str, &(sa_mask.sin_addr)) <= 0) {
        printf("Invalid subnet mask: %s\n", subnet_mask_str);
        return;
    }

    // Calculate the network and broadcast addresses
    unsigned int ip = ntohl(sa_ip.sin_addr.s_addr);
    unsigned int mask = ntohl(sa_mask.sin_addr.s_addr);
    unsigned int network = ip & mask;
    unsigned int broadcast = network | ~mask;

    // Print results
    printf("IP Address: %s\n", ip_str);
    printf("Subnet Mask: %s\n", subnet_mask_str);
    
    struct in_addr net_addr, broad_addr;
    net_addr.s_addr = htonl(network);
    broad_addr.s_addr = htonl(broadcast);
    
    printf("Network Address: %s\n", inet_ntoa(net_addr));
    printf("Broadcast Address: %s\n", inet_ntoa(broad_addr));

    // Calculate available hosts
    unsigned int available_hosts = ntohl(broadcast) - ntohl(network) - 1;
    printf("Available Hosts: %u\n", available_hosts);
}

int main() {
    char ip[MAX_BUFFER], subnet_mask[MAX_BUFFER];
    int choice;

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
      
        switch (choice) {
            case 1:
                printf("Enter IP Address (e.g., 192.168.1.1): ");
                scanf("%s", ip);
                printf("Enter Subnet Mask (e.g., 255.255.255.0): ");
                scanf("%s", subnet_mask);
                calculateSubnet(ip, subnet_mask);
                break;
            case 2:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}