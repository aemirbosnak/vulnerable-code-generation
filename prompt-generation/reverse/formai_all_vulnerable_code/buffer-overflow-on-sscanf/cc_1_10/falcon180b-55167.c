//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 4

typedef struct {
    char name[32];
    int size;
    char mask[MAX_SUBNET_MASK_SIZE];
} subnet_t;

int subnet_count = 0;
subnet_t subnets[MAX_SUBNETS];

int compare_subnets(const void *a, const void *b) {
    subnet_t *subnet1 = (subnet_t *)a;
    subnet_t *subnet2 = (subnet_t *)b;

    return strcmp(subnet1->name, subnet2->name);
}

void add_subnet(char *name, int size, char *mask) {
    if (subnet_count >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strncpy(subnets[subnet_count].name, name, 32);
    subnets[subnet_count].size = size;
    strncpy(subnets[subnet_count].mask, mask, MAX_SUBNET_MASK_SIZE);

    subnet_count++;
}

void print_subnets() {
    qsort(subnets, subnet_count, sizeof(subnet_t), compare_subnets);

    for (int i = 0; i < subnet_count; i++) {
        printf("%s/%d (%s)\n", subnets[i].name, subnets[i].size, subnets[i].mask);
    }
}

int main() {
    char input[1024];
    char name[32];
    int size;
    char mask[MAX_SUBNET_MASK_SIZE];

    printf("Enter subnet information (name size mask):\n");
    fgets(input, sizeof(input), stdin);

    while (sscanf(input, "%s %d %s", name, &size, mask) == 3) {
        add_subnet(name, size, mask);

        printf("Enter subnet information (name size mask) or press enter to finish:\n");
        fgets(input, sizeof(input), stdin);
    }

    print_subnets();

    return 0;
}