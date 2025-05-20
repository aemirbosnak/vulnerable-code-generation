//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the subnet structure
typedef struct subnet {
    char ip_address[16];
    char subnet_mask[16];
    char network_address[16];
    char broadcast_address[16];
} Subnet;

// function to calculate the network and broadcast addresses
void calculate_addresses(Subnet* sn) {
    // split the IP address and subnet mask into integers
    int ip[4] = {0};
    int mask[4] = {0};
    sscanf(sn->ip_address, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    sscanf(sn->subnet_mask, "%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

    // calculate network address
    int network[4] = {0};
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
    }
    sprintf(sn->network_address, "%d.%d.%d.%d", network[0], network[1], network[2], network[3]);

    // calculate broadcast address
    int broadcast[4] = {0};
    for (int i = 0; i < 4; i++) {
        broadcast[i] = ip[i] | (~mask[i] & 0xff);
    }
    sprintf(sn->broadcast_address, "%d.%d.%d.%d", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
}

int main() {
    // create a new subnet structure
    Subnet my_subnet = {"192.168.0.1", "255.255.255.0", "", ""};

    // calculate the network and broadcast addresses
    calculate_addresses(&my_subnet);

    // output the results
    printf("IP Address:\t%s\n", my_subnet.ip_address);
    printf("Subnet Mask:\t%s\n", my_subnet.subnet_mask);
    printf("Network Address:%s\n", my_subnet.network_address);
    printf("Broadcast Address:%s\n", my_subnet.broadcast_address);

    return 0;
}