//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of bits in an IPv4 address
#define MAX_BITS 32

// Define the structure of a subnet
typedef struct {
    unsigned int address;        // The IP address of the subnet
    unsigned int netmask;        // The netmask of the subnet
    unsigned int num_hosts;     // The number of hosts in the subnet
    unsigned int num_subnets;    // The number of subnets that can be created from the subnet
} subnet_t;

// Function to calculate the netmask of a subnet
unsigned int calculate_netmask(unsigned int num_hosts) {
    unsigned int netmask = 0;
    for (int i = 0; i < num_hosts; i++) {
        netmask |= (1 << (MAX_BITS - i - 1));
    }
    return netmask;
}

// Function to calculate the number of hosts in a subnet
unsigned int calculate_num_hosts(unsigned int netmask) {
    unsigned int num_hosts = 0;
    for (int i = 0; i < MAX_BITS; i++) {
        if ((netmask & (1 << (MAX_BITS - i - 1))) == 0) {
            num_hosts += (1 << i);
        }
    }
    return num_hosts - 2;
}

// Function to calculate the number of subnets that can be created from a subnet
unsigned int calculate_num_subnets(unsigned int netmask) {
    unsigned int num_subnets = 0;
    for (int i = 0; i < MAX_BITS; i++) {
        if ((netmask & (1 << (MAX_BITS - i - 1))) == 0) {
            num_subnets += (1 << i);
        }
    }
    return num_subnets;
}

// Function to print the subnet information
void print_subnet(subnet_t subnet) {
    printf("Subnet information:\n");
    printf("Address: %u\n", subnet.address);
    printf("Netmask: %u\n", subnet.netmask);
    printf("Number of hosts: %u\n", subnet.num_hosts);
    printf("Number of subnets: %u\n", subnet.num_subnets);
}

// Main function
int main() {
    // Get the IP address of the subnet from the user
    unsigned int address;
    printf("Enter the IP address of the subnet: ");
    scanf("%u", &address);

    // Get the number of hosts in the subnet from the user
    unsigned int num_hosts;
    printf("Enter the number of hosts in the subnet: ");
    scanf("%u", &num_hosts);

    // Calculate the netmask of the subnet
    unsigned int netmask = calculate_netmask(num_hosts);

    // Calculate the number of hosts in the subnet
    unsigned int num_hosts_actual = calculate_num_hosts(netmask);

    // Calculate the number of subnets that can be created from the subnet
    unsigned int num_subnets = calculate_num_subnets(netmask);

    // Create a subnet structure
    subnet_t subnet;
    subnet.address = address;
    subnet.netmask = netmask;
    subnet.num_hosts = num_hosts_actual;
    subnet.num_subnets = num_subnets;

    // Print the subnet information
    print_subnet(subnet);

    return 0;
}