//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_SIZE];
} Subnet;

int num_subnets = 0;
Subnet subnets[MAX_SUBNETS];

void add_subnet() {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    printf("Enter subnet name: ");
    scanf("%s", subnets[num_subnets].name);

    printf("Enter subnet IP: ");
    scanf("%s", subnets[num_subnets].ip);

    printf("Enter subnet mask: ");
    scanf("%s", subnets[num_subnets].mask);

    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s (%s) - %s\n", subnets[i].name, subnets[i].ip, subnets[i].mask);
    }
}

int main() {
    int choice;
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_SIZE];

    do {
        printf("\nSubnet Calculator\n");
        printf("1. Add subnet\n");
        printf("2. Print subnets\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_subnet();
                break;
            case 2:
                print_subnets();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}