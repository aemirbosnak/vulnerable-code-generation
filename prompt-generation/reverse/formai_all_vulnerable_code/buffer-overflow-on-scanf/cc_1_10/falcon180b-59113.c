//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 50
#define MAX_SUBNET_SIZE 32
#define MAX_IP_SIZE 16

typedef struct {
    char ip[MAX_IP_SIZE];
    char mask[MAX_IP_SIZE];
} subnet;

void add_subnet(subnet *subnets, int num_subnets, char *ip, char *mask) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strcpy(subnets[num_subnets].ip, ip);
    strcpy(subnets[num_subnets].mask, mask);

    num_subnets++;
}

void print_subnets(subnet *subnets, int num_subnets) {
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d: %s/%s\n", i + 1, subnets[i].ip, subnets[i].mask);
    }
}

int main() {
    subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    char ip[MAX_IP_SIZE];
    char mask[MAX_IP_SIZE];

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the subnet mask: ");
    scanf("%s", mask);

    add_subnet(subnets, num_subnets, ip, mask);

    printf("Enter Y to add another subnet, any other key to exit: ");
    char choice;
    scanf("%c", &choice);

    while (choice == 'Y' || choice == 'y') {
        printf("Enter the IP address: ");
        scanf("%s", ip);

        printf("Enter the subnet mask: ");
        scanf("%s", mask);

        add_subnet(subnets, num_subnets, ip, mask);

        printf("Enter Y to add another subnet, any other key to exit: ");
        scanf("%c", &choice);
    }

    print_subnets(subnets, num_subnets);

    return 0;
}