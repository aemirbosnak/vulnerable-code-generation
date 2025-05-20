//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_VALUE 4294967295

typedef struct {
    char name[MAX_SUBNET_SIZE];
    int size;
    int value;
} Subnet;

void print_subnet(Subnet subnet) {
    printf("Subnet name: %s\n", subnet.name);
    printf("Subnet size: %d\n", subnet.size);
    printf("Subnet value: %d\n\n", subnet.value);
}

int main() {
    int num_subnets;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets (1-10): ");
    scanf("%d", &num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d name (up to %d characters): ", i+1, MAX_SUBNET_SIZE-1);
        scanf("%s", subnets[i].name);

        printf("Enter subnet %d size (1-32): ", i+1);
        scanf("%d", &subnets[i].size);

        if (subnets[i].size < 1 || subnets[i].size > MAX_SUBNET_SIZE) {
            printf("Invalid subnet size. Exiting.\n");
            return 1;
        }

        printf("Enter subnet %d value (0-4294967295): ", i+1);
        scanf("%d", &subnets[i].value);

        if (subnets[i].value < 0 || subnets[i].value > MAX_SUBNET_VALUE) {
            printf("Invalid subnet value. Exiting.\n");
            return 1;
        }
    }

    printf("\nSubnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        print_subnet(subnets[i]);
    }

    return 0;
}