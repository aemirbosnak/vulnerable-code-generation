//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_IP_LENGTH 15

typedef struct {
    char ip[MAX_IP_LENGTH];
    char mask[MAX_IP_LENGTH];
    char subnet[MAX_IP_LENGTH];
    int num_hosts;
} Subnet;

void print_subnet(Subnet *subnet) {
    printf("IP Address: %s\n", subnet->ip);
    printf("Subnet Mask: %s\n", subnet->mask);
    printf("Subnet: %s\n", subnet->subnet);
    printf("Number of Hosts: %d\n", subnet->num_hosts);
    printf("\n");
}

int main() {
    int num_subnets, i;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the IP address for subnet %d: ", i+1);
        scanf("%s", subnets[i].ip);

        printf("Enter the subnet mask for subnet %d: ", i+1);
        scanf("%s", subnets[i].mask);

        strcpy(subnets[i].subnet, subnets[i].ip);
        strcat(subnets[i].subnet, "/");
        strcat(subnets[i].subnet, subnets[i].mask);

        subnets[i].num_hosts = (int)pow(2, (int)strlen(subnets[i].mask) - (int)strlen(subnets[i].mask) % 8) - 2;
    }

    printf("\n");
    printf("Subnet  IP Address  Subnet Mask  Number of Hosts\n");
    printf("--------------------------------------------------------\n");

    for (i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}