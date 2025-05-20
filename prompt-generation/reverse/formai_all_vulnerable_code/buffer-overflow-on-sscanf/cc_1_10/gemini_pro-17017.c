//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 32

typedef struct {
    unsigned char octets[4];
} ip_addr_t;

typedef struct {
    unsigned char mask;
    unsigned char prefix_len;
} subnet_mask_t;

void print_ip(ip_addr_t *ip) {
    printf("%u.%u.%u.%u", ip->octets[0], ip->octets[1], ip->octets[2], ip->octets[3]);
}

void print_mask(subnet_mask_t *mask) {
    printf("%u/%u", mask->mask, mask->prefix_len);
}

int parse_ip(char *ip_str, ip_addr_t *ip) {
    int octets[4];
    if (sscanf(ip_str, "%u.%u.%u.%u", &octets[0], &octets[1], &octets[2], &octets[3]) != 4) {
        return -1;
    }

    for (int i = 0; i < 4; i++) {
        if (octets[i] > 255) {
            return -1;
        }
        ip->octets[i] = octets[i];
    }

    return 0;
}

int parse_mask(char *mask_str, subnet_mask_t *mask) {
    int prefix_len;
    if (sscanf(mask_str, "%u/%u", &mask->mask, &prefix_len) != 2) {
        return -1;
    }

    if (prefix_len > MAX_MASK_LEN) {
        return -1;
    }

    mask->prefix_len = prefix_len;

    return 0;
}

int calculate_network_address(ip_addr_t *ip, subnet_mask_t *mask, ip_addr_t *network_address) {
    for (int i = 0; i < 4; i++) {
        network_address->octets[i] = ip->octets[i] & mask->mask;
    }

    return 0;
}

int calculate_broadcast_address(ip_addr_t *ip, subnet_mask_t *mask, ip_addr_t *broadcast_address) {
    for (int i = 0; i < 4; i++) {
        broadcast_address->octets[i] = ip->octets[i] | ~mask->mask;
    }

    return 0;
}

int calculate_usable_host_range(ip_addr_t *network_address, ip_addr_t *broadcast_address, ip_addr_t *start_address, ip_addr_t *end_address) {
    memcpy(start_address, network_address, sizeof(ip_addr_t));
    start_address->octets[3]++;

    memcpy(end_address, broadcast_address, sizeof(ip_addr_t));
    end_address->octets[3]--;

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <ip address> <subnet mask>\n", argv[0]);
        return -1;
    }

    ip_addr_t ip;
    if (parse_ip(argv[1], &ip) != 0) {
        printf("Invalid IP address: %s\n", argv[1]);
        return -1;
    }

    subnet_mask_t mask;
    if (parse_mask(argv[2], &mask) != 0) {
        printf("Invalid subnet mask: %s\n", argv[2]);
        return -1;
    }

    ip_addr_t network_address;
    if (calculate_network_address(&ip, &mask, &network_address) != 0) {
        printf("Error calculating network address\n");
        return -1;
    }

    ip_addr_t broadcast_address;
    if (calculate_broadcast_address(&ip, &mask, &broadcast_address) != 0) {
        printf("Error calculating broadcast address\n");
        return -1;
    }

    ip_addr_t start_address;
    ip_addr_t end_address;
    if (calculate_usable_host_range(&network_address, &broadcast_address, &start_address, &end_address) != 0) {
        printf("Error calculating usable host range\n");
        return -1;
    }

    printf("IP Address: ");
    print_ip(&ip);
    printf("\n");

    printf("Subnet Mask: ");
    print_mask(&mask);
    printf("\n");

    printf("Network Address: ");
    print_ip(&network_address);
    printf("\n");

    printf("Broadcast Address: ");
    print_ip(&broadcast_address);
    printf("\n");

    printf("Usable Host Range: ");
    print_ip(&start_address);
    printf(" - ");
    print_ip(&end_address);
    printf("\n");

    printf("Number of Usable Hosts: %u\n", pow(2, 32 - mask.prefix_len) - 2);

    return 0;
}