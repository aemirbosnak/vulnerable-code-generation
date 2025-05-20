//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32
#define MAX_SUBNET_NAME 32

typedef struct {
    char name[MAX_SUBNET_NAME];
    int subnet_size;
    char subnet_mask[MAX_SUBNET_MASK];
} subnet_t;

int num_subnets = 0;
subnet_t subnets[MAX_SUBNETS];

void add_subnet(char* name, int subnet_size, char* subnet_mask) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strcpy(subnets[num_subnets].name, name);
    subnets[num_subnets].subnet_size = subnet_size;
    strcpy(subnets[num_subnets].subnet_mask, subnet_mask);

    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Name: %s\n", subnets[i].name);
        printf("Subnet size: %d\n", subnets[i].subnet_size);
        printf("Subnet mask: %s\n\n", subnets[i].subnet_mask);
    }
}

int main() {
    char input[MAX_SUBNET_MASK];
    int subnet_size;

    printf("Enter subnet mask (e.g. 255.255.255.0):\n");
    scanf("%s", input);

    printf("Enter subnet size (1-32):\n");
    scanf("%d", &subnet_size);

    add_subnet("Subnet 1", subnet_size, input);
    add_subnet("Subnet 2", subnet_size, input);

    print_subnets();

    return 0;
}