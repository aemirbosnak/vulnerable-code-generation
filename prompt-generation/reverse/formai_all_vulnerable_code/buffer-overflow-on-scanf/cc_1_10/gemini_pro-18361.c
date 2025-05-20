//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold subnet information
typedef struct _subnet {
    unsigned long subnet_address;
    unsigned long subnet_mask;
    unsigned long broadcast_address;
    unsigned long first_usable_address;
    unsigned long last_usable_address;
    unsigned long number_of_hosts;
} subnet;

// Function to calculate subnet information
subnet calculate_subnet(unsigned long ip_address, unsigned long subnet_mask) {
    subnet subnet_info;

    // Calculate subnet address
    subnet_info.subnet_address = ip_address & subnet_mask;

    // Calculate broadcast address
    subnet_info.broadcast_address = subnet_info.subnet_address | ~subnet_mask;

    // Calculate first usable address
    subnet_info.first_usable_address = subnet_info.subnet_address + 1;

    // Calculate last usable address
    subnet_info.last_usable_address = subnet_info.broadcast_address - 1;

    // Calculate number of hosts
    subnet_info.number_of_hosts = (unsigned long)(~subnet_mask) - 1;

    return subnet_info;
}

// Function to print subnet information
void print_subnet_info(subnet subnet_info) {
    printf("Subnet address: %lu\n", subnet_info.subnet_address);
    printf("Subnet mask: %lu\n", subnet_info.subnet_mask);
    printf("Broadcast address: %lu\n", subnet_info.broadcast_address);
    printf("First usable address: %lu\n", subnet_info.first_usable_address);
    printf("Last usable address: %lu\n", subnet_info.last_usable_address);
    printf("Number of hosts: %lu\n", subnet_info.number_of_hosts);
}

// Main function
int main() {
    // Declare variables
    unsigned long ip_address, subnet_mask;

    // Get IP address from user
    printf("Enter IP address: ");
    scanf("%lu", &ip_address);

    // Get subnet mask from user
    printf("Enter subnet mask: ");
    scanf("%lu", &subnet_mask);

    // Calculate subnet information
    subnet subnet_info = calculate_subnet(ip_address, subnet_mask);

    // Print subnet information
    print_subnet_info(subnet_info);

    return 0;
}