//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

struct subnet {
    char name[20];
    char ip[16];
    char mask[16];
};

int main() {
    int num_subnets, i, j, k;
    struct subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the IP address of subnet %d: ", i+1);
        scanf("%s", subnets[i].ip);

        printf("Enter the subnet mask of subnet %d: ", i+1);
        scanf("%s", subnets[i].mask);
    }

    printf("\nSubnet Information:\n");
    printf("---------------------\n");
    printf("Name\tIP Address\tSubnet Mask\n");

    for (i = 0; i < num_subnets; i++) {
        printf("%s\t", subnets[i].name);
        for (j = 0; j < strlen(subnets[i].ip); j++) {
            if (subnets[i].ip[j] == '.') {
                printf("\t");
            } else {
                printf("%c", subnets[i].ip[j]);
            }
        }
        printf("\t");
        for (j = 0; j < strlen(subnets[i].mask); j++) {
            if (subnets[i].mask[j] == '.') {
                printf("\t");
            } else {
                printf("%c", subnets[i].mask[j]);
            }
        }
        printf("\n");
    }

    return 0;
}