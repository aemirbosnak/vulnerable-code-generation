//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

typedef struct {
    char ip[16];
    char mask[16];
    char subnet[16];
    char broadcast[16];
} subnet_t;

void print_subnet(subnet_t *subnet) {
    printf("IP Address: %s\n", subnet->ip);
    printf("Subnet Mask: %s\n", subnet->mask);
    printf("Subnet: %s\n", subnet->subnet);
    printf("Broadcast: %s\n\n", subnet->broadcast);
}

int main() {
    int num_subnets;
    subnet_t subnets[MAX_SUBNETS];

    printf("Enter the number of subnets (max %d): ", MAX_SUBNETS);
    scanf("%d", &num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter IP address for subnet %d: ", i+1);
        scanf("%s", subnets[i].ip);

        printf("Enter subnet mask for subnet %d: ", i+1);
        scanf("%s", subnets[i].mask);

        for (int j = 0; j < num_subnets; j++) {
            if (i == j)
                continue;

            if (strcmp(subnets[i].ip, subnets[j].ip) == 0 &&
                strcmp(subnets[i].mask, subnets[j].mask) == 0) {
                printf("Error: Duplicate IP address and subnet mask for subnets %d and %d\n", i+1, j+1);
                exit(1);
            }
        }

        sprintf(subnets[i].subnet, "%s/%d", subnets[i].ip, atoi(subnets[i].mask));
        strcat(subnets[i].subnet, ".0");

        sprintf(subnets[i].broadcast, "%s/%d", subnets[i].ip, atoi(subnets[i].mask));
        strcat(subnets[i].broadcast, ".255");
    }

    printf("Subnet Calculator Results:\n");
    for (int i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}