//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32

struct subnet {
    char name[MAX_SUBNET_SIZE];
    int mask;
    int num_hosts;
};

void add_subnet(struct subnet *subnets, int num_subnets, char *name, int mask) {
    int i;
    for (i = 0; i < num_subnets; i++) {
        if (strcmp(subnets[i].name, name) == 0) {
            fprintf(stderr, "Subnet '%s' already exists!\n", name);
            exit(1);
        }
    }
    strcpy(subnets[num_subnets].name, name);
    subnets[num_subnets].mask = mask;
    subnets[num_subnets].num_hosts = (32 - mask) / (8 - (mask % 8));
    num_subnets++;
}

void print_subnets(struct subnet *subnets, int num_subnets) {
    int i;
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet '%s':\n", subnets[i].name);
        printf("  Mask: %d.%d.%d.%d\n", (subnets[i].mask >> 24) & 0xFF, (subnets[i].mask >> 16) & 0xFF, (subnets[i].mask >> 8) & 0xFF, subnets[i].mask & 0xFF);
        printf("  Number of hosts: %d\n\n", subnets[i].num_hosts);
    }
}

int main(int argc, char *argv[]) {
    int num_subnets = 0;
    struct subnet subnets[MAX_SUBNETS];
    char name[MAX_SUBNET_SIZE];
    int mask;

    printf("Welcome to the Subnet Calculator!\n\n");

    while (1) {
        printf("\nEnter subnet name (or type 'done' to finish): ");
        scanf("%s", name);
        if (strcmp(name, "done") == 0) {
            break;
        }
        printf("Enter subnet mask (in dotted decimal notation): ");
        scanf("%d.%d.%d.%d", &mask, &mask, &mask, &mask);
        add_subnet(subnets, num_subnets, name, mask);
    }

    printf("\nSubnets:\n");
    print_subnets(subnets, num_subnets);

    return 0;
}