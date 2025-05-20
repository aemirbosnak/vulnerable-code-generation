//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32

typedef struct {
    char subnet[MAX_SUBNET_SIZE];
    int subnet_size;
} subnet_t;

void print_subnet(subnet_t *subnet) {
    printf("Subnet: %s\n", subnet->subnet);
    printf("Subnet size: %d\n", subnet->subnet_size);
}

void add_subnet(subnet_t *subnets, int num_subnets, char *subnet_str) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    subnet_t *new_subnet = &subnets[num_subnets];
    strcpy(new_subnet->subnet, subnet_str);
    new_subnet->subnet_size = strlen(subnet_str);

    num_subnets++;
}

int main() {
    char ip_addr[16];
    printf("Enter IP address: ");
    scanf("%s", ip_addr);

    int num_subnets = 0;
    subnet_t subnets[MAX_SUBNETS];

    char *token = strtok(ip_addr, ".");
    while (token!= NULL) {
        int octet = atoi(token);
        if (octet == 0 || octet == 127) {
            printf("Error: Invalid IP address.\n");
            return 1;
        }

        char subnet_str[MAX_SUBNET_SIZE];
        sprintf(subnet_str, "%d.%d.%d.%d", octet, octet, octet, octet+1);
        add_subnet(subnets, num_subnets, subnet_str);

        token = strtok(NULL, ".");
    }

    for (int i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}