//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_LENGTH 32

struct subnet {
    char name[MAX_SUBNET_SIZE];
    int size;
    int mask_length;
    char mask[MAX_SUBNET_MASK_LENGTH];
};

int main() {
    int num_subnets;
    struct subnet subnets[MAX_SUBNETS];
    char input[MAX_SUBNET_SIZE];
    char mask_input[MAX_SUBNET_MASK_LENGTH];
    int i;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the size of subnet %d: ", i+1);
        scanf("%d", &subnets[i].size);

        printf("Enter the mask length of subnet %d: ", i+1);
        scanf("%d", &subnets[i].mask_length);

        printf("Enter the mask of subnet %d: ", i+1);
        scanf("%s", mask_input);
        strncpy(subnets[i].mask, mask_input, MAX_SUBNET_MASK_LENGTH);
    }

    printf("\nSubnet Calculator Results:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("Name: %s\n", subnets[i].name);
        printf("Size: %d\n", subnets[i].size);
        printf("Mask Length: %d\n", subnets[i].mask_length);
        printf("Mask: %s\n", subnets[i].mask);
        printf("\n");
    }

    return 0;
}