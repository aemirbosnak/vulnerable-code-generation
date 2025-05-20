//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 32

typedef struct {
    char name[64];
    int num_subnets;
    int subnet_bits;
    int host_bits;
    int subnet_mask;
} Subnet;

void print_subnet(Subnet *subnet) {
    printf("Name: %s\n", subnet->name);
    printf("Number of subnets: %d\n", subnet->num_subnets);
    printf("Subnet bits: %d\n", subnet->subnet_bits);
    printf("Host bits: %d\n", subnet->host_bits);
    printf("Subnet mask: %d.%d.%d.%d\n", (subnet->subnet_mask >> 24) & 0xFF, (subnet->subnet_mask >> 16) & 0xFF, (subnet->subnet_mask >> 8) & 0xFF, subnet->subnet_mask & 0xFF);
}

int main() {
    int num_subnets;
    int i;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_subnets <= 0 || num_subnets > MAX_SUBNETS) {
        printf("Invalid number of subnets.\n");
        return 1;
    }

    Subnet subnets[MAX_SUBNETS];

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the number of hosts per subnet: ");
        scanf("%d", &subnets[i].num_subnets);

        if (subnets[i].num_subnets <= 0 || subnets[i].num_subnets > 254) {
            printf("Invalid number of hosts per subnet.\n");
            return 1;
        }

        subnets[i].subnet_bits = 32 - subnets[i].num_subnets;
        subnets[i].host_bits = subnets[i].num_subnets;
        subnets[i].subnet_mask = htonl(0xFFFFFFFF << (32 - subnets[i].subnet_bits));
    }

    printf("Subnet Name\tNumber of Subnets\tSubnet Bits\tHost Bits\tSubnet Mask\n");
    for (i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}