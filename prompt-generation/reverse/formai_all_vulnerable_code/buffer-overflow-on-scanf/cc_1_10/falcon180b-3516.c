//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 32
#define MAX_IP_SIZE 16

typedef struct {
    char ip[MAX_IP_SIZE];
    char mask[MAX_IP_SIZE];
    char subnet[MAX_IP_SIZE];
    int num_hosts;
} Subnet;

void calculate_subnet(Subnet *subnet) {
    int i;
    char *ip_ptr = strtok(subnet->ip, ".");
    char *mask_ptr = strtok(subnet->mask, ".");
    char *subnet_ptr = subnet->subnet;

    // Copy IP and mask to subnet
    for (i = 0; i < 4; i++) {
        strcat(subnet_ptr, ip_ptr);
        strcat(subnet_ptr, ".");
        strcat(subnet_ptr, mask_ptr);
        mask_ptr = strtok(NULL, ".");
        ip_ptr = strtok(NULL, ".");
    }

    // Calculate number of hosts
    subnet->num_hosts = 0;
    for (i = 0; i < 4; i++) {
        if (subnet_ptr[i] == '0' && subnet_ptr[i + 1]!= '.') {
            subnet->num_hosts += 2;
        }
        else if (subnet_ptr[i]!= '0' && subnet_ptr[i + 1]!= '.') {
            subnet->num_hosts += 1;
        }
    }
}

void print_subnet(Subnet *subnet) {
    printf("IP: %s\n", subnet->ip);
    printf("Mask: %s\n", subnet->mask);
    printf("Subnet: %s\n", subnet->subnet);
    printf("Number of hosts: %d\n", subnet->num_hosts);
}

int main() {
    int num_subnets, i;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter IP address for subnet %d: ", i + 1);
        scanf("%s", subnets[i].ip);

        printf("Enter subnet mask for subnet %d: ", i + 1);
        scanf("%s", subnets[i].mask);

        calculate_subnet(&subnets[i]);
    }

    printf("Subnet information:\n");
    for (i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
        printf("\n");
    }

    return 0;
}