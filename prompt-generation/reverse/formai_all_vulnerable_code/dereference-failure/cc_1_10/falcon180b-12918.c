//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 4

typedef struct {
    char address[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_SIZE];
    int num_hosts;
    int num_subnets;
} Subnet;

void print_subnet(Subnet *subnet) {
    printf("Address: %s\n", subnet->address);
    printf("Mask: %s\n", subnet->mask);
    printf("Number of hosts: %d\n", subnet->num_hosts);
    printf("Number of subnets: %d\n\n", subnet->num_subnets);
}

void calculate_subnets(int num_hosts, int num_subnets, Subnet *subnets) {
    int i, j;
    char mask[MAX_SUBNET_MASK_SIZE];
    for (i = 0; i < num_subnets; i++) {
        sprintf(mask, "%d", num_hosts - (num_subnets - i - 1) * 2);
        strcpy(subnets[i].address, "192.168.1.0");
        strcpy(subnets[i].mask, mask);
        subnets[i].num_hosts = num_hosts;
        subnets[i].num_subnets = num_subnets;
    }
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage: %s <IP address> <subnet mask> <number of hosts>\n", argv[0]);
        return 1;
    }

    char ip_address[MAX_SUBNET_SIZE];
    char subnet_mask[MAX_SUBNET_MASK_SIZE];
    int num_hosts;

    strcpy(ip_address, argv[1]);
    strcpy(subnet_mask, argv[2]);
    num_hosts = atoi(argv[3]);

    Subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    calculate_subnets(num_hosts, num_subnets, subnets);

    printf("Subnet 1:\n");
    print_subnet(&subnets[0]);

    return 0;
}