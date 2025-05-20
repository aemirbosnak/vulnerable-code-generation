//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int prefix, mask[4], i, j;
    char ip[16];
    printf("Enter IP address in dotted decimal notation: ");
    scanf("%s", &ip);
    printf("Enter prefix length: ");
    scanf("%d", &prefix);

    // Convert dotted decimal notation to integer values
    sscanf(ip, "%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

    // Calculate subnet mask based on prefix length
    for (i = 0; i < 4; i++) {
        if (prefix >= 8) {
            mask[i] = 255;
            prefix -= 8;
        }
        else if (prefix > 0) {
            mask[i] |= (1 << prefix) - 1;
            prefix = 0;
        }
        else {
            mask[i] = 0;
        }
    }

    // Print subnet mask in dotted decimal notation
    printf("Subnet mask: %d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);

    // Calculate network address
    int network[4];
    for (i = 0; i < 4; i++) {
        network[i] = mask[i] & mask[i];
    }

    // Print network address in dotted decimal notation
    printf("Network address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);

    // Calculate broadcast address
    int broadcast[4];
    for (i = 0; i < 4; i++) {
        broadcast[i] = network[i] | (~mask[i] & 255);
    }

    // Print broadcast address in dotted decimal notation
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);

    // Calculate number of hosts
    int hosts = 1;
    for (i = 0; i < 4; i++) {
        if (mask[i] != 255) {
            for (j = 0; j < 8; j++) {
                if (((mask[i] >> j) & 1) == 0) {
                    hosts <<= 1;
                }
            }
        }
    }
    hosts -= 2;

    // Print number of hosts
    printf("Number of hosts: %d\n", hosts);

    return 0;
}