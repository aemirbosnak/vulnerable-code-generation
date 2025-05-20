//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 32
#define MAX_IP_SIZE 16

struct subnet {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_SIZE];
    char ip[MAX_IP_SIZE];
};

struct subnet subnets[MAX_SUBNETS];
int num_subnets = 0;

void add_subnet(char *name, char *mask, char *ip) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        exit(1);
    }

    strcpy(subnets[num_subnets].name, name);
    strcpy(subnets[num_subnets].mask, mask);
    strcpy(subnets[num_subnets].ip, ip);

    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s - %s (%s)\n", subnets[i].name, subnets[i].mask, subnets[i].ip);
    }
}

int main() {
    printf("Welcome to the Paranoid Subnet Calculator!\n");

    char input[MAX_SUBNET_SIZE];
    while (1) {
        printf("Enter subnet name (or 'exit' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        char mask[MAX_SUBNET_MASK_SIZE];
        printf("Enter subnet mask: ");
        scanf("%s", mask);

        char ip[MAX_IP_SIZE];
        printf("Enter subnet IP address: ");
        scanf("%s", ip);

        add_subnet(input, mask, ip);
    }

    print_subnets();

    return 0;
}