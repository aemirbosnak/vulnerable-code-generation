//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_subnet_mask(int subnet_bits);

int main() {
    char ip_address[16];
    int subnet_bits, i, j, octet_count, subnet_octets[4], host_bits;
    int network_octet[4], broadcast_octet[4], subnet_mask[4], host_range[2];

    // Read input
    printf("Enter IP Address: ");
    scanf("%s", ip_address);
    printf("Enter Subnet Bits: ");
    scanf("%d", &subnet_bits);

    // Validate input
    if (subnet_bits < 0 || subnet_bits > 32) {
        printf("Invalid Subnet Bits: %d", subnet_bits);
        exit(1);
    }

    // Determine number of octets in IP address
    octet_count = 0;
    for (i=0; i<strlen(ip_address); i++) {
        if (ip_address[i] == '.') {
            octet_count++;
        }
    }
    octet_count++;

    // Validate number of octets
    if (octet_count != 4) {
        printf("Invalid IP Address: %s", ip_address);
        exit(1);
    }

    // Parse IP address and subnet octets
    char *tok = strtok(ip_address, ".");
    for (i=0; i<octet_count; i++) {
        if (tok == NULL) {
            printf("Invalid IP Address: %s", ip_address);
            exit(1);
        }
        subnet_octets[i] = atoi(tok);
        if (subnet_octets[i] < 0 || subnet_octets[i] > 255) {
            printf("Invalid IP Address: %s", ip_address);
            exit(1);
        }
        tok = strtok(NULL, ".");
    }

    // Calculate network address
    for (i=0; i<4; i++) {
        if (subnet_bits >= 8) {
            network_octet[i] = subnet_octets[i];
            subnet_bits -= 8;
        } else if (subnet_bits > 0) {
            int mask = 0;
            for (j=0; j<subnet_bits; j++) {
                mask = mask << 1;
                mask |= 0x1;
            }
            network_octet[i] = subnet_octets[i] & mask;
            subnet_bits = 0;
        } else {
            network_octet[i] = 0;
        }
    }

    // Calculate broadcast address
    host_bits = 32 - subnet_bits;
    if (host_bits == 0) {
        for (i=0; i<4; i++) {
            broadcast_octet[i] = subnet_octets[i];
        }
    } else {
        for (i=0; i<4; i++) {
            if (host_bits >= 8) {
                broadcast_octet[i] = subnet_octets[i];
                host_bits -= 8;
            } else {
                int mask = 0;
                for (j=0; j<host_bits; j++) {
                    mask = mask << 1;
                    mask |= 0x1;
                }
                broadcast_octet[i] = subnet_octets[i] | ~mask;
                host_bits = 0;
            }
        }
    }

    // Calculate subnet mask
    print_subnet_mask(subnet_bits);

    // Print network address, broadcast address, and host range
    printf("Network Address: %d.%d.%d.%d\n", network_octet[0], network_octet[1], network_octet[2], network_octet[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_octet[0], broadcast_octet[1], broadcast_octet[2], broadcast_octet[3]);
    host_range[0] = network_octet[3] + 1;
    host_range[1] = broadcast_octet[3] - 1;
    printf("Host Range: %d.%d.%d.%d-%d.%d.%d.%d", network_octet[0], network_octet[1], network_octet[2], host_range[0],
           broadcast_octet[0], broadcast_octet[1], broadcast_octet[2], host_range[1]);

    return 0;
}

void print_subnet_mask(int subnet_bits) {
    int subnet_mask[4] = {0, 0, 0, 0};
    int i, j;
    for (i=0; i<4; i++) {
        if (subnet_bits >= 8) {
            subnet_mask[i] = 0xFF;
            subnet_bits -= 8;
        } else if (subnet_bits > 0) {
            int mask = 0;
            for (j=0; j<subnet_bits; j++) {
                mask = mask << 1;
                mask |= 0x1;
            }
            subnet_mask[i] = mask;
            subnet_bits = 0;
        }
    }
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
}