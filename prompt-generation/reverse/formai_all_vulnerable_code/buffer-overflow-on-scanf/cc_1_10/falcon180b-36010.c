//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the number of subnets
int calculate_subnets(int num_hosts, int num_subnet_bits) {
    int num_subnets = 1;
    for (int i = num_subnet_bits; i < 32; i++) {
        num_subnets *= 2;
    }
    return num_subnets;
}

// Function to calculate the number of hosts per subnet
int calculate_hosts_per_subnet(int num_hosts, int num_subnet_bits) {
    int num_hosts_per_subnet = num_hosts / calculate_subnets(num_hosts, num_subnet_bits);
    return num_hosts_per_subnet;
}

// Function to calculate the subnet mask
void calculate_subnet_mask(int num_subnet_bits, char *subnet_mask) {
    int i;
    for (i = 0; i < num_subnet_bits; i++) {
        subnet_mask[i] = '1';
    }
    for (i = num_subnet_bits; i < 32; i++) {
        subnet_mask[i] = '0';
    }
    subnet_mask[32] = '\0';
}

// Function to print the subnet information
void print_subnet_info(int num_hosts, int num_subnet_bits, int num_subnets, int num_hosts_per_subnet, char *subnet_mask) {
    printf("Number of hosts: %d\n", num_hosts);
    printf("Number of subnet bits: %d\n", num_subnet_bits);
    printf("Number of subnets: %d\n", num_subnets);
    printf("Number of hosts per subnet: %d\n", num_hosts_per_subnet);
    printf("Subnet mask: %s\n", subnet_mask);
}

// Main function
int main() {
    int num_hosts, num_subnet_bits;
    char subnet_mask[33];

    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    printf("Enter the number of subnet bits: ");
    scanf("%d", &num_subnet_bits);

    calculate_subnet_mask(num_subnet_bits, subnet_mask);
    int num_subnets = calculate_subnets(num_hosts, num_subnet_bits);
    int num_hosts_per_subnet = calculate_hosts_per_subnet(num_hosts, num_subnet_bits);

    print_subnet_info(num_hosts, num_subnet_bits, num_subnets, num_hosts_per_subnet, subnet_mask);

    return 0;
}