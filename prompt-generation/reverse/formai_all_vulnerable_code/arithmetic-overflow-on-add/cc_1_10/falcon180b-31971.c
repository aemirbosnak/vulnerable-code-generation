//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 32
#define MAX_SUBNET_SIZE 32

typedef struct subnet_t {
    char name[MAX_SUBNET_SIZE];
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_SIZE];
    int num_hosts;
    int first_host;
    int last_host;
} subnet_t;

void print_subnet(subnet_t *subnet) {
    printf("Subnet name: %s\n", subnet->name);
    printf("IP address: %s\n", subnet->ip);
    printf("Subnet mask: %s\n", subnet->mask);
    printf("Number of hosts: %d\n", subnet->num_hosts);
    printf("First host: %s\n", subnet->first_host);
    printf("Last host: %s\n", subnet->last_host);
}

int main() {
    int num_subnets;
    char input[MAX_SUBNET_SIZE];
    subnet_t subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d:\n", i + 1);
        printf("Subnet name: ");
        scanf("%s", input);
        strcpy(subnets[i].name, input);

        printf("IP address: ");
        scanf("%s", input);
        strcpy(subnets[i].ip, input);

        printf("Subnet mask: ");
        scanf("%s", input);
        strcpy(subnets[i].mask, input);

        subnets[i].num_hosts = (int)pow(2, (int)strlen(subnets[i].mask) - (int)strspn(subnets[i].mask, "255")) - 2;
        subnets[i].first_host = htonl(ntohl(inet_addr(subnets[i].ip)) & ntohl(inet_addr(subnets[i].mask))) + 1;
        subnets[i].last_host = htonl(ntohl(inet_addr(subnets[i].ip)) | ~ntohl(inet_addr(subnets[i].mask)));
    }

    printf("Subnet information:\n");
    for (int i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}