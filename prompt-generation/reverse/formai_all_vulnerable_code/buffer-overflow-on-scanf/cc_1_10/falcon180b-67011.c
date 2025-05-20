//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define IP_LEN 4
#define SUBNET_LEN 4

void print_subnet_mask(unsigned int subnet_mask) {
    int i;
    for (i = 0; i < IP_LEN; i++) {
        printf("%d.", (subnet_mask >> (i * 8)) & 0xFF);
    }
    printf("\n");
}

int main() {
    int num_subnets, i;
    char ip_address[IP_LEN + 1];

    printf("Enter the IP address: ");
    scanf("%s", ip_address);

    num_subnets = 1;
    printf("Enter the number of subnets (1-%d): ", MAX_SUBNETS);
    scanf("%d", &num_subnets);

    printf("Enter the subnet mask (default is 255.255.255.0): ");
    scanf("%s", ip_address);

    unsigned int subnet_mask = 0xFFFFFFFF;
    if (strcmp(ip_address, "")!= 0) {
        subnet_mask = htonl(inet_addr(ip_address));
    }

    printf("\nSubnet Mask: ");
    print_subnet_mask(subnet_mask);

    unsigned int host_id = 0;
    unsigned int subnet_id = 0;
    unsigned int network_id = htonl(inet_addr(ip_address)) & subnet_mask;

    printf("\nNetwork ID: ");
    print_subnet_mask(network_id);

    unsigned int broadcast_id = network_id | ~subnet_mask;

    printf("\nBroadcast ID: ");
    print_subnet_mask(broadcast_id);

    unsigned int subnet_size = 0;
    unsigned int num_hosts = 0;

    if (num_subnets == 1) {
        subnet_size = 32 - subnet_mask;
        num_hosts = (32 - subnet_size) - 2;
    } else {
        subnet_size = (32 - subnet_mask) / num_subnets;
        num_hosts = (subnet_size - 2) * num_subnets;
    }

    printf("\nSubnet Size: %d\n", subnet_size);
    printf("Number of Hosts per Subnet: %d\n", num_hosts);

    unsigned int subnet_address = htonl(network_id) + (subnet_id * subnet_size);

    printf("\nSubnet Addresses:\n");
    for (i = 0; i < num_subnets; i++) {
        unsigned int current_subnet_address = subnet_address + (i * subnet_size);
        printf("Subnet %d: ", i + 1);
        print_subnet_mask(current_subnet_address);
        printf("\n");
    }

    return 0;
}