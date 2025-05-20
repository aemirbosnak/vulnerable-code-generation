//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_NAME_LENGTH 50
#define MAX_IP_ADDRESS_LENGTH 16
#define MAX_SUBNET_MASK_LENGTH 16

typedef struct {
    char name[MAX_SUBNET_NAME_LENGTH];
    char ip_address[MAX_IP_ADDRESS_LENGTH];
    char subnet_mask[MAX_SUBNET_MASK_LENGTH];
    int num_hosts;
} Subnet;

int main() {
    int num_subnets;
    Subnet subnets[MAX_SUBNETS];
    char input_buffer[1024];
    char *token;
    int i;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d information:\n", i+1);
        printf("Subnet name: ");
        scanf("%s", subnets[i].name);
        printf("IP address: ");
        scanf("%s", subnets[i].ip_address);
        printf("Subnet mask: ");
        scanf("%s", subnets[i].subnet_mask);
        printf("Number of hosts: ");
        scanf("%d", &subnets[i].num_hosts);
    }

    printf("\nSubnet Information:\n");
    printf("---------------------\n");
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("Name: %s\n", subnets[i].name);
        printf("IP address: %s\n", subnets[i].ip_address);
        printf("Subnet mask: %s\n", subnets[i].subnet_mask);
        printf("Number of hosts: %d\n", subnets[i].num_hosts);
        printf("\n");
    }

    return 0;
}