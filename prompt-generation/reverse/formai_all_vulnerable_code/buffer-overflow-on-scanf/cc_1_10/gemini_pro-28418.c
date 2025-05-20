//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold subnet information
typedef struct Subnet {
    unsigned int address;
    unsigned int netmask;
    unsigned int broadcast;
    unsigned int num_hosts;
} Subnet;

// Function to calculate subnet information
Subnet calculate_subnet(unsigned int address, unsigned int netmask) {
    Subnet subnet;

    // Calculate broadcast address
    subnet.broadcast = address | ~netmask;

    // Calculate network address
    subnet.address = address & netmask;

    // Calculate number of hosts
    subnet.num_hosts = ~netmask & 0xFFFFFFFF;

    return subnet;
}

// Function to print subnet information
void print_subnet(Subnet subnet) {
    printf("Subnet Information:\n");
    printf("Address: %u\n", subnet.address);
    printf("Netmask: %u\n", subnet.netmask);
    printf("Broadcast: %u\n", subnet.broadcast);
    printf("Number of Hosts: %u\n", subnet.num_hosts);
}

// Main function
int main() {
    // Get user input
    unsigned int address, netmask;
    printf("Enter the IP address: ");
    scanf("%u", &address);
    printf("Enter the netmask: ");
    scanf("%u", &netmask);

    // Calculate subnet information
    Subnet subnet = calculate_subnet(address, netmask);

    // Print subnet information
    print_subnet(subnet);

    return 0;
}