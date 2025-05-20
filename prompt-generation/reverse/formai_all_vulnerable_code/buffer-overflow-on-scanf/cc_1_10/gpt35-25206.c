//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {

    int ip_address[4];
    int subnet_mask[4];
    int subnet_bits;
    int subnet[4];
    int network_address[4];
    int broadcast_address[4];

    // input IP address
    printf("Enter IP address (xxx.xxx.xxx.xxx format): ");
    scanf("%d.%d.%d.%d", &ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3]);

    // input subnet mask
    printf("Enter subnet mask (/x format): ");
    scanf("/%d", &subnet_bits);

    // calculate subnet mask bits
    int i;
    for (i = 0; i < subnet_bits; i++) {
        subnet_mask[i/8] |= 1 << (7 - i % 8);
    }

    // calculate subnet address
    for (i = 0; i < 4; i++) {
        subnet[i] = ip_address[i] & subnet_mask[i];
    }

    // calculate network address
    for (i = 0; i < 4; i++) {
        network_address[i] = subnet[i];
    }

    // calculate broadcast address
    for (i = 0; i < 4; i++) {
        broadcast_address[i] = subnet[i] | ~subnet_mask[i];
    }

    // output results
    printf("IP address: %d.%d.%d.%d\n", ip_address[0], ip_address[1], ip_address[2], ip_address[3]);
    printf("Subnet mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
    printf("Subnet address: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);
    printf("Network address: %d.%d.%d.%d\n", network_address[0], network_address[1], network_address[2], network_address[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);

    return 0;
}