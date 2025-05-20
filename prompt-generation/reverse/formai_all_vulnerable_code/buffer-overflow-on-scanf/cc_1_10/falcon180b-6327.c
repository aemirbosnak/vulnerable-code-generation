//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

typedef struct {
    char name[64];
    char ip[16];
    char mask[16];
} subnet_t;

int num_subnets = 0;
subnet_t subnets[MAX_SUBNETS];

void add_subnet() {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    subnet_t *new_subnet = &subnets[num_subnets];

    printf("Enter subnet name: ");
    scanf("%s", new_subnet->name);

    printf("Enter IP address: ");
    scanf("%s", new_subnet->ip);

    printf("Enter subnet mask: ");
    scanf("%s", new_subnet->mask);

    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s - %s/%s\n", subnets[i].name, subnets[i].ip, subnets[i].mask);
    }
}

int main() {
    printf("Cyberpunk Subnet Calculator\n");

    while (1) {
        printf("\n");
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