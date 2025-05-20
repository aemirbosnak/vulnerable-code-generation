//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int subnet_mask, num_of_hosts = 0;
    unsigned char ip_address[4];
    unsigned char subnet_mask_oct[4];
    unsigned char net_address[4];
    unsigned char broadcast_address[4];
    unsigned char first_address[4];
    unsigned char last_address[4];
    
    printf("Enter IP Address: ");
    scanf("%hhu.%hhu.%hhu.%hhu", &ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3]);
    
    printf("Enter Subnet Mask (CIDR format): ");
    scanf("%d", &subnet_mask);
    
    // calculate subnet mask octets
    for (int i = 0; i < 4; i++) {
        if (subnet_mask >= 8) {
            subnet_mask_oct[i] = 255;
            subnet_mask -= 8;
        } else if (subnet_mask > 0) {
            subnet_mask_oct[i] = pow(2, 8-subnet_mask) - 1;
            subnet_mask = 0;
        } else {
            subnet_mask_oct[i] = 0;
        }
    }
    
    // calculate net address
    for (int i = 0; i < 4; i++) {
        net_address[i] = ip_address[i] & subnet_mask_oct[i];
    }
    
    // calculate broadcast address
    for (int i = 0; i < 4; i++) {
        broadcast_address[i] = net_address[i] | (~subnet_mask_oct[i] & 255);
    }
    
    // calculate number of hosts
    for (int i = 0; i < 4; i++) {
        if (subnet_mask_oct[i] == 255) {
            num_of_hosts += 8;
        } else if (subnet_mask_oct[i] == 0) {
            num_of_hosts += 0;
        } else {
            int bits = 0;
            unsigned char check = subnet_mask_oct[i];
            while (check > 0) {
                bits++;
                check >>= 1;
            }
            num_of_hosts += bits;
            break;
        }
    }
    
    // calculate first address
    for (int i = 0; i < 4; i++) {
        if (i == 3) {
            first_address[i] = net_address[i] + 1;
        } else {
            first_address[i] = net_address[i];
        }
    }
    
    // calculate last address
    for (int i = 0; i < 4; i++) {
        if (i == 3) {
            last_address[i] = broadcast_address[i] - 1;
        } else {
            last_address[i] = broadcast_address[i];
        }
    }
    
    // print results
    printf("\n");
    printf("IP Address: %hhu.%hhu.%hhu.%hhu\n", ip_address[0], ip_address[1], ip_address[2], ip_address[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet_mask_oct[0], subnet_mask_oct[1], subnet_mask_oct[2], subnet_mask_oct[3]);
    printf("Network Address: %d.%d.%d.%d\n", net_address[0], net_address[1], net_address[2], net_address[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
    printf("First Usable Address: %d.%d.%d.%d\n", first_address[0], first_address[1], first_address[2], first_address[3]);
    printf("Last Usable Address: %d.%d.%d.%d\n", last_address[0], last_address[1], last_address[2], last_address[3]);
    printf("Number of Hosts: %d\n", (int)pow(2, num_of_hosts)-2);
    
    return 0;
}