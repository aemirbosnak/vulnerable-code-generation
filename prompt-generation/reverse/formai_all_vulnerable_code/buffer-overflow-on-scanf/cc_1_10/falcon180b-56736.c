//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_NAME 32

typedef struct {
    char name[MAX_SUBNET_NAME];
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_SIZE];
    int num_hosts;
} subnet_t;

int num_subnets = 0;
subnet_t subnets[MAX_SUBNETS];

void add_subnet() {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    subnet_t new_subnet;
    strcpy(new_subnet.name, "");
    strcpy(new_subnet.ip, "");
    strcpy(new_subnet.mask, "");
    new_subnet.num_hosts = 0;

    subnets[num_subnets] = new_subnet;
    num_subnets++;
}

void remove_subnet(int index) {
    if (index >= num_subnets || index < 0) {
        printf("Error: Invalid subnet index.\n");
        return;
    }

    num_subnets--;
    for (int i = index; i < num_subnets; i++) {
        subnets[i] = subnets[i + 1];
    }
}

void print_subnets() {
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i + 1);
        printf("  Name: %s\n", subnets[i].name);
        printf("  IP Address: %s\n", subnets[i].ip);
        printf("  Subnet Mask: %s\n", subnets[i].mask);
        printf("  Number of Hosts: %d\n\n", subnets[i].num_hosts);
    }
}

int main() {
    int choice;

    do {
        printf("C Subnet Calculator\n");
        printf("1. Add Subnet\n");
        printf("2. Remove Subnet\n");
        printf("3. Print Subnets\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_subnet();
            break;
        case 2:
            printf("Enter subnet index to remove: ");
            int index;
            scanf("%d", &index);
            remove_subnet(index);
            break;
        case 3:
            print_subnets();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}