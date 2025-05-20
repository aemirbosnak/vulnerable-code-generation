//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32
#define MAX_SUBNET_VALUE 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK];
    char value[MAX_SUBNET_VALUE];
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

    printf("Enter subnet mask in CIDR notation: ");
    scanf("%s", subnets[num_subnets].mask);

    if (strlen(subnets[num_subnets].mask) > MAX_SUBNET_MASK) {
        printf("Error: Subnet mask is too long.\n");
        return;
    }

    printf("Enter subnet value in decimal: ");
    scanf("%s", subnets[num_subnets].value);

    if (strlen(subnets[num_subnets].value) > MAX_SUBNET_VALUE) {
        printf("Error: Subnet value is too long.\n");
        return;
    }

    num_subnets++;
}

void display_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s (%s) = %s\n", subnets[i].name, subnets[i].mask, subnets[i].value);
    }
}

int main() {
    printf("Welcome to the Subnet Calculator!\n");

    while (1) {
        printf("\n");
        printf("1. Add subnet\n");
        printf("2. Display subnets\n");
        printf("3. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_subnet();
            break;
        case 2:
            display_subnets();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}