//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char ip[MAX_SUBNET_SIZE];
    char netmask[MAX_SUBNET_SIZE];
    char gateway[MAX_SUBNET_SIZE];
    int num_hosts;
} subnet_t;

int main() {
    int num_subnets;
    subnet_t subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i + 1);
        scanf("%s", subnets[i].name);

        printf("Enter the IP address of subnet %d: ", i + 1);
        scanf("%s", subnets[i].ip);

        printf("Enter the netmask of subnet %d: ", i + 1);
        scanf("%s", subnets[i].netmask);

        printf("Enter the gateway of subnet %d: ", i + 1);
        scanf("%s", subnets[i].gateway);

        printf("Enter the number of hosts in subnet %d: ", i + 1);
        scanf("%d", &subnets[i].num_hosts);
    }

    printf("\nSubnet Information:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i + 1);
        printf("Name: %s\n", subnets[i].name);
        printf("IP Address: %s\n", subnets[i].ip);
        printf("Netmask: %s\n", subnets[i].netmask);
        printf("Gateway: %s\n", subnets[i].gateway);
        printf("Number of Hosts: %d\n", subnets[i].num_hosts);
        printf("\n");
    }

    return 0;
}