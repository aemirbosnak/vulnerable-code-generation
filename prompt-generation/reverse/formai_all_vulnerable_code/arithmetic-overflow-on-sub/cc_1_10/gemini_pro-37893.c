//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subnets
#define MAX_SUBNETS 100

// Define the subnet calculator structure
typedef struct {
    unsigned long subnet_mask;
    unsigned long subnet_address;
    unsigned long broadcast_address;
    unsigned long first_usable_address;
    unsigned long last_usable_address;
    unsigned long total_hosts;
} subnet_calculator;

// Calculate the subnet calculator
subnet_calculator calculate_subnet(unsigned long ip_address, unsigned long subnet_mask) {
    // Initialize the subnet calculator
    subnet_calculator subnet;

    // Calculate the subnet mask
    subnet.subnet_mask = subnet_mask;

    // Calculate the subnet address
    subnet.subnet_address = ip_address & subnet_mask;

    // Calculate the broadcast address
    subnet.broadcast_address = subnet.subnet_address | ~subnet_mask;

    // Calculate the first usable address
    subnet.first_usable_address = subnet.subnet_address + 1;

    // Calculate the last usable address
    subnet.last_usable_address = subnet.broadcast_address - 1;

    // Calculate the total hosts
    subnet.total_hosts = (unsigned long) pow(2, 32 - ntohl(subnet_mask)) - 2;

    // Return the subnet calculator
    return subnet;
}

// Print the subnet calculator
void print_subnet(subnet_calculator subnet) {
    // Print the subnet mask
    printf("Subnet mask: %lu.%lu.%lu.%lu\n",
        (subnet.subnet_mask >> 24) & 0xFF,
        (subnet.subnet_mask >> 16) & 0xFF,
        (subnet.subnet_mask >> 8) & 0xFF,
        subnet.subnet_mask & 0xFF);

    // Print the subnet address
    printf("Subnet address: %lu.%lu.%lu.%lu\n",
        (subnet.subnet_address >> 24) & 0xFF,
        (subnet.subnet_address >> 16) & 0xFF,
        (subnet.subnet_address >> 8) & 0xFF,
        subnet.subnet_address & 0xFF);

    // Print the broadcast address
    printf("Broadcast address: %lu.%lu.%lu.%lu\n",
        (subnet.broadcast_address >> 24) & 0xFF,
        (subnet.broadcast_address >> 16) & 0xFF,
        (subnet.broadcast_address >> 8) & 0xFF,
        subnet.broadcast_address & 0xFF);

    // Print the first usable address
    printf("First usable address: %lu.%lu.%lu.%lu\n",
        (subnet.first_usable_address >> 24) & 0xFF,
        (subnet.first_usable_address >> 16) & 0xFF,
        (subnet.first_usable_address >> 8) & 0xFF,
        subnet.first_usable_address & 0xFF);

    // Print the last usable address
    printf("Last usable address: %lu.%lu.%lu.%lu\n",
        (subnet.last_usable_address >> 24) & 0xFF,
        (subnet.last_usable_address >> 16) & 0xFF,
        (subnet.last_usable_address >> 8) & 0xFF,
        subnet.last_usable_address & 0xFF);

    // Print the total hosts
    printf("Total hosts: %lu\n", subnet.total_hosts);
}

// Main function
int main() {
    // Get the IP address and subnet mask from the user
    unsigned long ip_address, subnet_mask;
    printf("Enter the IP address: ");
    scanf("%lu", &ip_address);
    printf("Enter the subnet mask: ");
    scanf("%lu", &subnet_mask);

    // Calculate the subnet calculator
    subnet_calculator subnet = calculate_subnet(ip_address, subnet_mask);

    // Print the subnet calculator
    print_subnet(subnet);

    return 0;
}