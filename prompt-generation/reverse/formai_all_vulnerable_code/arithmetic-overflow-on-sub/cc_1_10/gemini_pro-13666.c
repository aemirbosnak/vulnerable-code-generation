//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of bits in an IP address
#define MAX_BITS 32

// Define the maximum number of subnets
#define MAX_SUBNETS 256

// Define the maximum number of hosts per subnet
#define MAX_HOSTS 65536

// Define the structure of a subnet
typedef struct {
    unsigned int address;
    unsigned int mask;
    unsigned int num_hosts;
} subnet_t;

// Define the function to calculate the subnets
void calculate_subnets(unsigned int address, unsigned int mask, unsigned int *num_subnets, subnet_t *subnets) {
    // Check if the address and mask are valid
    if (address < 0 || address > 0xFFFFFFFF) {
        printf("Invalid address\n");
        return;
    }
    if (mask < 0 || mask > 0xFFFFFFFF) {
        printf("Invalid mask\n");
        return;
    }

    // Calculate the number of subnets
    *num_subnets = (1 << (MAX_BITS - mask));

    // Calculate the subnets
    for (unsigned int i = 0; i < *num_subnets; i++) {
        subnets[i].address = address & mask;
        subnets[i].mask = mask;
        subnets[i].num_hosts = (1 << (MAX_BITS - mask)) - 2;
    }
}

// Define the function to print the subnets
void print_subnets(unsigned int num_subnets, subnet_t *subnets) {
    // Print the subnets
    for (unsigned int i = 0; i < num_subnets; i++) {
        printf("Subnet %u:\n", i + 1);
        printf("    Address: %u.%u.%u.%u\n",
            (subnets[i].address >> 24) & 0xFF,
            (subnets[i].address >> 16) & 0xFF,
            (subnets[i].address >> 8) & 0xFF,
            subnets[i].address & 0xFF);
        printf("    Mask: %u.%u.%u.%u\n",
            (subnets[i].mask >> 24) & 0xFF,
            (subnets[i].mask >> 16) & 0xFF,
            (subnets[i].mask >> 8) & 0xFF,
            subnets[i].mask & 0xFF);
        printf("    Number of hosts: %u\n", subnets[i].num_hosts);
    }
}

// Define the main function
int main() {
    // Declare the variables
    unsigned int address, mask, num_subnets;
    subnet_t subnets[MAX_SUBNETS];

    // Prompt the user for the address and mask
    printf("Enter the IP address: ");
    scanf("%u", &address);
    printf("Enter the subnet mask: ");
    scanf("%u", &mask);

    // Calculate the subnets
    calculate_subnets(address, mask, &num_subnets, subnets);

    // Print the subnets
    print_subnets(num_subnets, subnets);

    return 0;
}