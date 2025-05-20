//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

typedef struct {
    char *name;
    int num_subnets;
    int *subnet_sizes;
} Subnet;

void read_subnets(Subnet *subnets, int num_subnets) {
    for (int i = 0; i < num_subnets; i++) {
        printf("Enter subnet name: ");
        scanf("%s", subnets[i].name);
        printf("Enter number of subnets: ");
        scanf("%d", &subnets[i].num_subnets);
        subnets[i].subnet_sizes = (int *) malloc(subnets[i].num_subnets * sizeof(int));
        for (int j = 0; j < subnets[i].num_subnets; j++) {
            printf("Enter subnet size for %s (%d): ", subnets[i].name, j+1);
            scanf("%d", &subnets[i].subnet_sizes[j]);
        }
    }
}

void print_subnets(Subnet *subnets, int num_subnets) {
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %s:\n", subnets[i].name);
        for (int j = 0; j < subnets[i].num_subnets; j++) {
            printf("  Subnet %d: %d\n", j+1, subnets[i].subnet_sizes[j]);
        }
    }
}

int main() {
    Subnet subnets[MAX_SUBNETS];
    int num_subnets;

    printf("Enter number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS) {
        printf("Error: Maximum number of subnets is %d\n", MAX_SUBNETS);
        return 1;
    }

    read_subnets(subnets, num_subnets);
    print_subnets(subnets, num_subnets);

    return 0;
}