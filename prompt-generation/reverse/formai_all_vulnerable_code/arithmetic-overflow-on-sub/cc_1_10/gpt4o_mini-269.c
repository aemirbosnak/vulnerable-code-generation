//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_SUBNETS 32

typedef struct {
    char subnet_addr[16];
    char netmask[16];
    char broadcast[16];
    int number_of_hosts;
} SubnetDetails;

void calculate_subnet_details(const char* ip, int prefix_length, SubnetDetails* details) {
    struct in_addr ipv4_addr, netmask_addr, network_addr, broadcast_addr;

    // Convert IP address to binary form
    inet_pton(AF_INET, ip, &ipv4_addr);
    
    // Create netmask from prefix length
    unsigned int mask = 0xFFFFFFFF << (32 - prefix_length);
    netmask_addr.s_addr = htonl(mask);

    // Calculate Network Address
    network_addr.s_addr = ipv4_addr.s_addr & netmask_addr.s_addr;
    
    // Calculate Broadcast Address
    broadcast_addr.s_addr = network_addr.s_addr | ~netmask_addr.s_addr;

    // Populate SubnetDetails structure
    inet_ntop(AF_INET, &network_addr, details->subnet_addr, sizeof(details->subnet_addr));
    inet_ntop(AF_INET, &netmask_addr, details->netmask, sizeof(details->netmask));
    inet_ntop(AF_INET, &broadcast_addr, details->broadcast, sizeof(details->broadcast));

    // Calculate number of hosts
    details->number_of_hosts = (1 << (32 - prefix_length)) - 2; // -2 for network and broadcast addresses
}

void print_subnet_details(SubnetDetails* details) {
    printf("Subnet Address: %s\n", details->subnet_addr);
    printf("Netmask: %s\n", details->netmask);
    printf("Broadcast Address: %s\n", details->broadcast);
    printf("Number of Usable Hosts: %d\n", details->number_of_hosts);
}

int main() {
    char ip[16];
    int prefix_length;
    SubnetDetails details;

    printf("Enter the IP address (e.g., 192.168.1.0): ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0;  // Remove trailing newline character

    printf("Enter the prefix length (e.g., 24): ");
    scanf("%d", &prefix_length);

    if (prefix_length < 0 || prefix_length > 32) {
        fprintf(stderr, "Error: invalid prefix length. It must be between 0 and 32.\n");
        exit(EXIT_FAILURE);
    }

    calculate_subnet_details(ip, prefix_length, &details);
    print_subnet_details(&details);

    return 0;
}