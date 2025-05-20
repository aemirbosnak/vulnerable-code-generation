//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 24

struct subnet {
    char name[MAX_SUBNET_SIZE];
    int size;
};

void read_subnet(struct subnet *subnet) {
    printf("Enter subnet name: ");
    fgets(subnet->name, MAX_SUBNET_SIZE, stdin);
    subnet->name[strcspn(subnet->name, "\n")] = '\0';

    printf("Enter subnet size: ");
    scanf("%d", &subnet->size);
}

void print_subnet(const struct subnet *subnet) {
    printf("%s (%d)\n", subnet->name, subnet->size);
}

int compare_subnets(const void *a, const void *b) {
    const struct subnet *subnet_a = (const struct subnet *)a;
    const struct subnet *subnet_b = (const struct subnet *)b;

    return strcmp(subnet_a->name, subnet_b->name);
}

int main() {
    struct subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    printf("Enter number of subnets (up to %d): ", MAX_SUBNETS);
    scanf("%d", &num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        read_subnet(&subnets[i]);
    }

    qsort(subnets, num_subnets, sizeof(struct subnet), compare_subnets);

    for (int i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}