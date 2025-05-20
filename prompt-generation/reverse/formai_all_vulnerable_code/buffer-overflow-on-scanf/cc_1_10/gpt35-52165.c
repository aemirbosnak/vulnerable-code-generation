//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Declare variables
    char ip_addr[16];
    int subnet_mask;
    char subnet_mask_str[16], subnet_mask_binary[33], subnet_mask_decimal[16];
    char network_addr[16], broadcast_addr[16];
    int num_hosts;

    // Get IP address
    printf("Enter IP address: ");
    fgets(ip_addr, 16, stdin);
    strtok(ip_addr, "\n");  // Remove newline character

    // Get subnet mask
    printf("Enter subnet mask (as integer): ");
    scanf("%d", &subnet_mask);

    // Convert subnet mask to binary and decimal forms
    for (int i = 0; i < 32; i++) {
        if (i < subnet_mask) {
            subnet_mask_binary[i] = '1';
        } else {
            subnet_mask_binary[i] = '0';
        }
        if ((i+1) % 8 == 0 && i != 31) {
            subnet_mask_binary[i+1] = '.';
        }
    }
    snprintf(subnet_mask_str, sizeof(subnet_mask_str), "%s", subnet_mask_binary);
    printf("Subnet mask (binary): %s\n", subnet_mask_str);

    // Calculate decimal form of subnet mask
    snprintf(subnet_mask_decimal, sizeof(subnet_mask_decimal), "%d.%d.%d.%d",
             strtol(&subnet_mask_str[0], NULL, 2), strtol(&subnet_mask_str[9], NULL, 2),
             strtol(&subnet_mask_str[18], NULL, 2), strtol(&subnet_mask_str[27], NULL, 2));
    printf("Subnet mask (decimal): %s\n", subnet_mask_decimal);

    // Get network and broadcast addresses
    for (int i = 0; i < 16; i++) {
        if (subnet_mask_decimal[i] != '.') {
            network_addr[i] = ip_addr[i] & subnet_mask_decimal[i];
            broadcast_addr[i] = ip_addr[i] | ~subnet_mask_decimal[i];
        } else {
            network_addr[i] = subnet_mask_decimal[i];
            broadcast_addr[i] = subnet_mask_decimal[i];
        }
    }
    printf("Network address: %s\n", network_addr);
    printf("Broadcast address: %s\n", broadcast_addr);

    // Calculate number of hosts
    num_hosts = (1 << (32 - subnet_mask)) - 2;
    printf("Number of hosts: %d\n", num_hosts);

    return 0;
}