//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 16

typedef struct {
    char name[MAX_SUBNETS][MAX_SUBNET_SIZE];
    int size[MAX_SUBNETS];
    char mask[MAX_SUBNETS][MAX_SUBNET_MASK_SIZE];
} subnet_t;

void subnet_calculator(subnet_t *subnet, int num_subnets, int base_ip, int subnet_mask) {
    int i, j, k;
    int subnet_size = 0;
    int subnet_mask_size = 0;

    for (i = 0; i < num_subnets; i++) {
        sprintf(subnet->name[i], "Subnet %d", i + 1);
        subnet->size[i] = 0;
        subnet_mask_size = 0;

        while (subnet_size < 32) {
            if ((base_ip & (1 << subnet_size)) == 0) {
                subnet->mask[i][subnet_mask_size++] = '1';
                subnet_size++;
            } else {
                subnet->mask[i][subnet_mask_size++] = '0';
            }
        }

        subnet->mask[i][subnet_mask_size] = '\0';
        subnet->size[i] = pow(2, subnet_size) - 1;
    }
}

int main() {
    int num_subnets, base_ip, subnet_mask;
    subnet_t subnet;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS) {
        printf("Error: Maximum number of subnets exceeded.\n");
        return 1;
    }

    printf("Enter the base IP address: ");
    scanf("%d", &base_ip);

    printf("Enter the subnet mask: ");
    scanf("%d", &subnet_mask);

    if (subnet_mask > MAX_SUBNET_MASK_SIZE * 8) {
        printf("Error: Subnet mask size exceeded.\n");
        return 1;
    }

    subnet_calculator(&subnet, num_subnets, base_ip, subnet_mask);

    printf("Subnet Name\tSubnet Size\tSubnet Mask\n");

    for (int i = 0; i < num_subnets; i++) {
        printf("%s\t%d\t%s\n", subnet.name[i], subnet.size[i], subnet.mask[i]);
    }

    return 0;
}