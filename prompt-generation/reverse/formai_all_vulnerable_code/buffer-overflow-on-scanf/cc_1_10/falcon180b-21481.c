//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32

typedef struct {
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_SIZE];
    char subnet[MAX_SUBNET_SIZE];
} subnet_t;

void generate_subnets(subnet_t *subnets, int num_subnets, char *ip, char *mask) {
    int i, j;
    for (i = 0; i < num_subnets; i++) {
        strcpy(subnets[i].ip, ip);
        strcpy(subnets[i].mask, mask);
        for (j = 0; j < strlen(subnets[i].mask); j++) {
            if (subnets[i].mask[j] == '1') {
                subnets[i].subnet[j] = '0';
            } else {
                subnets[i].subnet[j] = '1';
            }
        }
        subnets[i].subnet[strlen(subnets[i].mask)] = '\0';
    }
}

int main() {
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_SIZE];
    int num_subnets;

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter subnet mask: ");
    scanf("%s", mask);

    num_subnets = atoi(mask) - 1;

    subnet_t subnets[MAX_SUBNETS];
    generate_subnets(subnets, num_subnets, ip, mask);

    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\n", subnets[i].subnet);
    }

    return 0;
}