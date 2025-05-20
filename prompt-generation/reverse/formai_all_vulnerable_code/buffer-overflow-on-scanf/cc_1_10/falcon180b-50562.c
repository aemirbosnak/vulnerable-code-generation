//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 32
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 16

typedef struct {
    char name[64];
    int num_subnets;
    int subnet_size;
    char subnet_mask[MAX_SUBNET_MASK_SIZE];
} Subnet;

int main() {
    int num_subnets;
    int subnet_size;
    int i, j;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    printf("Enter the subnet size (in bits): ");
    scanf("%d", &subnet_size);

    Subnet subnets[MAX_SUBNETS];

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i + 1);
        scanf("%s", subnets[i].name);

        printf("Enter the number of hosts in subnet %s: ", subnets[i].name);
        scanf("%d", &subnets[i].num_subnets);

        subnets[i].subnet_size = subnet_size;

        for (j = 0; j < subnet_size; j++) {
            subnets[i].subnet_mask[j] = '1';
        }

        subnets[i].subnet_mask[subnet_size] = '\0';
    }

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %s:\n", subnets[i].name);
        printf("Subnet mask: %s\n", subnets[i].subnet_mask);
        printf("Number of hosts: %d\n\n", subnets[i].num_subnets);
    }

    return 0;
}