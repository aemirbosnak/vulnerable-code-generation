//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: systematic
/*
 * C Subnet Calculator
 *
 * Calculates the number of subnets that can be created in a given network
 * and the number of hosts in each subnet.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORK_BITS 32

// Structure to represent a network address
typedef struct {
    unsigned int network_address;
    unsigned int subnet_mask;
} network_t;

// Function to calculate the number of subnets that can be created in a given network
int calculate_subnets(network_t network) {
    unsigned int network_bits = MAX_NETWORK_BITS;
    unsigned int subnet_mask = network.subnet_mask;
    unsigned int subnet_count = 1;

    while (network_bits > subnet_mask) {
        subnet_count *= 2;
        network_bits--;
    }

    return subnet_count;
}

// Function to calculate the number of hosts in each subnet
int calculate_hosts(network_t network) {
    unsigned int subnet_mask = network.subnet_mask;
    unsigned int host_bits = MAX_NETWORK_BITS - subnet_mask;
    unsigned int host_count = 1;

    while (host_bits > 0) {
        host_count *= 2;
        host_bits--;
    }

    return host_count;
}

int main(int argc, char *argv[]) {
    network_t network;

    // Parse the network address and subnet mask from the command line arguments
    if (argc < 3) {
        printf("Usage: %s <network address> <subnet mask>\n", argv[0]);
        return 1;
    }

    network.network_address = strtol(argv[1], NULL, 10);
    network.subnet_mask = strtol(argv[2], NULL, 10);

    // Calculate the number of subnets and hosts
    int subnet_count = calculate_subnets(network);
    int host_count = calculate_hosts(network);

    // Print the results
    printf("Number of subnets: %d\n", subnet_count);
    printf("Number of hosts per subnet: %d\n", host_count);

    return 0;
}