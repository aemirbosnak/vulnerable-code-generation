//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: realistic
/*
 * Subnet Calculator
 *
 * This program calculates the subnet mask of a given IP address and subnet prefix.
 *
 * Usage:
 *   ./subnet_calculator <ip_address> <prefix>
 *
 * Example:
 *   ./subnet_calculator 192.168.1.0 24
 */

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

#define IP_ADDRESS_SIZE 4
#define IP_ADDRESS_STR_SIZE 16
#define IP_ADDRESS_MAX_PREFIX 32

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip_address> <prefix>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int prefix = atoi(argv[2]);

    if (prefix < 1 || prefix > IP_ADDRESS_MAX_PREFIX) {
        printf("Invalid prefix: %d\n", prefix);
        return 1;
    }

    struct in_addr addr;
    if (inet_pton(AF_INET, ip_address, &addr) != 1) {
        printf("Invalid IP address: %s\n", ip_address);
        return 1;
    }

    char subnet_mask[IP_ADDRESS_STR_SIZE];
    inet_ntop(AF_INET, &addr, subnet_mask, IP_ADDRESS_STR_SIZE);

    int i;
    for (i = 0; i < IP_ADDRESS_SIZE; i++) {
        if (i < prefix / 8) {
            subnet_mask[i] = 255;
        } else if (i == prefix / 8) {
            subnet_mask[i] = 255 - (256 % (1 << (8 - (prefix % 8))));
        } else {
            subnet_mask[i] = 0;
        }
    }

    printf("Subnet mask: %s\n", subnet_mask);

    return 0;
}