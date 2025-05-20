//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: Cryptic
// Unique C Subnet Calculator Example Program
// Cryptic Style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Structures
struct Subnet {
    int subnet_addr;
    int subnet_mask;
    int network_id;
    int broadcast_addr;
    int total_hosts;
    int available_hosts;
};

// Functions
int calculate_subnet(int net_addr, int net_mask) {
    return (net_addr & net_mask) << 1;
}

int calculate_network_id(int net_addr, int net_mask) {
    return (net_addr & net_mask) >> 1;
}

int calculate_broadcast_addr(int net_addr, int net_mask) {
    return (net_addr & net_mask) | (~net_mask);
}

int calculate_total_hosts(int subnet_mask) {
    return pow(2, 32 - subnet_mask);
}

int calculate_available_hosts(int total_hosts) {
    return total_hosts - 2;
}

// Main function
int main() {
    // Declare variables
    struct Subnet subnet;
    int net_addr, net_mask;

    // Get input
    printf("Enter the network address: ");
    scanf("%d", &net_addr);
    printf("Enter the subnet mask: ");
    scanf("%d", &net_mask);

    // Calculate subnet address
    subnet.subnet_addr = calculate_subnet(net_addr, net_mask);

    // Calculate network ID
    subnet.network_id = calculate_network_id(net_addr, net_mask);

    // Calculate broadcast address
    subnet.broadcast_addr = calculate_broadcast_addr(net_addr, net_mask);

    // Calculate total hosts
    subnet.total_hosts = calculate_total_hosts(net_mask);

    // Calculate available hosts
    subnet.available_hosts = calculate_available_hosts(subnet.total_hosts);

    // Print output
    printf("Subnet Address: %d\n", subnet.subnet_addr);
    printf("Network ID: %d\n", subnet.network_id);
    printf("Broadcast Address: %d\n", subnet.broadcast_addr);
    printf("Total Hosts: %d\n", subnet.total_hosts);
    printf("Available Hosts: %d\n", subnet.available_hosts);

    return 0;
}