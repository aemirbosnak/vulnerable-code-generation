//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 16
#define MAX_SUBNET_SIZE 256
#define MAX_SUBNET_MASK_SIZE 32

typedef struct {
    char name[32];
    int num_subnets;
    int subnet_size;
    char subnet_mask[MAX_SUBNET_MASK_SIZE];
} Subnet;

void print_subnet(Subnet *subnet) {
    printf("Subnet: %s\n", subnet->name);
    printf("Number of subnets: %d\n", subnet->num_subnets);
    printf("Subnet size: %d\n", subnet->subnet_size);
    printf("Subnet mask: %s\n\n", subnet->subnet_mask);
}

int main() {
    int num_subnets;
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    Subnet subnets[MAX_SUBNETS];
    int num_filled_subnets = 0;

    while (num_filled_subnets < num_subnets) {
        printf("Enter the name of the subnet (leave blank to finish): ");
        char name[32];
        scanf("%s", name);

        if (name[0] == '\0') {
            break;
        }

        Subnet *subnet = &subnets[num_filled_subnets];
        strcpy(subnet->name, name);

        printf("Enter the number of subnets in %s: ", name);
        scanf("%d", &subnet->num_subnets);

        printf("Enter the subnet size in %s: ", name);
        scanf("%d", &subnet->subnet_size);

        printf("Enter the subnet mask in %s (in dotted decimal notation): ", name);
        scanf("%s", subnet->subnet_mask);

        num_filled_subnets++;
    }

    printf("\nSubnet calculations:\n");
    for (int i = 0; i < num_filled_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}