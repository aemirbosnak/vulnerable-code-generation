//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_IP_LEN 16
#define MAX_SUBNET_LEN 32
#define MAX_HOST_LEN 32
#define MAX_NETMASK_LEN 32
#define MAX_BROADCAST_LEN 32
#define MAX_GATEWAY_LEN 32
#define MAX_DNS_LEN 32

typedef struct {
    unsigned char octets[4];
} ip_addr_t;

typedef struct {
    unsigned int mask;
    unsigned int len;
} subnet_mask_t;

typedef struct {
    unsigned int count;
    unsigned int len;
} host_range_t;

typedef struct {
    ip_addr_t ip;
    ip_addr_t netmask;
    subnet_mask_t subnet;
    host_range_t host;
    ip_addr_t broadcast;
    ip_addr_t gateway;
    ip_addr_t dns;
} subnet_info_t;

static int parse_ip_addr(const char *str, ip_addr_t *ip) {
    int octets[4];
    if (sscanf(str, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]) != 4) {
        return -1;
    }
    for (int i = 0; i < 4; i++) {
        if (octets[i] < 0 || octets[i] > 255) {
            return -1;
        }
        ip->octets[i] = octets[i];
    }
    return 0;
}

static int parse_subnet_mask(const char *str, subnet_mask_t *mask) {
    int cidr;
    if (sscanf(str, "%d", &cidr) != 1) {
        return -1;
    }
    if (cidr < 0 || cidr > 32) {
        return -1;
    }
    mask->mask = 0xFFFFFFFF << (32 - cidr);
    mask->len = cidr;
    return 0;
}

static int calculate_host_range(subnet_info_t *info) {
    info->host.count = pow(2, 32 - info->subnet.len) - 2;
    info->host.len = 32 - info->subnet.len;
    return 0;
}

static int calculate_broadcast(subnet_info_t *info) {
    for (int i = 0; i < 4; i++) {
        info->broadcast.octets[i] = info->ip.octets[i] | ~info->netmask.octets[i];
    }
    return 0;
}

static int calculate_gateway(subnet_info_t *info) {
    for (int i = 0; i < 4; i++) {
        info->gateway.octets[i] = info->ip.octets[i] | ~info->netmask.octets[i];
    }
    info->gateway.octets[3]--;
    return 0;
}

static int calculate_dns(subnet_info_t *info) {
    for (int i = 0; i < 4; i++) {
        info->dns.octets[i] = info->ip.octets[i] | ~info->netmask.octets[i];
    }
    info->dns.octets[3] -= 2;
    return 0;
}

static int calculate_netmask(subnet_info_t *info) {
    for (int i = 0; i < 4; i++) {
        info->netmask.octets[i] = info->subnet.mask >> (24 - (i * 8));
    }
    return 0;
}

static int print_subnet_info(subnet_info_t *info) {
    printf("IP Address: %d.%d.%d.%d\n", info->ip.octets[0], info->ip.octets[1], info->ip.octets[2], info->ip.octets[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", info->netmask.octets[0], info->netmask.octets[1], info->netmask.octets[2], info->netmask.octets[3]);
    printf("Subnet: %d/%d\n", info->subnet.mask, info->subnet.len);
    printf("Host Range: %d.%d.%d.%d/%d\n", info->ip.octets[0], info->ip.octets[1], info->ip.octets[2], info->ip.octets[3] + 1, info->host.len);
    printf("Broadcast: %d.%d.%d.%d\n", info->broadcast.octets[0], info->broadcast.octets[1], info->broadcast.octets[2], info->broadcast.octets[3]);
    printf("Gateway: %d.%d.%d.%d\n", info->gateway.octets[0], info->gateway.octets[1], info->gateway.octets[2], info->gateway.octets[3]);
    printf("DNS: %d.%d.%d.%d\n", info->dns.octets[0], info->dns.octets[1], info->dns.octets[2], info->dns.octets[3]);
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <ip_address> <subnet_mask>\n", argv[0]);
        return -1;
    }

    subnet_info_t info;
    if (parse_ip_addr(argv[1], &info.ip) != 0) {
        printf("Invalid IP address: %s\n", argv[1]);
        return -1;
    }

    if (parse_subnet_mask(argv[2], &info.subnet) != 0) {
        printf("Invalid subnet mask: %s\n", argv[2]);
        return -1;
    }

    if (calculate_netmask(&info) != 0) {
        printf("Error calculating netmask\n");
        return -1;
    }

    if (calculate_host_range(&info) != 0) {
        printf("Error calculating host range\n");
        return -1;
    }

    if (calculate_broadcast(&info) != 0) {
        printf("Error calculating broadcast\n");
        return -1;
    }

    if (calculate_gateway(&info) != 0) {
        printf("Error calculating gateway\n");
        return -1;
    }

    if (calculate_dns(&info) != 0) {
        printf("Error calculating DNS\n");
        return -1;
    }

    print_subnet_info(&info);

    return 0;
}