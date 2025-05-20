//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 32
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 4

typedef struct {
    char name[64];
    int num_subnets;
    int subnet_size;
    char subnet_mask[MAX_SUBNET_MASK_SIZE];
} Subnet;

void print_subnet(Subnet *subnet) {
    printf("Subnet name: %s\n", subnet->name);
    printf("Number of subnets: %d\n", subnet->num_subnets);
    printf("Subnet size: %d\n", subnet->subnet_size);
    printf("Subnet mask: %s\n", subnet->subnet_mask);
}

int main() {
    int num_subnets;
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    Subnet subnets[num_subnets];

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d information:\n", i+1);
        printf("Subnet name: ");
        scanf("%s", subnets[i].name);

        printf("Enter the number of subnets: ");
        scanf("%d", &subnets[i].num_subnets);

        printf("Enter the subnet size: ");
        scanf("%d", &subnets[i].subnet_size);

        printf("Enter the subnet mask (in dot-decimal notation): ");
        scanf("%s", subnets[i].subnet_mask);
    }

    for (int i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}