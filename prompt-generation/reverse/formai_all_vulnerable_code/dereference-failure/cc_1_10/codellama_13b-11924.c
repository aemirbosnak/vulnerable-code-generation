//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: enthusiastic
/*
 * C Subnet Calculator
 *
 * This program calculates the subnet mask and network ID for a given IP address.
 *
 * Usage: ./subnet_calculator <ip_address>
 *
 * Example: ./subnet_calculator 192.168.1.100
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Check if the user has provided an IP address
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }

    // Convert the IP address to a binary string
    char *ip_address = argv[1];
    int binary_ip[32];
    int i;
    for (i = 0; i < 32; i++) {
        binary_ip[i] = (ip_address[i / 8] >> (7 - i % 8)) & 1;
    }

    // Calculate the subnet mask
    int subnet_mask[32];
    for (i = 0; i < 32; i++) {
        subnet_mask[i] = (i + 1) % 8 == 0 ? 1 : 0;
    }

    // Calculate the network ID
    int network_id[32];
    for (i = 0; i < 32; i++) {
        network_id[i] = binary_ip[i] & subnet_mask[i];
    }

    // Print the results
    printf("Subnet Mask: ");
    for (i = 0; i < 32; i++) {
        printf("%d", subnet_mask[i]);
    }
    printf("\n");
    printf("Network ID: ");
    for (i = 0; i < 32; i++) {
        printf("%d", network_id[i]);
    }
    printf("\n");

    return 0;
}