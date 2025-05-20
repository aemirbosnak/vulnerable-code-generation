//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 15
#define MAX_MASK_LENGTH 2

// Structure to hold subnet information
typedef struct {
    char ip[MAX_IP_LENGTH + 1];
    int subnet_mask;
    char network[MAX_IP_LENGTH + 1];
    char broadcast[MAX_IP_LENGTH + 1];
    char first_host[MAX_IP_LENGTH + 1];
    char last_host[MAX_IP_LENGTH + 1];
    int total_hosts;
} SubnetInfo;

// Function to calculate subnet addresses
void calculate_subnet(SubnetInfo *subnet) {
    struct in_addr ip_addr, network_addr, broadcast_addr;
    int mask = subnet->subnet_mask;

    // Convert IP address to binary form
    if (inet_pton(AF_INET, subnet->ip, &ip_addr) != 1) {
        fprintf(stderr, "Invalid IP address.\n");
        exit(EXIT_FAILURE);
    }

    // Network address calculation
    network_addr.s_addr = ip_addr.s_addr & htonl(~((1 << (32 - mask)) - 1));
    inet_ntop(AF_INET, &network_addr, subnet->network, sizeof(subnet->network));

    // Broadcast address calculation
    broadcast_addr.s_addr = network_addr.s_addr | htonl((1 << (32 - mask)) - 1);
    inet_ntop(AF_INET, &broadcast_addr, subnet->broadcast, sizeof(subnet->broadcast));

    // First usable host
    strcpy(subnet->first_host, subnet->network);
    subnet->first_host[strlen(subnet->first_host) - 1] += 1; // increment last octet

    // Last usable host
    strcpy(subnet->last_host, subnet->broadcast);
    subnet->last_host[strlen(subnet->last_host) - 1] -= 1; // decrement last octet

    // Total usable hosts
    subnet->total_hosts = (1 << (32 - mask)) - 2; // total addresses minus network and broadcast
}

// Function to print subnet information
void print_subnet_info(const SubnetInfo *subnet) {
    printf("IP Address: %s\n", subnet->ip);
    printf("Subnet Mask: /%d\n", subnet->subnet_mask);
    printf("Network Address: %s\n", subnet->network);
    printf("Broadcast Address: %s\n", subnet->broadcast);
    printf("First Usable Host: %s\n", subnet->first_host);
    printf("Last Usable Host: %s\n", subnet->last_host);
    printf("Total Usable Hosts: %d\n", subnet->total_hosts);
}

int main() {
    SubnetInfo subnet;

    printf("Subnet Calculator\n");
    printf("=================\n");

    // User input for IP Address and Subnet Mask
    printf("Enter IP Address (format: x.x.x.x): ");
    fgets(subnet.ip, sizeof(subnet.ip), stdin);
    subnet.ip[strcspn(subnet.ip, "\n")] = 0; // Remove newline character

    printf("Enter Subnet Mask (e.g., 24 for /24): ");
    scanf("%d", &subnet.subnet_mask);

    // Validate subnet mask
    if (subnet.subnet_mask < 0 || subnet.subnet_mask > 32) {
        fprintf(stderr, "Invalid subnet mask. It must be between 0 and 32.\n");
        return EXIT_FAILURE;
    }

    // Calculate subnet information
    calculate_subnet(&subnet);

    // Print the calculated subnet information
    print_subnet_info(&subnet);

    return EXIT_SUCCESS;
}