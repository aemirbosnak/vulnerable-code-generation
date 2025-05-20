//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 4

typedef struct {
    char ip[MAX_SUBNET_SIZE];
    int mask;
    int num_hosts;
} Subnet;

int main() {
    int num_subnets;
    int i;
    Subnet subnets[MAX_SUBNETS];

    // Get number of subnets from user
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Initialize subnet array
    for (i = 0; i < num_subnets; i++) {
        strcpy(subnets[i].ip, "");
        subnets[i].mask = 0;
        subnets[i].num_hosts = 0;
    }

    // Get subnet information from user
    for (i = 0; i < num_subnets; i++) {
        printf("Enter the IP address for subnet %d: ", i+1);
        scanf("%s", subnets[i].ip);

        printf("Enter the subnet mask for subnet %d: ", i+1);
        scanf("%d", &subnets[i].mask);

        // Calculate number of hosts in subnet
        int num_ones = 0;
        int j = 0;
        while ((subnets[i].mask >> j) & 1) {
            num_ones++;
            j++;
        }
        subnets[i].num_hosts = pow(2, MAX_SUBNET_SIZE - num_ones) - 2;
    }

    // Print subnet information
    printf("\nSubnet Information:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("IP Address: %s\n", subnets[i].ip);
        printf("Subnet Mask: %d.%d.%d.%d\n", (subnets[i].mask >> 24) & 0xFF, (subnets[i].mask >> 16) & 0xFF, (subnets[i].mask >> 8) & 0xFF, subnets[i].mask & 0xFF);
        printf("Number of Hosts: %d\n\n", subnets[i].num_hosts);
    }

    return 0;
}