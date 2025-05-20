//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 4

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char subnet_mask[MAX_SUBNET_MASK_SIZE];
    char first_ip[MAX_SUBNET_SIZE];
    char last_ip[MAX_SUBNET_SIZE];
    char gateway[MAX_SUBNET_SIZE];
} Subnet;

void print_subnet(Subnet subnet) {
    printf("Subnet name: %s\n", subnet.name);
    printf("Subnet mask: %s\n", subnet.subnet_mask);
    printf("First IP: %s\n", subnet.first_ip);
    printf("Last IP: %s\n", subnet.last_ip);
    printf("Gateway: %s\n\n", subnet.gateway);
}

int main() {
    int num_subnets, i;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the subnet mask of subnet %d: ", i+1);
        scanf("%s", subnets[i].subnet_mask);

        printf("Enter the first IP of subnet %d: ", i+1);
        scanf("%s", subnets[i].first_ip);

        printf("Enter the last IP of subnet %d: ", i+1);
        scanf("%s", subnets[i].last_ip);

        printf("Enter the gateway of subnet %d: ", i+1);
        scanf("%s", subnets[i].gateway);
    }

    for (i = 0; i < num_subnets; i++) {
        print_subnet(subnets[i]);
    }

    return 0;
}