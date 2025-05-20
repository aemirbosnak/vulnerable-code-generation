//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MASK_BITS 32

struct subnet_info {
    unsigned int network_address;
    unsigned int subnet_mask;
    unsigned int broadcast_address;
    unsigned int first_usable_address;
    unsigned int last_usable_address;
    unsigned int total_usable_hosts;
};

void calculate_subnet_info(struct subnet_info *info, const char *ip_address, const char *subnet_mask) {
    struct in_addr ip_addr;
    struct in_addr subnet_mask_addr;
    unsigned int network_address;
    unsigned int broadcast_address;
    unsigned int first_usable_address;
    unsigned int last_usable_address;
    unsigned int total_usable_hosts;

    if (inet_pton(AF_INET, ip_address, &ip_addr) != 1) {
        fprintf(stderr, "Invalid IP address: %s\n", ip_address);
        exit(EXIT_FAILURE);
    }

    if (inet_pton(AF_INET, subnet_mask, &subnet_mask_addr) != 1) {
        fprintf(stderr, "Invalid subnet mask: %s\n", subnet_mask);
        exit(EXIT_FAILURE);
    }

    network_address = ip_addr.s_addr & subnet_mask_addr.s_addr;
    broadcast_address = network_address | ~subnet_mask_addr.s_addr;
    first_usable_address = network_address + 1;
    last_usable_address = broadcast_address - 1;
    total_usable_hosts = (1 << (MASK_BITS - ntohl(subnet_mask_addr.s_addr))) - 2;

    info->network_address = network_address;
    info->subnet_mask = subnet_mask_addr.s_addr;
    info->broadcast_address = broadcast_address;
    info->first_usable_address = first_usable_address;
    info->last_usable_address = last_usable_address;
    info->total_usable_hosts = total_usable_hosts;
}

void print_subnet_info(const struct subnet_info *info) {
    printf("Network address: %s\n", inet_ntoa((struct in_addr) { info->network_address }));
    printf("Subnet mask: %s\n", inet_ntoa((struct in_addr) { info->subnet_mask }));
    printf("Broadcast address: %s\n", inet_ntoa((struct in_addr) { info->broadcast_address }));
    printf("First usable address: %s\n", inet_ntoa((struct in_addr) { info->first_usable_address }));
    printf("Last usable address: %s\n", inet_ntoa((struct in_addr) { info->last_usable_address }));
    printf("Total usable hosts: %u\n", info->total_usable_hosts);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s IP_ADDRESS SUBNET_MASK\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct subnet_info info;

    calculate_subnet_info(&info, argv[1], argv[2]);
    print_subnet_info(&info);

    return EXIT_SUCCESS;
}