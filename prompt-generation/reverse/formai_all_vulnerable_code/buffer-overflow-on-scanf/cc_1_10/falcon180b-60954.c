//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_COUNT 100

typedef struct {
    char name[MAX_SUBNET_SIZE];
    int size;
    int count;
} Subnet;

void init_subnet(Subnet *subnet, char *name, int size) {
    strncpy(subnet->name, name, MAX_SUBNET_SIZE);
    subnet->size = size;
    subnet->count = 0;
}

int main() {
    int num_subnets, i;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        char name[MAX_SUBNET_SIZE];
        int size;

        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", name);

        printf("Enter the size of subnet %s: ", name);
        scanf("%d", &size);

        init_subnet(&subnets[i], name, size);
    }

    printf("\nSubnet Information:\n");
    printf("---------------------\n");

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("Name: %s\n", subnets[i].name);
        printf("Size: %d\n", subnets[i].size);
        printf("Count: %d\n", subnets[i].count);
        printf("\n");
    }

    return 0;
}