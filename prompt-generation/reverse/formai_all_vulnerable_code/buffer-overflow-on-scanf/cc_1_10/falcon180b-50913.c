//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 10

typedef struct {
    char name[20];
    int size;
    char mask[16];
    char broadcast[16];
} subnet_t;

int main() {

    char input[100];
    int num_subnets, i, j, k;

    printf("Enter the IP address: ");
    scanf("%s", input);

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    subnet_t subnets[MAX_SUBNETS];

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the subnet name: ");
        scanf("%s", subnets[i].name);

        printf("Enter the subnet size: ");
        scanf("%d", &subnets[i].size);

        strcpy(subnets[i].mask, "255.255.255.0");
        strcpy(subnets[i].broadcast, "255.255.255.255");
    }

    printf("\n");
    printf("+------------------------+\n");
    printf("|  Subnet Name  |  Subnet Mask  |\n");
    printf("+------------------------+\n");

    for (i = 0; i < num_subnets; i++) {
        printf("| %-15s | %-15s |\n", subnets[i].name, subnets[i].mask);
    }

    printf("\n");
    printf("+------------------------+\n");
    printf("|  Subnet Name  |  Subnet Size  |\n");
    printf("+------------------------+\n");

    for (i = 0; i < num_subnets; i++) {
        printf("| %-15s | %-15d |\n", subnets[i].name, subnets[i].size);
    }

    printf("\n");
    printf("+------------------------+\n");
    printf("|  Subnet Name  |  Broadcast Address  |\n");
    printf("+------------------------+\n");

    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < strlen(subnets[i].mask); j++) {
            if (subnets[i].mask[j] == '.' && subnets[i].size > 0) {
                k = atoi(subnets[i].mask + j + 1);
                printf("| %-15s | %s.%d.%d.%d |\n", subnets[i].name, subnets[i].broadcast, k, k, k);
                subnets[i].size--;
            }
        }
    }

    return 0;
}