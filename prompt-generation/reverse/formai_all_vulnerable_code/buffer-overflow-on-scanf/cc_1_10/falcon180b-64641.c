//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_NAME 64

typedef struct {
    char name[MAX_SUBNET_NAME];
    char address[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_SIZE];
    int size;
} subnet_t;

void add_subnet(subnet_t *subnets, int count, char *name, char *address, char *mask, int size) {
    if (count >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strncpy(subnets[count].name, name, MAX_SUBNET_NAME);
    strncpy(subnets[count].address, address, MAX_SUBNET_SIZE);
    strncpy(subnets[count].mask, mask, MAX_SUBNET_SIZE);
    subnets[count].size = size;

    count++;
}

void print_subnets(subnet_t *subnets, int count) {
    printf("Subnets:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", subnets[i].name);
        printf("Address: %s\n", subnets[i].address);
        printf("Mask: %s\n", subnets[i].mask);
        printf("Size: %d\n\n", subnets[i].size);
    }
}

int main() {
    subnet_t subnets[MAX_SUBNETS];
    int count = 0;

    printf("Enter subnet information:\n");
    while (1) {
        char name[MAX_SUBNET_NAME];
        printf("Name: ");
        scanf("%s", name);

        char address[MAX_SUBNET_SIZE];
        printf("Address: ");
        scanf("%s", address);

        char mask[MAX_SUBNET_SIZE];
        printf("Mask: ");
        scanf("%s", mask);

        int size;
        printf("Size: ");
        scanf("%d", &size);

        add_subnet(subnets, count, name, address, mask, size);

        char choice;
        printf("\nDo you want to add another subnet? (y/n): ");
        scanf(" %c", &choice);

        if (choice!= 'y') {
            break;
        }

        count++;
    }

    print_subnets(subnets, count);

    return 0;
}