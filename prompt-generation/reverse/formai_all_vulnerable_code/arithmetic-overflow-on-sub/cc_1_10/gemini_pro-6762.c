//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MASK_LEN 32

typedef struct {
    uint32_t ip;
    uint8_t mask_len;
} subnet_t;

static void print_usage(char *prog_name) {
    printf("Usage: %s <ip_address> <mask_len>\n", prog_name);
    printf("Example: %s 192.168.1.0 24\n", prog_name);
}

static int parse_ip_address(char *ip_str, uint32_t *ip) {
    struct in_addr in_addr;
    if (inet_aton(ip_str, &in_addr) == 0) {
        return -1;
    }
    *ip = ntohl(in_addr.s_addr);
    return 0;
}

static int parse_mask_len(char *mask_len_str, uint8_t *mask_len) {
    long int mask_len_long;
    if (strtol(mask_len_str, NULL, 10) < 0 || strtol(mask_len_str, NULL, 10) > MAX_MASK_LEN) {
        return -1;
    }
    mask_len_long = strtol(mask_len_str, NULL, 10);
    *mask_len = (uint8_t) mask_len_long;
    return 0;
}

static int calculate_subnet(subnet_t *subnet, uint32_t ip, uint8_t mask_len) {
    uint32_t mask = htonl(0xFFFFFFFF << (32 - mask_len));
    subnet->ip = ip & mask;
    subnet->mask_len = mask_len;
    return 0;
}

static void print_subnet(subnet_t *subnet) {
    char ip_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &subnet->ip, ip_str, INET_ADDRSTRLEN);
    printf("Subnet IP: %s\n", ip_str);
    printf("Subnet Mask: %d.%d.%d.%d\n",
        (subnet->ip >> 24) & 0xFF,
        (subnet->ip >> 16) & 0xFF,
        (subnet->ip >> 8) & 0xFF,
        subnet->ip & 0xFF);
    printf("Subnet Mask Length: %d\n", subnet->mask_len);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    uint32_t ip;
    uint8_t mask_len;
    subnet_t subnet;

    if (parse_ip_address(argv[1], &ip) != 0) {
        printf("Invalid IP address: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (parse_mask_len(argv[2], &mask_len) != 0) {
        printf("Invalid mask length: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    if (calculate_subnet(&subnet, ip, mask_len) != 0) {
        printf("Failed to calculate subnet\n");
        return EXIT_FAILURE;
    }

    print_subnet(&subnet);

    return EXIT_SUCCESS;
}