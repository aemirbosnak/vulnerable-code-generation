//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 512

void print_usage() {
    printf("Usage: Subnet Calculator\n");
    printf("Type 'exit' to leave the calculator.\n");
    printf("Enter the IP Address and Subnet Mask to calculate subnet details.\n");
}

void calculate_subnet(char *ip_address, char *subnet_mask) {
    struct sockaddr_in ip, mask;
    
    // Initialize structures
    memset(&ip, 0, sizeof(ip));
    memset(&mask, 0, sizeof(mask));

    // Convert strings to in_addr
    inet_pton(AF_INET, ip_address, &(ip.sin_addr));
    inet_pton(AF_INET, subnet_mask, &(mask.sin_addr));
    
    // Calculate network address
    struct in_addr network;
    network.s_addr = ip.sin_addr.s_addr & mask.sin_addr.s_addr;

    // Calculate broadcast address
    struct in_addr broadcast;
    broadcast.s_addr = network.s_addr | ~mask.sin_addr.s_addr;

    // Calculate number of hosts
    unsigned int total_hosts = (1 << (32 - __builtin_popcount(mask.sin_addr.s_addr))) - 2;

    printf("\n--- Subnet Details ---\n");
    printf("IP Address: %s\n", ip_address);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Network Address: %s\n", inet_ntoa(network));
    printf("Broadcast Address: %s\n", inet_ntoa(broadcast));
    printf("Total Usable Hosts: %u\n", total_hosts);
}

int main() {
    char ip_address[BUFFER_SIZE];
    char subnet_mask[BUFFER_SIZE];
    char choice[BUFFER_SIZE];
    int client_count = 0;

    printf("Welcome to the Multiplayer Subnet Calculator!\n");
    print_usage();

    while (client_count < MAX_CLIENTS) {
        printf("\nClient %d, enter your details (IP Address and Subnet Mask):\n", client_count + 1);
        printf("IP Address: ");
        fgets(ip_address, BUFFER_SIZE, stdin);
        ip_address[strcspn(ip_address, "\n")] = 0; // Remove newline

        if (strcmp(ip_address, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }

        printf("Subnet Mask: ");
        fgets(subnet_mask, BUFFER_SIZE, stdin);
        subnet_mask[strcspn(subnet_mask, "\n")] = 0; // Remove newline

        if (strcmp(subnet_mask, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }

        calculate_subnet(ip_address, subnet_mask);
        client_count++;
        printf("\nDo you want to add another client? (yes/no): ");
        fgets(choice, BUFFER_SIZE, stdin);
        choice[strcspn(choice, "\n")] = 0; // Remove newline

        if (strcmp(choice, "no") == 0) {
            break;
        }
    }

    printf("Thank you for using the Subnet Calculator. Goodbye!\n");
    return 0;
}