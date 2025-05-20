//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define IP_LEN 4
#define SUBNET_LEN 2

typedef struct {
    char ip[IP_LEN];
    char subnet[SUBNET_LEN];
    char broadcast[IP_LEN];
    int num_hosts;
} Subnet;

void print_subnet(Subnet *subnet) {
    printf("IP: %s\n", subnet->ip);
    printf("Subnet: %s\n", subnet->subnet);
    printf("Broadcast: %s\n", subnet->broadcast);
    printf("Number of hosts: %d\n\n", subnet->num_hosts);
}

int main() {
    int num_subnets, i;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter IP address for subnet %d: ", i + 1);
        scanf("%s", subnets[i].ip);

        subnets[i].num_hosts = 0;
        subnets[i].subnet[0] = 192;
        subnets[i].subnet[1] = 168;
        subnets[i].subnet[2] = 0;
        strcat(subnets[i].subnet, subnets[i].ip);
        strcat(subnets[i].subnet, ".0");

        subnets[i].broadcast[0] = '.';
        subnets[i].broadcast[1] = '.';
        subnets[i].broadcast[2] = '.';
        subnets[i].broadcast[3] = '.';
        strcat(subnets[i].broadcast, subnets[i].ip);
        strcat(subnets[i].broadcast, ".255");
    }

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i + 1);
        print_subnet(&subnets[i]);
    }

    return 0;
}