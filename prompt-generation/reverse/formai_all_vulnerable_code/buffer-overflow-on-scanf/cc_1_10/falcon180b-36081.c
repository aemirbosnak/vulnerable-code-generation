//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK];
    int num_hosts;
} subnet_t;

int num_subnets = 0;
subnet_t subnets[MAX_SUBNETS];

int add_subnet(char *name, char *mask) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached\n");
        return -1;
    }

    strncpy(subnets[num_subnets].name, name, MAX_SUBNET_SIZE);
    strncpy(subnets[num_subnets].mask, mask, MAX_SUBNET_MASK);

    int num_ones = 0;
    for (int i = 0; i < strlen(mask); i++) {
        if (mask[i] == '1') {
            num_ones++;
        }
    }

    subnets[num_subnets].num_hosts = pow(2, num_ones) - 2;

    num_subnets++;

    return 0;
}

int main() {
    char input[MAX_SUBNET_SIZE + MAX_SUBNET_MASK + 1];
    printf("Enter subnet name and mask (e.g. 192.168.0.0/24): ");
    scanf("%s", input);

    char *name = strtok(input, "/");
    char *mask = strtok(NULL, "/");

    add_subnet(name, mask);

    printf("Subnet Name\tSubnet Mask\tNumber of Hosts\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\t%s\t%d\n", subnets[i].name, subnets[i].mask, subnets[i].num_hosts);
    }

    return 0;
}