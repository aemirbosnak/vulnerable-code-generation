//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK];
    int num_hosts;
    int num_subnets;
} subnet_t;

void calculate_subnets(int num_bits, int num_hosts, int *num_subnets) {
    *num_subnets = 1;
    while ((1 << num_bits) < num_hosts) {
        (*num_subnets)++;
        num_bits++;
    }
}

void print_subnet_info(subnet_t *subnet) {
    printf("Subnet Name: %s\n", subnet->name);
    printf("Subnet Mask: %s\n", subnet->mask);
    printf("Number of Hosts: %d\n", subnet->num_hosts);
    printf("Number of Subnets: %d\n\n", subnet->num_subnets);
}

int main() {
    int i, j, k, num_subnets = 0;
    char input_ip[MAX_SUBNET_SIZE];
    char input_mask[MAX_SUBNET_MASK];
    subnet_t subnets[MAX_SUBNETS];

    printf("Enter IP Address: ");
    scanf("%s", input_ip);

    printf("Enter Subnet Mask: ");
    scanf("%s", input_mask);

    for (i = 0; i < strlen(input_mask); i++) {
        if (input_mask[i] == '.') {
            input_mask[i] = '\0';
        }
    }

    for (i = 0; i < strlen(input_ip); i++) {
        if (input_ip[i] == '.') {
            input_ip[i] = '\0';
        }
    }

    strcpy(subnets[num_subnets].name, input_ip);
    strcpy(subnets[num_subnets].mask, input_mask);

    calculate_subnets(strlen(input_mask), 1, &subnets[num_subnets].num_hosts);
    subnets[num_subnets].num_subnets = 1;

    num_subnets++;

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        print_subnet_info(&subnets[i]);
    }

    return 0;
}