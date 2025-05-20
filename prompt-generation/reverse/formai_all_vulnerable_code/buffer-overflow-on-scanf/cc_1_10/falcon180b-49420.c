//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

typedef struct {
    char *name;
    int num_hosts;
    int subnet_mask;
} Subnet;

int main(int argc, char *argv[]) {
    char input[100];
    Subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;
    int i;

    // Prompt user for input
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Loop through each subnet
    for (i = 0; i < num_subnets; i++) {
        // Prompt user for subnet name
        printf("Enter the name of subnet %d: ", i + 1);
        scanf("%s", input);
        subnets[i].name = strdup(input);

        // Prompt user for number of hosts
        printf("Enter the number of hosts in subnet %s: ", subnets[i].name);
        scanf("%d", &subnets[i].num_hosts);

        // Calculate subnet mask
        int num_bits = log2(subnets[i].num_hosts);
        int subnet_mask = ~(0xFFFFFFFF << num_bits);
        subnets[i].subnet_mask = subnet_mask;
    }

    // Print subnet information
    printf("\nSubnet information:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %s:\n", subnets[i].name);
        printf("Number of hosts: %d\n", subnets[i].num_hosts);
        printf("Subnet mask: %d.%d.%d.%d\n", (subnets[i].subnet_mask >> 24) & 0xFF, (subnets[i].subnet_mask >> 16) & 0xFF, (subnets[i].subnet_mask >> 8) & 0xFF, subnets[i].subnet_mask & 0xFF);
        printf("\n");
    }

    return 0;
}