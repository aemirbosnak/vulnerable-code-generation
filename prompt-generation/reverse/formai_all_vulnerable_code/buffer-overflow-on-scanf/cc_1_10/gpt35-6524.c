//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

void subnet_calc() {
    int ip_address[4], subnet_mask[4], subnet_bits;
    printf("Enter IP address [ex: 192.168.0.1]: ");
    scanf("%d.%d.%d.%d", &ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3]);

    printf("Enter subnet mask [ex: 255.255.255.0 or /24]: ");
    scanf("%d.%d.%d.%d", &subnet_mask[0], &subnet_mask[1], &subnet_mask[2], &subnet_mask[3]);

    // convert subnet mask to bits
    subnet_bits = subnet_mask[0] * 256 * 256 * 256 + subnet_mask[1] * 256 * 256 + subnet_mask[2] * 256 + subnet_mask[3];
    int maskcount = 0;
    while (subnet_bits > 0) {
        if (subnet_bits % 2 == 1) {
            maskcount++;
        }
        subnet_bits /= 2;
    }

    int ip_bits[32];
    // convert ip address to bits
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            if (ip_address[i] % 2 == 1) {
                ip_bits[i * 8 + 7 - j] = 1;
            } else {
                ip_bits[i * 8 + 7 - j] = 0;
            }
            ip_address[i] /= 2;
        }
    }

    int network_address[4];
    // calculate network address
    for (int i = 0; i < 4; i++) {
        int temp = 0;
        for (int j = 0; j < 8; j++) {
            temp += ip_bits[i * 8 + j] * (1 << (7 - j));
        }
        network_address[i] = temp & subnet_mask[i];
    }

    int broadcast_address[4];
    // calculate broadcast address
    for (int i = 0; i < 4; i++) {
        broadcast_address[i] = network_address[i] + ((1 << (8 - (maskcount % 8))) - 1);
    }

    printf("\nNetwork address: %d.%d.%d.%d", network_address[0], network_address[1], network_address[2], network_address[3]);
    printf("\nBroadcast address: %d.%d.%d.%d", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
}

int main() {
    subnet_calc();
    return 0;
}