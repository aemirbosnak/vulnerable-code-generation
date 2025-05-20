//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 30
#define MAX_SUBNET_MASK_SIZE 10

typedef struct {
    char subnet_mask[MAX_SUBNET_MASK_SIZE];
    int subnet_size;
    int num_subnets;
} Subnet;

void generate_subnet_mask(char* subnet_mask, int subnet_size) {
    int i;
    for (i = 0; i < subnet_size; i++) {
        subnet_mask[i] = '1';
    }
    for (i = subnet_size; i < MAX_SUBNET_MASK_SIZE; i++) {
        subnet_mask[i] = '0';
    }
}

void generate_subnet_table(Subnet* subnets, int num_subnets, int subnet_size) {
    char subnet_mask[MAX_SUBNET_MASK_SIZE];
    generate_subnet_mask(subnet_mask, subnet_size);
    int i;
    for (i = 0; i < num_subnets; i++) {
        sprintf(subnets[i].subnet_mask, "%s", subnet_mask);
        subnets[i].subnet_size = subnet_size;
    }
}

void print_subnet_table(Subnet* subnets, int num_subnets) {
    int i;
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d: %s\n", i + 1, subnets[i].subnet_mask);
    }
}

int main() {
    int num_subnets;
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    Subnet subnets[MAX_SUBNETS];
    if (num_subnets > MAX_SUBNETS) {
        printf("Error: Maximum number of subnets is %d\n", MAX_SUBNETS);
        return 1;
    }

    int subnet_size;
    printf("Enter the subnet size: ");
    scanf("%d", &subnet_size);

    if (subnet_size > 30) {
        printf("Error: Maximum subnet size is 30\n");
        return 1;
    }

    generate_subnet_table(subnets, num_subnets, subnet_size);
    print_subnet_table(subnets, num_subnets);

    return 0;
}