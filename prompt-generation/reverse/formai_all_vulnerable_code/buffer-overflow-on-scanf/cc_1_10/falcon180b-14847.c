//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 256

struct subnet {
    char name[20];
    int size;
    int num_hosts;
    int broadcast_address;
    int first_address;
    int last_address;
};

void init_subnet(struct subnet *subnet, char *name, int size) {
    strcpy(subnet->name, name);
    subnet->size = size;
    subnet->num_hosts = size - 2;
    subnet->broadcast_address = (int)pow(2, size) - 1;
    subnet->first_address = 1;
    subnet->last_address = subnet->broadcast_address;
}

int main() {
    int num_subnets, i;
    struct subnet subnets[MAX_SUBNETS];

    printf("Enter number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet name: ");
        scanf("%s", subnets[i].name);

        printf("Enter subnet size (1-24): ");
        scanf("%d", &subnets[i].size);

        if (subnets[i].size < 1 || subnets[i].size > 24) {
            printf("Invalid subnet size.\n");
            return 1;
        }

        init_subnet(&subnets[i], subnets[i].name, subnets[i].size);

        printf("\nSubnet %s:\n", subnets[i].name);
        printf("Size: %d\n", subnets[i].size);
        printf("Number of hosts: %d\n", subnets[i].num_hosts);
        printf("Broadcast address: %d\n", subnets[i].broadcast_address);
        printf("First address: %d\n", subnets[i].first_address);
        printf("Last address: %d\n\n", subnets[i].last_address);
    }

    return 0;
}