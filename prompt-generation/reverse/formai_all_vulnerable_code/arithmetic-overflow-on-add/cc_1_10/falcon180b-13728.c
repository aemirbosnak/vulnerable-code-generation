//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    int size;
    int mask;
    int num_hosts;
    int broadcast_addr;
} Subnet;

void create_subnet(Subnet *subnet, char *name, int size, int mask) {
    strcpy(subnet->name, name);
    subnet->size = size;
    subnet->mask = mask;
    subnet->num_hosts = subnet->size - (subnet->mask + 1);
    subnet->broadcast_addr = (subnet->size - 1) | (subnet->mask ^ 0xFFFFFFFF);
}

void print_subnet(Subnet *subnet) {
    printf("Subnet Name: %s\n", subnet->name);
    printf("Subnet Size: %d\n", subnet->size);
    printf("Subnet Mask: %d\n", subnet->mask);
    printf("Number of Hosts: %d\n", subnet->num_hosts);
    printf("Broadcast Address: %d\n", subnet->broadcast_addr);
    printf("\n");
}

int main() {
    int num_subnets, i;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);
        printf("Enter the subnet size (1-32): ");
        scanf("%d", &subnets[i].size);
        printf("Enter the subnet mask (1-32): ");
        scanf("%d", &subnets[i].mask);
        create_subnet(&subnets[i], subnets[i].name, subnets[i].size, subnets[i].mask);
    }

    for (i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}