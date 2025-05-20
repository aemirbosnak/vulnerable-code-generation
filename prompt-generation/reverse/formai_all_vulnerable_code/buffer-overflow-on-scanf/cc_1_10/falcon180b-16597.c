//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 32
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 16

typedef struct {
    char name[32];
    int size;
    int mask;
} subnet_t;

int main() {
    int num_subnets;
    subnet_t subnets[MAX_SUBNETS];
    char input[1024];

    // Prompt user for number of subnets
    printf("Enter number of subnets: ");
    scanf("%d", &num_subnets);

    // Read subnet information from user
    for (int i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d name: ", i+1);
        scanf("%s", subnets[i].name);
        printf("Enter subnet %d size: ", i+1);
        scanf("%d", &subnets[i].size);
        printf("Enter subnet %d mask: ", i+1);
        scanf("%d", &subnets[i].mask);
    }

    // Calculate subnet masks
    for (int i = 0; i < num_subnets; i++) {
        int mask_size = subnets[i].mask;
        char mask[MAX_SUBNET_MASK_SIZE];
        int j;

        for (j = 0; j < mask_size; j++) {
            mask[j] = '1';
        }

        for (; j < MAX_SUBNET_MASK_SIZE; j++) {
            mask[j] = '0';
        }

        subnets[i].mask = strtoul(mask, NULL, 2);
    }

    // Print subnet information
    printf("Subnet information:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d: %s, size %d, mask %d\n", i+1, subnets[i].name, subnets[i].size, subnets[i].mask);
    }

    return 0;
}