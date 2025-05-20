//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10

typedef struct {
    char ip[16];
    char netmask[16];
    char gateway[16];
    char dns[16];
} subnet_t;

subnet_t subnets[MAX_SUBNETS];
int num_subnets = 0;

void add_subnet() {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    subnet_t *subnet = &subnets[num_subnets];

    printf("Enter IP address: ");
    scanf("%s", subnet->ip);

    printf("Enter netmask: ");
    scanf("%s", subnet->netmask);

    printf("Enter gateway: ");
    scanf("%s", subnet->gateway);

    printf("Enter DNS server: ");
    scanf("%s", subnet->dns);

    num_subnets++;
}

void print_subnets() {
    if (num_subnets == 0) {
        printf("No subnets added.\n");
        return;
    }

    for (int i = 0; i < num_subnets; i++) {
        subnet_t *subnet = &subnets[i];

        printf("Subnet %d:\n", i + 1);
        printf("IP address: %s\n", subnet->ip);
        printf("Netmask: %s\n", subnet->netmask);
        printf("Gateway: %s\n", subnet->gateway);
        printf("DNS server: %s\n\n", subnet->dns);
    }
}

int main() {
    printf("Welcome to the Subnet Calculator!\n\n");

    while (1) {
        printf("Select an option:\n");
        printf("1. Add subnet\n");
        printf("2. Print subnets\n");
        printf("3. Exit\n");

        char option;
        scanf(" %c", &option);

        switch (option) {
        case '1':
            add_subnet();
            break;
        case '2':
            print_subnets();
            break;
        case '3':
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}