//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to store the subnet information
typedef struct {
    unsigned long ip_address;
    unsigned int subnet_mask;
    unsigned int prefix_length;
    unsigned long network_address;
    unsigned long broadcast_address;
    unsigned long usable_host_range;
    unsigned long total_hosts;
} subnet_info;

// Function to calculate the subnet information
void calculate_subnet(subnet_info *subnet) {
    // Convert the IP address and subnet mask to binary
    unsigned long ip_binary = subnet->ip_address;
    unsigned int subnet_mask_binary = subnet->subnet_mask;

    // Calculate the prefix length
    subnet->prefix_length = 0;
    for (int i = 0; i < 32; i++) {
        if ((subnet_mask_binary >> i) & 1) {
            subnet->prefix_length++;
        }
    }

    // Calculate the network address
    subnet->network_address = ip_binary & subnet_mask_binary;

    // Calculate the broadcast address
    subnet->broadcast_address = subnet->network_address | ~subnet_mask_binary;

    // Calculate the usable host range
    subnet->usable_host_range = subnet->broadcast_address - subnet->network_address - 1;

    // Calculate the total number of hosts
    subnet->total_hosts = pow(2, 32 - subnet->prefix_length) - 2;
}

// Function to print the subnet information
void print_subnet(subnet_info subnet) {
    printf("IP Address: %lu\n", subnet.ip_address);
    printf("Subnet Mask: %u\n", subnet.subnet_mask);
    printf("Prefix Length: %u\n", subnet.prefix_length);
    printf("Network Address: %lu\n", subnet.network_address);
    printf("Broadcast Address: %lu\n", subnet.broadcast_address);
    printf("Usable Host Range: %lu\n", subnet.usable_host_range);
    printf("Total Hosts: %lu\n", subnet.total_hosts);
}

// Main function
int main() {
    // Get the IP address and subnet mask from the user
    unsigned long ip_address;
    unsigned int subnet_mask;
    printf("Enter the IP address: ");
    scanf("%lu", &ip_address);
    printf("Enter the subnet mask: ");
    scanf("%u", &subnet_mask);

    // Create a subnet_info structure
    subnet_info subnet;
    subnet.ip_address = ip_address;
    subnet.subnet_mask = subnet_mask;

    // Calculate the subnet information
    calculate_subnet(&subnet);

    // Print the subnet information
    print_subnet(subnet);

    return 0;
}