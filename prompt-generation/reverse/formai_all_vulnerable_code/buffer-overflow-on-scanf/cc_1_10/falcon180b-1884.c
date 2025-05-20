//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBNETS 16
#define MAX_SUBNET_SIZE 16

// Function to calculate the number of subnets
int calculate_number_of_subnets(int num_hosts) {
    int i, j;
    int num_subnets = 1;

    for (i = 0; i < MAX_SUBNETS; i++) {
        for (j = 0; j < MAX_SUBNET_SIZE; j++) {
            if ((num_hosts - 1) % (2 * j + 1) == 0) {
                num_subnets++;
            }
        }
    }

    return num_subnets;
}

// Function to calculate the subnet mask
void calculate_subnet_mask(int num_hosts, int num_subnets) {
    int i, j;
    int mask_size = 0;

    for (i = 0; i < MAX_SUBNETS; i++) {
        for (j = 0; j < MAX_SUBNET_SIZE; j++) {
            if ((num_hosts - 1) % (2 * j + 1) == 0) {
                mask_size = 2 * j + 1;
                break;
            }
        }
    }

    printf("Subnet mask: ");
    for (i = 0; i < mask_size; i++) {
        printf("255");
    }
    printf("\n");
}

// Function to calculate the subnet IDs
void calculate_subnet_ids(int num_hosts, int num_subnets, int mask_size) {
    int i, j;
    int subnet_id = 0;

    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < mask_size; j++) {
            if (((subnet_id >> j) & 1) == 0) {
                printf("Subnet ID %d: ", i + 1);
                printf("%d.%d.%d.%d\n", i >> 8, (i >> 4) & 0xf, (i >> 2) & 0xf, i & 0xf);
                subnet_id++;
                break;
            }
        }
    }
}

int main() {
    int num_hosts;

    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    int num_subnets = calculate_number_of_subnets(num_hosts);
    calculate_subnet_mask(num_hosts, num_subnets);
    calculate_subnet_ids(num_hosts, num_subnets, 8);

    return 0;
}