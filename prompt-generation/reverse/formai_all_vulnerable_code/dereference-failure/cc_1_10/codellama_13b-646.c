//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_ADDRESS 32
#define MAX_NETMASK 32

struct ip_address {
    char ip_address[MAX_IP_ADDRESS];
    char netmask[MAX_NETMASK];
};

void print_subnets(struct ip_address *ip_addr) {
    int i;
    int j;
    int netmask;
    int ip_addr_int;
    int subnet_addr;
    int subnet_mask;

    // Convert IP address to integer
    ip_addr_int = atoi(ip_addr->ip_address);

    // Convert netmask to integer
    netmask = atoi(ip_addr->netmask);

    // Calculate subnet mask
    subnet_mask = ~(0xFFFFFFFF << netmask);

    // Print subnets
    for (i = 0; i < 32; i++) {
        subnet_addr = ip_addr_int & subnet_mask;
        printf("Subnet %d: %d.%d.%d.%d/%d\n", i,
                (subnet_addr >> 24) & 0xFF,
                (subnet_addr >> 16) & 0xFF,
                (subnet_addr >> 8) & 0xFF,
                (subnet_addr >> 0) & 0xFF,
                netmask);
    }
}

int main(int argc, char *argv[]) {
    struct ip_address ip_addr;

    // Check if the user has provided an IP address
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    // Get the IP address from the user
    strcpy(ip_addr.ip_address, argv[1]);

    // Print subnets
    print_subnets(&ip_addr);

    return 0;
}