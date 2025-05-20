//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Declare variables for subnet calculation
    unsigned int ip_address, subnet_mask, prefix_length, num_hosts, num_subnets;

    // Declare variables for romantic calculations
    unsigned int heart_size, love_factor, compatibility_score;

    // Gather user input for IP address and subnet mask
    printf("Your IP address: ");
    scanf("%u", &ip_address);
    printf("Your subnet mask: ");
    scanf("%u", &subnet_mask);

    // Calculate prefix length, number of hosts, and number of subnets
    prefix_length = 0;
    for (unsigned int i = 0; i < 32; i++) {
        if ((subnet_mask >> i) & 1) {
            prefix_length++;
        }
    }
    num_hosts = pow(2, 32 - prefix_length) - 2;
    num_subnets = pow(2, prefix_length);

    // Calculate heart size based on IP address
    heart_size = (ip_address >> 16) % 256;

    // Calculate love factor based on subnet mask
    love_factor = (subnet_mask >> 8) % 256;

    // Calculate compatibility score based on prefix length
    compatibility_score = prefix_length * 5;

    // Print the subnet calculation results
    printf("\nSubnet calculation:\n");
    printf("Prefix length: %u\n", prefix_length);
    printf("Number of hosts: %u\n", num_hosts);
    printf("Number of subnets: %u\n", num_subnets);

    // Print the romantic calculation results
    printf("\nRomantic calculation:\n");
    printf("Heart size: %u\n", heart_size);
    printf("Love factor: %u\n", love_factor);
    printf("Compatibility score: %u\n", compatibility_score);

    // Generate a romantic message based on the calculation results
    printf("\nYour love is as wide as the subnet mask: %u.\n", subnet_mask);
    printf("Your heart is as big as the IP address: %u.\n", ip_address);
    printf("Your compatibility is as strong as the prefix length: %u.\n", prefix_length);

    return 0;
}