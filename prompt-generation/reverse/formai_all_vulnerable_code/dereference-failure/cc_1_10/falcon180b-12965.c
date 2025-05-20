//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32
#define MAX_SUBNET_NAME 32

typedef struct {
    char name[MAX_SUBNET_NAME];
    char mask[MAX_SUBNET_MASK];
    int size;
} Subnet;

int num_subnets = 0;
Subnet subnets[MAX_SUBNETS];

void add_subnet(char* name, char* mask, int size) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strncpy(subnets[num_subnets].name, name, MAX_SUBNET_NAME);
    strncpy(subnets[num_subnets].mask, mask, MAX_SUBNET_MASK);
    subnets[num_subnets].size = size;

    num_subnets++;
}

int main() {
    char input[1024];
    char* token;
    int i;

    printf("Welcome to the Subnet Calculator!\n");

    while (fgets(input, sizeof(input), stdin)) {
        token = strtok(input, " ");

        if (strcmp(token, "add") == 0) {
            token = strtok(NULL, " ");
            add_subnet(token, "255.255.255.0", 24);
        } else if (strcmp(token, "list") == 0) {
            for (i = 0; i < num_subnets; i++) {
                printf("Subnet %d:\n", i+1);
                printf("Name: %s\n", subnets[i].name);
                printf("Mask: %s\n", subnets[i].mask);
                printf("Size: %d\n\n", subnets[i].size);
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}