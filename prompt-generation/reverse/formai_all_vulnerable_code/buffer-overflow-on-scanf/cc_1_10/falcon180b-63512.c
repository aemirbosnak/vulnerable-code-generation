//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

struct subnet {
    char name[50];
    int num_hosts;
    int subnet_mask;
};

void calculate_subnets(int num_hosts, int num_subnets) {
    int i, j, k, subnet_size, remaining_hosts;

    printf("Calculating subnets...\n");

    for (i = 0; i < num_subnets; i++) {
        subnet_size = num_hosts / num_subnets;
        remaining_hosts = num_hosts % num_subnets;

        for (j = 0; j < num_subnets; j++) {
            if (j < remaining_hosts) {
                subnet_size++;
            }

            printf("Subnet %d: ", i+1);
            printf("%d hosts (%d-%d)\n", subnet_size, i*subnet_size+1, (i+1)*subnet_size-1);
        }
    }
}

int main() {
    int num_hosts, num_subnets;
    struct subnet subnets[MAX_SUBNETS];
    int i;

    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_hosts % num_subnets!= 0) {
        printf("Error: The number of hosts must be evenly divisible by the number of subnets.\n");
        return 1;
    }

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);
    }

    calculate_subnets(num_hosts, num_subnets);

    return 0;
}