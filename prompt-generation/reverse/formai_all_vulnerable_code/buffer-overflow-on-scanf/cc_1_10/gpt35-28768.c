//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OCTET_VALUE 255

int main() {
    char ip_address[16];
    int subnet_mask;
    char subnet_mask_binary[35];
    char network_address[16];
    char broadcast_address[16];
    int subnet_bits_count = 0;
    int host_bits_count = 0;
    int i, j;
    int ip_address_octets[4];
    int subnet_mask_binary_octets[4];

    printf("Enter IP address: ");
    scanf("%15s", ip_address);
    printf("Enter subnet mask (in decimal notation): ");
    scanf("%d", &subnet_mask);

    // Error handling for invalid IP address
    if (sscanf(ip_address, "%d.%d.%d.%d", &ip_address_octets[0], &ip_address_octets[1], &ip_address_octets[2], &ip_address_octets[3]) != 4) {
        printf("Invalid IP address\n");
        exit(EXIT_FAILURE);
    }

    // Error handling for invalid subnet mask
    if (subnet_mask < 0 || subnet_mask > 32) {
        printf("Invalid subnet mask\n");
        exit(EXIT_FAILURE);
    }

    // Converting subnet mask from decimal to binary notation
    for (i = 0; i < subnet_mask; i++) {
        subnet_mask_binary[i] = '1';
    }
    subnet_mask_binary[i] = '\0';

    for (i = subnet_mask; i < 32; i++) {
        subnet_mask_binary[i] = '0';
    }
    subnet_mask_binary[i] = '\0';

    // Converting subnet mask from binary to decimal notation
    for (i = 0, j = 0; i < strlen(subnet_mask_binary); i+=8, j++) {
        char octet[8];
        strncpy(octet, subnet_mask_binary+i, 8);
        octet[8] = '\0';
        subnet_mask_binary_octets[j] = strtol(octet, NULL, 2);
    }

    // Calculating subnet bits count
    for (i = 0; i < 4; i++) {
        subnet_bits_count += __builtin_popcount(subnet_mask_binary_octets[i]);
    }

    // Calculating host bits count
    host_bits_count = 32 - subnet_bits_count;

    // Calculating network address
    for (i = 0; i < 4; i++) {
        network_address[i] = ip_address_octets[i] & subnet_mask_binary_octets[i];
    }
    network_address[i] = '\0';

    // Calculating broadcast address
    for (i = 0; i < 4; i++) {
        broadcast_address[i] = network_address[i] | ~subnet_mask_binary_octets[i];
    }
    broadcast_address[i] = '\0';

    // Printing results
    printf("\n----------------------------------------\n");
    printf("IP address: %s\n", ip_address);
    printf("Subnet mask (in decimal notation): %d\n", subnet_mask);
    printf("Subnet mask (in binary notation): %s\n", subnet_mask_binary);
    printf("Network address: %s\n", network_address);
    printf("Broadcast address: %s\n", broadcast_address);
    printf("Number of subnet bits: %d\n", subnet_bits_count);
    printf("Number of host bits: %d\n", host_bits_count);
    printf("----------------------------------------\n");

    return 0;
}