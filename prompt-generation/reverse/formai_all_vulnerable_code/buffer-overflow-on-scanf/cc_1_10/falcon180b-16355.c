//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char subnet[MAX_SUBNET_MASK];
    char mask[MAX_SUBNET_MASK];
    int num_hosts;
} subnet_t;

subnet_t subnets[MAX_SUBNETS];
int num_subnets = 0;

void add_subnet() {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    subnet_t subnet;
    memset(&subnet, 0, sizeof(subnet_t));

    printf("Enter subnet name: ");
    scanf("%s", subnet.name);

    printf("Enter subnet IP address: ");
    scanf("%s", subnet.subnet);

    printf("Enter subnet mask: ");
    scanf("%s", subnet.mask);

    subnet.num_hosts = 0;
    for (int i = 0; i < strlen(subnet.mask); i++) {
        if (subnet.mask[i] == '0') {
            subnet.num_hosts++;
        }
    }

    subnets[num_subnets++] = subnet;

    printf("Subnet added successfully!\n");
}

void delete_subnet() {
    if (num_subnets == 0) {
        printf("Error: No subnets to delete.\n");
        return;
    }

    int index;
    printf("Enter subnet index to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_subnets) {
        printf("Error: Invalid subnet index.\n");
        return;
    }

    num_subnets--;
    for (int i = index; i < num_subnets; i++) {
        subnets[i] = subnets[i+1];
    }

    printf("Subnet deleted successfully!\n");
}

void list_subnets() {
    if (num_subnets == 0) {
        printf("No subnets found.\n");
        return;
    }

    for (int i = 0; i < num_subnets; i++) {
        printf("%d. %s (%s) - %d hosts\n", i+1, subnets[i].name, subnets[i].subnet, subnets[i].num_hosts);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add subnet\n2. Delete subnet\n3. List subnets\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_subnet();
                break;
            case 2:
                delete_subnet();
                break;
            case 3:
                list_subnets();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}