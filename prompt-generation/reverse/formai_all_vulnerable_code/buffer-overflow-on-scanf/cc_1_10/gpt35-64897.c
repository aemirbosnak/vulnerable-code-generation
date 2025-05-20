//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip[16], subnet[16];
    int mask, hosts, first, last, bits, i, j, k = 0;

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter subnet mask: ");
    scanf("%d", &mask);

    // extract subnet mask
    i = mask / 8;
    j = mask % 8;
    for (k = 0; k < i; k++) {
        subnet[k] = 255;
    }
    if (j > 0) {
        subnet[k++] = (256 - (1 << (8 - j)));
    }
    while (k < 4) {
        subnet[k++] = 0;
    }

    // calculate network address
    unsigned char net[4];
    for (k = 0; k < 4; k++) {
        net[k] = (ip[k] & subnet[k]);
    }

    // calculate broadcast address
    unsigned char bcast[4];
    for (k = 0; k < 4; k++) {
        bcast[k] = (net[k] | (~subnet[k] & 0xff));
    }

    // calculate number of usable hosts
    bits = 32 - mask;
    hosts = (bits == 32) ? 0 : (1 << bits) - 2;

    // calculate first and last usable address
    first = ((net[0] << 24) | (net[1] << 16) | (net[2] << 8) | net[3]) + 1;
    last = ((bcast[0] << 24) | (bcast[1] << 16) | (bcast[2] << 8) | bcast[3]) - 1;

    // print results
    printf("Netmask: %u.%u.%u.%u\n", subnet[0], subnet[1], subnet[2], subnet[3]);
    printf("Network Address: %u.%u.%u.%u\n", net[0], net[1], net[2], net[3]);
    printf("Broadcast Address: %u.%u.%u.%u\n", bcast[0], bcast[1], bcast[2], bcast[3]);
    printf("Usable Hosts: %d\n", hosts);
    printf("First Usable Address: %u.%u.%u.%u\n", (first >> 24) & 0xff, (first >> 16) & 0xff, (first >> 8) & 0xff, first & 0xff);
    printf("Last Usable Address: %u.%u.%u.%u\n", (last >> 24) & 0xff, (last >> 16) & 0xff, (last >> 8) & 0xff, last & 0xff);

    return 0;
}