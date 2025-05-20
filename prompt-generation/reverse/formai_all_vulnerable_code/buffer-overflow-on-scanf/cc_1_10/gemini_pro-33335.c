//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of bits in an IPv4 address
#define IPV4_BITS 32

// Define the maximum number of subnets
#define MAX_SUBNETS 256

// Define the structure of a subnet
typedef struct {
    unsigned int address;
    unsigned int netmask;
    unsigned int broadcast;
    unsigned int first_host;
    unsigned int last_host;
    unsigned int num_hosts;
} subnet_t;

// Function to calculate the subnet mask for a given number of subnets
unsigned int get_subnet_mask(unsigned int num_subnets) {
    unsigned int subnet_mask = 0;
    for (unsigned int i = 0; i < IPV4_BITS; i++) {
        if (num_subnets & (1 << i)) {
            subnet_mask |= (1 << i);
        }
    }
    return subnet_mask;
}

// Function to calculate the broadcast address for a given subnet
unsigned int get_broadcast_address(subnet_t subnet) {
    return (subnet.address | ~subnet.netmask);
}

// Function to calculate the first host address for a given subnet
unsigned int get_first_host_address(subnet_t subnet) {
    return (subnet.address & subnet.netmask);
}

// Function to calculate the last host address for a given subnet
unsigned int get_last_host_address(subnet_t subnet) {
    return (subnet.broadcast & subnet.netmask);
}

// Function to calculate the number of hosts in a given subnet
unsigned int get_num_hosts(subnet_t subnet) {
    return (~subnet.netmask & 0xFFFFFFFF);
}

// Function to print the subnet information
void print_subnet(subnet_t subnet) {
    printf("Subnet address: %u.%u.%u.%u\n", (subnet.address >> 24) & 0xFF, (subnet.address >> 16) & 0xFF, (subnet.address >> 8) & 0xFF, subnet.address & 0xFF);
    printf("Subnet mask: %u.%u.%u.%u\n", (subnet.netmask >> 24) & 0xFF, (subnet.netmask >> 16) & 0xFF, (subnet.netmask >> 8) & 0xFF, subnet.netmask & 0xFF);
    printf("Broadcast address: %u.%u.%u.%u\n", (subnet.broadcast >> 24) & 0xFF, (subnet.broadcast >> 16) & 0xFF, (subnet.broadcast >> 8) & 0xFF, subnet.broadcast & 0xFF);
    printf("First host address: %u.%u.%u.%u\n", (subnet.first_host >> 24) & 0xFF, (subnet.first_host >> 16) & 0xFF, (subnet.first_host >> 8) & 0xFF, subnet.first_host & 0xFF);
    printf("Last host address: %u.%u.%u.%u\n", (subnet.last_host >> 24) & 0xFF, (subnet.last_host >> 16) & 0xFF, (subnet.last_host >> 8) & 0xFF, subnet.last_host & 0xFF);
    printf("Number of hosts: %u\n", subnet.num_hosts);
}

// Function to calculate all subnets for a given IP address and number of subnets
void calculate_subnets(unsigned int ip_address, unsigned int num_subnets) {
    // Get the subnet mask
    unsigned int subnet_mask = get_subnet_mask(num_subnets);

    // Create an array of subnets
    subnet_t subnets[MAX_SUBNETS];

    // Calculate the subnets
    for (unsigned int i = 0; i < num_subnets; i++) {
        subnets[i].address = ip_address + (i * subnet_mask);
        subnets[i].netmask = subnet_mask;
        subnets[i].broadcast = get_broadcast_address(subnets[i]);
        subnets[i].first_host = get_first_host_address(subnets[i]);
        subnets[i].last_host = get_last_host_address(subnets[i]);
        subnets[i].num_hosts = get_num_hosts(subnets[i]);
    }

    // Print the subnets
    for (unsigned int i = 0; i < num_subnets; i++) {
        print_subnet(subnets[i]);
    }
}

int main() {
    // Get the IP address
    unsigned int ip_address;
    printf("Enter the IP address: ");
    scanf("%u", &ip_address);

    // Get the number of subnets
    unsigned int num_subnets;
    printf("Enter the number of subnets: ");
    scanf("%u", &num_subnets);

    // Calculate the subnets
    calculate_subnets(ip_address, num_subnets);

    return 0;
}