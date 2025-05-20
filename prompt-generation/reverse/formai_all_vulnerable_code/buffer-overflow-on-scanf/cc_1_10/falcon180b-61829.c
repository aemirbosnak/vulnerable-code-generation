//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 10

int num_subnets;
int subnet_sizes[MAX_SUBNETS];
int *subnet_masks;

void generate_subnets(int num_hosts, int num_subnets) {
    int i, j;
    int max_subnet_size = num_hosts / num_subnets;
    int remainder = num_hosts % num_subnets;

    for (i = 0; i < num_subnets; i++) {
        if (i < remainder) {
            subnet_sizes[i] = max_subnet_size + 1;
        } else {
            subnet_sizes[i] = max_subnet_size;
        }
    }

    subnet_masks = (int *) malloc(num_subnets * sizeof(int));

    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < MAX_SUBNET_SIZE; j++) {
            if (i < remainder || j < subnet_sizes[i]) {
                subnet_masks[i] |= (1 << j);
            }
        }
    }
}

void print_subnets(int num_subnets) {
    int i;

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d: ", i + 1);
        printf("Hosts: %d - %d\n", i * subnet_sizes[i], (i + 1) * subnet_sizes[i] - 1);
        printf("Subnet Mask: %d.%d.%d.%d\n", (subnet_masks[i] >> 24) & 0xFF, (subnet_masks[i] >> 16) & 0xFF, (subnet_masks[i] >> 8) & 0xFF, subnet_masks[i] & 0xFF);
        printf("\n");
    }
}

int main() {
    int num_hosts, num_subnets;

    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS || num_subnets <= 0) {
        printf("Error: Invalid number of subnets.\n");
        return 1;
    }

    generate_subnets(num_hosts, num_subnets);
    print_subnets(num_subnets);

    return 0;
}