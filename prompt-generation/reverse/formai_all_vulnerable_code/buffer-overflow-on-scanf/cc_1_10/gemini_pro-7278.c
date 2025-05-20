//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of subnets
#define MAX_SUBNETS 100

// Define the maximum number of hosts per subnet
#define MAX_HOSTS 254

// Define the structure of a subnet
typedef struct {
    unsigned int subnet_address;
    unsigned int subnet_mask;
    unsigned int num_hosts;
} subnet_t;

// Function to calculate the subnet mask
unsigned int get_subnet_mask(unsigned int num_hosts) {
    unsigned int mask = 0;
    while (num_hosts >>= 1) {
        mask++;
    }
    return mask;
}

// Function to calculate the subnet address
unsigned int get_subnet_address(unsigned int ip_address, unsigned int subnet_mask) {
    return ip_address & subnet_mask;
}

// Function to calculate the number of hosts per subnet
unsigned int get_num_hosts(unsigned int subnet_mask) {
    return pow(2, 32 - subnet_mask) - 2;
}

// Function to print the subnet information
void print_subnet(subnet_t subnet) {
    printf("Subnet address: %u.%u.%u.%u\n",
        (subnet.subnet_address >> 24) & 0xFF,
        (subnet.subnet_address >> 16) & 0xFF,
        (subnet.subnet_address >> 8) & 0xFF,
        subnet.subnet_address & 0xFF);
    printf("Subnet mask: %u.%u.%u.%u\n",
        (subnet.subnet_mask >> 24) & 0xFF,
        (subnet.subnet_mask >> 16) & 0xFF,
        (subnet.subnet_mask >> 8) & 0xFF,
        subnet.subnet_mask & 0xFF);
    printf("Number of hosts: %u\n", subnet.num_hosts);
    printf("\n");
}

// Function to calculate the subnets for a given IP address and number of hosts
subnet_t* calculate_subnets(unsigned int ip_address, unsigned int num_hosts) {
    // Allocate memory for the subnets
    subnet_t* subnets = malloc(sizeof(subnet_t) * MAX_SUBNETS);

    // Calculate the subnet mask
    unsigned int subnet_mask = get_subnet_mask(num_hosts);

    // Calculate the subnet address
    unsigned int subnet_address = get_subnet_address(ip_address, subnet_mask);

    // Calculate the number of hosts per subnet
    unsigned int num_subnets = get_num_hosts(subnet_mask);

    // Initialize the subnets
    for (int i = 0; i < num_subnets; i++) {
        subnets[i].subnet_address = subnet_address + (i * num_hosts);
        subnets[i].subnet_mask = subnet_mask;
        subnets[i].num_hosts = num_hosts;
    }

    // Return the subnets
    return subnets;
}

// Function to print the subnets
void print_subnets(subnet_t* subnets, unsigned int num_subnets) {
    for (int i = 0; i < num_subnets; i++) {
        print_subnet(subnets[i]);
    }
}

// Function to free the memory allocated for the subnets
void free_subnets(subnet_t* subnets) {
    free(subnets);
}

int main() {
    // Get the IP address from the user
    printf("Enter the IP address: ");
    unsigned int ip_address;
    scanf("%u", &ip_address);

    // Get the number of hosts per subnet from the user
    printf("Enter the number of hosts per subnet: ");
    unsigned int num_hosts;
    scanf("%u", &num_hosts);

    // Calculate the subnets
    subnet_t* subnets = calculate_subnets(ip_address, num_hosts);

    // Print the subnets
    print_subnets(subnets, num_hosts);

    // Free the memory allocated for the subnets
    free_subnets(subnets);

    return 0;
}