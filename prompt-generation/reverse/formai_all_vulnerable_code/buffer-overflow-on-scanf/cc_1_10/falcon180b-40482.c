//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char ip[MAX_SUBNET_SIZE];
    int num_hosts;
    int subnet_mask;
} subnet_t;

void print_subnet(subnet_t* subnet) {
    printf("Subnet Name: %s\n", subnet->name);
    printf("IP Address: %s\n", subnet->ip);
    printf("Number of Hosts: %d\n", subnet->num_hosts);
    printf("Subnet Mask: %d\n\n", subnet->subnet_mask);
}

int main() {
    int num_subnets;
    int i;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS) {
        printf("Error: Maximum number of subnets is %d\n", MAX_SUBNETS);
        return 1;
    }

    subnet_t subnets[num_subnets];

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the details for subnet %d:\n", i+1);
        printf("Subnet Name: ");
        scanf("%s", subnets[i].name);

        printf("IP Address: ");
        scanf("%s", subnets[i].ip);

        printf("Number of Hosts: ");
        scanf("%d", &subnets[i].num_hosts);

        printf("Subnet Mask: ");
        scanf("%d", &subnets[i].subnet_mask);
    }

    for (i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}