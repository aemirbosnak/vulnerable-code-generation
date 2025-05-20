//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Structure for storing subnet information
typedef struct subnet_info {
    char ip_address[16];
    char subnet_mask[16];
    char network_address[16];
    char broadcast_address[16];
    char number_of_hosts[16];
    char wildcard_mask[16];
} subnet_info;

// Function to calculate subnet information
subnet_info* calculate_subnet_info(char* ip_address, char* subnet_mask) {
    // Convert IP address and subnet mask to binary representation
    unsigned int ip_binary = inet_addr(ip_address);
    unsigned int subnet_mask_binary = inet_addr(subnet_mask);

    // Perform bitwise AND operation to get network address
    unsigned int network_address_binary = ip_binary & subnet_mask_binary;

    // Perform bitwise OR operation to get broadcast address
    unsigned int broadcast_address_binary = ip_binary | ~subnet_mask_binary;

    // Convert binary representation back to IP addresses
    char network_address[16];
    inet_ntop(AF_INET, &network_address_binary, network_address, sizeof(network_address));

    char broadcast_address[16];
    inet_ntop(AF_INET, &broadcast_address_binary, broadcast_address, sizeof(broadcast_address));

    // Calculate number of hosts
    unsigned int number_of_hosts_binary = ~subnet_mask_binary & 0xFFFFFFFF;
    char number_of_hosts[16];
    inet_ntop(AF_INET, &number_of_hosts_binary, number_of_hosts, sizeof(number_of_hosts));

    // Calculate wildcard mask
    unsigned int wildcard_mask_binary = ~subnet_mask_binary;
    char wildcard_mask[16];
    inet_ntop(AF_INET, &wildcard_mask_binary, wildcard_mask, sizeof(wildcard_mask));

    // Create and return subnet information structure
    subnet_info* subnet_info = malloc(sizeof(subnet_info));
    strcpy(subnet_info->ip_address, ip_address);
    strcpy(subnet_info->subnet_mask, subnet_mask);
    strcpy(subnet_info->network_address, network_address);
    strcpy(subnet_info->broadcast_address, broadcast_address);
    strcpy(subnet_info->number_of_hosts, number_of_hosts);
    strcpy(subnet_info->wildcard_mask, wildcard_mask);

    return subnet_info;
}

// Function to print subnet information
void print_subnet_info(subnet_info* subnet_info) {
    printf("Subnet Information:\n");
    printf("IP Address: %s\n", subnet_info->ip_address);
    printf("Subnet Mask: %s\n", subnet_info->subnet_mask);
    printf("Network Address: %s\n", subnet_info->network_address);
    printf("Broadcast Address: %s\n", subnet_info->broadcast_address);
    printf("Number of Hosts: %s\n", subnet_info->number_of_hosts);
    printf("Wildcard Mask: %s\n", subnet_info->wildcard_mask);
}

// Main function
int main() {
    // Get IP address and subnet mask from user
    char ip_address[16];
    char subnet_mask[16];
    printf("Enter IP address: ");
    scanf("%s", ip_address);
    printf("Enter subnet mask: ");
    scanf("%s", subnet_mask);

    // Calculate subnet information
    subnet_info* subnet_info = calculate_subnet_info(ip_address, subnet_mask);

    // Print subnet information
    print_subnet_info(subnet_info);

    // Free allocated memory
    free(subnet_info);

    return 0;
}