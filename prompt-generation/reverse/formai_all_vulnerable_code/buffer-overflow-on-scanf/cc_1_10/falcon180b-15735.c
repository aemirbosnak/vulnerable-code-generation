//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32
#define IP_ADDR_SIZE 16

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char subnet_mask[MAX_SUBNET_MASK];
    int num_hosts;
} subnet;

void generate_subnet_mask(char *subnet_mask, int num_bits) {
    int i;
    for (i = 0; i < num_bits; i++) {
        if (i % 8 == 0 && i!= 0) {
            strcat(subnet_mask, ".");
        }
        if ((i % 8) == 7) {
            sprintf(subnet_mask + strlen(subnet_mask), "%d", (255 >> (i % 8)) & 0xff);
        } else {
            sprintf(subnet_mask + strlen(subnet_mask), "%d", 255);
        }
    }
}

int main(int argc, char *argv[]) {
    int i, j, k, num_subnets;
    char ip_addr[IP_ADDR_SIZE];
    char subnet_mask[MAX_SUBNET_MASK];
    subnet subnets[MAX_SUBNETS];

    printf("Enter the IP address: ");
    scanf("%s", ip_addr);

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the number of hosts in subnet %s: ", subnets[i].name);
        scanf("%d", &subnets[i].num_hosts);

        strcpy(subnet_mask, ip_addr);
        k = strlen(subnet_mask);
        while (k < MAX_SUBNET_MASK) {
            subnet_mask[k++] = '0';
        }

        generate_subnet_mask(subnet_mask, 32 - atoi(subnet_mask + k - 1));

        strcpy(subnets[i].subnet_mask, subnet_mask);
    }

    for (i = 0; i < num_subnets; i++) {
        printf("\nSubnet %s details:\n", subnets[i].name);
        printf("IP address: %s\n", subnets[i].subnet_mask);
        printf("Subnet mask: %s\n", subnets[i].subnet_mask);
        printf("Number of hosts: %d\n", subnets[i].num_hosts);
        printf("\n");
    }

    return 0;
}