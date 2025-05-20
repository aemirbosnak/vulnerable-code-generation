//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <inttypes.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 3
#define MAX_CIDR_LEN 3

struct ip_addr {
    uint8_t addr[4];
};

struct subnet_mask {
    uint8_t mask[4];
};

struct cidr_mask {
    uint8_t cidr;
};

int parse_ip_addr(const char *ip_str, struct ip_addr *ip) {
    int ret = inet_pton(AF_INET, ip_str, ip->addr);
    if (ret != 1) {
        return -1;
    }
    return 0;
}

int parse_subnet_mask(const char *mask_str, struct subnet_mask *mask) {
    int ret = inet_pton(AF_INET, mask_str, mask->mask);
    if (ret != 1) {
        return -1;
    }
    return 0;
}

int parse_cidr_mask(const char *cidr_str, struct cidr_mask *cidr) {
    int ret = sscanf(cidr_str, "%hhu", &cidr->cidr);
    if (ret != 1) {
        return -1;
    }
    return 0;
}

int calculate_network_addr(const struct ip_addr *ip, const struct subnet_mask *mask, struct ip_addr *network) {
    for (int i = 0; i < 4; i++) {
        network->addr[i] = ip->addr[i] & mask->mask[i];
    }
    return 0;
}

int calculate_broadcast_addr(const struct ip_addr *ip, const struct subnet_mask *mask, struct ip_addr *broadcast) {
    for (int i = 0; i < 4; i++) {
        broadcast->addr[i] = ip->addr[i] | ~mask->mask[i];
    }
    return 0;
}

int calculate_first_host_addr(const struct ip_addr *network, struct ip_addr *first_host) {
    memcpy(first_host, network, sizeof(struct ip_addr));
    for (int i = 3; i >= 0; i--) {
        if (first_host->addr[i] < 255) {
            first_host->addr[i]++;
            break;
        }
    }
    return 0;
}

int calculate_last_host_addr(const struct ip_addr *broadcast, struct ip_addr *last_host) {
    memcpy(last_host, broadcast, sizeof(struct ip_addr));
    for (int i = 3; i >= 0; i--) {
        if (last_host->addr[i] > 0) {
            last_host->addr[i]--;
            break;
        }
    }
    return 0;
}

void print_ip_addr(const struct ip_addr *ip) {
    printf("%" PRIu8 ".%" PRIu8 ".%" PRIu8 ".%" PRIu8 "\n", ip->addr[0], ip->addr[1], ip->addr[2], ip->addr[3]);
}

void print_subnet_mask(const struct subnet_mask *mask) {
    printf("%" PRIu8 ".%" PRIu8 ".%" PRIu8 ".%" PRIu8 "\n", mask->mask[0], mask->mask[1], mask->mask[2], mask->mask[3]);
}

void print_cidr_mask(const struct cidr_mask *cidr) {
    printf("%" PRIu8 "\n", cidr->cidr);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <ip address> <subnet mask> <cidr mask>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct ip_addr ip;
    struct subnet_mask mask;
    struct cidr_mask cidr;

    if (parse_ip_addr(argv[1], &ip) == -1) {
        fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (parse_subnet_mask(argv[2], &mask) == -1) {
        fprintf(stderr, "Invalid subnet mask: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    if (parse_cidr_mask(argv[3], &cidr) == -1) {
        fprintf(stderr, "Invalid CIDR mask: %s\n", argv[3]);
        return EXIT_FAILURE;
    }

    struct ip_addr network;
    struct ip_addr broadcast;
    struct ip_addr first_host;
    struct ip_addr last_host;

    if (calculate_network_addr(&ip, &mask, &network) == -1) {
        fprintf(stderr, "Error calculating network address\n");
        return EXIT_FAILURE;
    }

    if (calculate_broadcast_addr(&ip, &mask, &broadcast) == -1) {
        fprintf(stderr, "Error calculating broadcast address\n");
        return EXIT_FAILURE;
    }

    if (calculate_first_host_addr(&network, &first_host) == -1) {
        fprintf(stderr, "Error calculating first host address\n");
        return EXIT_FAILURE;
    }

    if (calculate_last_host_addr(&broadcast, &last_host) == -1) {
        fprintf(stderr, "Error calculating last host address\n");
        return EXIT_FAILURE;
    }

    printf("IP address: ");
    print_ip_addr(&ip);

    printf("Subnet mask: ");
    print_subnet_mask(&mask);

    printf("CIDR mask: ");
    print_cidr_mask(&cidr);

    printf("Network address: ");
    print_ip_addr(&network);

    printf("Broadcast address: ");
    print_ip_addr(&broadcast);

    printf("First host address: ");
    print_ip_addr(&first_host);

    printf("Last host address: ");
    print_ip_addr(&last_host);

    return EXIT_SUCCESS;
}