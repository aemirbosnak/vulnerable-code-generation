//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SUBNETS 32
#define MAX_SUBNET_LENGTH 32

struct subnet {
    char name[MAX_SUBNET_LENGTH];
    int mask;
    int num_hosts;
};

int main() {
    int num_subnets;
    int i, j;
    struct subnet subnets[MAX_SUBNETS];

    // Get number of subnets from user
    printf("Enter number of subnets: ");
    scanf("%d", &num_subnets);

    // Initialize subnets array
    for (i = 0; i < num_subnets; i++) {
        subnets[i].mask = 0;
        subnets[i].num_hosts = 0;
        strcpy(subnets[i].name, "");
    }

    // Get subnet information from user
    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d name: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter subnet %d mask: ", i+1);
        scanf("%d", &subnets[i].mask);

        subnets[i].num_hosts = pow(2, 32 - subnets[i].mask) - 2; // calculate number of hosts based on mask
    }

    // Print subnet information
    printf("\nSubnet Information:\n");
    printf("---------------------\n");
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d: %s\n", i+1, subnets[i].name);
        printf("Mask: %d.%d.%d.%d\n", (subnets[i].mask >> 24) & 0xFF, (subnets[i].mask >> 16) & 0xFF, (subnets[i].mask >> 8) & 0xFF, subnets[i].mask & 0xFF);
        printf("Number of hosts: %d\n", subnets[i].num_hosts);
        printf("\n");
    }

    return 0;
}