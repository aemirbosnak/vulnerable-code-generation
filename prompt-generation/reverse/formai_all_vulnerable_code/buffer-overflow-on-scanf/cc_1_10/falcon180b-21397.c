//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

// Function to calculate the subnet mask
unsigned int calculate_subnet_mask(unsigned int ip_address, unsigned int num_subnets) {
    int i, j;
    unsigned int subnet_mask = 0;

    for (i = 0; i < 32; i++) {
        if ((ip_address & (1 << i)) == 0) {
            for (j = 0; j < num_subnets; j++) {
                subnet_mask |= (1 << i);
            }
        }
    }

    return subnet_mask;
}

// Function to calculate the number of hosts per subnet
int calculate_hosts_per_subnet(unsigned int subnet_mask) {
    int hosts_per_subnet = 0;

    while (subnet_mask!= 0) {
        if (subnet_mask & 1) {
            hosts_per_subnet++;
        }
        subnet_mask >>= 1;
    }

    return hosts_per_subnet;
}

// Function to calculate the number of subnets
int calculate_number_of_subnets(unsigned int num_hosts, int hosts_per_subnet) {
    int num_subnets = 0;

    while (num_hosts > hosts_per_subnet) {
        num_hosts -= hosts_per_subnet;
        num_subnets++;
    }

    return num_subnets;
}

int main() {
    int num_hosts, num_subnets;
    unsigned int ip_address, subnet_mask;

    printf("Enter the IP address: ");
    scanf("%u", &ip_address);

    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    num_subnets = calculate_number_of_subnets(num_hosts, 1);

    printf("Enter the number of subnets (1-%d): ", MAX_SUBNETS);
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS) {
        printf("Error: Maximum number of subnets is %d\n", MAX_SUBNETS);
        return 1;
    }

    subnet_mask = calculate_subnet_mask(ip_address, num_subnets);

    printf("Subnet mask: %u\n", subnet_mask);
    printf("Number of hosts per subnet: %d\n", calculate_hosts_per_subnet(subnet_mask));

    return 0;
}