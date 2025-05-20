//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_NAME_LENGTH 64
#define MAX_SUBNET_VALUE_LENGTH 16

typedef struct {
    char name[MAX_SUBNET_NAME_LENGTH];
    char value[MAX_SUBNET_VALUE_LENGTH];
    int size;
} Subnet;

int num_subnets = 0;
Subnet subnets[MAX_SUBNETS];

void add_subnet() {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    subnets[num_subnets].size = 0;
    printf("Enter subnet name: ");
    scanf("%s", subnets[num_subnets].name);

    printf("Enter subnet value (in CIDR notation): ");
    scanf("%s", subnets[num_subnets].value);

    int i;
    for (i = 0; i < strlen(subnets[num_subnets].value); i++) {
        if (!isdigit(subnets[num_subnets].value[i])) {
            printf("Error: Invalid subnet value.\n");
            return;
        }
    }

    subnets[num_subnets].size = atoi(subnets[num_subnets].value);
    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    int i;
    for (i = 0; i < num_subnets; i++) {
        printf("%s (%d)\n", subnets[i].name, subnets[i].size);
    }
}

int main() {
    printf("C Subnet Calculator\n");

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