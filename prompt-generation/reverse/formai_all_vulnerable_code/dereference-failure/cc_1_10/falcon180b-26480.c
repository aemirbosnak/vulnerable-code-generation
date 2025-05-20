//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 32
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[32];
    int size;
    int subnet_mask;
} subnet_t;

subnet_t subnets[MAX_SUBNETS];
int num_subnets = 0;

void add_subnet(char* name, int size, int subnet_mask) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strncpy(subnets[num_subnets].name, name, 32);
    subnets[num_subnets].size = size;
    subnets[num_subnets].subnet_mask = subnet_mask;

    num_subnets++;
}

void print_subnets() {
    printf("\nSubnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s (%d hosts) - %d.%d.%d.%d\n", subnets[i].name, subnets[i].size,
            (subnets[i].subnet_mask >> 24) & 0xff,
            (subnets[i].subnet_mask >> 16) & 0xff,
            (subnets[i].subnet_mask >> 8) & 0xff,
            subnets[i].subnet_mask & 0xff);
    }
}

int main() {
    char input[1024];
    char* token;
    int size = 0;
    int subnet_mask = 0;

    printf("Enter subnet name: ");
    fgets(input, sizeof(input), stdin);
    token = strtok(input, " ");
    strncpy(subnets[num_subnets].name, token, 32);

    printf("Enter subnet size (1-32): ");
    fgets(input, sizeof(input), stdin);
    size = atoi(input);

    if (size < 1 || size > 32) {
        printf("Error: Invalid subnet size.\n");
        return 1;
    }

    if (size == 32) {
        subnet_mask = 0;
    } else {
        subnet_mask = 0xffffffff << (32 - size);
    }

    add_subnet(subnets[num_subnets].name, size, subnet_mask);

    printf("Subnet added successfully.\n");
    print_subnets();

    return 0;
}