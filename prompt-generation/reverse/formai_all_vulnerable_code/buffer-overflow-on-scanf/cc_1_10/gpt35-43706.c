//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the C Subnet Calculator!\n\n");
    printf("Please enter the IP address in dotted decimal notation (eg. 192.168.0.1): ");
    char ip[16];
    scanf("%15s", ip);

    // Parse IP Address
    int a, b, c, d;
    sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d);

    printf("\nOctet 1: %d\nOctet 2: %d\nOctet 3: %d\nOctet 4: %d\n\n", a, b, c, d);

    // Prompt user for subnet mask
    int subnet_mask;
    printf("Please enter the subnet mask in CIDR format (eg. 24): ");
    scanf("%d", &subnet_mask);

    // Calculate CIDR notation
    int cidr_octets[4] = {0, 0, 0, 0};
    int cidr_bits = 0;
    while (subnet_mask > 0) {
        if (subnet_mask >= 8) {
            cidr_bits += 8;
            cidr_octets[cidr_bits/8 - 1] = 255;
            subnet_mask -= 8;
        } else {
            cidr_bits += subnet_mask;
            int mask = 0;
            for (int i = 0; i < subnet_mask; i++) {
                mask = mask << 1;
                mask |= 1;
            }
            cidr_octets[cidr_bits/8] = mask;
            subnet_mask = 0;
        }
    }

    printf("\nCIDR Notation: %d.%d.%d.%d\n", cidr_octets[0], cidr_octets[1], cidr_octets[2], cidr_octets[3]);

    // Calculate network address
    int network_address[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        network_address[i] = (cidr_octets[i] & (ip[i] & cidr_octets[i]));
    }

    printf("Network Address: %d.%d.%d.%d\n", network_address[0], network_address[1], network_address[2], network_address[3]);

    // Calculate broadcast address
    int broadcast_address[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        broadcast_address[i] = (cidr_octets[i] | (~cidr_octets[i] & (ip[i] | cidr_octets[i])));
    }

    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);

    // Calculate number of hosts
    int bits_host = 32 - cidr_bits;
    int hosts = 1;
    for (int i = 0; i < bits_host; i++) {
        hosts = hosts << 1;
    }

    printf("Number of Hosts: %d\n", hosts - 2);

    return 0;
}