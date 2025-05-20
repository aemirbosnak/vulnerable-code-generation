//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of subnets
#define MAX_SUBNETS 64

// Define the maximum number of hosts per subnet
#define MAX_HOSTS_PER_SUBNET 254

// Define the structure of a subnet
typedef struct subnet {
    unsigned long start_ip;
    unsigned long end_ip;
    unsigned long broadcast_ip;
    unsigned int subnet_mask;
    unsigned int num_hosts;
} subnet_t;

// Function to calculate the subnet mask
unsigned int calculate_subnet_mask(unsigned int num_subnets) {
    unsigned int subnet_mask = 32;
    while (num_subnets > 1) {
        num_subnets >>= 1;
        subnet_mask--;
    }
    return subnet_mask;
}

// Function to calculate the number of hosts per subnet
unsigned int calculate_num_hosts(unsigned int subnet_mask) {
    unsigned int num_hosts = (unsigned int) pow(2, (32 - subnet_mask)) - 2;
    return num_hosts;
}

// Function to calculate the start IP address of a subnet
unsigned long calculate_start_ip(unsigned long ip_address, unsigned int subnet_mask) {
    unsigned long start_ip = ip_address & (unsigned long) pow(2, subnet_mask) - 1;
    return start_ip;
}

// Function to calculate the end IP address of a subnet
unsigned long calculate_end_ip(unsigned long ip_address, unsigned int subnet_mask) {
    unsigned long end_ip = ip_address | (unsigned long) pow(2, (32 - subnet_mask)) - 1;
    return end_ip;
}

// Function to calculate the broadcast IP address of a subnet
unsigned long calculate_broadcast_ip(unsigned long ip_address, unsigned int subnet_mask) {
    unsigned long broadcast_ip = ip_address | (unsigned long) pow(2, (32 - subnet_mask)) - 1;
    return broadcast_ip;
}

// Function to print the subnet information
void print_subnet(subnet_t subnet) {
    printf("Subnet %d:\n", subnet.subnet_mask);
    printf("Start IP: %lu.%lu.%lu.%lu\n", (subnet.start_ip >> 24) & 0xff, (subnet.start_ip >> 16) & 0xff, (subnet.start_ip >> 8) & 0xff, subnet.start_ip & 0xff);
    printf("End IP: %lu.%lu.%lu.%lu\n", (subnet.end_ip >> 24) & 0xff, (subnet.end_ip >> 16) & 0xff, (subnet.end_ip >> 8) & 0xff, subnet.end_ip & 0xff);
    printf("Broadcast IP: %lu.%lu.%lu.%lu\n", (subnet.broadcast_ip >> 24) & 0xff, (subnet.broadcast_ip >> 16) & 0xff, (subnet.broadcast_ip >> 8) & 0xff, subnet.broadcast_ip & 0xff);
    printf("Number of hosts: %u\n", subnet.num_hosts);
}

// Function to calculate the subnets
void calculate_subnets(unsigned long ip_address, unsigned int num_subnets) {
    // Calculate the subnet mask
    unsigned int subnet_mask = calculate_subnet_mask(num_subnets);

    // Calculate the number of hosts per subnet
    unsigned int num_hosts = calculate_num_hosts(subnet_mask);

    // Create an array of subnets
    subnet_t subnets[MAX_SUBNETS];

    // Calculate the subnets
    for (unsigned int i = 0; i < num_subnets; i++) {
        subnets[i].subnet_mask = subnet_mask;
        subnets[i].num_hosts = num_hosts;

        // Calculate the start IP address of the subnet
        subnets[i].start_ip = calculate_start_ip(ip_address, subnet_mask);

        // Calculate the end IP address of the subnet
        subnets[i].end_ip = calculate_end_ip(ip_address, subnet_mask);

        // Calculate the broadcast IP address of the subnet
        subnets[i].broadcast_ip = calculate_broadcast_ip(ip_address, subnet_mask);

        // Increment the IP address
        ip_address += num_hosts + 1;
    }

    // Print the subnets
    for (unsigned int i = 0; i < num_subnets; i++) {
        print_subnet(subnets[i]);
    }
}

int main() {
    // Get the IP address
    unsigned long ip_address;
    printf("Enter the IP address: ");
    scanf("%lu", &ip_address);

    // Get the number of subnets
    unsigned int num_subnets;
    printf("Enter the number of subnets: ");
    scanf("%u", &num_subnets);

    // Calculate the subnets
    calculate_subnets(ip_address, num_subnets);

    return 0;
}