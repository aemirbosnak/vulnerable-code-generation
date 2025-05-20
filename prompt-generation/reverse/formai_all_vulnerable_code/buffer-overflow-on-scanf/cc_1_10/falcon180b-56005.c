//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK];
    int num_hosts;
} Subnet;

int main() {
    int num_subnets;
    int i, j;
    Subnet subnets[MAX_SUBNETS];

    // Get the number of subnets from the user
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Get the subnet information from the user
    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the mask of subnet %d: ", i+1);
        scanf("%s", subnets[i].mask);

        subnets[i].num_hosts = 0;
    }

    // Calculate the number of hosts in each subnet
    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < strlen(subnets[i].mask); j++) {
            if (subnets[i].mask[j] == '1') {
                subnets[i].num_hosts++;
            }
        }
    }

    // Print the subnet information
    printf("\nSubnet Information:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("Name: %s\n", subnets[i].name);
        printf("Mask: %s\n", subnets[i].mask);
        printf("Number of hosts: %d\n\n", subnets[i].num_hosts);
    }

    return 0;
}