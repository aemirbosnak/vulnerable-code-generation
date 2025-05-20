//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of bits in an IPv4 address
#define MAX_BITS 32

// Define the structure of an IPv4 subnet
typedef struct {
    unsigned int address;    // The IP address of the subnet
    unsigned int netmask;    // The netmask of the subnet
    unsigned int prefix;    // The prefix length of the subnet
    unsigned int num_hosts;  // The number of hosts in the subnet
    unsigned int broadcast;  // The broadcast address of the subnet
} subnet_t;

// Function to calculate the subnet mask for a given prefix length
unsigned int calculate_netmask(unsigned int prefix) {
    return (0xFFFFFFFF << (MAX_BITS - prefix));
}

// Function to calculate the number of hosts in a given subnet
unsigned int calculate_num_hosts(unsigned int prefix) {
    return (0xFFFFFFFF >> prefix);
}

// Function to calculate the broadcast address for a given subnet
unsigned int calculate_broadcast(unsigned int address, unsigned int netmask) {
    return (address | ~netmask);
}

// Function to print the details of a given subnet
void print_subnet(subnet_t subnet) {
    printf("Subnet Address: %u.%u.%u.%u\n",
        (subnet.address >> 24) & 0xFF,
        (subnet.address >> 16) & 0xFF,
        (subnet.address >> 8) & 0xFF,
        subnet.address & 0xFF);
    printf("Netmask: %u.%u.%u.%u\n",
        (subnet.netmask >> 24) & 0xFF,
        (subnet.netmask >> 16) & 0xFF,
        (subnet.netmask >> 8) & 0xFF,
        subnet.netmask & 0xFF);
    printf("Prefix Length: %u\n", subnet.prefix);
    printf("Number of Hosts: %u\n", subnet.num_hosts);
    printf("Broadcast Address: %u.%u.%u.%u\n",
        (subnet.broadcast >> 24) & 0xFF,
        (subnet.broadcast >> 16) & 0xFF,
        (subnet.broadcast >> 8) & 0xFF,
        subnet.broadcast & 0xFF);
}

// Main function
int main() {
    // Define the input variables
    unsigned int address;
    unsigned int prefix;

    // Get the input from the user
    printf("Enter the IP address of the subnet: ");
    scanf("%u", &address);
    printf("Enter the prefix length of the subnet: ");
    scanf("%u", &prefix);

    // Calculate the subnet mask, number of hosts, and broadcast address
    subnet_t subnet;
    subnet.address = address;
    subnet.netmask = calculate_netmask(prefix);
    subnet.prefix = prefix;
    subnet.num_hosts = calculate_num_hosts(prefix);
    subnet.broadcast = calculate_broadcast(address, subnet.netmask);

    // Print the details of the subnet
    print_subnet(subnet);

    return 0;
}