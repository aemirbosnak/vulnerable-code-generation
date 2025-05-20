//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_IP_LEN 16

typedef struct {
    unsigned char octets[4];
} ip_addr;

typedef struct {
    ip_addr addr;
    unsigned int prefix_len;
    ip_addr netmask;
    ip_addr broadcast;
    unsigned int num_hosts;
} subnet_info;

void print_ip(const ip_addr *ip)
{
    printf("%d.%d.%d.%d", ip->octets[0], ip->octets[1], ip->octets[2], ip->octets[3]);
}

void print_subnet_info(const subnet_info *info)
{
    printf("Address: ");
    print_ip(&info->addr);
    printf("\nPrefix length: %u\n", info->prefix_len);
    printf("Netmask: ");
    print_ip(&info->netmask);
    printf("\nBroadcast: ");
    print_ip(&info->broadcast);
    printf("\nNumber of hosts: %u\n", info->num_hosts);
}

int calculate_subnet_info(const ip_addr *ip, unsigned int prefix_len, subnet_info *info)
{
    if (prefix_len > 32)
        return -1;

    info->addr = *ip;
    info->prefix_len = prefix_len;

    unsigned int mask = 0xFFFFFFFF << (32 - prefix_len);
    info->netmask.octets[0] = (mask >> 24) & 0xFF;
    info->netmask.octets[1] = (mask >> 16) & 0xFF;
    info->netmask.octets[2] = (mask >> 8) & 0xFF;
    info->netmask.octets[3] = mask & 0xFF;

    info->broadcast.octets[0] = info->addr.octets[0] | ~info->netmask.octets[0];
    info->broadcast.octets[1] = info->addr.octets[1] | ~info->netmask.octets[1];
    info->broadcast.octets[2] = info->addr.octets[2] | ~info->netmask.octets[2];
    info->broadcast.octets[3] = info->addr.octets[3] | ~info->netmask.octets[3];

    info->num_hosts = pow(2, 32 - prefix_len) - 2;

    return 0;
}

int parse_ip(const char *str, ip_addr *ip)
{
    int octets[4];
    int num_octets = sscanf(str, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);
    if (num_octets != 4)
        return -1;

    for (int i = 0; i < 4; i++) {
        if (octets[i] < 0 || octets[i] > 255)
            return -1;
    }

    ip->octets[0] = octets[0];
    ip->octets[1] = octets[1];
    ip->octets[2] = octets[2];
    ip->octets[3] = octets[3];

    return 0;
}

int main(void)
{
    char ip_str[MAX_IP_LEN + 1];
    unsigned int prefix_len;

    printf("Enter IP address: ");
    if (scanf("%s", ip_str) != 1) {
        fprintf(stderr, "Invalid IP address\n");
        return EXIT_FAILURE;
    }

    printf("Enter prefix length: ");
    if (scanf("%u", &prefix_len) != 1) {
        fprintf(stderr, "Invalid prefix length\n");
        return EXIT_FAILURE;
    }

    ip_addr ip;
    if (parse_ip(ip_str, &ip) != 0) {
        fprintf(stderr, "Invalid IP address\n");
        return EXIT_FAILURE;
    }

    subnet_info info;
    if (calculate_subnet_info(&ip, prefix_len, &info) != 0) {
        fprintf(stderr, "Invalid prefix length\n");
        return EXIT_FAILURE;
    }

    print_subnet_info(&info);

    return EXIT_SUCCESS;
}