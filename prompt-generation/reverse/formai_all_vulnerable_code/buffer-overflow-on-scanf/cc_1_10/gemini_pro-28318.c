//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store subnet information
typedef struct subnet_info {
    unsigned int subnet_mask;
    unsigned int subnet_address;
    unsigned int broadcast_address;
    unsigned int host_range;
    unsigned int num_hosts;
} subnet_info;

// Function to calculate subnet information
subnet_info calculate_subnet_info(unsigned int ip_address, unsigned int subnet_mask) {
    // Check if the subnet mask is valid
    if (subnet_mask < 0 || subnet_mask > 32) {
        printf("Error: Invalid subnet mask.\n");
        exit(1);
    }

    // Calculate the subnet address
    unsigned int subnet_address = ip_address & subnet_mask;

    // Calculate the broadcast address
    unsigned int broadcast_address = subnet_address | ~subnet_mask;

    // Calculate the host range
    unsigned int host_range = ~subnet_mask;

    // Calculate the number of hosts
    unsigned int num_hosts = host_range - 2;  // Subtract 2 for the subnet address and broadcast address

    // Return the subnet information
    subnet_info subnet_info = {subnet_mask, subnet_address, broadcast_address, host_range, num_hosts};
    return subnet_info;
}

// Function to print subnet information
void print_subnet_info(subnet_info subnet_info) {
    printf("Subnet mask: %u.%u.%u.%u\n", (subnet_info.subnet_mask >> 24) & 0xFF, (subnet_info.subnet_mask >> 16) & 0xFF, (subnet_info.subnet_mask >> 8) & 0xFF, subnet_info.subnet_mask & 0xFF);
    printf("Subnet address: %u.%u.%u.%u\n", (subnet_info.subnet_address >> 24) & 0xFF, (subnet_info.subnet_address >> 16) & 0xFF, (subnet_info.subnet_address >> 8) & 0xFF, subnet_info.subnet_address & 0xFF);
    printf("Broadcast address: %u.%u.%u.%u\n", (subnet_info.broadcast_address >> 24) & 0xFF, (subnet_info.broadcast_address >> 16) & 0xFF, (subnet_info.broadcast_address >> 8) & 0xFF, subnet_info.broadcast_address & 0xFF);
    printf("Host range: %u.%u.%u.%u - %u.%u.%u.%u\n", (subnet_info.subnet_address >> 24) & 0xFF, (subnet_info.subnet_address >> 16) & 0xFF, (subnet_info.subnet_address >> 8) & 0xFF, (subnet_info.subnet_address & 0xFF) + 1, (subnet_info.broadcast_address >> 24) & 0xFF, (subnet_info.broadcast_address >> 16) & 0xFF, (subnet_info.broadcast_address >> 8) & 0xFF, subnet_info.broadcast_address & 0xFF - 1);
    printf("Number of hosts: %u\n", subnet_info.num_hosts);
}

// Main function
int main() {
    // Get the IP address and subnet mask from the user
    unsigned int ip_address, subnet_mask;
    printf("Enter the IP address: ");
    scanf("%u", &ip_address);
    printf("Enter the subnet mask: ");
    scanf("%u", &subnet_mask);

    // Calculate the subnet information
    subnet_info subnet_info = calculate_subnet_info(ip_address, subnet_mask);

    // Print the subnet information
    print_subnet_info(subnet_info);

    return 0;
}