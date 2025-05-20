//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 4

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_SIZE];
    int num_hosts;
} subnet_t;

void print_subnet(subnet_t *subnet) {
    printf("Subnet name: %s\n", subnet->name);
    printf("IP address: %s\n", subnet->ip);
    printf("Subnet mask: %s\n", subnet->mask);
    printf("Number of hosts: %d\n", subnet->num_hosts);
}

int main() {
    int num_subnets, i;
    subnet_t subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name for subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the IP address for subnet %d: ", i+1);
        scanf("%s", subnets[i].ip);

        printf("Enter the subnet mask for subnet %d: ", i+1);
        scanf("%s", subnets[i].mask);

        subnets[i].num_hosts = calculate_num_hosts(subnets[i].ip, subnets[i].mask);
    }

    for (i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}

int calculate_num_hosts(char *ip, char *mask) {
    int num_hosts = 0;
    int i;

    for (i = 0; i < strlen(mask); i++) {
        if (mask[i] == '1') {
            num_hosts++;
        }
    }

    return num_hosts;
}