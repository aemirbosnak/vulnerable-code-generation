//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_ADDR_LEN 16
#define MAX_SUBNET_MASK_LEN 16

typedef struct {
    unsigned char octets[4];
} ip_addr_t;

typedef struct {
    unsigned char octets[4];
    unsigned int prefix_len;
} subnet_mask_t;

void print_ip_addr(ip_addr_t ip_addr) {
    printf("%u.%u.%u.%u", ip_addr.octets[0], ip_addr.octets[1], ip_addr.octets[2], ip_addr.octets[3]);
}

void print_subnet_mask(subnet_mask_t subnet_mask) {
    printf("%u.%u.%u.%u/%u", subnet_mask.octets[0], subnet_mask.octets[1], subnet_mask.octets[2], subnet_mask.octets[3], subnet_mask.prefix_len);
}

int parse_ip_addr(char *ip_addr_str, ip_addr_t *ip_addr) {
    int octets_parsed = 0;
    char *octet_str = strtok(ip_addr_str, ".");
    while (octet_str != NULL && octets_parsed < 4) {
        ip_addr->octets[octets_parsed] = atoi(octet_str);
        octets_parsed++;
        octet_str = strtok(NULL, ".");
    }
    return (octets_parsed == 4);
}

int parse_subnet_mask(char *subnet_mask_str, subnet_mask_t *subnet_mask) {
    int octets_parsed = 0;
    char *octet_str = strtok(subnet_mask_str, ".");
    while (octet_str != NULL && octets_parsed < 4) {
        subnet_mask->octets[octets_parsed] = atoi(octet_str);
        octets_parsed++;
        octet_str = strtok(NULL, ".");
    }
    if (octets_parsed != 4) {
        return 0;
    }
    char *prefix_len_str = strtok(NULL, "/");
    if (prefix_len_str == NULL) {
        return 0;
    }
    subnet_mask->prefix_len = atoi(prefix_len_str);
    return (subnet_mask->prefix_len >= 0 && subnet_mask->prefix_len <= 32);
}

int calculate_subnet_info(ip_addr_t ip_addr, subnet_mask_t subnet_mask, ip_addr_t *network_addr, ip_addr_t *broadcast_addr, unsigned int *num_hosts) {
    if (subnet_mask.prefix_len > 32) {
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        network_addr->octets[i] = ip_addr.octets[i] & subnet_mask.octets[i];
        broadcast_addr->octets[i] = network_addr->octets[i] | ~subnet_mask.octets[i];
    }
    *num_hosts = pow(2, 32 - subnet_mask.prefix_len) - 2;
    return 1;
}

int main() {
    char ip_addr_str[MAX_IP_ADDR_LEN];
    char subnet_mask_str[MAX_SUBNET_MASK_LEN];
    ip_addr_t ip_addr;
    subnet_mask_t subnet_mask;
    ip_addr_t network_addr;
    ip_addr_t broadcast_addr;
    unsigned int num_hosts;

    printf("Enter IP address: ");
    scanf("%s", ip_addr_str);

    printf("Enter subnet mask: ");
    scanf("%s", subnet_mask_str);

    if (!parse_ip_addr(ip_addr_str, &ip_addr)) {
        printf("Invalid IP address.\n");
        return 1;
    }

    if (!parse_subnet_mask(subnet_mask_str, &subnet_mask)) {
        printf("Invalid subnet mask.\n");
        return 1;
    }

    if (!calculate_subnet_info(ip_addr, subnet_mask, &network_addr, &broadcast_addr, &num_hosts)) {
        printf("Invalid subnet mask.\n");
        return 1;
    }

    printf("IP address: ");
    print_ip_addr(ip_addr);
    printf("\n");

    printf("Subnet mask: ");
    print_subnet_mask(subnet_mask);
    printf("\n");

    printf("Network address: ");
    print_ip_addr(network_addr);
    printf("\n");

    printf("Broadcast address: ");
    print_ip_addr(broadcast_addr);
    printf("\n");

    printf("Number of hosts: %u\n", num_hosts);

    return 0;
}