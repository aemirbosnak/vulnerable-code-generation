//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 100
#define MAX_IP_LENGTH 16
#define MAX_SUBNET_NAME_LENGTH 50

typedef struct {
    char name[MAX_SUBNET_NAME_LENGTH];
    char ip[MAX_IP_LENGTH];
    char mask[MAX_IP_LENGTH];
    int size;
} subnet_t;

int main() {
    int num_subnets = 0;
    subnet_t subnets[MAX_SUBNETS];

    while (num_subnets < MAX_SUBNETS) {
        printf("Enter subnet name (leave blank to finish): ");
        char name[MAX_SUBNET_NAME_LENGTH];
        scanf("%s", name);

        if (name[0] == '\0') {
            break;
        }

        printf("Enter subnet IP address: ");
        char ip[MAX_IP_LENGTH];
        scanf("%s", ip);

        printf("Enter subnet mask: ");
        char mask[MAX_IP_LENGTH];
        scanf("%s", mask);

        int size = atoi(mask);

        if (size <= 0 || size > 32) {
            printf("Invalid subnet mask\n");
            continue;
        }

        strcpy(subnets[num_subnets].name, name);
        strcpy(subnets[num_subnets].ip, ip);
        strcpy(subnets[num_subnets].mask, mask);
        subnets[num_subnets].size = size;

        num_subnets++;
    }

    printf("Subnet list:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\t%s/%d\n", subnets[i].name, subnets[i].ip, subnets[i].size);
    }

    return 0;
}