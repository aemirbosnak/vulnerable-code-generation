//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: accurate
/*
 * Unique C Subnet Calculator
 *
 * Calculates the number of subnets and hosts in a given subnet
 */

#include <stdio.h>

// Function to calculate the number of subnets and hosts
int calculate_subnets(int subnet_mask) {
    int subnet_bits = 0;
    int host_bits = 0;
    int subnet_count = 0;
    int host_count = 0;

    // Calculate the number of subnet bits
    while (subnet_mask > 0) {
        if (subnet_mask & 1) {
            subnet_bits++;
        }
        subnet_mask >>= 1;
    }

    // Calculate the number of host bits
    host_bits = 32 - subnet_bits;

    // Calculate the number of subnets
    subnet_count = 1 << subnet_bits;

    // Calculate the number of hosts per subnet
    host_count = 1 << host_bits;

    return subnet_count * host_count;
}

int main() {
    int subnet_mask;

    // Get the subnet mask from the user
    printf("Enter the subnet mask: ");
    scanf("%d", &subnet_mask);

    // Calculate the number of subnets and hosts
    int subnet_count = calculate_subnets(subnet_mask);

    // Print the results
    printf("The number of subnets is %d\n", subnet_count);

    return 0;
}