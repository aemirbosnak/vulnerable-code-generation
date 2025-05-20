//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define IP_MAX_SIZE 16
#define SUBNET_MASK_MAX_SIZE 4

typedef struct {
    char ip[IP_MAX_SIZE];
    char subnet_mask[SUBNET_MASK_MAX_SIZE];
} subnet;

void print_subnet(subnet *s) {
    printf("IP: %s\n", s->ip);
    printf("Subnet Mask: %s\n", s->subnet_mask);
}

int calculate_subnets(int num_hosts, int num_subnets) {
    int i, j;
    int subnet_size = 0;
    int host_size = 0;
    int total_subnets = 0;
    int current_subnet = 0;

    // Calculate the subnet size
    for (i = 0; i < num_subnets; i++) {
        subnet_size += pow(2, i);
    }

    // Calculate the host size
    host_size = num_hosts - subnet_size;

    // Calculate the total number of subnets
    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < host_size; j++) {
            total_subnets++;
        }
        current_subnet++;
    }

    return total_subnets;
}

int main() {
    int num_hosts, num_subnets;
    subnet subnets[MAX_SUBNETS];
    int num_subnets_calculated;
    int i;

    // Get the number of hosts from the user
    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    // Get the number of subnets from the user
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Calculate the number of subnets
    num_subnets_calculated = calculate_subnets(num_hosts, num_subnets);

    // Print the subnets
    printf("Number of Subnets: %d\n", num_subnets_calculated);
    printf("Subnets:\n");
    for (i = 0; i < num_subnets_calculated; i++) {
        sprintf(subnets[i].ip, "192.168.%d.%d", i/8, i%8);
        sprintf(subnets[i].subnet_mask, "255.255.%d.%d", (i/8) * 8 + 8, (i%8) * 8);
        print_subnet(&subnets[i]);
    }

    return 0;
}