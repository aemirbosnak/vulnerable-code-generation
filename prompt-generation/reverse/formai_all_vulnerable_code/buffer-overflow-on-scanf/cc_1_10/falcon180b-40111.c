//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100

struct subnet {
    char name[50];
    int ip_address;
    int subnet_mask;
    int gateway;
    int dns1;
    int dns2;
};

int main() {
    int num_subnets;
    struct subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d information:\n", i+1);
        printf("Subnet name: ");
        scanf("%s", subnets[i].name);
        printf("IP address: ");
        scanf("%d", &subnets[i].ip_address);
        printf("Subnet mask: ");
        scanf("%d", &subnets[i].subnet_mask);
        printf("Gateway: ");
        scanf("%d", &subnets[i].gateway);
        printf("DNS 1: ");
        scanf("%d", &subnets[i].dns1);
        printf("DNS 2: ");
        scanf("%d", &subnets[i].dns2);
    }

    for (int i = 0; i < num_subnets; i++) {
        printf("\nSubnet %d information:\n", i+1);
        printf("Name: %s\n", subnets[i].name);
        printf("IP address: %d\n", subnets[i].ip_address);
        printf("Subnet mask: %d\n", subnets[i].subnet_mask);
        printf("Gateway: %d\n", subnets[i].gateway);
        printf("DNS 1: %d\n", subnets[i].dns1);
        printf("DNS 2: %d\n", subnets[i].dns2);
        printf("\n");
    }

    return 0;
}