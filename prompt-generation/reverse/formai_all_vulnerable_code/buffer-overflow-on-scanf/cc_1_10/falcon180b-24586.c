//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 4

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_SIZE];
    int size;
} Subnet;

int main() {
    int num_subnets;
    Subnet subnets[MAX_SUBNETS];
    int i, j;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS || num_subnets <= 0) {
        printf("Invalid number of subnets\n");
        return 1;
    }

    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d name (up to %d characters): ", i+1, MAX_SUBNET_SIZE-1);
        scanf("%s", subnets[i].name);

        printf("Enter subnet %d mask (up to %d characters): ", i+1, MAX_SUBNET_MASK_SIZE-1);
        scanf("%s", subnets[i].mask);

        subnets[i].size = atoi(subnets[i].mask);
    }

    printf("Subnets:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s (%d): ", subnets[i].name, subnets[i].size);
        for (j = 0; j < subnets[i].size; j++) {
            printf("%d.%d.%d.%d ", (int)(rand() % 256), (int)(rand() % 256), (int)(rand() % 256), (int)(rand() % 256));
        }
        printf("\n");
    }

    return 0;
}