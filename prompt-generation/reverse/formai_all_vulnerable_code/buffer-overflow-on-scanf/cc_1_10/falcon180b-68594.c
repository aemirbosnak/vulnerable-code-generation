//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_IP_SIZE 16

typedef struct {
    char *name;
    char *ip;
    char *subnet_mask;
    int num_hosts;
} subnet_t;

int main() {
    int num_subnets = 0;
    subnet_t subnets[MAX_SUBNETS];

    while (num_subnets < MAX_SUBNETS) {
        printf("Enter subnet name: ");
        char name[MAX_IP_SIZE];
        scanf("%s", name);

        printf("Enter IP address: ");
        char ip[MAX_IP_SIZE];
        scanf("%s", ip);

        printf("Enter subnet mask: ");
        char subnet_mask[MAX_IP_SIZE];
        scanf("%s", subnet_mask);

        printf("Enter number of hosts: ");
        int num_hosts;
        scanf("%d", &num_hosts);

        subnet_t *s = &subnets[num_subnets];
        s->name = strdup(name);
        s->ip = strdup(ip);
        s->subnet_mask = strdup(subnet_mask);
        s->num_hosts = num_hosts;

        num_subnets++;
    }

    printf("\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("Name: %s\n", subnets[i].name);
        printf("IP: %s\n", subnets[i].ip);
        printf("Subnet Mask: %s\n", subnets[i].subnet_mask);
        printf("Number of Hosts: %d\n\n", subnets[i].num_hosts);
    }

    return 0;
}