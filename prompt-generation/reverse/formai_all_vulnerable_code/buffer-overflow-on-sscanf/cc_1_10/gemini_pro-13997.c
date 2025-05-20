//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_IP_ADDRESS_LEN 16
#define MAX_SUBNET_MASK_LEN 16

typedef struct {
    uint8_t octets[4];
} ip_address_t;

typedef struct {
    uint8_t octets[4];
    uint8_t prefix_length;
} subnet_mask_t;

void print_ip_address(ip_address_t *ip) {
    printf("%u.%u.%u.%u", ip->octets[0], ip->octets[1], ip->octets[2], ip->octets[3]);
}

void print_subnet_mask(subnet_mask_t *mask) {
    printf("%u.%u.%u.%u/%u", mask->octets[0], mask->octets[1], mask->octets[2], mask->octets[3], mask->prefix_length);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip address> <subnet mask>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ip_address_t ip;
    if (sscanf(argv[1], "%hhu.%hhu.%hhu.%hhu", &ip.octets[0], &ip.octets[1], &ip.octets[2], &ip.octets[3]) != 4) {
        fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    subnet_mask_t mask;
    if (sscanf(argv[2], "%hhu.%hhu.%hhu.%hhu/%hhu", &mask.octets[0], &mask.octets[1], &mask.octets[2], &mask.octets[3], &mask.prefix_length) != 5) {
        fprintf(stderr, "Invalid subnet mask: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    if (mask.prefix_length > 32) {
        fprintf(stderr, "Invalid prefix length: %u\n", mask.prefix_length);
        return EXIT_FAILURE;
    }

    uint8_t mask_octets[4];
    for (int i = 0; i < 4; i++) {
        mask_octets[i] = 0;
        for (int j = 0; j < mask.prefix_length - (i * 8); j++) {
            mask_octets[i] |= (1 << (7 - j));
        }
    }

    ip_address_t network_address;
    for (int i = 0; i < 4; i++) {
        network_address.octets[i] = ip.octets[i] & mask_octets[i];
    }

    uint32_t num_hosts = (1 << (32 - mask.prefix_length)) - 2;

    printf("IP address: ");
    print_ip_address(&ip);
    printf("\n");

    printf("Subnet mask: ");
    print_subnet_mask(&mask);
    printf("\n");

    printf("Network address: ");
    print_ip_address(&network_address);
    printf("\n");

    printf("Number of hosts: %u\n", num_hosts);

    return EXIT_SUCCESS;
}