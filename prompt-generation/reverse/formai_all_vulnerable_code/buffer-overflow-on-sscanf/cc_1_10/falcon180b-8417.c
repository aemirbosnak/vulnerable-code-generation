//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32
#define MAX_SUBNET_ADDR 40

typedef struct {
    char name[MAX_SUBNET_ADDR];
    char subnet[MAX_SUBNET_ADDR];
    char mask[MAX_SUBNET_ADDR];
} subnet_t;

int num_subnets = 0;
subnet_t subnets[MAX_SUBNETS];

void subnet_add(char *name, char *subnet, char *mask)
{
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strncpy(subnets[num_subnets].name, name, MAX_SUBNET_ADDR);
    strncpy(subnets[num_subnets].subnet, subnet, MAX_SUBNET_ADDR);
    strncpy(subnets[num_subnets].mask, mask, MAX_SUBNET_ADDR);

    num_subnets++;
}

void subnet_print()
{
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s: %s/%s\n", subnets[i].name, subnets[i].subnet, subnets[i].mask);
    }
}

int main()
{
    char input[MAX_SUBNET_ADDR];
    char name[MAX_SUBNET_ADDR];
    char subnet_ip[MAX_SUBNET_ADDR];
    char subnet_mask[MAX_SUBNET_ADDR];
    int subnet_bits;

    printf("Welcome to the Subnet Calculator!\n");

    while (1) {
        printf("Enter a subnet IP address or type 'quit' to exit: ");
        fgets(input, MAX_SUBNET_ADDR, stdin);

        if (strcmp(input, "quit") == 0) {
            subnet_print();
            break;
        }

        if (sscanf(input, "%s %s %s %d", name, subnet_ip, subnet_mask, &subnet_bits)!= 4) {
            printf("Invalid input.\n");
            continue;
        }

        strncpy(subnets[num_subnets].name, name, MAX_SUBNET_ADDR);
        strncpy(subnets[num_subnets].subnet, subnet_ip, MAX_SUBNET_ADDR);
        strncpy(subnets[num_subnets].mask, subnet_mask, MAX_SUBNET_ADDR);

        num_subnets++;
    }

    return 0;
}