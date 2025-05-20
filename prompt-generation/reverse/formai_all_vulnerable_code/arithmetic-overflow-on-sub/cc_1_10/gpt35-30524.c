//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip_address[15];
    char subnet_mask[15];
    int subnet_bits;
    int mask[32];
    int network_address[4];
    int broadcast_address[4];

    printf("Welcome to the Subnet Calculator!\n\n");

    printf("Please enter your IP address: ");
    scanf("%s", ip_address);

    printf("Please enter your subnet mask: ");
    scanf("%s", subnet_mask);

    printf("Please enter the number of subnet bits: ");
    scanf("%d", &subnet_bits);

    // Convert subnet mask to binary
    char *token = strtok(subnet_mask, ".");
    int i = 0;
    while (token != NULL) {
        int octet = atoi(token);

        // Convert octet to binary
        for (int j = 0; j < 8; j++) {
            mask[i*8+j] = octet % 2;
            octet /= 2;
        }

        i++;
        token = strtok(NULL, ".");
    }

    // Apply subnet bits to the mask
    for (int j = 31; j >= 0; j--) {
        if (j >= 32 - subnet_bits) {
            mask[j] = 1;
        } else {
            mask[j] = 0;
        }
    }

    // Convert IP address to binary
    token = strtok(ip_address, ".");
    i = 0;
    while (token != NULL) {
        int octet = atoi(token);

        // Convert octet to binary
        for (int j = 0; j < 8; j++) {
            if (mask[i*8+j]) {
                network_address[i] += octet % 2;
            }
            octet /= 2;
            mask[i*8+j] = 0;
        }

        i++;
        token = strtok(NULL, ".");
    }

    // Calculate broadcast address
    memcpy(broadcast_address, network_address, sizeof network_address);
    for (int j = 31; j >= 0; j--) {
        if (mask[j] == 0) {
            broadcast_address[j/8] += 1 << (j%8);
        } else {
            break;
        }
    }

    // Print results
    printf("\nNetwork Address: %d.%d.%d.%d\n", network_address[3], network_address[2], network_address[1], network_address[0]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_address[3], broadcast_address[2], broadcast_address[1], broadcast_address[0]);

    return 0;
}