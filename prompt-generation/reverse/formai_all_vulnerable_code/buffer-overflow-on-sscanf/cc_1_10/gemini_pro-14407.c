//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 16

typedef struct {
    unsigned int address;
    unsigned int subnet_mask;
    unsigned int num_hosts;
} subnet_t;

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments was provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <network address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the network address
    unsigned int network_address;
    if (sscanf(argv[1], "%u.%u.%u.%u", &network_address, &network_address, &network_address, &network_address) != 4) {
        fprintf(stderr, "Invalid network address: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Create an array of subnets
    subnet_t subnets[MAX_SUBNETS];

    // Initialize the first subnet
    subnets[0].address = network_address;
    subnets[0].subnet_mask = 0xFFFFFFFF;
    subnets[0].num_hosts = 0;

    // Calculate the subnets
    for (int i = 1; i < MAX_SUBNETS; i++) {
        // Divide the subnet mask by 2
        subnets[i].subnet_mask = subnets[i - 1].subnet_mask >> 1;

        // Set the address of the subnet
        subnets[i].address = subnets[i - 1].address & subnets[i].subnet_mask;

        // Calculate the number of hosts in the subnet
        subnets[i].num_hosts = pow(2, 32 - count_bits(subnets[i].subnet_mask)) - 2;
    }

    // Print the subnets
    for (int i = 0; i < MAX_SUBNETS; i++) {
        printf("Subnet %d:\n", i + 1);
        printf("    Address: %u.%u.%u.%u\n", subnets[i].address >> 24, (subnets[i].address >> 16) & 0xFF, (subnets[i].address >> 8) & 0xFF, subnets[i].address & 0xFF);
        printf("    Subnet mask: %u.%u.%u.%u\n", subnets[i].subnet_mask >> 24, (subnets[i].subnet_mask >> 16) & 0xFF, (subnets[i].subnet_mask >> 8) & 0xFF, subnets[i].subnet_mask & 0xFF);
        printf("    Number of hosts: %u\n\n", subnets[i].num_hosts);
    }

    return EXIT_SUCCESS;
}

int count_bits(unsigned int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}