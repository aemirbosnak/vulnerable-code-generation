//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[MAX_SUBNETS][MAX_SUBNET_SIZE];
    char mask[MAX_SUBNETS][MAX_SUBNET_MASK];
    int num_subnets;
} Subnet;

void generate_subnet_mask(char mask[], int mask_size) {
    int i;
    for (i = 0; i < mask_size; i++) {
        mask[i] = '1';
    }
    mask[i] = '\0';
}

void generate_subnet_names(Subnet subnet) {
    int i;
    for (i = 0; i < subnet.num_subnets; i++) {
        sprintf(subnet.name[i], "Subnet %d", i+1);
    }
}

int main() {
    Subnet subnet;
    int num_subnets, mask_size;
    char input[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK];

    printf("Enter the IP address: ");
    scanf("%s", input);

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    printf("Enter the subnet mask size (1-32): ");
    scanf("%d", &mask_size);

    generate_subnet_mask(mask, mask_size);

    printf("Enter the subnet mask: ");
    scanf("%s", mask);

    generate_subnet_names(subnet);

    printf("Subnet Name\tSubnet Mask\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\t\t%s\n", subnet.name[i], subnet.mask[i]);
    }

    return 0;
}