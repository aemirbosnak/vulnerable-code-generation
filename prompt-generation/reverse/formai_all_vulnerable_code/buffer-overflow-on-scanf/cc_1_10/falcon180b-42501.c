//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 16
#define IP_ADDR_LEN 16

struct subnet {
    char ip_addr[IP_ADDR_LEN];
    char mask[IP_ADDR_LEN];
    char gateway[IP_ADDR_LEN];
    char dns1[IP_ADDR_LEN];
    char dns2[IP_ADDR_LEN];
};

int main() {
    int num_subnets;
    struct subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS) {
        printf("Error: Maximum number of subnets is %d\n", MAX_SUBNETS);
        return 1;
    }

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d:\n", i + 1);
        printf("IP address: ");
        scanf("%s", subnets[i].ip_addr);
        printf("Subnet mask: ");
        scanf("%s", subnets[i].mask);
        printf("Gateway: ");
        scanf("%s", subnets[i].gateway);
        printf("DNS 1: ");
        scanf("%s", subnets[i].dns1);
        printf("DNS 2: ");
        scanf("%s", subnets[i].dns2);
    }

    printf("Subnet information:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i + 1);
        printf("IP address: %s\n", subnets[i].ip_addr);
        printf("Subnet mask: %s\n", subnets[i].mask);
        printf("Gateway: %s\n", subnets[i].gateway);
        printf("DNS 1: %s\n", subnets[i].dns1);
        printf("DNS 2: %s\n", subnets[i].dns2);
    }

    return 0;
}