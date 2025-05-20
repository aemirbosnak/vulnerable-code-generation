//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SUBNETS 256

typedef struct subnet_t {
    int subnet_mask;
    int broadcast_address;
    int network_address;
    int usable_hosts;
} subnet_t;

subnet_t subnet_calc(int cidr) {
    subnet_t subnet;
    subnet.subnet_mask = 0;
    subnet.broadcast_address = 0;
    subnet.network_address = 0;
    subnet.usable_hosts = 0;

    switch (cidr) {
        case 0:
            subnet.subnet_mask = 0xFF;
            subnet.broadcast_address = 0xFF;
            subnet.network_address = 0;
            subnet.usable_hosts = 254;
            break;
        case 1:
            subnet.subnet_mask = 0xFF00;
            subnet.broadcast_address = 0xFF00;
            subnet.network_address = 0;
            subnet.usable_hosts = 254;
            break;
        case 2:
            subnet.subnet_mask = 0xFF0000;
            subnet.broadcast_address = 0xFF0000;
            subnet.network_address = 0;
            subnet.usable_hosts = 254;
            break;
        default:
            printf("Error: Invalid CIDR value.\n");
            exit(1);
    }

    return subnet;
}

int main() {
    int cidr;
    printf("Enter the CIDR subnet mask: ");
    scanf("%d", &cidr);

    subnet_t subnet = subnet_calc(cidr);

    if (subnet.usable_hosts > 0) {
        printf("Subnet Mask: %02x\n", subnet.subnet_mask);
        printf("Broadcast Address: %02x\n", subnet.broadcast_address);
        printf("Network Address: %02x\n", subnet.network_address);
        printf("Usable Hosts: %d\n", subnet.usable_hosts);
    } else {
        printf("Error: No usable hosts.\n");
    }

    return 0;
}