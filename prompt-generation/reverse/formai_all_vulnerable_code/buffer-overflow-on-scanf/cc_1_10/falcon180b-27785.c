//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 30
#define MAX_SUBNET_MASKS 10
#define MAX_MASK_SIZE 30

typedef struct {
    char mask[MAX_SUBNET_MASKS][MAX_SUBNET_MASKS];
    int subnet_size[MAX_SUBNETS];
    int mask_size[MAX_SUBNETS];
    int num_subnets;
} subnet_t;

void init_subnet(subnet_t* s) {
    memset(s->mask, 0, sizeof(s->mask));
    s->num_subnets = 0;
}

void add_subnet(subnet_t* s, int size, int mask_size) {
    strncpy(s->mask[s->num_subnets], "255.255.255.0", mask_size);
    s->subnet_size[s->num_subnets] = size;
    s->mask_size[s->num_subnets] = mask_size;
    s->num_subnets++;
}

int main() {
    int num_subnets;
    int num_hosts;
    int subnet_size;
    int mask_size;
    int i;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    printf("Enter the number of hosts per subnet: ");
    scanf("%d", &num_hosts);

    printf("Enter the subnet size: ");
    scanf("%d", &subnet_size);

    subnet_t s;
    init_subnet(&s);

    for (i = 0; i < num_subnets; i++) {
        add_subnet(&s, subnet_size, mask_size);
    }

    printf("Subnet configuration:\n");
    printf("Number of subnets: %d\n", num_subnets);
    printf("Number of hosts per subnet: %d\n", num_hosts);
    printf("Subnet size: %d\n", subnet_size);

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("Subnet size: %d\n", s.subnet_size[i]);
        printf("Mask size: %d\n", s.mask_size[i]);
        printf("Mask: %s\n", s.mask[i]);
        printf("\n");
    }

    return 0;
}