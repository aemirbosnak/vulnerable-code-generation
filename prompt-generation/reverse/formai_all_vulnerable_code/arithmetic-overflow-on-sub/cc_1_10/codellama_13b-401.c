//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: multivariable
/*
 * Subnet Calculator Example Program
 *
 * This program calculates the subnet mask and the number of hosts
 * in a given subnet.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the subnet mask
int calculate_subnet_mask(int subnet_address, int subnet_mask) {
    // Calculate the number of bits in the subnet mask
    int num_bits = 0;
    while (subnet_mask > 0) {
        num_bits++;
        subnet_mask >>= 1;
    }

    // Calculate the subnet mask
    int subnet_mask_value = (1 << num_bits) - 1;

    // Return the subnet mask
    return subnet_mask_value;
}

// Function to calculate the number of hosts
int calculate_num_hosts(int subnet_mask, int num_hosts) {
    // Calculate the number of hosts
    int num_hosts_value = (1 << num_hosts) - 1;

    // Return the number of hosts
    return num_hosts_value;
}

int main() {
    // Declare variables
    int subnet_address, subnet_mask, num_hosts;

    // Get user input
    printf("Enter the subnet address: ");
    scanf("%d", &subnet_address);
    printf("Enter the subnet mask: ");
    scanf("%d", &subnet_mask);
    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    // Calculate the subnet mask
    int subnet_mask_value = calculate_subnet_mask(subnet_address, subnet_mask);

    // Calculate the number of hosts
    int num_hosts_value = calculate_num_hosts(subnet_mask_value, num_hosts);

    // Print the results
    printf("Subnet mask: %d\n", subnet_mask_value);
    printf("Number of hosts: %d\n", num_hosts_value);

    return 0;
}