//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 32

typedef struct subnet {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_SIZE];
    int num_hosts;
} subnet_t;

int num_subnets = 0;
subnet_t subnets[MAX_SUBNETS];

void add_subnet(char* name, char* mask, int num_hosts) {
    if (num_subnets == MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }
    strncpy(subnets[num_subnets].name, name, MAX_SUBNET_SIZE);
    strncpy(subnets[num_subnets].mask, mask, MAX_SUBNET_MASK_SIZE);
    subnets[num_subnets].num_hosts = num_hosts;
    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Name: %s\nMask: %s\nNumber of Hosts: %d\n", subnets[i].name, subnets[i].mask, subnets[i].num_hosts);
    }
}

int main() {
    char input[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_SIZE];
    int num_hosts;
    int i;

    printf("Enter the subnet name (up to %d characters): ", MAX_SUBNET_SIZE-1);
    fgets(input, MAX_SUBNET_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character

    printf("Enter the subnet mask (up to %d characters): ", MAX_SUBNET_MASK_SIZE-1);
    fgets(mask, MAX_SUBNET_MASK_SIZE, stdin);
    mask[strcspn(mask, "\n")] = '\0'; // remove newline character

    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    add_subnet(input, mask, num_hosts);
    print_subnets();

    return 0;
}