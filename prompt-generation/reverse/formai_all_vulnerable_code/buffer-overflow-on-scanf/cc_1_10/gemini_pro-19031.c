//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a subnet
typedef struct subnet {
    unsigned int address;
    unsigned int mask;
    unsigned int broadcast;
    unsigned int network;
    unsigned int num_hosts;
} subnet_t;

// Function to calculate the subnet mask
unsigned int calculate_mask(unsigned int num_hosts) {
    unsigned int mask = 0;
    while (num_hosts >>= 1) {
        mask <<= 1;
        mask |= 1;
    }
    return mask;
}

// Function to calculate the broadcast address
unsigned int calculate_broadcast(unsigned int address, unsigned int mask) {
    return address | ~mask;
}

// Function to calculate the network address
unsigned int calculate_network(unsigned int address, unsigned int mask) {
    return address & mask;
}

// Function to calculate the number of hosts
unsigned int calculate_num_hosts(unsigned int mask) {
    return ~mask + 1;
}

// Function to print the subnet information
void print_subnet(subnet_t subnet) {
    printf("Address: %u\n", subnet.address);
    printf("Mask: %u\n", subnet.mask);
    printf("Broadcast: %u\n", subnet.broadcast);
    printf("Network: %u\n", subnet.network);
    printf("Number of hosts: %u\n\n", subnet.num_hosts);
}

// Main function
int main() {
    // Declare the subnet
    subnet_t subnet;

    // Get the user input
    printf("Enter the subnet address: ");
    scanf("%u", &subnet.address);
    printf("Enter the number of hosts: ");
    scanf("%u", &subnet.num_hosts);

    // Calculate the subnet mask
    subnet.mask = calculate_mask(subnet.num_hosts);

    // Calculate the broadcast address
    subnet.broadcast = calculate_broadcast(subnet.address, subnet.mask);

    // Calculate the network address
    subnet.network = calculate_network(subnet.address, subnet.mask);

    // Print the subnet information
    print_subnet(subnet);

    return 0;
}