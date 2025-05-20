//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBNET_BITS 24
#define MAX_HOSTS_PER_SUBNET 256

int getSubnetMask(int subnet_bits) {
    int mask = 0xffffffff;
    mask &= (~(1 << (32 - subnet_bits)));
    return mask;
}

int getNetworkId(int subnet_bits, int subnet_mask) {
    int network_id = subnet_mask;
    network_id <<= subnet_bits;
    return network_id;
}

int getBroadcastId(int subnet_bits, int subnet_mask) {
    int broadcast_id = getNetworkId(subnet_bits, subnet_mask) + 1;
    broadcast_id &= getSubnetMask(subnet_bits);
    return broadcast_id;
}

int getFirstHostId(int subnet_bits, int subnet_mask) {
    int first_host_id = getNetworkId(subnet_bits, subnet_mask);
    first_host_id += 1;
    first_host_id &= getSubnetMask(subnet_bits);
    return first_host_id;
}

int getLastHostId(int subnet_bits, int subnet_mask) {
    int last_host_id = getNetworkId(subnet_bits, subnet_mask);
    last_host_id -= 1;
    last_host_id &= getSubnetMask(subnet_bits);
    return last_host_id;
}

int getNumHosts(int subnet_bits, int subnet_mask) {
    return getLastHostId(subnet_bits, subnet_mask) - getFirstHostId(subnet_bits, subnet_mask) + 1;
}

int main() {
    int subnet_bits = 24;
    int subnet_mask = getSubnetMask(subnet_bits);
    int network_id = getNetworkId(subnet_bits, subnet_mask);
    int broadcast_id = getBroadcastId(subnet_bits, subnet_mask);
    int first_host_id = getFirstHostId(subnet_bits, subnet_mask);
    int last_host_id = getLastHostId(subnet_bits, subnet_mask);
    int num_hosts = getNumHosts(subnet_bits, subnet_mask);

    printf("Subnet mask: %d\n", subnet_mask);
    printf("Network ID: %d\n", network_id);
    printf("Broadcast ID: %d\n", broadcast_id);
    printf("First host ID: %d\n", first_host_id);
    printf("Last host ID: %d\n", last_host_id);
    printf("Number of hosts: %d\n", num_hosts);

    return 0;
}