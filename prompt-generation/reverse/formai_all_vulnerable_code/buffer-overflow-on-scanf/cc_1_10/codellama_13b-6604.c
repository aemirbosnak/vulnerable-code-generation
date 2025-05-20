//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: safe
/*
 * Unique C Subnet Calculator Example Program
 *
 * This program calculates the subnet mask of a given IP address and
 * network prefix.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function to calculate subnet mask
unsigned long calculate_subnet_mask(int network_prefix) {
    unsigned long mask = 0;
    int i;

    // Set the most significant bits of the mask to 1
    for (i = 0; i < network_prefix; i++) {
        mask |= 1 << (31 - i);
    }

    // Set the least significant bits of the mask to 0
    for (i = network_prefix; i < 32; i++) {
        mask &= ~(1 << (31 - i));
    }

    return mask;
}

// Function to calculate the number of hosts in a subnet
unsigned long calculate_number_of_hosts(unsigned long subnet_mask) {
    return ~subnet_mask + 1;
}

int main() {
    // Declare variables
    char ip_address[16];
    int network_prefix;
    unsigned long subnet_mask;
    unsigned long number_of_hosts;

    // Get the IP address and network prefix from the user
    printf("Enter the IP address: ");
    fgets(ip_address, sizeof(ip_address), stdin);
    printf("Enter the network prefix: ");
    scanf("%d", &network_prefix);

    // Calculate the subnet mask
    subnet_mask = calculate_subnet_mask(network_prefix);

    // Calculate the number of hosts in the subnet
    number_of_hosts = calculate_number_of_hosts(subnet_mask);

    // Print the results
    printf("Subnet mask: %lu\n", subnet_mask);
    printf("Number of hosts: %lu\n", number_of_hosts);

    return 0;
}