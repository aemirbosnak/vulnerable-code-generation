//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define IP_SIZE 16

typedef struct {
    char *name;
    int num_subnets;
    int subnet_size;
    char *subnets[MAX_SUBNETS];
} Subnet;

void init_subnet(Subnet *subnet) {
    subnet->name = NULL;
    subnet->num_subnets = 0;
    subnet->subnet_size = 0;
    for (int i = 0; i < MAX_SUBNETS; i++) {
        subnet->subnets[i] = NULL;
    }
}

void add_subnet(Subnet *subnet, char *ip) {
    if (subnet->num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }
    char *subnet_ip = malloc(IP_SIZE);
    strcpy(subnet_ip, ip);
    subnet->subnets[subnet->num_subnets] = subnet_ip;
    subnet->num_subnets++;
}

int main() {
    Subnet subnet;
    init_subnet(&subnet);

    char ip[IP_SIZE];
    printf("Enter a subnet IP address: ");
    scanf("%s", ip);
    add_subnet(&subnet, ip);

    printf("Subnet name: ");
    scanf("%s", subnet.name);

    int num_subnets = subnet.num_subnets;
    printf("Number of subnets: ");
    scanf("%d", &num_subnets);
    subnet.num_subnets = num_subnets;

    printf("Subnet size: ");
    scanf("%d", &subnet.subnet_size);

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter a subnet IP address: ");
        scanf("%s", subnet.subnets[i]);
    }

    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\n", subnet.subnets[i]);
    }

    return 0;
}