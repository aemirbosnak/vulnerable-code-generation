//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 8

typedef struct {
    char *name;
    char *subnet;
    char *mask;
    int size;
} subnet_t;

int num_subnets = 0;
subnet_t subnets[MAX_SUBNETS];

void add_subnet(char *name, char *subnet, char *mask, int size) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    subnet_t *s = &subnets[num_subnets];
    s->name = strdup(name);
    s->subnet = strdup(subnet);
    s->mask = strdup(mask);
    s->size = size;

    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        subnet_t *s = &subnets[i];
        printf("%s\t%s\t%s\t%d\n", s->name, s->subnet, s->mask, s->size);
    }
}

int main() {
    add_subnet("Subnet 1", "192.168.1.0", "255.255.255.0", 24);
    add_subnet("Subnet 2", "192.168.2.0", "255.255.255.0", 24);
    add_subnet("Subnet 3", "10.0.0.0", "255.0.0.0", 8);

    print_subnets();

    return 0;
}