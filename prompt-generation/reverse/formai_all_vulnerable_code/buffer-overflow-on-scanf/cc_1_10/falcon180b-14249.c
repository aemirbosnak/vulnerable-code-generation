//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

typedef struct {
    char name[20];
    int num_hosts;
    int subnet_mask;
    int first_ip;
    int last_ip;
} Subnet;

void print_subnet(Subnet subnet) {
    printf("Subnet Name: %s\n", subnet.name);
    printf("Number of Hosts: %d\n", subnet.num_hosts);
    printf("Subnet Mask: %d.%d.%d.%d\n", (subnet.subnet_mask >> 24) & 0xFF, (subnet.subnet_mask >> 16) & 0xFF, (subnet.subnet_mask >> 8) & 0xFF, subnet.subnet_mask & 0xFF);
    printf("First IP: %d.%d.%d.%d\n", (subnet.first_ip >> 24) & 0xFF, (subnet.first_ip >> 16) & 0xFF, (subnet.first_ip >> 8) & 0xFF, subnet.first_ip & 0xFF);
    printf("Last IP: %d.%d.%d.%d\n", (subnet.last_ip >> 24) & 0xFF, (subnet.last_ip >> 16) & 0xFF, (subnet.last_ip >> 8) & 0xFF, subnet.last_ip & 0xFF);
}

int main() {
    int num_subnets, i;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets to calculate (maximum %d): ", MAX_SUBNETS);
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of the subnet: ");
        scanf(" %19s", subnets[i].name);

        printf("Enter the number of hosts in the subnet: ");
        scanf("%d", &subnets[i].num_hosts);

        printf("Enter the subnet mask (e.g. 255.255.255.0): ");
        scanf("%d.%d.%d.%d", &subnets[i].subnet_mask);

        subnets[i].first_ip = htonl(subnets[i].subnet_mask & ~0xffffff00 | 0x00000000);
        subnets[i].last_ip = htonl(subnets[i].subnet_mask & ~0xffffff00 | 0xffffffff);
    }

    printf("\nSubnet Calculations:\n");
    for (i = 0; i < num_subnets; i++) {
        print_subnet(subnets[i]);
    }

    return 0;
}