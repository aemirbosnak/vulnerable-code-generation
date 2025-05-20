//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 100
#define MAX_HOSTS_PER_SUBNET 254

// Function to calculate the number of subnets required
int calculate_subnets(int num_hosts) {
    int subnets = 1;

    // Calculate the number of subnets required
    while ((pow(2, subnets) - 2) < num_hosts) {
        subnets++;
    }

    return subnets;
}

// Function to calculate the number of hosts per subnet
int calculate_hosts_per_subnet(int num_hosts, int num_subnets) {
    int hosts_per_subnet = num_hosts / num_subnets;

    // Calculate the number of hosts per subnet
    if (hosts_per_subnet > MAX_HOSTS_PER_SUBNET) {
        hosts_per_subnet = MAX_HOSTS_PER_SUBNET;
    }

    return hosts_per_subnet;
}

// Function to calculate the subnet mask
void calculate_subnet_mask(int subnet_bits, char *subnet_mask) {
    int i;
    for (i = 0; i < 4; i++) {
        sprintf(&subnet_mask[i*3], "%d", (255 << (8 - subnet_bits)) & 255);
    }
    subnet_mask[9] = '\0';
}

int main() {
    int num_hosts, num_subnets, hosts_per_subnet, i;
    char subnet_mask[16];

    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    num_subnets = calculate_subnets(num_hosts);
    hosts_per_subnet = calculate_hosts_per_subnet(num_hosts, num_subnets);

    printf("\nNumber of subnets: %d\n", num_subnets);
    printf("Number of hosts per subnet: %d\n", hosts_per_subnet);

    calculate_subnet_mask(8 - log2(hosts_per_subnet), subnet_mask);

    printf("\nSubnet mask: %s\n", subnet_mask);

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d: ", i+1);
        printf("%s.%d.%d.%d - %s.%d.%d.%d\n",
            subnet_mask[0], subnet_mask[1], subnet_mask[2], (i * hosts_per_subnet) + 1,
            subnet_mask[0], subnet_mask[1], subnet_mask[2], (i * hosts_per_subnet) + hosts_per_subnet);
    }

    return 0;
}