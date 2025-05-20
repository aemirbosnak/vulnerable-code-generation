//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

// Function to calculate the subnet mask
void calculate_subnet_mask(int subnet_bits, int* subnet_mask) {
    int i, j;
    for (i = 0, j = 0x80000000; i < subnet_bits; i++, j >>= 1) {
        *subnet_mask |= j;
    }
}

// Function to calculate the number of hosts in a subnet
int calculate_hosts(int subnet_bits) {
    return (int) pow(2, subnet_bits) - 2;
}

// Function to print the subnet information
void print_subnet_info(int subnet_num, int subnet_mask, int hosts) {
    printf("Subnet %d:\n", subnet_num);
    printf("Subnet Mask: ");
    for (int i = 0; i < 4; i++) {
        printf("%d.%d.%d.%d ", (subnet_mask >> (i * 8)) & 0xFF);
    }
    printf("\nNumber of Hosts: %d\n", hosts);
    printf("\n");
}

int main() {
    int num_subnets, subnet_size;
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);
    printf("Enter the subnet size (in bits): ");
    scanf("%d", &subnet_size);

    if (num_subnets > MAX_SUBNETS || subnet_size > 30 || subnet_size < 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int subnet_mask[num_subnets];
    for (int i = 0; i < num_subnets; i++) {
        calculate_subnet_mask(subnet_size, &subnet_mask[i]);
        int hosts = calculate_hosts(subnet_size);
        print_subnet_info(i + 1, subnet_mask[i], hosts);
    }

    return 0;
}