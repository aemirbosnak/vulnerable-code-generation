//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_ADDR_LEN 16

typedef struct {
    uint32_t addr;
    uint32_t mask;
} ip_subnet_t;

static int parse_ip_addr(const char *ip_addr, uint32_t *addr)
{
    char *endptr;
    uint32_t octets[4];

    if (sscanf(ip_addr, "%u.%u.%u.%u", &octets[0], &octets[1], &octets[2], &octets[3]) != 4) {
        return -1;
    }

    for (int i = 0; i < 4; i++) {
        if (octets[i] > 255) {
            return -1;
        }
    }

    *addr = (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];

    return 0;
}

static int parse_subnet_mask(const char *mask, uint32_t *mask_addr)
{
    char *endptr;
    uint32_t octets[4];

    if (sscanf(mask, "%u.%u.%u.%u", &octets[0], &octets[1], &octets[2], &octets[3]) != 4) {
        return -1;
    }

    for (int i = 0; i < 4; i++) {
        if (octets[i] > 255) {
            return -1;
        }
    }

    *mask_addr = (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];

    return 0;
}

static int calc_subnet_info(const ip_subnet_t *subnet, ip_subnet_t *result)
{
    result->addr = subnet->addr & subnet->mask;
    result->mask = subnet->mask;

    return 0;
}

static void print_ip_addr(uint32_t addr)
{
    printf("%u.%u.%u.%u", (addr >> 24) & 0xff, (addr >> 16) & 0xff, (addr >> 8) & 0xff, addr & 0xff);
}

static void print_subnet_info(const ip_subnet_t *subnet)
{
    printf("IP Address: ");
    print_ip_addr(subnet->addr);
    printf("\n");

    printf("Subnet Mask: ");
    print_ip_addr(subnet->mask);
    printf("\n");

    printf("Network Address: ");
    print_ip_addr(subnet->addr & subnet->mask);
    printf("\n");

    printf("Broadcast Address: ");
    print_ip_addr((subnet->addr & subnet->mask) | ~subnet->mask);
    printf("\n");

    printf("Usable Host Range: ");
    print_ip_addr(subnet->addr & subnet->mask | 1);
    printf(" - ");
    print_ip_addr((subnet->addr & subnet->mask) | ~subnet->mask - 1);
    printf("\n");

    printf("Total Host Count: %u\n", ~(subnet->mask >> 31) - 2);
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s <ip_addr> <subnet_mask>\n", argv[0]);
        return -1;
    }

    ip_subnet_t subnet;
    if (parse_ip_addr(argv[1], &subnet.addr) < 0) {
        printf("Invalid IP address: %s\n", argv[1]);
        return -1;
    }

    if (parse_subnet_mask(argv[2], &subnet.mask) < 0) {
        printf("Invalid subnet mask: %s\n", argv[2]);
        return -1;
    }

    ip_subnet_t result;
    if (calc_subnet_info(&subnet, &result) < 0) {
        printf("Error calculating subnet information\n");
        return -1;
    }

    print_subnet_info(&result);

    return 0;
}