//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNET_BITS 32

typedef struct subnet_t {
    int bits;
    char mask[MAX_SUBNET_BITS];
    char network_address[16];
    char broadcast_address[16];
} subnet_t;

subnet_t calculate_subnet(char *network_address, int num_hosts) {
    subnet_t subnet;

    // Calculate the number of subnet bits
    int bits = 0;
    while (num_hosts & (1 << bits)) {
        bits++;
    }

    // Create the subnet mask
    subnet.mask[0] = 255 - (1 << (32 - bits));
    subnet.mask[1] = 0;

    // Calculate the network address
    subnet.network_address[0] = network_address[0] & subnet.mask[0];
    subnet.network_address[1] = network_address[1] & subnet.mask[0];
    subnet.network_address[2] = network_address[2] & subnet.mask[0];
    subnet.network_address[3] = network_address[3] & subnet.mask[0];

    // Calculate the broadcast address
    subnet.broadcast_address[0] = network_address[0] & subnet.mask[0] | 255;
    subnet.broadcast_address[1] = network_address[1] & subnet.mask[0] | 255;
    subnet.broadcast_address[2] = network_address[2] & subnet.mask[0] | 255;
    subnet.broadcast_address[3] = network_address[3] & subnet.mask[0] | 255;

    subnet.bits = bits;

    return subnet;
}

int main() {
    char network_address[] = "192.168.1.0";
    int num_hosts = 256;

    subnet_t subnet = calculate_subnet(network_address, num_hosts);

    printf("Subnet Mask: %s\n", subnet.mask);
    printf("Network Address: %s\n", subnet.network_address);
    printf("Broadcast Address: %s\n", subnet.broadcast_address);
    printf("Number of Hosts: %d\n", subnet.bits);

    return 0;
}