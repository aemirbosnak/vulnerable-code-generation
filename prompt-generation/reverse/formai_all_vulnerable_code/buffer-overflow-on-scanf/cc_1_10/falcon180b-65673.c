//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32

typedef struct {
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_SIZE];
    char gateway[MAX_SUBNET_SIZE];
    char dns[MAX_SUBNET_SIZE];
} subnet_t;

void print_subnet(subnet_t *subnet) {
    printf("IP: %s\n", subnet->ip);
    printf("Mask: %s\n", subnet->mask);
    printf("Gateway: %s\n", subnet->gateway);
    printf("DNS: %s\n\n", subnet->dns);
}

int main() {
    int num_subnets;
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS) {
        printf("Error: Maximum number of subnets is %d\n", MAX_SUBNETS);
        return 1;
    }

    subnet_t subnets[num_subnets];

    for (int i = 0; i < num_subnets; i++) {
        printf("\nSubnet %d:\n", i+1);

        char ip[MAX_SUBNET_SIZE];
        char mask[MAX_SUBNET_SIZE];
        char gateway[MAX_SUBNET_SIZE];
        char dns[MAX_SUBNET_SIZE];

        printf("IP: ");
        scanf("%s", ip);
        strcpy(subnets[i].ip, ip);

        printf("Mask: ");
        scanf("%s", mask);
        strcpy(subnets[i].mask, mask);

        printf("Gateway: ");
        scanf("%s", gateway);
        strcpy(subnets[i].gateway, gateway);

        printf("DNS: ");
        scanf("%s", dns);
        strcpy(subnets[i].dns, dns);
    }

    printf("\nSubnet information:\n");
    for (int i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}