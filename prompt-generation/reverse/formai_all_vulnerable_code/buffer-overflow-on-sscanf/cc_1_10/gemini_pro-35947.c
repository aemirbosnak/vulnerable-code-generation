//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_IP_LENGTH 16
#define MAX_MASK_LENGTH 4

typedef struct {
    uint8_t octets[4];
} IPAddress;

typedef struct {
    uint8_t bits;
} Mask;

void print_ip_address(IPAddress* ip) {
    for (int i = 0; i < 4; i++) {
        printf("%d", ip->octets[i]);
        if (i < 3) {
            printf(".");
        }
    }
    printf("\n");
}

void print_mask(Mask* mask) {
    printf("%d\n", mask->bits);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <ip address> <mask>\n", argv[0]);
        return 1;
    }

    // Parse the IP address
    IPAddress ip;
    if (sscanf(argv[1], "%hhu.%hhu.%hhu.%hhu", &ip.octets[0], &ip.octets[1], &ip.octets[2], &ip.octets[3]) != 4) {
        printf("Invalid IP address: %s\n", argv[1]);
        return 1;
    }

    // Parse the mask
    Mask mask;
    if (sscanf(argv[2], "%hhu", &mask.bits) != 1) {
        printf("Invalid mask: %s\n", argv[2]);
        return 1;
    }
    if (mask.bits > 32) {
        printf("Mask must be between 0 and 32 bits\n");
        return 1;
    }

    // Calculate the network address
    IPAddress network_address;
    for (int i = 0; i < 4; i++) {
        network_address.octets[i] = ip.octets[i] & ((255 << (8 - mask.bits)) >> (8 - mask.bits));
    }

    // Calculate the broadcast address
    IPAddress broadcast_address;
    for (int i = 0; i < 4; i++) {
        broadcast_address.octets[i] = ip.octets[i] | ~((255 << (8 - mask.bits)) >> (8 - mask.bits));
    }

    // Calculate the number of hosts
    uint32_t num_hosts = (1 << (32 - mask.bits)) - 2;

    // Print the results
    printf("IP address: ");
    print_ip_address(&ip);
    printf("Mask: ");
    print_mask(&mask);
    printf("Network address: ");
    print_ip_address(&network_address);
    printf("Broadcast address: ");
    print_ip_address(&broadcast_address);
    printf("Number of hosts: %d\n", num_hosts);

    return 0;
}