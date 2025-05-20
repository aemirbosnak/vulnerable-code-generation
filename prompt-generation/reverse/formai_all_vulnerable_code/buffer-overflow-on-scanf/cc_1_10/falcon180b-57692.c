//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char subnet_mask[MAX_SUBNET_MASK];
    int num_hosts;
} subnet;

int num_subnets = 0;
subnet subnets[MAX_SUBNETS];

void add_subnet(char* name, char* subnet_mask, int num_hosts) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        exit(1);
    }
    strcpy(subnets[num_subnets].name, name);
    strcpy(subnets[num_subnets].subnet_mask, subnet_mask);
    subnets[num_subnets].num_hosts = num_hosts;
    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s (%s) - %d hosts\n", subnets[i].name, subnets[i].subnet_mask, subnets[i].num_hosts);
    }
}

int main() {
    char input[MAX_SUBNET_SIZE];
    char subnet_mask[MAX_SUBNET_MASK];
    int num_hosts;

    printf("Enter the subnet name (up to %d characters): ", MAX_SUBNET_SIZE - 1);
    scanf("%s", input);

    printf("Enter the subnet mask (up to %d characters): ", MAX_SUBNET_MASK - 1);
    scanf("%s", subnet_mask);

    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    add_subnet(input, subnet_mask, num_hosts);
    print_subnets();

    return 0;
}