//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNET_SIZE 32
#define MAX_SUBNETS 256

typedef struct {
    char name[64];
    char ip_address[16];
    char netmask[16];
    char gateway[16];
    char dns1[16];
    char dns2[16];
} subnet_t;

subnet_t subnets[MAX_SUBNETS];
int num_subnets = 0;

void add_subnet() {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    printf("Enter subnet name: ");
    scanf("%s", subnets[num_subnets].name);

    printf("Enter IP address: ");
    scanf("%s", subnets[num_subnets].ip_address);

    printf("Enter netmask: ");
    scanf("%s", subnets[num_subnets].netmask);

    printf("Enter gateway: ");
    scanf("%s", subnets[num_subnets].gateway);

    printf("Enter DNS server 1: ");
    scanf("%s", subnets[num_subnets].dns1);

    printf("Enter DNS server 2: ");
    scanf("%s", subnets[num_subnets].dns2);

    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\n", subnets[i].name);
    }
}

int main() {
    printf("Subnet Calculator\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add subnet\n");
        printf("2. Print subnets\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_subnet();
                break;
            case 2:
                print_subnets();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}