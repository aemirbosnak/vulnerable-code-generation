//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10

struct subnet {
    char name[20];
    int num_hosts;
    int subnet_mask;
    int num_subnets;
};

struct subnet *create_subnet(char *name, int num_hosts, int subnet_mask, int num_subnets) {
    struct subnet *subnet = malloc(sizeof(struct subnet));
    strcpy(subnet->name, name);
    subnet->num_hosts = num_hosts;
    subnet->subnet_mask = subnet_mask;
    subnet->num_subnets = num_subnets;
    return subnet;
}

void print_subnet(struct subnet *subnet) {
    printf("Subnet Name: %s\n", subnet->name);
    printf("Number of Hosts: %d\n", subnet->num_hosts);
    printf("Subnet Mask: %d.%d.%d.%d\n", (subnet->subnet_mask & 0xff000000) >> 24, (subnet->subnet_mask & 0x00ff0000) >> 16, (subnet->subnet_mask & 0x0000ff00) >> 8, (subnet->subnet_mask & 0x000000ff));
    printf("Number of Subnets: %d\n", subnet->num_subnets);
}

void add_subnet(struct subnet **subnets, int *num_subnets, char *name, int num_hosts, int subnet_mask, int num_subnets_per_subnet) {
    (*num_subnets)++;
    *subnets = realloc(*subnets, sizeof(struct subnet) * (*num_subnets));
    struct subnet *subnet = create_subnet(name, num_hosts, subnet_mask, num_subnets_per_subnet);
    *subnets[*num_subnets - 1] = *subnet;
}

int main() {
    int num_subnets = 0;
    struct subnet *subnets[MAX_SUBNETS];

    add_subnet(&subnets, &num_subnets, "Subnet 1", 254, 255, 1);
    add_subnet(&subnets, &num_subnets, "Subnet 2", 254, 255, 2);
    add_subnet(&subnets, &num_subnets, "Subnet 3", 254, 255, 4);

    for (int i = 0; i < num_subnets; i++) {
        print_subnet(subnets[i]);
    }

    return 0;
}