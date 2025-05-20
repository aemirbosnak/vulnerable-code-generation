//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 256
#define MAX_SUBNET_MASK_SIZE 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_SIZE];
    int num_hosts;
} Subnet;

int main() {
    int num_subnets;
    Subnet subnets[MAX_SUBNETS];
    int i, j;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i + 1);
        scanf("%s", subnets[i].name);

        printf("Enter the mask of subnet %d: ", i + 1);
        scanf("%s", subnets[i].mask);

        subnets[i].num_hosts = calculate_num_hosts(subnets[i].mask);
    }

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d has %d hosts.\n", i + 1, subnets[i].num_hosts);
    }

    return 0;
}

int calculate_num_hosts(char *mask) {
    int num_hosts = 0;
    int len = strlen(mask);
    int i;

    for (i = 0; i < len; i++) {
        if (mask[i] == '1') {
            num_hosts++;
        }
    }

    return num_hosts;
}