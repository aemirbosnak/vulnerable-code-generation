//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32

typedef struct subnet {
    char name[MAX_SUBNET_SIZE];
    char ip[16];
    char mask[16];
    int size;
} subnet_t;

subnet_t subnets[MAX_SUBNETS];
int num_subnets = 0;

void add_subnet() {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    printf("Enter subnet name: ");
    scanf("%s", subnets[num_subnets].name);

    printf("Enter subnet IP address: ");
    scanf("%s", subnets[num_subnets].ip);

    printf("Enter subnet mask: ");
    scanf("%s", subnets[num_subnets].mask);

    subnets[num_subnets].size = atoi(subnets[num_subnets].mask);
    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Name: %s\n", subnets[i].name);
        printf("IP Address: %s\n", subnets[i].ip);
        printf("Mask: %s\n", subnets[i].mask);
        printf("Size: %d\n\n", subnets[i].size);
    }
}

int main() {
    printf("Subnet Calculator\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add subnet\n");
        printf("2. Print subnets\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_subnet();
            break;
        case 2:
            print_subnets();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}