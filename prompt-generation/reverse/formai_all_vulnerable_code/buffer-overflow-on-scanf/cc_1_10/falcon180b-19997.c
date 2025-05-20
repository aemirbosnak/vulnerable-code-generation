//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 30
#define MAX_SUBNET_MASK_SIZE 15

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_SIZE];
    int num_hosts;
} subnet;

void calculate_subnets(int num_subnets, subnet *subnets) {
    int i, j, k, num_hosts = pow(2, 8 - num_subnets);

    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < num_hosts; j++) {
            for (k = 0; k < MAX_SUBNET_MASK_SIZE; k++) {
                if (j & (1 << k)) {
                    subnets[i].mask[k] = '1';
                } else {
                    subnets[i].mask[k] = '0';
                }
            }
            subnets[i].num_hosts = num_hosts;
            sprintf(subnets[i].name, "Subnet %d", i + 1);
            i++;
        }
    }
}

int main() {
    int num_subnets;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS || num_subnets <= 0) {
        printf("Invalid number of subnets.\n");
        return 1;
    }

    subnet subnets[MAX_SUBNETS];

    calculate_subnets(num_subnets, subnets);

    printf("\nSubnet\tIP Address Range\tNumber of Hosts\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%-10s\t%-15s\t\t%d\n", subnets[i].name, subnets[i].mask, subnets[i].num_hosts);
    }

    return 0;
}