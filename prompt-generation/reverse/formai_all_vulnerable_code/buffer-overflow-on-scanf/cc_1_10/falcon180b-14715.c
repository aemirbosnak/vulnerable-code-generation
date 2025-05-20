//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 256
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_COUNT 256

typedef struct {
    char name[32];
    unsigned int subnet_size;
    unsigned int subnet_count;
} subnet_t;

subnet_t subnets[MAX_SUBNETS];

int main() {
    int num_subnets = 0;
    char input[256];

    printf("Enter subnet name (or 'done' to finish): ");
    scanf("%s", input);

    while (strcmp(input, "done")!= 0) {
        if (num_subnets >= MAX_SUBNETS) {
            printf("Maximum number of subnets reached.\n");
            exit(1);
        }

        printf("Enter subnet size (1-32): ");
        scanf("%d", &subnets[num_subnets].subnet_size);

        printf("Enter subnet count: ");
        scanf("%d", &subnets[num_subnets].subnet_count);

        strncpy(subnets[num_subnets].name, input, sizeof(subnets[num_subnets].name));
        num_subnets++;

        printf("Enter subnet name (or 'done' to finish): ");
        scanf("%s", input);
    }

    printf("\nSubnet Configuration:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d: %s\n", i+1, subnets[i].name);
        printf("  Subnet Size: %d\n", subnets[i].subnet_size);
        printf("  Subnet Count: %d\n", subnets[i].subnet_count);
        printf("\n");
    }

    return 0;
}