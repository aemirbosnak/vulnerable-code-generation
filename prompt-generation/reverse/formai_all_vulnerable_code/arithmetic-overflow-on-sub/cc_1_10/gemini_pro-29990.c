//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subnets
#define MAX_SUBNETS 256

// Define the maximum number of hosts per subnet
#define MAX_HOSTS_PER_SUBNET 254

// Define the structure of a subnet
typedef struct {
    unsigned int subnet_address;
    unsigned int subnet_mask;
    unsigned int num_hosts;
    char *subnet_name;
} subnet_t;

// Define the function to calculate the subnet mask
unsigned int calculate_subnet_mask(unsigned int cidr) {
    unsigned int subnet_mask = 0xFFFFFFFF;

    // Shift the subnet mask to the left by the number of bits in the CIDR
    subnet_mask <<= (32 - cidr);

    // Return the subnet mask
    return subnet_mask;
}

// Define the function to calculate the number of hosts per subnet
unsigned int calculate_num_hosts(unsigned int cidr) {
    unsigned int num_hosts = (1 << (32 - cidr)) - 2;

    // Return the number of hosts
    return num_hosts;
}

// Define the function to create a subnet
subnet_t *create_subnet(unsigned int subnet_address, unsigned int subnet_mask, unsigned int num_hosts, char *subnet_name) {
    // Allocate memory for the subnet
    subnet_t *subnet = malloc(sizeof(subnet_t));

    // Set the subnet's properties
    subnet->subnet_address = subnet_address;
    subnet->subnet_mask = subnet_mask;
    subnet->num_hosts = num_hosts;
    subnet->subnet_name = subnet_name;

    // Return the subnet
    return subnet;
}

// Define the function to print the subnet information
void print_subnet(subnet_t *subnet) {
    // Print the subnet's properties
    printf("Subnet address: %u.%u.%u.%u\n", (subnet->subnet_address >> 24) & 0xFF, (subnet->subnet_address >> 16) & 0xFF, (subnet->subnet_address >> 8) & 0xFF, subnet->subnet_address & 0xFF);
    printf("Subnet mask: %u.%u.%u.%u\n", (subnet->subnet_mask >> 24) & 0xFF, (subnet->subnet_mask >> 16) & 0xFF, (subnet->subnet_mask >> 8) & 0xFF, subnet->subnet_mask & 0xFF);
    printf("Number of hosts: %u\n", subnet->num_hosts);
    printf("Subnet name: %s\n", subnet->subnet_name);
}

// Define the function to free the subnet
void free_subnet(subnet_t *subnet) {
    // Free the subnet's memory
    free(subnet);
}

// Define the main function
int main() {
    // Get the subnet address
    unsigned int subnet_address;
    printf("Enter the subnet address: ");
    scanf("%u", &subnet_address);

    // Get the CIDR
    unsigned int cidr;
    printf("Enter the CIDR: ");
    scanf("%u", &cidr);

    // Calculate the subnet mask
    unsigned int subnet_mask = calculate_subnet_mask(cidr);

    // Calculate the number of hosts per subnet
    unsigned int num_hosts = calculate_num_hosts(cidr);

    // Create the subnet
    subnet_t *subnet = create_subnet(subnet_address, subnet_mask, num_hosts, "Default");

    // Print the subnet information
    print_subnet(subnet);

    // Free the subnet
    free_subnet(subnet);

    return 0;
}