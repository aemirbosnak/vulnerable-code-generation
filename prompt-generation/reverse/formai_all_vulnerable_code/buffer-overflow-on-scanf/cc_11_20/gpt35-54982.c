//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>

/* This subnet calculator program calculates the subnet
mask, host ID, and broadcast ID for a given IP address and
subnet mask. Enjoy the calculation! */

int main() {

    // Declare variables
    int ip[4];
    int subnet[4];
    int subnet_bits;
    int subnet_octet;
    int subnet_mask[4];
    int host_id[4];
    int broadcast_id[4];

    // Get IP address from user
    printf("Enter your IP address (ex: 192.168.0.1): ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    // Get subnet mask from user
    printf("\nEnter your subnet mask (ex: 255.255.255.0): ");
    scanf("%d.%d.%d.%d", &subnet[0], &subnet[1], &subnet[2], &subnet[3]);
    
    // Calculate and display subnet mask in CIDR notation
    subnet_bits = 0;
    for (int i = 0; i < 4; i++) {
        if (subnet[i] == 255) {
            subnet_bits += 8;
        } else if (subnet[i] == 254) {
            subnet_bits += 7;
        } else if (subnet[i] == 252) {
            subnet_bits += 6;
        } else if (subnet[i] == 248) {
            subnet_bits += 5;
        } else if (subnet[i] == 240) {
            subnet_bits += 4;
        } else if (subnet[i] == 224) {
            subnet_bits += 3;
        } else if (subnet[i] == 192) {
            subnet_bits += 2;
        } else if (subnet[i] == 128) {
            subnet_bits += 1;
        }
    }
    printf("\nSubnet mask in CIDR notation: /%d\n", subnet_bits);

    // Get the subnet octet
    subnet_octet = subnet_bits / 8;

    // Calculate the subnet mask
    for (int i = 0; i < subnet_octet; i++) {
        subnet_mask[i] = subnet[i];
    }
    for (int i = subnet_octet; i < 4; i++) {
        subnet_mask[i] = 0;
    }
    printf("\nSubnet mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);

    // Calculate the host ID
    for (int i = 0; i < 4; i++) {
        host_id[i] = ip[i] & (~subnet_mask[i]);
    }
    printf("\nHost ID: %d.%d.%d.%d\n", host_id[0], host_id[1], host_id[2], host_id[3]);

    // Calculate the broadcast ID
    for (int i = 0; i < 4; i++) {
        broadcast_id[i] = host_id[i] | subnet_mask[i];
    }
    printf("\nBroadcast ID: %d.%d.%d.%d\n", broadcast_id[0], broadcast_id[1], broadcast_id[2], broadcast_id[3]);

    return 0;
}