//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASKS 32
#define MAX_SUBNET_ROUTES 32

typedef struct {
    char name[32];
    char mask[32];
    char route[32];
} subnet_t;

subnet_t subnets[MAX_SUBNETS];
int num_subnets = 0;

void add_subnet(char* name, char* mask, char* route) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strncpy(subnets[num_subnets].name, name, 32);
    strncpy(subnets[num_subnets].mask, mask, 32);
    strncpy(subnets[num_subnets].route, route, 32);

    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Name: %s\n", subnets[i].name);
        printf("Mask: %s\n", subnets[i].mask);
        printf("Route: %s\n", subnets[i].route);
        printf("\n");
    }
}

int main() {
    char input[MAX_SUBNET_MASKS];
    int i, j;

    printf("Enter subnet mask (in dotted decimal format): ");
    scanf("%s", input);

    for (i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            printf("Error: Invalid subnet mask.\n");
            return 1;
        }
    }

    for (i = 0; i < MAX_SUBNETS; i++) {
        printf("Enter subnet name: ");
        scanf("%s", subnets[i].name);

        printf("Enter subnet mask (in dotted decimal format): ");
        scanf("%s", subnets[i].mask);

        if (strlen(subnets[i].mask)!= 8) {
            printf("Error: Invalid subnet mask.\n");
            return 1;
        }

        for (j = 0; j < strlen(subnets[i].mask); j++) {
            if (!isdigit(subnets[i].mask[j])) {
                printf("Error: Invalid subnet mask.\n");
                return 1;
            }
        }

        printf("Enter subnet route: ");
        scanf("%s", subnets[i].route);

        if (strlen(subnets[i].route)!= 8) {
            printf("Error: Invalid subnet route.\n");
            return 1;
        }

        for (j = 0; j < strlen(subnets[i].route); j++) {
            if (!isdigit(subnets[i].route[j])) {
                printf("Error: Invalid subnet route.\n");
                return 1;
            }
        }
    }

    printf("Subnets added successfully.\n");

    print_subnets();

    return 0;
}