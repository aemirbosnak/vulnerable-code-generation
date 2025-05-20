//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32

typedef struct {
    char ip[16];
    char mask[16];
    char subnet[16];
    int num_hosts;
} subnet_t;

void generate_subnets(subnet_t *subnets, int num_subnets, char *ip, char *mask) {
    for (int i = 0; i < num_subnets; i++) {
        sprintf(subnets[i].ip, "%s.%d", ip, i + 1);
        sprintf(subnets[i].mask, "%s.%d", mask, i + 1);
        sprintf(subnets[i].subnet, "%s/%d", subnets[i].ip, atoi(mask) + i + 1);
        subnets[i].num_hosts = (atoi(mask) + i + 1) * (atoi(mask) + i + 1) - 2;
    }
}

void print_subnets(subnet_t *subnets, int num_subnets) {
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i + 1);
        printf("IP: %s\n", subnets[i].ip);
        printf("Mask: %s\n", subnets[i].mask);
        printf("Subnet: %s\n", subnets[i].subnet);
        printf("Number of hosts: %d\n\n", subnets[i].num_hosts);
    }
}

int main() {
    char ip[16];
    char mask[16];

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the subnet mask: ");
    scanf("%s", mask);

    subnet_t subnets[MAX_SUBNETS];
    int num_subnets = 0;

    while (num_subnets < MAX_SUBNETS) {
        generate_subnets(subnets, num_subnets, ip, mask);
        num_subnets++;
    }

    print_subnets(subnets, num_subnets);

    return 0;
}