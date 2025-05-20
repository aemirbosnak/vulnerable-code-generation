//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 10

typedef struct {
    char name[50];
    int size;
    int subnet_size;
    int num_subnets;
    int *subnets;
} Subnet;

void generate_subnets(int size, int subnet_size, int num_subnets, int *subnets) {
    int i, j, k;
    for (i = 0; i < num_subnets; i++) {
        subnets[i] = 0;
    }
    for (i = 0; i < MAX_SUBNETS; i++) {
        if (size == 1) {
            subnets[0] = i;
            break;
        }
        for (j = 0; j < MAX_SUBNET_SIZE; j++) {
            if ((i >> j) & 1) {
                for (k = 0; k < num_subnets; k++) {
                    if ((subnets[k] >> j) & 1) {
                        break;
                    }
                }
                if (k == num_subnets) {
                    subnets[k] |= (1 << j);
                }
            }
        }
    }
}

int main() {
    int i, j, num_subnets;
    char input[100];
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i + 1);
        scanf("%s", subnets[i].name);
        printf("Enter the size of subnet %d: ", i + 1);
        scanf("%d", &subnets[i].size);
        printf("Enter the subnet mask size of subnet %d: ", i + 1);
        scanf("%d", &subnets[i].subnet_size);
    }

    for (i = 0; i < num_subnets; i++) {
        generate_subnets(subnets[i].size, subnets[i].subnet_size, num_subnets, subnets[i].subnets);
    }

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %s has %d subnets:\n", subnets[i].name, subnets[i].num_subnets);
        for (j = 0; j < subnets[i].num_subnets; j++) {
            printf("%d ", subnets[i].subnets[j]);
        }
        printf("\n");
    }

    return 0;
}