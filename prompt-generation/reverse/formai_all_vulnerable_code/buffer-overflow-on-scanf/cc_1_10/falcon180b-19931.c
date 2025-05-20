//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_IP_SIZE 16

typedef struct {
    char ip[MAX_IP_SIZE];
    int mask;
    int subnet_size;
} Subnet;

void print_subnet(Subnet *subnet) {
    char subnet_ip[MAX_IP_SIZE];
    sprintf(subnet_ip, "%s/%d", subnet->ip, subnet->mask);
    printf("%s\n", subnet_ip);
}

int main() {
    int num_subnets;
    scanf("%d", &num_subnets);

    Subnet subnets[MAX_SUBNETS];
    int num_subnets_found = 0;

    while (num_subnets_found < num_subnets) {
        char input_ip[MAX_IP_SIZE];
        int mask;
        scanf("%s %d", input_ip, &mask);

        Subnet *subnet = &subnets[num_subnets_found];
        strcpy(subnet->ip, input_ip);
        subnet->mask = mask;
        subnet->subnet_size = 0;

        int i;
        for (i = 0; i < MAX_SUBNETS; i++) {
            if (subnets[i].ip[0] == '\0') {
                break;
            }
        }
        if (i == MAX_SUBNETS) {
            printf("No more subnets available.\n");
            exit(1);
        }

        num_subnets_found++;
    }

    int total_subnet_size = 0;
    for (int i = 0; i < num_subnets_found; i++) {
        Subnet *subnet = &subnets[i];
        int subnet_size = (32 - subnet->mask) + 1;
        subnet->subnet_size = subnet_size;
        total_subnet_size += subnet_size;
    }

    printf("Total subnet size: %d\n", total_subnet_size);

    for (int i = 0; i < num_subnets_found; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}