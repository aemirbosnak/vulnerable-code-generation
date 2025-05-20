//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32
#define MAX_SUBNET_IP 16

typedef struct {
    char subnet_ip[MAX_SUBNET_IP];
    char subnet_mask[MAX_SUBNET_MASK];
    unsigned int num_hosts;
} subnet_t;

void print_subnet(subnet_t *subnet) {
    printf("Subnet IP: %s\n", subnet->subnet_ip);
    printf("Subnet Mask: %s\n", subnet->subnet_mask);
    printf("Number of hosts: %d\n", subnet->num_hosts);
}

int main() {
    int num_subnets;
    subnet_t subnets[MAX_SUBNETS];
    int i, j;

    // Get number of subnets from user
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Initialize subnets
    for (i = 0; i < num_subnets; i++) {
        subnets[i].subnet_ip[0] = '\0';
        subnets[i].subnet_mask[0] = '\0';
        subnets[i].num_hosts = 0;
    }

    // Get subnet details from user
    for (i = 0; i < num_subnets; i++) {
        printf("Enter details for subnet %d:\n", i+1);
        printf("Subnet IP: ");
        scanf("%s", subnets[i].subnet_ip);
        printf("Subnet Mask: ");
        scanf("%s", subnets[i].subnet_mask);

        // Calculate number of hosts
        int num_ones = 0;
        for (j = 0; j < strlen(subnets[i].subnet_mask); j++) {
            if (subnets[i].subnet_mask[j] == '1') {
                num_ones++;
            }
        }
        subnets[i].num_hosts = pow(2, num_ones) - 2;
    }

    // Print subnet details
    printf("\nSubnet details:\n");
    for (i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}