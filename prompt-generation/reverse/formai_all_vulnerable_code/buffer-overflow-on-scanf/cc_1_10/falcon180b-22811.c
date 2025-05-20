//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SUBNETS 10

typedef struct {
    char ip[16];
    int subnet_mask;
    int num_subnets;
    int num_hosts;
} subnet_t;

void calculate_subnets(subnet_t *subnet, int num_subnets) {
    int i, j, k;
    char ip[16];
    for (i = 0; i < num_subnets; i++) {
        strcpy(ip, subnet->ip);
        for (j = 0; j < 4; j++) {
            if (i == 0) {
                k = 0;
            } else {
                k = i - 1;
            }
            if (j == 3) {
                sprintf(&ip[j], "%d", k + 1);
            } else {
                sprintf(&ip[j], "%d", k);
            }
        }
        subnet->subnet_mask = atoi(ip);
        subnet->num_subnets = pow(2, (32 - subnet->subnet_mask));
        subnet->num_hosts = subnet->num_subnets - 2;
        subnet++;
    }
}

int main() {
    subnet_t subnet[MAX_SUBNETS];
    int num_subnets;

    printf("Enter the IP address: ");
    scanf("%s", subnet[0].ip);

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    calculate_subnets(subnet, num_subnets);

    printf("Subnet IP addresses:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\n", subnet[i].ip);
    }

    printf("Subnet mask: %d\n", subnet[0].subnet_mask);
    printf("Number of subnets: %d\n", subnet[0].num_subnets);
    printf("Number of hosts per subnet: %d\n", subnet[0].num_hosts);

    return 0;
}