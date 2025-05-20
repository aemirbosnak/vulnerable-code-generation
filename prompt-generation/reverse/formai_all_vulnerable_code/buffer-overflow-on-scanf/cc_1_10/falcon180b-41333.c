//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[32];
    char ip[16];
    char mask[16];
    char gateway[16];
    int size;
} subnet_t;

int num_subnets = 0;
subnet_t subnets[MAX_SUBNETS];

void add_subnet() {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        exit(1);
    }

    printf("Enter subnet name: ");
    scanf("%s", subnets[num_subnets].name);

    printf("Enter subnet IP address: ");
    scanf("%s", subnets[num_subnets].ip);

    printf("Enter subnet mask: ");
    scanf("%s", subnets[num_subnets].mask);

    printf("Enter subnet gateway: ");
    scanf("%s", subnets[num_subnets].gateway);

    printf("Enter subnet size (1-32): ");
    scanf("%d", &subnets[num_subnets].size);

    num_subnets++;
}

int main() {
    printf("Subnet Calculator\n");

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
            printf("Subnets:\n");
            for (int i = 0; i < num_subnets; i++) {
                printf("%s (%s/%d)\n", subnets[i].name, subnets[i].ip, subnets[i].size);
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}