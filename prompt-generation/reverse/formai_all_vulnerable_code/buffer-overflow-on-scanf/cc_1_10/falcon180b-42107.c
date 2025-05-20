//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate subnet mask
void calculate_subnet_mask(int ip_address[], int subnet_bits) {
    int i, j;
    char subnet_mask[16];
    memset(subnet_mask, '0', 16);

    for (i = 0; i < subnet_bits; i++) {
        subnet_mask[i] = '1';
    }

    for (i = subnet_bits; i < 16; i++) {
        subnet_mask[i] = '0';
    }

    printf("Subnet mask: %s\n", subnet_mask);
}

// Function to calculate network address
void calculate_network_address(int ip_address[], int subnet_bits) {
    int i;
    int network_address[4];

    for (i = 0; i < 4; i++) {
        network_address[i] = ip_address[i] & (255 - (1 << (8 - subnet_bits)));
    }

    printf("Network address: %d.%d.%d.%d\n", network_address[0], network_address[1], network_address[2], network_address[3]);
}

// Function to calculate broadcast address
void calculate_broadcast_address(int ip_address[], int subnet_bits) {
    int i;
    int broadcast_address[4];

    for (i = 0; i < 4; i++) {
        broadcast_address[i] = ip_address[i] | (~(255 - (1 << (8 - subnet_bits))));
    }

    printf("Broadcast address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
}

// Function to calculate number of hosts
void calculate_number_of_hosts(int subnet_bits) {
    int number_of_hosts = (int)pow(2, subnet_bits) - 2;

    printf("Number of hosts: %d\n", number_of_hosts);
}

int main() {
    int ip_address[4], subnet_bits;

    printf("Enter IP address: ");
    scanf("%d.%d.%d.%d", &ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3]);

    printf("Enter subnet bits: ");
    scanf("%d", &subnet_bits);

    calculate_subnet_mask(ip_address, subnet_bits);
    calculate_network_address(ip_address, subnet_bits);
    calculate_broadcast_address(ip_address, subnet_bits);
    calculate_number_of_hosts(subnet_bits);

    return 0;
}