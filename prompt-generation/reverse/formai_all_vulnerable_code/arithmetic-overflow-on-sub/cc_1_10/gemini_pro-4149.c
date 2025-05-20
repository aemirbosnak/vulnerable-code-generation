//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subnet {
    unsigned int address;
    unsigned int netmask;
    unsigned int broadcast;
    unsigned int first_host;
    unsigned int last_host;
    unsigned int num_hosts;
};

void calculate_subnet(struct subnet *subnet, unsigned int address, unsigned int netmask) {
    subnet->address = address;
    subnet->netmask = netmask;
    subnet->broadcast = (address | ~netmask) + 1;
    subnet->first_host = address + 1;
    subnet->last_host = subnet->broadcast - 1;
    subnet->num_hosts = (1 << (32 - netmask)) - 2;
}

void print_subnet(struct subnet *subnet) {
    printf("Address: %u.%u.%u.%u\n", (subnet->address >> 24) & 0xFF,
                                        (subnet->address >> 16) & 0xFF,
                                        (subnet->address >> 8) & 0xFF,
                                        subnet->address & 0xFF);
    printf("Netmask: %u.%u.%u.%u\n", (subnet->netmask >> 24) & 0xFF,
                                         (subnet->netmask >> 16) & 0xFF,
                                         (subnet->netmask >> 8) & 0xFF,
                                         subnet->netmask & 0xFF);
    printf("Broadcast: %u.%u.%u.%u\n", (subnet->broadcast >> 24) & 0xFF,
                                          (subnet->broadcast >> 16) & 0xFF,
                                          (subnet->broadcast >> 8) & 0xFF,
                                          subnet->broadcast & 0xFF);
    printf("First host: %u.%u.%u.%u\n", (subnet->first_host >> 24) & 0xFF,
                                           (subnet->first_host >> 16) & 0xFF,
                                           (subnet->first_host >> 8) & 0xFF,
                                           subnet->first_host & 0xFF);
    printf("Last host: %u.%u.%u.%u\n", (subnet->last_host >> 24) & 0xFF,
                                         (subnet->last_host >> 16) & 0xFF,
                                         (subnet->last_host >> 8) & 0xFF,
                                         subnet->last_host & 0xFF);
    printf("Number of hosts: %u\n", subnet->num_hosts);
}

int main() {
    struct subnet subnet;

    unsigned int address;
    printf("Enter the IP address: ");
    scanf("%u", &address);

    unsigned int netmask;
    printf("Enter the netmask: ");
    scanf("%u", &netmask);

    calculate_subnet(&subnet, address, netmask);
    print_subnet(&subnet);

    return 0;
}