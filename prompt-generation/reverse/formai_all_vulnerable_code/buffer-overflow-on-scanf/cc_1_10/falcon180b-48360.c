//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 4

typedef struct {
    char subnet[MAX_SUBNET_SIZE];
    char subnet_mask[MAX_SUBNET_MASK_SIZE];
    int num_hosts;
} subnet_t;

void subnet_calculator(int num_subnets, subnet_t subnets[]) {
    int i, j;
    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < MAX_SUBNET_SIZE; j++) {
            subnets[i].subnet[j] = '0';
        }
        subnets[i].subnet[j] = '\0';
        for (j = 0; j < MAX_SUBNET_MASK_SIZE; j++) {
            subnets[i].subnet_mask[j] = '1';
        }
        subnets[i].subnet_mask[j] = '\0';
        subnets[i].num_hosts = 0;
    }
}

void print_subnets(int num_subnets, subnet_t subnets[]) {
    int i;
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d: %s\n", i+1, subnets[i].subnet);
        printf("Subnet Mask: %s\n", subnets[i].subnet_mask);
        printf("Number of Hosts: %d\n\n", subnets[i].num_hosts);
    }
}

int main() {
    int num_subnets, i;
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    subnet_t subnets[MAX_SUBNETS];
    subnet_calculator(num_subnets, subnets);

    printf("Subnet Calculator\n");
    printf("=================\n");
    print_subnets(num_subnets, subnets);

    return 0;
}