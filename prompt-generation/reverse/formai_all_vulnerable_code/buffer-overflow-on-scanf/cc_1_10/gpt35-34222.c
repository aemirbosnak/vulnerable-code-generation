//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    // declare variables
    char ip[20], mask[20];
    int cidr, i, j, k, l, n;
    int octet[4], binary_mask[32];

    // read input from user
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter subnet mask in CIDR notation: ");
    scanf("%d", &cidr);

    // convert CIDR notation to binary mask
    memset(binary_mask, 0, sizeof(binary_mask));
    for (i = 0; i < cidr; i++) {
        binary_mask[i] = 1;
    }

    // split IP address into octets
    sscanf(ip, "%d.%d.%d.%d", &octet[0], &octet[1], &octet[2], &octet[3]);

    // calculate subnet mask in decimal notation
    memset(mask, 0, sizeof(mask));
    for (i = 0, j = 0; i < 32; i += 8, j++) {
        for (k = i, l = 7, n = 0; k < i + 8; k++, l--) {
            n += binary_mask[k] * (int)pow(2, l);
        }
        sprintf(mask + strlen(mask), "%d", n);
        if (j < 3)
            sprintf(mask + strlen(mask), ".");
    }

    // calculate network address
    int network[4];
    for (i = 0; i < 4; i++) {
        network[i] = octet[i] & (binary_mask[i*8] * (int)pow(2, 7) + binary_mask[i*8+1] * (int)pow(2, 6) + binary_mask[i*8+2] * (int)pow(2, 5) + binary_mask[i*8+3] * (int)pow(2, 4) + binary_mask[i*8+4] * (int)pow(2, 3) + binary_mask[i*8+5] * (int)pow(2, 2) + binary_mask[i*8+6] * (int)pow(2, 1) + binary_mask[i*8+7]);
    }

    // calculate broadcast address
    int broadcast[4];
    for (i = 0; i < 4; i++) {
        broadcast[i] = network[i] | (~binary_mask[i*8] * (int)pow(2, 7) + ~binary_mask[i*8+1] * (int)pow(2, 6) + ~binary_mask[i*8+2] * (int)pow(2, 5) + ~binary_mask[i*8+3] * (int)pow(2, 4) + ~binary_mask[i*8+4] * (int)pow(2, 3) + ~binary_mask[i*8+5] * (int)pow(2, 2) + ~binary_mask[i*8+6] * (int)pow(2, 1) + ~binary_mask[i*8+7]);
    }

    // calculate number of hosts
    int num_hosts = (int)pow(2, 32 - cidr) - 2;

    // output results
    printf("\nIP address: %s\n", ip);
    printf("Subnet mask: %s\n", mask);
    printf("Network address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Number of hosts: %d\n", num_hosts);

    return 0;
}