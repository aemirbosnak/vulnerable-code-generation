//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <math.h>

int main() {
    int address[4], subnet_mask[4], subnet_bits, network_id[4], broadcast_id[4], hosts;
    
    printf("Welcome to the Energetic Subnet Calculator!\n");
    printf("Please enter the IPv4 address: ");
    scanf("%d.%d.%d.%d", &address[0], &address[1], &address[2], &address[3]);
    printf("Please enter the number of bits for the subnet mask: ");
    scanf("%d", &subnet_bits);
    
    // Calculate subnet mask
    int i, j, k = 0;
    for (i = 0; i < 4; i++) {
        if (subnet_bits >= 8) {
            subnet_mask[i] = 255;
            subnet_bits -= 8;
        } else if (subnet_bits > 0) {
            for (j = 7; j >= 8 - subnet_bits; j--) {
                subnet_mask[i] += pow(2, j);
            }
            subnet_bits = 0;
        } else {
            subnet_mask[i] = 0;
        }
    }
    
    // Calculate network ID
    for (i = 0; i < 4; i++) {
        network_id[i] = address[i] & subnet_mask[i];
    }
    
    // Calculate broadcast ID
    for (i = 0; i < 4; i++) {
        broadcast_id[i] = network_id[i] | (~subnet_mask[i] & 255);
    }
    
    // Calculate number of hosts
    hosts = pow(2, 32 - subnet_bits) - 2;
    
    printf("=========================================\n");
    printf("IP Address\t: %d.%d.%d.%d\n", address[0], address[1], address[2], address[3]);
    printf("Subnet Mask\t: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
    printf("Network ID\t: %d.%d.%d.%d\n", network_id[0], network_id[1], network_id[2], network_id[3]);
    printf("Broadcast ID\t: %d.%d.%d.%d\n", broadcast_id[0], broadcast_id[1], broadcast_id[2], broadcast_id[3]);
    printf("Number of Hosts\t: %d\n", hosts);
    printf("=========================================\n");
    
    return 0;
}