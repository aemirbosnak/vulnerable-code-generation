//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* This is a visionary C Subnet Calculator Program */
/* It takes a network address and a subnet mask as input */
/* And outputs the corresponding subnet information */

int main() {
    char net_address[16], subnet_mask[16];
    int ip[4], subnet[4], mask[4], subnet_bits;
    unsigned int subnet_id, broadcast_id, host_id, num_hosts;

    // Prompt user for network IP address and subnet mask
    printf("Enter the network IP address (xxx.xxx.xxx.xxx): ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Enter the subnet mask (xxx.xxx.xxx.xxx): ");
    scanf("%d.%d.%d.%d", &subnet[0], &subnet[1], &subnet[2], &subnet[3]);

    // Convert subnet mask to binary
    for (int i = 0; i < 4; i++) {
        mask[i] = 0;
        for (int j = 0; j < 8; j++) {
            mask[i] += ((subnet[i] >> (7 - j)) & 1) * (int)pow(2, j);
        }
    }

    // Calculate the number of subnet bits and host bits
    subnet_bits = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 7; j >= 0; j--) {
            if (((mask[i] >> j) & 1) == 0) {
                subnet_bits++;
            }
            else {
                break;
            }
        }
    }
    int host_bits = 32 - subnet_bits;

    // Calculate the subnet ID and broadcast ID
    subnet_id = (ip[0] & mask[0]) * (int)pow(2, 24) + (ip[1] & mask[1]) * (int)pow(2, 16) + (ip[2] & mask[2]) * (int)pow(2, 8) + (ip[3] & mask[3]);
    broadcast_id = subnet_id + (int)(pow(2, host_bits)) - 1;

    // Calculate the number of hosts
    num_hosts = (int)pow(2, host_bits) - 2;

    // Output the subnet information
    printf("\n");
    printf("Network address:\t%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    printf("Subnet mask:\t\t%d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);
    printf("Subnet ID:\t\t%d\n", subnet_id);
    printf("Broadcast ID:\t\t%d\n", broadcast_id);
    printf("Number of subnet bits:\t%d\n", subnet_bits);
    printf("Number of host bits:\t%d\n", host_bits);
    printf("Number of hosts:\t%d\n", num_hosts);

    return 0;
}