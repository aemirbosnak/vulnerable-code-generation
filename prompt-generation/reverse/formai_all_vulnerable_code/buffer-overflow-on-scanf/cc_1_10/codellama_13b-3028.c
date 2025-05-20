//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: lively
// C Subnet Calculator

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the subnet mask
void calculate_subnet_mask(int subnet_mask_length) {
    char subnet_mask[4];
    int subnet_mask_int;

    // Convert the subnet mask length to an integer
    subnet_mask_int = 0xFFFFFFFF << (32 - subnet_mask_length);

    // Convert the integer to a string
    sprintf(subnet_mask, "%d.%d.%d.%d", (subnet_mask_int >> 24) & 0xFF, (subnet_mask_int >> 16) & 0xFF, (subnet_mask_int >> 8) & 0xFF, subnet_mask_int & 0xFF);

    // Print the subnet mask
    printf("Subnet mask: %s\n", subnet_mask);
}

// Function to calculate the number of subnets
void calculate_num_subnets(int subnet_mask_length) {
    int num_subnets;

    // Calculate the number of subnets
    num_subnets = 2 ^ (32 - subnet_mask_length);

    // Print the number of subnets
    printf("Number of subnets: %d\n", num_subnets);
}

// Function to calculate the number of hosts
void calculate_num_hosts(int subnet_mask_length) {
    int num_hosts;

    // Calculate the number of hosts
    num_hosts = 2 ^ (32 - subnet_mask_length) - 2;

    // Print the number of hosts
    printf("Number of hosts: %d\n", num_hosts);
}

// Main function
int main() {
    int subnet_mask_length;

    // Get the subnet mask length
    printf("Enter the subnet mask length: ");
    scanf("%d", &subnet_mask_length);

    // Calculate the subnet mask
    calculate_subnet_mask(subnet_mask_length);

    // Calculate the number of subnets
    calculate_num_subnets(subnet_mask_length);

    // Calculate the number of hosts
    calculate_num_hosts(subnet_mask_length);

    return 0;
}