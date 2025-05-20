//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Structure to store subnet information
typedef struct {
    uint32_t ip_address;     // IP address of the subnet
    uint32_t subnet_mask;    // Subnet mask of the subnet
    uint32_t network_address; // Network address of the subnet
    uint32_t broadcast_address; // Broadcast address of the subnet
    uint32_t usable_hosts;     // Number of usable hosts in the subnet
} subnet_info_t;

// Function to calculate subnet information
subnet_info_t calculate_subnet_info(uint32_t ip_address, uint32_t subnet_mask) {
    subnet_info_t subnet_info;

    // Calculate the network address
    subnet_info.network_address = ip_address & subnet_mask;

    // Calculate the broadcast address
    subnet_info.broadcast_address = subnet_info.network_address | ~subnet_mask;

    // Calculate the number of usable hosts
    subnet_info.usable_hosts = (1 << (32 - ntohl(subnet_mask))) - 2;

    // Return the subnet information
    return subnet_info;
}

// Function to print subnet information
void print_subnet_info(subnet_info_t subnet_info) {
    char ip_address_str[INET_ADDRSTRLEN];
    char subnet_mask_str[INET_ADDRSTRLEN];
    char network_address_str[INET_ADDRSTRLEN];
    char broadcast_address_str[INET_ADDRSTRLEN];

    // Convert IP addresses to strings
    inet_ntop(AF_INET, &subnet_info.ip_address, ip_address_str, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &subnet_info.subnet_mask, subnet_mask_str, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &subnet_info.network_address, network_address_str, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &subnet_info.broadcast_address, broadcast_address_str, INET_ADDRSTRLEN);

    // Print subnet information
    printf("IP Address: %s\n", ip_address_str);
    printf("Subnet Mask: %s\n", subnet_mask_str);
    printf("Network Address: %s\n", network_address_str);
    printf("Broadcast Address: %s\n", broadcast_address_str);
    printf("Usable Hosts: %u\n", subnet_info.usable_hosts);
}

// Main function
int main(int argc, char **argv) {
    // Check if the user has provided enough arguments
    if (argc != 3) {
        printf("Usage: %s <ip_address> <subnet_mask>\n", argv[0]);
        return 1;
    }

    // Convert the IP address and subnet mask to network byte order
    uint32_t ip_address = inet_addr(argv[1]);
    uint32_t subnet_mask = inet_addr(argv[2]);

    // Calculate subnet information
    subnet_info_t subnet_info = calculate_subnet_info(ip_address, subnet_mask);

    // Print subnet information
    print_subnet_info(subnet_info);

    return 0;
}