//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 32
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_NAME 64

typedef struct {
    char name[MAX_SUBNET_NAME];
    int size;
} Subnet;

int num_subnets = 0;
Subnet subnets[MAX_SUBNETS];

void add_subnet(char* name, int size) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    subnets[num_subnets].name[0] = '\0';
    strncat(subnets[num_subnets].name, name, MAX_SUBNET_NAME - 1);
    subnets[num_subnets].size = size;

    num_subnets++;
}

void print_subnets() {
    if (num_subnets == 0) {
        printf("No subnets defined.\n");
        return;
    }

    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("  %s (%d hosts)\n", subnets[i].name, (int)pow(2, subnets[i].size) - 2);
    }
}

int main() {
    char input[MAX_SUBNET_NAME];

    while (1) {
        printf("Enter subnet name (or type 'list' to view subnets): ");
        scanf("%s", input);

        if (strcmp(input, "list") == 0) {
            print_subnets();
        } else {
            int size = 0;
            while (size <= 0 || size > 32) {
                printf("Enter subnet size (1-32): ");
                scanf("%d", &size);

                if (size <= 0 || size > 32) {
                    printf("Invalid size. Please enter a value between 1 and 32.\n");
                }
            }

            add_subnet(input, size);
        }
    }

    return 0;
}