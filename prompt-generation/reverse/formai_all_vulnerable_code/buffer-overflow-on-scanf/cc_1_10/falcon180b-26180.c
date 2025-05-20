//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 16
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 4

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_SIZE];
    int size;
} Subnet;

void print_subnet(Subnet *subnet) {
    printf("Subnet Name: %s\n", subnet->name);
    printf("IP Address: %s\n", subnet->ip);
    printf("Subnet Mask: %s\n", subnet->mask);
    printf("Subnet Size: %d\n", subnet->size);
}

int main() {
    int num_subnets;
    Subnet subnets[MAX_SUBNETS];

    printf("Cyberpunk Subnet Calculator\n");

    printf("Enter the number of subnets (1-%d): ", MAX_SUBNETS);
    scanf("%d", &num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the IP address of subnet %d: ", i+1);
        scanf("%s", subnets[i].ip);

        printf("Enter the subnet mask of subnet %d (e.g. 255.255.255.0): ", i+1);
        scanf("%s", subnets[i].mask);

        subnets[i].size = atoi(subnets[i].mask) & 0xff;

        printf("Subnet %d created successfully.\n", i+1);
    }

    printf("Subnet List:\n");
    for (int i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}