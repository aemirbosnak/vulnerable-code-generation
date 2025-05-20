//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define IP_ADDRESS_SIZE 16

struct subnet {
    char name[MAX_SUBNET_SIZE];
    char ip[IP_ADDRESS_SIZE];
    char mask[IP_ADDRESS_SIZE];
    int num_hosts;
};

void print_subnets(struct subnet *subnets, int num_subnets) {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\n", subnets[i].name);
        printf("IP Address: %s\n", subnets[i].ip);
        printf("Subnet Mask: %s\n", subnets[i].mask);
        printf("Number of Hosts: %d\n\n", subnets[i].num_hosts);
    }
}

int main() {
    int num_subnets, i;
    struct subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the IP address of subnet %d: ", i+1);
        scanf("%s", subnets[i].ip);

        printf("Enter the subnet mask of subnet %d: ", i+1);
        scanf("%s", subnets[i].mask);

        subnets[i].num_hosts = 0;
        for (int j = 0; j < IP_ADDRESS_SIZE; j++) {
            if (subnets[i].mask[j] == '1') {
                subnets[i].num_hosts++;
            }
        }
    }

    print_subnets(subnets, num_subnets);

    return 0;
}