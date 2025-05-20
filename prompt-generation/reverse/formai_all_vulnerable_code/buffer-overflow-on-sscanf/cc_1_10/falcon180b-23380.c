//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char netmask[MAX_SUBNET_SIZE];
    int num_hosts;
} Subnet;

Subnet subnets[MAX_SUBNETS];
int num_subnets = 0;

void add_subnet(char *name, char *netmask, int num_hosts) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strcpy(subnets[num_subnets].name, name);
    strcpy(subnets[num_subnets].netmask, netmask);
    subnets[num_subnets].num_hosts = num_hosts;

    num_subnets++;
}

int main() {
    char input[1024];
    char name[MAX_SUBNET_SIZE];
    char netmask[MAX_SUBNET_SIZE];
    int num_hosts;

    printf("Enter subnet information (name netmask num_hosts):\n");
    fgets(input, sizeof(input), stdin);

    sscanf(input, "%s %s %d", name, netmask, &num_hosts);

    add_subnet(name, netmask, num_hosts);

    printf("Subnet information:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Name: %s\n", subnets[i].name);
        printf("Netmask: %s\n", subnets[i].netmask);
        printf("Number of hosts: %d\n\n", subnets[i].num_hosts);
    }

    return 0;
}