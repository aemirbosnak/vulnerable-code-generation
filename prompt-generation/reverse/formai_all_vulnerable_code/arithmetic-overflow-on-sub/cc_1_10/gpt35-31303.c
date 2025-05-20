//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include<stdio.h>

int main() {
    //Title
    printf("-----Subnet Calculator in C-----\n");
    printf("Surprise! You're about to reckon some IPs...\n");
    
    //Initializations
    int ip_address[4], subnet_mask[4], subnet_bits;
    int subnet_octets[4], mask;
    int subnet_id[4], broadcast_id[4];
    int potential_hosts, broadcast_octet;
    int i, j;
    
    //Prompt User for IP Address
    printf("Please enter your IP Address:");
    scanf("%d.%d.%d.%d",&ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3]);

    //Prompt User for Subnet Mask
    printf("Please enter your Subnet Mask:");
    scanf("%d.%d.%d.%d",&subnet_mask[0], &subnet_mask[1], &subnet_mask[2], &subnet_mask[3]);

    //Prompt User for Subnet Bits
    printf("Please enter the number of Subnet Bits:");
    scanf("%d",&subnet_bits);

    //Calculate Mask and Subnet Octets
    mask = 0xffffff00 << (subnet_bits % 8);
    subnet_octets[0] = (subnet_mask[0] & (mask >> 24)) | (ip_address[0] & ~(mask >> 24));
    subnet_octets[1] = (subnet_mask[1] & (mask >> 16)) | (ip_address[1] & ~(mask >> 16));
    subnet_octets[2] = (subnet_mask[2] & (mask >> 8)) | (ip_address[2] & ~(mask >> 8));
    subnet_octets[3] = (subnet_mask[3] & mask) | (ip_address[3] & ~mask);

    //Calculate Network ID
    subnet_id[0] = subnet_octets[0];
    subnet_id[1] = subnet_octets[1];
    subnet_id[2] = subnet_octets[2];
    subnet_id[3] = subnet_octets[3];

    //Calculate Broadcast ID
    potential_hosts = 1 << (32 - subnet_bits);
    broadcast_octet = (potential_hosts - 1) % 256;
    broadcast_id[0] = (subnet_id[0] & ~mask) | broadcast_octet;
    broadcast_id[1] = (subnet_id[1] & ~mask) | ((potential_hosts - 1) / 256 % 256);
    broadcast_id[2] = (subnet_id[2] & ~mask) | ((potential_hosts - 1) / 256 / 256 % 256);
    broadcast_id[3] = (subnet_id[3] & ~mask) | (potential_hosts - 2) % 256;

    //Display the Calculations
    printf("Subnet Address:%d.%d.%d.%d\n", subnet_id[0],subnet_id[1],subnet_id[2],subnet_id[3]);
    printf("Broadcast Address:%d.%d.%d.%d\n", broadcast_id[0],broadcast_id[1],broadcast_id[2],broadcast_id[3]);
    printf("Number of Hosts:%d\n", potential_hosts - 2);
    printf("Wildcard Mask:%d.%d.%d.%d\n", ~subnet_mask[0] & 255, ~subnet_mask[1] & 255, ~subnet_mask[2] & 255, ~subnet_mask[3] & 255);
    printf("Mask Bits:%d\n", subnet_bits);
    
    printf("\n\nWow! That was a pretty astounding subnet calculator. Thank you for using!\n");

    return 0;
}