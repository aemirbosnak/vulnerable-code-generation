//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a subnet
typedef struct subnet {
    unsigned long start_ip;
    unsigned long end_ip;
    unsigned int subnet_mask;
    unsigned int prefix_length;
    unsigned int num_hosts;
} subnet_t;

// Function to calculate the subnet mask
unsigned int get_subnet_mask(unsigned int prefix_length) {
    return (0xFFFFFFFF << (32 - prefix_length));
}

// Function to calculate the number of hosts
unsigned int get_num_hosts(unsigned int prefix_length) {
    return (0xFFFFFFFF >> prefix_length);
}

// Function to calculate the start IP address
unsigned long get_start_ip(unsigned long ip_address, unsigned int subnet_mask) {
    return (ip_address & subnet_mask);
}

// Function to calculate the end IP address
unsigned long get_end_ip(unsigned long start_ip, unsigned int num_hosts) {
    return (start_ip + num_hosts - 1);
}

// Function to print the subnet information
void print_subnet(subnet_t subnet) {
    printf("Subnet Information:\n");
    printf("Start IP: %lu\n", subnet.start_ip);
    printf("End IP: %lu\n", subnet.end_ip);
    printf("Subnet Mask: %u\n", subnet.subnet_mask);
    printf("Prefix Length: %u\n", subnet.prefix_length);
    printf("Number of Hosts: %u\n", subnet.num_hosts);
}

// Main function
int main() {
    // Get the IP address and prefix length from the user
    unsigned long ip_address;
    unsigned int prefix_length;
    printf("Enter the IP address: ");
    scanf("%lu", &ip_address);
    printf("Enter the prefix length: ");
    scanf("%u", &prefix_length);

    // Calculate the subnet mask, number of hosts, start IP, and end IP
    unsigned int subnet_mask = get_subnet_mask(prefix_length);
    unsigned int num_hosts = get_num_hosts(prefix_length);
    unsigned long start_ip = get_start_ip(ip_address, subnet_mask);
    unsigned long end_ip = get_end_ip(start_ip, num_hosts);

    // Create a subnet structure and store the information
    subnet_t subnet;
    subnet.start_ip = start_ip;
    subnet.end_ip = end_ip;
    subnet.subnet_mask = subnet_mask;
    subnet.prefix_length = prefix_length;
    subnet.num_hosts = num_hosts;

    // Print the subnet information
    print_subnet(subnet);

    return 0;
}