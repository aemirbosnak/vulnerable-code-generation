//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 32

typedef struct ip_addr {
    unsigned char octets[4];
} ip_addr;

typedef struct subnet_mask {
    unsigned char octets[4];
} subnet_mask;

typedef struct subnet_info {
    ip_addr network_addr;
    ip_addr broadcast_addr;
    unsigned int num_hosts;
    unsigned int subnet_id;
} subnet_info;

void print_ip_addr(ip_addr addr) {
    printf("%d.%d.%d.%d", addr.octets[0], addr.octets[1], addr.octets[2], addr.octets[3]);
}

void print_subnet_mask(subnet_mask mask) {
    printf("%d.%d.%d.%d", mask.octets[0], mask.octets[1], mask.octets[2], mask.octets[3]);
}

void print_subnet_info(subnet_info info) {
    printf("Network address: ");
    print_ip_addr(info.network_addr);
    printf("\nBroadcast address: ");
    print_ip_addr(info.broadcast_addr);
    printf("\nNumber of hosts: %d\n", info.num_hosts);
    printf("Subnet ID: %d\n", info.subnet_id);
}

int is_valid_ip_addr(char *ip_str) {
    int octets[4];
    int num_octets = sscanf(ip_str, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);
    if (num_octets != 4) {
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        if (octets[i] < 0 || octets[i] > 255) {
            return 0;
        }
    }
    return 1;
}

int is_valid_subnet_mask(char *mask_str) {
    int octets[4];
    int num_octets = sscanf(mask_str, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);
    if (num_octets != 4) {
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        if (octets[i] < 0 || octets[i] > 255) {
            return 0;
        }
        if (octets[i] != 0 && octets[i] != 255) {
            return 0;
        }
    }
    return 1;
}

int get_num_host_bits(subnet_mask mask) {
    int num_host_bits = 0;
    for (int i = 0; i < 4; i++) {
        num_host_bits += __builtin_popcount(mask.octets[i]);
    }
    return num_host_bits;
}

subnet_info calculate_subnet_info(ip_addr ip, subnet_mask mask) {
    subnet_info info;
    info.network_addr.octets[0] = ip.octets[0] & mask.octets[0];
    info.network_addr.octets[1] = ip.octets[1] & mask.octets[1];
    info.network_addr.octets[2] = ip.octets[2] & mask.octets[2];
    info.network_addr.octets[3] = ip.octets[3] & mask.octets[3];

    info.broadcast_addr.octets[0] = ip.octets[0] | ~mask.octets[0];
    info.broadcast_addr.octets[1] = ip.octets[1] | ~mask.octets[1];
    info.broadcast_addr.octets[2] = ip.octets[2] | ~mask.octets[2];
    info.broadcast_addr.octets[3] = ip.octets[3] | ~mask.octets[3];

    info.num_hosts = pow(2, get_num_host_bits(mask)) - 2;

    info.subnet_id = (info.network_addr.octets[0] << 24) | (info.network_addr.octets[1] << 16) | (info.network_addr.octets[2] << 8) | info.network_addr.octets[3];

    return info;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip address> <subnet mask>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (!is_valid_ip_addr(argv[1])) {
        printf("Invalid IP address: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (!is_valid_subnet_mask(argv[2])) {
        printf("Invalid subnet mask: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    ip_addr ip;
    sscanf(argv[1], "%d.%d.%d.%d", &ip.octets[0], &ip.octets[1], &ip.octets[2], &ip.octets[3]);

    subnet_mask mask;
    sscanf(argv[2], "%d.%d.%d.%d", &mask.octets[0], &mask.octets[1], &mask.octets[2], &mask.octets[3]);

    subnet_info info = calculate_subnet_info(ip, mask);

    print_subnet_info(info);

    return EXIT_SUCCESS;
}