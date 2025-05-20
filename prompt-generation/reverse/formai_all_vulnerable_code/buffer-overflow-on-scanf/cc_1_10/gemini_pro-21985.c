//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of subnets per subnet mask
#define MAX_SUBNETS 256

// Define the maximum number of hosts per subnet
#define MAX_HOSTS 65536

// Define the structure of a subnet
typedef struct subnet {
    unsigned int address;
    unsigned int mask;
    unsigned int broadcast;
    unsigned int first_host;
    unsigned int last_host;
    unsigned int num_hosts;
} subnet_t;

// Define the function to calculate the subnet mask
unsigned int calculate_subnet_mask(unsigned int num_subnets) {
    // Calculate the number of bits in the subnet mask
    unsigned int num_bits = 32 - log2(num_subnets);

    // Create the subnet mask
    unsigned int subnet_mask = 0;
    for (unsigned int i = 0; i < num_bits; i++) {
        subnet_mask |= (1 << (31 - i));
    }

    // Return the subnet mask
    return subnet_mask;
}

// Define the function to calculate the broadcast address
unsigned int calculate_broadcast_address(unsigned int address, unsigned int mask) {
    // Create the broadcast address
    unsigned int broadcast_address = address | ~mask;

    // Return the broadcast address
    return broadcast_address;
}

// Define the function to calculate the first host address
unsigned int calculate_first_host_address(unsigned int address, unsigned int mask) {
    // Create the first host address
    unsigned int first_host_address = address & mask;

    // Return the first host address
    return first_host_address;
}

// Define the function to calculate the last host address
unsigned int calculate_last_host_address(unsigned int address, unsigned int mask) {
    // Create the last host address
    unsigned int last_host_address = address | ~mask;

    // Return the last host address
    return last_host_address;
}

// Define the function to calculate the number of hosts per subnet
unsigned int calculate_num_hosts(unsigned int mask) {
    // Calculate the number of bits in the host mask
    unsigned int num_bits = 32 - log2(mask);

    // Calculate the number of hosts
    unsigned int num_hosts = pow(2, num_bits) - 2;

    // Return the number of hosts
    return num_hosts;
}

// Define the function to print the subnet information
void print_subnet_information(subnet_t subnet) {
    printf("Subnet address: %u.%u.%u.%u\n",
        (subnet.address >> 24) & 0xFF,
        (subnet.address >> 16) & 0xFF,
        (subnet.address >> 8) & 0xFF,
        subnet.address & 0xFF);

    printf("Subnet mask: %u.%u.%u.%u\n",
        (subnet.mask >> 24) & 0xFF,
        (subnet.mask >> 16) & 0xFF,
        (subnet.mask >> 8) & 0xFF,
        subnet.mask & 0xFF);

    printf("Broadcast address: %u.%u.%u.%u\n",
        (subnet.broadcast >> 24) & 0xFF,
        (subnet.broadcast >> 16) & 0xFF,
        (subnet.broadcast >> 8) & 0xFF,
        subnet.broadcast & 0xFF);

    printf("First host address: %u.%u.%u.%u\n",
        (subnet.first_host >> 24) & 0xFF,
        (subnet.first_host >> 16) & 0xFF,
        (subnet.first_host >> 8) & 0xFF,
        subnet.first_host & 0xFF);

    printf("Last host address: %u.%u.%u.%u\n",
        (subnet.last_host >> 24) & 0xFF,
        (subnet.last_host >> 16) & 0xFF,
        (subnet.last_host >> 8) & 0xFF,
        subnet.last_host & 0xFF);

    printf("Number of hosts: %u\n", subnet.num_hosts);
}

// Define the main function
int main() {
    // Get the subnet address
    printf("Enter the subnet address: ");
    unsigned int address;
    scanf("%u", &address);

    // Get the number of subnets
    printf("Enter the number of subnets: ");
    unsigned int num_subnets;
    scanf("%u", &num_subnets);

    // Calculate the subnet mask
    unsigned int subnet_mask = calculate_subnet_mask(num_subnets);

    // Calculate the broadcast address
    unsigned int broadcast_address = calculate_broadcast_address(address, subnet_mask);

    // Calculate the first host address
    unsigned int first_host_address = calculate_first_host_address(address, subnet_mask);

    // Calculate the last host address
    unsigned int last_host_address = calculate_last_host_address(address, subnet_mask);

    // Calculate the number of hosts per subnet
    unsigned int num_hosts = calculate_num_hosts(subnet_mask);

    // Create the subnet
    subnet_t subnet;
    subnet.address = address;
    subnet.mask = subnet_mask;
    subnet.broadcast = broadcast_address;
    subnet.first_host = first_host_address;
    subnet.last_host = last_host_address;
    subnet.num_hosts = num_hosts;

    // Print the subnet information
    print_subnet_information(subnet);

    return 0;
}