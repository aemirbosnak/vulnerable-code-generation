//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 24
#define MAX_SUBNET_COUNT (MAX_SUBNET_SIZE - 2)

typedef struct {
    char name[64];
    int size;
    int subnet_count;
    int *subnets;
} Subnet;

void subnet_init(Subnet *subnet, char *name, int size) {
    strncpy(subnet->name, name, sizeof(subnet->name));
    subnet->size = size;
    subnet->subnet_count = 0;
    subnet->subnets = calloc(MAX_SUBNET_COUNT, sizeof(int));
}

void subnet_add(Subnet *subnet, int subnet_id) {
    if (subnet->subnet_count >= MAX_SUBNET_COUNT) {
        printf("Error: Too many subnets for %s\n", subnet->name);
        return;
    }
    subnet->subnets[subnet->subnet_count++] = subnet_id;
}

void subnet_print(Subnet *subnet) {
    printf("Subnet %s:\n", subnet->name);
    printf("  Size: %d\n", subnet->size);
    printf("  Subnets:\n");
    for (int i = 0; i < subnet->subnet_count; i++) {
        printf("    %d\n", subnet->subnets[i]);
    }
}

int main() {
    int num_subnets;
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    Subnet *subnets = calloc(num_subnets, sizeof(Subnet));

    for (int i = 0; i < num_subnets; i++) {
        char name[64];
        printf("Enter the name for subnet %d: ", i + 1);
        scanf("%s", name);
        printf("Enter the size for subnet %s: ", name);
        scanf("%d", &subnets[i].size);
        subnet_init(&subnets[i], name, subnets[i].size);
    }

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter the subnets for %s:\n", subnets[i].name);
        int subnet_id;
        while (scanf("%d", &subnet_id) == 1) {
            subnet_add(&subnets[i], subnet_id);
        }
    }

    for (int i = 0; i < num_subnets; i++) {
        subnet_print(&subnets[i]);
    }

    return 0;
}