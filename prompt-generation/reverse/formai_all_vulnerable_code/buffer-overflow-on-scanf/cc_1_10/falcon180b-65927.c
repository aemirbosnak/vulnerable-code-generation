//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define IP_ADDRESS_LENGTH 16

struct subnet {
    char ip[IP_ADDRESS_LENGTH];
    char mask[IP_ADDRESS_LENGTH];
    char gateway[IP_ADDRESS_LENGTH];
    char dns1[IP_ADDRESS_LENGTH];
    char dns2[IP_ADDRESS_LENGTH];
};

int main() {
    int num_subnets;
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if(num_subnets < 1 || num_subnets > MAX_SUBNETS) {
        printf("Invalid number of subnets.\n");
        return 1;
    }

    struct subnet subnets[num_subnets];

    for(int i = 0; i < num_subnets; i++) {
        printf("\nEnter the details for subnet %d:\n", i+1);
        printf("IP address: ");
        scanf("%s", subnets[i].ip);
        printf("Subnet mask: ");
        scanf("%s", subnets[i].mask);
        printf("Gateway: ");
        scanf("%s", subnets[i].gateway);
        printf("DNS server 1: ");
        scanf("%s", subnets[i].dns1);
        printf("DNS server 2: ");
        scanf("%s", subnets[i].dns2);
    }

    printf("\nSubnet information:\n");
    for(int i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("IP address: %s\n", subnets[i].ip);
        printf("Subnet mask: %s\n", subnets[i].mask);
        printf("Gateway: %s\n", subnets[i].gateway);
        printf("DNS server 1: %s\n", subnets[i].dns1);
        printf("DNS server 2: %s\n", subnets[i].dns2);
        printf("\n");
    }

    return 0;
}