//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

typedef struct {
    char name[20];
    int num_hosts;
    int subnet_mask;
    int subnet_id;
} Subnet;

void subnet_calc(int num_hosts, int num_subnets) {
    int i, j, k, subnet_size;
    char subnet_name[20];

    // Calculate subnet size
    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet name: ");
        scanf("%s", subnet_name);
        printf("Enter number of hosts for %s: ", subnet_name);
        scanf("%d", &subnet_size);
        printf("Subnet %s has %d hosts.\n", subnet_name, subnet_size);
    }
}

int main() {
    int num_hosts, num_subnets;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter number of hosts: ");
    scanf("%d", &num_hosts);

    printf("Enter number of subnets: ");
    scanf("%d", &num_subnets);

    printf("Enter subnet details:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Enter subnet name: ");
        scanf("%s", subnets[i].name);
        printf("Enter number of hosts for %s: ", subnets[i].name);
        scanf("%d", &subnets[i].num_hosts);
        printf("Enter subnet mask for %s: ", subnets[i].name);
        scanf("%d", &subnets[i].subnet_mask);
    }

    printf("Subnet details:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s has %d hosts and a subnet mask of %d.\n", subnets[i].name, subnets[i].num_hosts, subnets[i].subnet_mask);
    }

    subnet_calc(num_hosts, num_subnets);

    return 0;
}