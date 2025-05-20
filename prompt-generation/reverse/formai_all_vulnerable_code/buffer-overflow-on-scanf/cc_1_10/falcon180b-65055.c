//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 16

typedef struct {
    char subnet[MAX_SUBNET_SIZE];
    int size;
} subnet_t;

typedef struct {
    char subnet_mask[MAX_SUBNET_MASK_SIZE];
    int size;
} subnet_mask_t;

int main() {
    int num_subnets;
    int subnet_size;
    int subnet_mask_size;
    int i;
    subnet_t subnets[MAX_SUBNETS];
    subnet_mask_t subnet_masks[MAX_SUBNETS];

    printf("Enter number of subnets: ");
    scanf("%d", &num_subnets);

    printf("Enter subnet size: ");
    scanf("%d", &subnet_size);

    printf("Enter subnet mask size: ");
    scanf("%d", &subnet_mask_size);

    for (i = 0; i < num_subnets; i++) {
        strcpy(subnets[i].subnet, "192.168.0.0");
        subnets[i].size = subnet_size;

        strcpy(subnet_masks[i].subnet_mask, "255.255.0.0");
        subnet_masks[i].size = subnet_mask_size;
    }

    printf("Subnets:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s\n", subnets[i].subnet);
    }

    printf("Subnet masks:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s\n", subnet_masks[i].subnet_mask);
    }

    return 0;
}