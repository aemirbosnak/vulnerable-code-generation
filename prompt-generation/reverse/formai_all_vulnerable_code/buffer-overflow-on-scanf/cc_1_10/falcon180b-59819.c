//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>

#define MAX_SUBNETS 16
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 16

typedef struct {
    char name[MAX_SUBNET_MASK_SIZE];
    int size;
    char mask[MAX_SUBNET_MASK_SIZE];
} subnet;

subnet subnets[MAX_SUBNETS];
int num_subnets = 0;

void add_subnet() {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    printf("Enter the subnet name: ");
    scanf("%s", subnets[num_subnets].name);

    printf("Enter the subnet size: ");
    scanf("%d", &subnets[num_subnets].size);

    printf("Enter the subnet mask (in dotted decimal notation): ");
    scanf("%s", subnets[num_subnets].mask);

    num_subnets++;
}

int compare_subnets(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void print_subnets() {
    qsort(subnets, num_subnets, sizeof(subnet), compare_subnets);

    for (int i = 0; i < num_subnets; i++) {
        printf("%s (%d): %s\n", subnets[i].name, subnets[i].size, subnets[i].mask);
    }
}

int main() {
    add_subnet();
    add_subnet();
    add_subnet();

    print_subnets();

    return 0;
}