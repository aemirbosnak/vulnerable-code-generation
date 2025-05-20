//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <math.h>

int main() {
    // Get the user's input
    char ip_address[20];
    char subnet_mask[20];
    printf("Enter the IP address: ");
    scanf("%s", ip_address);
    printf("Enter the subnet mask: ");
    scanf("%s", subnet_mask);

    // Convert the IP address and subnet mask to binary
    unsigned int ip_binary[32];
    unsigned int subnet_mask_binary[32];
    for (int i = 0; i < 32; i++) {
        ip_binary[i] = (ip_address[i / 8] & (1 << (7 - (i % 8)))) ? 1 : 0;
        subnet_mask_binary[i] = (subnet_mask[i / 8] & (1 << (7 - (i % 8)))) ? 1 : 0;
    }

    // Calculate the network address
    unsigned int network_address_binary[32];
    for (int i = 0; i < 32; i++) {
        network_address_binary[i] = ip_binary[i] & subnet_mask_binary[i];
    }

    // Convert the network address to decimal
    unsigned int network_address_decimal[4];
    for (int i = 0; i < 4; i++) {
        network_address_decimal[i] = 0;
        for (int j = 0; j < 8; j++) {
            network_address_decimal[i] |= (network_address_binary[i * 8 + j] << (7 - j));
        }
    }

    // Calculate the broadcast address
    unsigned int broadcast_address_binary[32];
    for (int i = 0; i < 32; i++) {
        broadcast_address_binary[i] = ip_binary[i] | (~subnet_mask_binary[i]);
    }

    // Convert the broadcast address to decimal
    unsigned int broadcast_address_decimal[4];
    for (int i = 0; i < 4; i++) {
        broadcast_address_decimal[i] = 0;
        for (int j = 0; j < 8; j++) {
            broadcast_address_decimal[i] |= (broadcast_address_binary[i * 8 + j] << (7 - j));
        }
    }

    // Calculate the number of hosts
    unsigned int number_of_hosts = pow(2, 32 - subnet_mask_binary[31]);

    // Print the results
    printf("Network address: %d.%d.%d.%d\n", network_address_decimal[0], network_address_decimal[1], network_address_decimal[2], network_address_decimal[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast_address_decimal[0], broadcast_address_decimal[1], broadcast_address_decimal[2], broadcast_address_decimal[3]);
    printf("Number of hosts: %d\n", number_of_hosts);

    return 0;
}