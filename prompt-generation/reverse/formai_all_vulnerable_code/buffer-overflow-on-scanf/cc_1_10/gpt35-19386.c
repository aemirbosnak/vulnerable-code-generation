//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void calculate_subnet(char *ipaddr, char *subnetmask) {
    char *ipaddr_octets[4], *subnetmask_octets[4];
    int ipaddr_int[4], subnetmask_int[4], network_address_int[4], broadcast_address_int[4];
    char network_address_char[16], broadcast_address_char[16];
    int bits_set = 0, i, j;

    // Parse IP address and subnet mask into octets
    ipaddr_octets[0] = strtok(ipaddr, ".");
    for (i = 1; i < 4; i++) {
        ipaddr_octets[i] = strtok(NULL, ".");
    }
    subnetmask_octets[0] = strtok(subnetmask, ".");
    for (i = 1; i < 4; i++) {
        subnetmask_octets[i] = strtok(NULL, ".");
    }

    // Convert octets to integers
    for (i = 0; i < 4; i++) {
        ipaddr_int[i] = atoi(ipaddr_octets[i]);
        subnetmask_int[i] = atoi(subnetmask_octets[i]);
    }

    // Calculate network and broadcast addresses
    for (i = 0; i < 4; i++) {
        network_address_int[i] = ipaddr_int[i] & subnetmask_int[i];
        broadcast_address_int[i] = ipaddr_int[i] | (~subnetmask_int[i] & 0xFF);
    }

    // Convert network and broadcast addresses back to char arrays
    sprintf(network_address_char, "%d.%d.%d.%d", network_address_int[0], network_address_int[1], network_address_int[2], network_address_int[3]);
    sprintf(broadcast_address_char, "%d.%d.%d.%d", broadcast_address_int[0], broadcast_address_int[1], broadcast_address_int[2], broadcast_address_int[3]);

    // Count number of bits set in the subnet mask
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            if ((subnetmask_int[i] & (int)pow(2, j)) != 0) {
                bits_set++;
            }
        }
    }

    // Output results
    printf("IP Address:   %s\n", ipaddr);
    printf("Subnet Mask:  %s\n", subnetmask);
    printf("Network Address: %s\n", network_address_char);
    printf("Broadcast Address: %s\n", broadcast_address_char);
    printf("Number of Hosts: %d\n", (int)pow(2, 32-bits_set)-2);
}

int main() {
    char ipaddr[16], subnetmask[16];

    printf("Enter IP Address: ");
    scanf("%s", ipaddr);
    printf("Enter Subnet Mask: ");
    scanf("%s", subnetmask);

    calculate_subnet(ipaddr, subnetmask);

    return 0;
}