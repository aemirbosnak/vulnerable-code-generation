//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: curious
/* Curious Subnet Calculator */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Curious Subnet Calculator!\n");
    printf("Enter the IP address: ");

    char ip_address[16];
    fgets(ip_address, 16, stdin);

    printf("Enter the network mask: ");

    char network_mask[3];
    fgets(network_mask, 3, stdin);

    int subnet_bits = atoi(network_mask);
    int address_parts[4];
    sscanf(ip_address, "%d.%d.%d.%d", &address_parts[0], &address_parts[1], &address_parts[2], &address_parts[3]);

    int subnet_octet = subnet_bits / 8;
    int leftover_bits = subnet_bits % 8;

    int subnet_mask[4] = {0, 0, 0, 0};

    for (int i = 0; i < subnet_octet; i++) {
        subnet_mask[i] = 255;
    }

    if (leftover_bits > 0) {
        subnet_mask[subnet_octet] = (256 - (1 << (8 - leftover_bits)));
    }

    printf("\n");

    for (int i = 0; i < 4; i++) {
        printf("Octet %d: %d\n", i + 1, address_parts[i]);
    }

    printf("\nSubnet Mask:\n");

    for (int i = 0; i < 4; i++) {
        printf("%d", subnet_mask[i]);
        if (i < 3) {
            printf(".");
        }
    }

    printf("\n");

    int num_hosts = 1 << (8 - leftover_bits);

    printf("\nNumber of Hosts: %d\n", num_hosts - 2);

    printf("\nNetwork Address:\n");

    for (int i = 0; i < 4; i++) {
        printf("%d", address_parts[i] & subnet_mask[i]);
        if (i < 3) {
            printf(".");
        }
    }

    printf("\n");

    int broadcast_address[4];

    for (int i = 0; i < 4; i++) {
        if (i < subnet_octet) {
            broadcast_address[i] = address_parts[i];
        } else if (i == subnet_octet) {
            broadcast_address[i] = address_parts[i] | (~subnet_mask[i] & 0xFF);
        } else {
            broadcast_address[i] = 255;
        }
    }

    printf("\nBroadcast Address:\n");

    for (int i = 0; i < 4; i++) {
        printf("%d", broadcast_address[i]);
        if (i < 3) {
            printf(".");
        }
    }

    printf("\n");

    return 0;
}