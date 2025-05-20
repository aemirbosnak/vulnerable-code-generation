//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 15

int main()
{
    char ip[MAX_IP_LENGTH];
    int subnet_mask, octets[4], i, num_hosts;

    printf("Enter an IP address in dotted decimal format (xxx.xxx.xxx.xxx): ");
    fgets(ip, MAX_IP_LENGTH, stdin);

    printf("Enter the subnet mask as a number between 0 and 32: ");
    scanf("%d", &subnet_mask);

    // Split IP address into octets
    char *p = strtok(ip, ".");
    for (i = 0; i < 4; i++) {
        octets[i] = atoi(p);
        p = strtok(NULL, ".");
    }

    // Calculate subnet mask in binary
    int mask_binary[32];
    for (i = 0; i < subnet_mask; i++) {
        mask_binary[i] = 1;
    }
    for (i = subnet_mask; i < 32; i++) {
        mask_binary[i] = 0;
    }

    // Calculate network address in decimal
    int network_address[4];
    for (i = 0; i < 4; i++) {
        network_address[i] = octets[i] & (mask_binary[i*8] * 128 + mask_binary[i*8+1] * 64 + mask_binary[i*8+2] * 32 + mask_binary[i*8+3] * 16 + mask_binary[i*8+4] * 8 + mask_binary[i*8+5] * 4 + mask_binary[i*8+6] * 2 + mask_binary[i*8+7]);
    }

    // Calculate broadcast address in decimal
    int broadcast_address[4];
    for (i = 0; i < 4; i++) {
        broadcast_address[i] = octets[i] | ((mask_binary[i*8] * 128 + mask_binary[i*8+1] * 64 + mask_binary[i*8+2] * 32 + mask_binary[i*8+3] * 16 + mask_binary[i*8+4] * 8 + mask_binary[i*8+5] * 4 + mask_binary[i*8+6] * 2 + mask_binary[i*8+7]) ^ 255);
    }

    // Calculate number of hosts in subnet
    num_hosts = 1;
    for (i = 0; i < 32 - subnet_mask; i++) {
        num_hosts *= 2;
    }
    num_hosts -= 2; // Subtract network and broadcast addresses

    // Print results
    printf("\nNetwork address: %d.%d.%d.%d\n", network_address[0], network_address[1], network_address[2], network_address[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
    printf("Number of hosts in subnet: %d\n", num_hosts);

    return 0;
}