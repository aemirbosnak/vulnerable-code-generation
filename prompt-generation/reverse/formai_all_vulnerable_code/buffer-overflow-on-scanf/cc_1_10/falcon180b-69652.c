//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 1000
#define IP_ADDRESS_LEN 15
#define SUBNET_MASK_LEN 3

typedef struct {
    char ip_address[IP_ADDRESS_LEN];
    char subnet_mask[SUBNET_MASK_LEN];
} subnet_t;

void print_subnet_table(subnet_t subnets[], int num_subnets) {
    printf("Subnet\tIP Address\tSubnet Mask\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%d\t%s\t%s\n", i+1, subnets[i].ip_address, subnets[i].subnet_mask);
    }
}

int main() {
    char ip_address[IP_ADDRESS_LEN];
    char subnet_mask[SUBNET_MASK_LEN];
    int num_subnets = 0;

    printf("Enter IP address: ");
    scanf("%s", ip_address);
    printf("Enter subnet mask: ");
    scanf("%s", subnet_mask);

    subnet_t subnets[MAX_SUBNETS];

    int i = 0;
    while (i < MAX_SUBNETS && num_subnets < MAX_SUBNETS) {
        strcpy(subnets[i].ip_address, ip_address);
        strcpy(subnets[i].subnet_mask, subnet_mask);
        num_subnets++;
        i++;
    }

    if (num_subnets == 0) {
        printf("Invalid IP address or subnet mask.\n");
        return 1;
    }

    printf("Subnet table:\n");
    print_subnet_table(subnets, num_subnets);

    return 0;
}