//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

struct subnet {
    char name[MAX_SUBNET_SIZE];
    int size;
    char mask[MAX_SUBNET_MASK];
};

int num_subnets = 0;
struct subnet subnets[MAX_SUBNETS];

void add_subnet(char *name, int size, char *mask) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strncpy(subnets[num_subnets].name, name, MAX_SUBNET_SIZE);
    subnets[num_subnets].size = size;
    strncpy(subnets[num_subnets].mask, mask, MAX_SUBNET_MASK);

    num_subnets++;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    char ip[16];
    strncpy(ip, argv[1], 16);

    int i = 0;
    while (i < strlen(ip) && ip[i]!= '.') {
        i++;
    }

    int subnet_size = atoi(ip + i + 1);
    char subnet_mask[MAX_SUBNET_MASK];

    sprintf(subnet_mask, "255.%s.%s.%s", ip[i + 1], ip[i + 2], ip[i + 3]);

    add_subnet(ip, subnet_size, subnet_mask);

    return 0;
}