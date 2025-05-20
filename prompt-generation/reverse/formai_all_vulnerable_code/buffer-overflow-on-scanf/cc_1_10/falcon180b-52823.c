//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 30
#define MAX_SUBNET_NAME 50

struct subnet {
    char name[MAX_SUBNET_NAME];
    int size;
    int mask;
    int count;
};

int main() {
    int num_subnets, i, j, k;
    struct subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i + 1);
        scanf("%s", subnets[i].name);

        printf("Enter the size of subnet %d: ", i + 1);
        scanf("%d", &subnets[i].size);

        printf("Enter the mask of subnet %d: ", i + 1);
        scanf("%d", &subnets[i].mask);

        subnets[i].count = 0;
    }

    printf("\nSubnet\tSize\tMask\tIP Addresses\n");
    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < subnets[i].size; j++) {
            printf("%s\t", subnets[i].name);
            for (k = 0; k < 4; k++) {
                if (k == 3) {
                    printf("%d", j + 1);
                } else {
                    printf("%d.", (subnets[i].mask >> (3 - k)) & 0x7f);
                }
            }
            printf("\t%d\n", subnets[i].mask);
            subnets[i].count++;
        }
    }

    return 0;
}