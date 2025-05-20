//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 3

typedef struct {
    unsigned char octets[4];
} IPv4Address;

typedef struct {
    unsigned char bits;
} SubnetMask;

int validate_ip_address(IPv4Address *ip_address) {
    for (int i = 0; i < 4; i++) {
        if (ip_address->octets[i] < 0 || ip_address->octets[i] > 255) {
            return 0;
        }
    }

    return 1;
}

int validate_subnet_mask(SubnetMask *subnet_mask) {
    if (subnet_mask->bits < 0 || subnet_mask->bits > 32) {
        return 0;
    }

    return 1;
}

void calculate_network_address(IPv4Address *ip_address, SubnetMask *subnet_mask, IPv4Address *network_address) {
    for (int i = 0; i < 4; i++) {
        network_address->octets[i] = ip_address->octets[i] & subnet_mask->bits;
    }
}

void calculate_broadcast_address(IPv4Address *ip_address, SubnetMask *subnet_mask, IPv4Address *broadcast_address) {
    for (int i = 0; i < 4; i++) {
        broadcast_address->octets[i] = ip_address->octets[i] | (~subnet_mask->bits);
    }
}

void print_ip_address(IPv4Address *ip_address) {
    for (int i = 0; i < 4; i++) {
        printf("%u", ip_address->octets[i]);
        if (i < 3) {
            printf(".");
        }
    }

    printf("\n");
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <IP address> <subnet mask>\n", argv[0]);
        return 1;
    }

    IPv4Address ip_address;
    SubnetMask subnet_mask;

    if (sscanf(argv[1], "%hhu.%hhu.%hhu.%hhu", &ip_address.octets[0], &ip_address.octets[1], &ip_address.octets[2], &ip_address.octets[3]) != 4) {
        printf("Invalid IP address\n");
        return 1;
    }

    if (!validate_ip_address(&ip_address)) {
        printf("Invalid IP address\n");
        return 1;
    }

    if (sscanf(argv[2], "%hhu", &subnet_mask.bits) != 1) {
        printf("Invalid subnet mask\n");
        return 1;
    }

    if (!validate_subnet_mask(&subnet_mask)) {
        printf("Invalid subnet mask\n");
        return 1;
    }

    IPv4Address network_address;
    IPv4Address broadcast_address;

    calculate_network_address(&ip_address, &subnet_mask, &network_address);
    calculate_broadcast_address(&ip_address, &subnet_mask, &broadcast_address);

    printf("IP address: ");
    print_ip_address(&ip_address);

    printf("Subnet mask: %u\n", subnet_mask.bits);

    printf("Network address: ");
    print_ip_address(&network_address);

    printf("Broadcast address: ");
    print_ip_address(&broadcast_address);

    return 0;
}