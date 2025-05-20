//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_NAME_LEN 20
#define MAX_SUBNET_IP_LEN 16
#define MAX_SUBNET_MASK_LEN 16

typedef struct {
    char name[MAX_SUBNET_NAME_LEN];
    char ip[MAX_SUBNET_IP_LEN];
    char mask[MAX_SUBNET_MASK_LEN];
} subnet_t;

int num_subnets = 0;
subnet_t subnets[MAX_SUBNETS];

void add_subnet() {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    printf("Enter subnet name (max %d characters): ", MAX_SUBNET_NAME_LEN - 1);
    scanf("%s", subnets[num_subnets].name);

    printf("Enter subnet IP address: ");
    scanf("%s", subnets[num_subnets].ip);

    printf("Enter subnet mask: ");
    scanf("%s", subnets[num_subnets].mask);

    num_subnets++;
}

void print_subnets() {
    if (num_subnets == 0) {
        printf("No subnets found.\n");
        return;
    }

    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s (%s) %s\n", subnets[i].name, subnets[i].ip, subnets[i].mask);
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