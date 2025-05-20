//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_NAME_LEN 50
#define MAX_SUBNET_IP_LEN 16
#define MAX_SUBNET_MASK_LEN 16

typedef struct {
    char name[MAX_SUBNET_NAME_LEN];
    char ip[MAX_SUBNET_IP_LEN];
    char mask[MAX_SUBNET_MASK_LEN];
    int num_hosts;
    int num_subnets;
} Subnet;

void print_subnet(Subnet *s) {
    printf("Subnet Name: %s\n", s->name);
    printf("IP Address: %s\n", s->ip);
    printf("Subnet Mask: %s\n", s->mask);
    printf("Number of Hosts: %d\n", s->num_hosts);
    printf("Number of Subnets: %d\n\n", s->num_subnets);
}

void add_subnet(Subnet *s, int index) {
    strcpy(s->name, "Subnet");
    sprintf(s->ip, "192.168.%d.0", index);
    sprintf(s->mask, "255.255.255.0");
    s->num_hosts = 254;
    s->num_subnets = 2;
}

int main() {
    int num_subnets;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        add_subnet(&subnets[i], i);
        printf("Subnet %d added.\n", i);
    }

    for (int i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}