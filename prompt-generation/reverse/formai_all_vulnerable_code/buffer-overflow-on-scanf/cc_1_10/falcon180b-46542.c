//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 1000
#define MAX_SUBNET_MASK_SIZE 20

typedef struct {
    char *name;
    int size;
    char mask[MAX_SUBNET_MASK_SIZE];
} Subnet;

void add_subnet(Subnet *subnets, int num_subnets, char *name, int size, char *mask) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    subnets[num_subnets].name = strdup(name);
    subnets[num_subnets].size = size;
    strncpy(subnets[num_subnets].mask, mask, MAX_SUBNET_MASK_SIZE);

    num_subnets++;
}

void print_subnets(Subnet *subnets, int num_subnets) {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("  %s (%d hosts)\n", subnets[i].name, (int)pow(2, (double)subnets[i].size) - 2);
    }
}

int main() {
    Subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    char input[MAX_SUBNET_MASK_SIZE];
    while (1) {
        printf("Enter a subnet mask (e.g. 255.255.255.0) or type 'done' to finish:\n");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        char *token = strtok(input, ".");
        if (token == NULL) {
            printf("Error: Invalid subnet mask.\n");
            continue;
        }

        int size = 0;
        while (token!= NULL) {
            int value = atoi(token);
            if (value < 0 || value > 255) {
                printf("Error: Invalid subnet mask.\n");
                return 1;
            }

            size += value;
            token = strtok(NULL, ".");
        }

        char name[MAX_SUBNET_MASK_SIZE];
        sprintf(name, "Subnet %d", num_subnets + 1);
        add_subnet(subnets, num_subnets, name, size, input);

        num_subnets++;
    }

    print_subnets(subnets, num_subnets);

    return 0;
}