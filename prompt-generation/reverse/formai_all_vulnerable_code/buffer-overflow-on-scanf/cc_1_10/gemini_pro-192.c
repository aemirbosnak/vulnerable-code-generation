//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of subnets
#define MAX_SUBNETS 10

// Define the structure of a subnet
typedef struct subnet {
    unsigned int subnet_id;
    unsigned int subnet_mask;
    unsigned int subnet_address;
    unsigned int subnet_broadcast;
    unsigned int subnet_size;
    unsigned int subnet_num_hosts;
} subnet;

// Define the structure of the input parameters
typedef struct input_params {
    unsigned int network_address;
    unsigned int network_mask;
    unsigned int num_subnets;
} input_params;

// Function to calculate the subnet mask
unsigned int calculate_subnet_mask(unsigned int num_subnets) {
    unsigned int subnet_mask = 32;
    while (num_subnets > 0) {
        num_subnets >>= 1;
        subnet_mask--;
    }
    return subnet_mask;
}

// Function to calculate the subnet address
unsigned int calculate_subnet_address(unsigned int network_address, unsigned int subnet_mask) {
    return network_address & subnet_mask;
}

// Function to calculate the subnet broadcast
unsigned int calculate_subnet_broadcast(unsigned int subnet_address, unsigned int subnet_mask) {
    return subnet_address | ~subnet_mask;
}

// Function to calculate the subnet size
unsigned int calculate_subnet_size(unsigned int subnet_mask) {
    return pow(2, 32 - subnet_mask);
}

// Function to calculate the subnet number of hosts
unsigned int calculate_subnet_num_hosts(unsigned int subnet_size) {
    return subnet_size - 2;
}

// Function to create a subnet
subnet create_subnet(unsigned int subnet_id, unsigned int subnet_mask, unsigned int subnet_address, unsigned int subnet_broadcast, unsigned int subnet_size, unsigned int subnet_num_hosts) {
    subnet subnet;
    subnet.subnet_id = subnet_id;
    subnet.subnet_mask = subnet_mask;
    subnet.subnet_address = subnet_address;
    subnet.subnet_broadcast = subnet_broadcast;
    subnet.subnet_size = subnet_size;
    subnet.subnet_num_hosts = subnet_num_hosts;
    return subnet;
}

// Function to print a subnet
void print_subnet(subnet subnet) {
    printf("Subnet %u:\n", subnet.subnet_id);
    printf("  Subnet mask: %u\n", subnet.subnet_mask);
    printf("  Subnet address: %u\n", subnet.subnet_address);
    printf("  Subnet broadcast: %u\n", subnet.subnet_broadcast);
    printf("  Subnet size: %u\n", subnet.subnet_size);
    printf("  Subnet number of hosts: %u\n", subnet.subnet_num_hosts);
}

// Function to calculate the subnets
void calculate_subnets(input_params input_params) {
    // Calculate the subnet mask
    unsigned int subnet_mask = calculate_subnet_mask(input_params.num_subnets);

    // Calculate the subnet address
    unsigned int subnet_address = calculate_subnet_address(input_params.network_address, subnet_mask);

    // Calculate the subnet broadcast
    unsigned int subnet_broadcast = calculate_subnet_broadcast(subnet_address, subnet_mask);

    // Calculate the subnet size
    unsigned int subnet_size = calculate_subnet_size(subnet_mask);

    // Calculate the subnet number of hosts
    unsigned int subnet_num_hosts = calculate_subnet_num_hosts(subnet_size);

    // Create the subnets
    subnet subnets[MAX_SUBNETS];
    for (unsigned int i = 0; i < input_params.num_subnets; i++) {
        subnets[i] = create_subnet(i, subnet_mask, subnet_address, subnet_broadcast, subnet_size, subnet_num_hosts);
        subnet_address += subnet_size;
        subnet_broadcast += subnet_size;
    }

    // Print the subnets
    for (unsigned int i = 0; i < input_params.num_subnets; i++) {
        print_subnet(subnets[i]);
        printf("\n");
    }
}

int main() {
    // Get the input parameters
    input_params input_params;
    printf("Enter the network address: ");
    scanf("%u", &input_params.network_address);
    printf("Enter the network mask: ");
    scanf("%u", &input_params.network_mask);
    printf("Enter the number of subnets: ");
    scanf("%u", &input_params.num_subnets);

    // Calculate the subnets
    calculate_subnets(input_params);

    return 0;
}