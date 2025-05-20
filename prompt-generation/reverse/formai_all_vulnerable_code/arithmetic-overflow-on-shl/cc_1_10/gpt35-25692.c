//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define MASK_BITS_COUNT 32

typedef struct subnet_info {
    uint32_t subnet_mask;
    uint32_t network_address;
    uint32_t broadcast_address;
    uint32_t host_min;
    uint32_t host_max;
    uint32_t hosts_count;
} subnet_info_t;

uint32_t create_subnet_mask(uint8_t bits_set_count) {
    return ~((1 << (MASK_BITS_COUNT - bits_set_count)) - 1);
}

void calculate_subnet_info(uint32_t ip_address, uint8_t bits_set_count, subnet_info_t* subnet_info) {
    subnet_info->subnet_mask = create_subnet_mask(bits_set_count);
    subnet_info->network_address = ip_address & subnet_info->subnet_mask;
    subnet_info->broadcast_address = subnet_info->network_address | ~subnet_info->subnet_mask;
    subnet_info->hosts_count = (bits_set_count == MASK_BITS_COUNT) ? 1 : (1 << (MASK_BITS_COUNT - bits_set_count)) - 2;
    subnet_info->host_min = subnet_info->network_address + 1;
    subnet_info->host_max = subnet_info->broadcast_address - 1;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s [IPv4 address] [subnet mask bits set count]\n", argv[0]);
        return -1;
    }

    struct in_addr ip_address;
    inet_aton(argv[1], &ip_address);

    uint8_t bits_set_count = atoi(argv[2]);

    subnet_info_t subnet_info;
    calculate_subnet_info(ip_address.s_addr, bits_set_count, &subnet_info);

    printf("Subnet Mask: %d.%d.%d.%d\n", (subnet_info.subnet_mask >> 24) & 0xFF, (subnet_info.subnet_mask >> 16) & 0xFF, (subnet_info.subnet_mask >> 8) & 0xFF, subnet_info.subnet_mask & 0xFF);
    printf("Network Address: %d.%d.%d.%d\n", (subnet_info.network_address >> 24) & 0xFF, (subnet_info.network_address >> 16) & 0xFF, (subnet_info.network_address >> 8) & 0xFF, subnet_info.network_address & 0xFF);
    printf("Broadcast Address: %d.%d.%d.%d\n", (subnet_info.broadcast_address >> 24) & 0xFF, (subnet_info.broadcast_address >> 16) & 0xFF, (subnet_info.broadcast_address >> 8) & 0xFF, subnet_info.broadcast_address & 0xFF);
    printf("Hosts Count: %d\n", subnet_info.hosts_count);
    printf("Minimum Host Address: %d.%d.%d.%d\n", (subnet_info.host_min >> 24) & 0xFF, (subnet_info.host_min >> 16) & 0xFF, (subnet_info.host_min >> 8) & 0xFF, subnet_info.host_min & 0xFF);
    printf("Maximum Host Address: %d.%d.%d.%d\n", (subnet_info.host_max >> 24) & 0xFF, (subnet_info.host_max >> 16) & 0xFF, (subnet_info.host_max >> 8) & 0xFF, subnet_info.host_max & 0xFF);

    return 0;
}