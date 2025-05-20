//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 4

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_SIZE];
    int num_hosts;
} subnet;

int main() {
    int num_subnets;
    subnet subnets[MAX_SUBNETS];
    char input[100];
    int i, j;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i + 1);
        scanf("%s", subnets[i].name);

        printf("Enter the mask for subnet %s (e.g. 255.255.255.0): ", subnets[i].name);
        scanf("%s", subnets[i].mask);

        subnets[i].num_hosts = 0;
    }

    printf("\nSubnet Name\tMask\tHosts\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s\t", subnets[i].name);

        for (j = 0; j < strlen(subnets[i].mask); j++) {
            if (subnets[i].mask[j] == '.') {
                printf("%d\t", atoi(input));
                memset(input, 0, sizeof(input));
            } else {
                strcat(input, subnets[i].mask[j]);
            }
        }

        printf("%s\t%d\n", input, subnets[i].num_hosts);
    }

    return 0;
}