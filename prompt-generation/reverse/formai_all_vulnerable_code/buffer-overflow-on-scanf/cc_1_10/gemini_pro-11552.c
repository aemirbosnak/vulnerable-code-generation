//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store subnet information
typedef struct {
    unsigned int address;
    unsigned int subnet_mask;
    unsigned int network_address;
    unsigned int broadcast_address;
    unsigned int number_of_hosts;
} Subnet;

// Function to calculate subnet information
Subnet calculate_subnet(unsigned int address, unsigned int subnet_mask) {
    Subnet subnet;

    // Calculate network address
    subnet.network_address = address & subnet_mask;

    // Calculate broadcast address
    subnet.broadcast_address = subnet.network_address | ~subnet_mask;

    // Calculate number of hosts
    subnet.number_of_hosts = (1 << (32 - count_set_bits(subnet_mask))) - 2;

    // Store address and subnet mask
    subnet.address = address;
    subnet.subnet_mask = subnet_mask;

    return subnet;
}

// Function to count set bits in a number
int count_set_bits(unsigned int number) {
    int count = 0;
    while (number) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

// Function to print subnet information
void print_subnet(Subnet subnet) {
    printf("Subnet Information:\n");
    printf("-------------------\n");
    printf("Address: %u.%u.%u.%u\n", (subnet.address >> 24) & 0xFF, (subnet.address >> 16) & 0xFF, (subnet.address >> 8) & 0xFF, subnet.address & 0xFF);
    printf("Subnet Mask: %u.%u.%u.%u\n", (subnet.subnet_mask >> 24) & 0xFF, (subnet.subnet_mask >> 16) & 0xFF, (subnet.subnet_mask >> 8) & 0xFF, subnet.subnet_mask & 0xFF);
    printf("Network Address: %u.%u.%u.%u\n", (subnet.network_address >> 24) & 0xFF, (subnet.network_address >> 16) & 0xFF, (subnet.network_address >> 8) & 0xFF, subnet.network_address & 0xFF);
    printf("Broadcast Address: %u.%u.%u.%u\n", (subnet.broadcast_address >> 24) & 0xFF, (subnet.broadcast_address >> 16) & 0xFF, (subnet.broadcast_address >> 8) & 0xFF, subnet.broadcast_address & 0xFF);
    printf("Number of Hosts: %u\n", subnet.number_of_hosts);
}

// Main function
int main() {
    // Get address and subnet mask from user
    unsigned int address, subnet_mask;
    printf("Enter IP address: ");
    scanf("%u", &address);
    printf("Enter subnet mask: ");
    scanf("%u", &subnet_mask);

    // Calculate subnet information
    Subnet subnet = calculate_subnet(address, subnet_mask);

    // Print subnet information
    print_subnet(subnet);

    return 0;
}