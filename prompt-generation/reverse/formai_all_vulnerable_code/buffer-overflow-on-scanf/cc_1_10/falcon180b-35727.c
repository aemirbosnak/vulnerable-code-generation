//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 30
#define MAX_SUBNET_NAME_SIZE 50

typedef struct {
    char name[MAX_SUBNET_NAME_SIZE];
    int size;
} Subnet;

void add_subnet(Subnet *subnets, int num_subnets, char *name, int size) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strncpy(subnets[num_subnets].name, name, MAX_SUBNET_NAME_SIZE);
    subnets[num_subnets].size = size;

    num_subnets++;
}

void print_subnets(Subnet *subnets, int num_subnets) {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s (%d)\n", subnets[i].name, subnets[i].size);
    }
}

int main() {
    Subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    while (1) {
        printf("Enter subnet name (or type 'done' to finish):\n");
        char name[MAX_SUBNET_NAME_SIZE];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter subnet size (1-30):\n");
        int size;
        scanf("%d", &size);

        if (size < 1 || size > MAX_SUBNET_SIZE) {
            printf("Error: Invalid subnet size.\n");
            continue;
        }

        add_subnet(subnets, num_subnets, name, size);
    }

    print_subnets(subnets, num_subnets);

    return 0;
}