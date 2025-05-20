//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function to calculate subnet mask
void calculate_subnet_mask(int subnet_bits, int *subnet_mask) {
    // Initialize subnet mask to all 1s
    int i;
    for (i = 0; i < 32; i++) {
        *subnet_mask |= 1 << i;
    }

    // Set subnet bits to 0
    for (i = 0; i < subnet_bits; i++) {
        *subnet_mask &= ~(1 << i);
    }
}

// Function to print subnet information
void print_subnet_info(int ip_address, int subnet_mask) {
    int i;
    for (i = 0; i < 32; i++) {
        if (subnet_mask & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

// Main function
int main() {
    int ip_address, subnet_bits, subnet_mask;

    // Get user input for IP address and subnet bits
    printf("Enter IP address: ");
    scanf("%d", &ip_address);
    printf("Enter subnet bits: ");
    scanf("%d", &subnet_bits);

    // Calculate subnet mask
    calculate_subnet_mask(subnet_bits, &subnet_mask);

    // Print subnet information
    printf("IP address: %d\n", ip_address);
    printf("Subnet mask: ");
    print_subnet_info(ip_address, subnet_mask);

    return 0;
}