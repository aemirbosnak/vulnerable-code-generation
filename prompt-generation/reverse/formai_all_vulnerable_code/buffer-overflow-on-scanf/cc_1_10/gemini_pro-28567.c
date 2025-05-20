//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the subnet information
typedef struct {
    unsigned long address;
    unsigned int prefix_length;
    unsigned long subnet_mask;
    unsigned long broadcast_address;
    unsigned long first_usable_address;
    unsigned long last_usable_address;
    unsigned long total_usable_addresses;
} subnet_info;

// Function to calculate the subnet information
subnet_info calculate_subnet(unsigned long address, unsigned int prefix_length) {
    subnet_info info;

    // Convert the prefix length to a subnet mask
    info.subnet_mask = 0xFFFFFFFF << (32 - prefix_length);

    // Apply the subnet mask to the address to get the network address
    info.address = address & info.subnet_mask;

    // Calculate the broadcast address
    info.broadcast_address = info.address | ~info.subnet_mask;

    // Calculate the first usable address
    info.first_usable_address = info.address + 1;

    // Calculate the last usable address
    info.last_usable_address = info.broadcast_address - 1;

    // Calculate the total number of usable addresses
    info.total_usable_addresses = info.last_usable_address - info.first_usable_address + 1;

    // Return the subnet information
    return info;
}

// Function to print the subnet information
void print_subnet_info(subnet_info info) {
    printf("Address: %s\n", inet_ntoa(info.address));
    printf("Prefix length: %d\n", info.prefix_length);
    printf("Subnet mask: %s\n", inet_ntoa(info.subnet_mask));
    printf("Broadcast address: %s\n", inet_ntoa(info.broadcast_address));
    printf("First usable address: %s\n", inet_ntoa(info.first_usable_address));
    printf("Last usable address: %s\n", inet_ntoa(info.last_usable_address));
    printf("Total usable addresses: %d\n", info.total_usable_addresses);
}

// Main function
int main() {
    // Get the address and prefix length from the user
    unsigned long address;
    unsigned int prefix_length;
    printf("Enter the IP address: ");
    scanf("%s", inet_ntoa(address));
    printf("Enter the prefix length: ");
    scanf("%d", &prefix_length);

    // Calculate the subnet information
    subnet_info info = calculate_subnet(address, prefix_length);

    // Print the subnet information
    print_subnet_info(info);

    return 0;
}