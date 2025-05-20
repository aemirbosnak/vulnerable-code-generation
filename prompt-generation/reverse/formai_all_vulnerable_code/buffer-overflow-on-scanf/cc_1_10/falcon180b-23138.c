//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_SIZE];
    int num_hosts;
} subnet_t;

int main() {
    int num_subnets, i;
    subnet_t subnets[MAX_SUBNETS];
    char input[MAX_SUBNET_SIZE];
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_SIZE];
    int host_bits, subnet_bits;

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the subnet mask: ");
    scanf("%s", mask);

    host_bits = 0;
    for (i = 0; i < strlen(mask); i++) {
        if (mask[i] == '1') {
            host_bits++;
        } else if (mask[i]!= '0') {
            printf("Invalid subnet mask\n");
            return 1;
        }
    }

    subnet_bits = strlen(mask) - host_bits;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the subnet name: ");
        scanf("%s", subnets[i].name);

        sprintf(subnets[i].ip, "%s", ip);
        strcat(subnets[i].ip, ".");

        sprintf(subnets[i].mask, "%s", mask);
        strcat(subnets[i].mask, ".");

        subnets[i].num_hosts = pow(2, host_bits) - 2;
    }

    printf("Subnet Information:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet Name: %s\n", subnets[i].name);
        printf("IP Address: %s\n", subnets[i].ip);
        printf("Subnet Mask: %s\n", subnets[i].mask);
        printf("Number of Hosts: %d\n\n", subnets[i].num_hosts);
    }

    return 0;
}