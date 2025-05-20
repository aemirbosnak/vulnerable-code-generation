//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h> 

#define IP_ADDR_LEN 16 // Maximum length of an IPv4 address string
#define SUBNET_LEN 16 // Maximum length of a subnet mask string
#define MAX_SUBNETS 256

void print_usage() {
    printf("Usage: subnet_calculator <IP Address> <Subnet Mask>\n");
    printf("Example: subnet_calculator 192.168.1.10 255.255.255.0\n");
}

int is_valid_ip(const char *ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) != 0;
}

int is_valid_subnet(const char *subnet) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, subnet, &(sa.sin_addr)) != 0;
}

void calculate_subnet(const char *ip, const char *subnet) {
    struct sockaddr_in ip_addr, subnet_addr;
    inet_pton(AF_INET, ip, &(ip_addr.sin_addr));
    inet_pton(AF_INET, subnet, &(subnet_addr.sin_addr));

    // Calculating Network Address
    uint32_t ip_int = ntohl(ip_addr.sin_addr.s_addr);
    uint32_t subnet_int = ntohl(subnet_addr.sin_addr.s_addr);
    uint32_t network_int = ip_int & subnet_int;

    // Calculating Broadcast Address
    uint32_t broadcast_int = network_int | ~subnet_int;

    // Calculate Number of Usable Hosts
    uint32_t host_bits = 32 - __builtin_popcount(subnet_int); // Number of zeros in subnet mask
    uint32_t total_hosts = (1 << host_bits);
    uint32_t usable_hosts = total_hosts - 2; // Subtracting network and broadcast addresses

    // Prepare for output
    char network_str[IP_ADDR_LEN], broadcast_str[IP_ADDR_LEN];
    inet_ntop(AF_INET, &(struct in_addr){htonl(network_int)}, network_str, IP_ADDR_LEN);
    inet_ntop(AF_INET, &(struct in_addr){htonl(broadcast_int)}, broadcast_str, IP_ADDR_LEN);

    // Output results
    printf("IP Address:       %s\n", ip);
    printf("Subnet Mask:      %s\n", subnet);
    printf("Network Address:  %s\n", network_str);
    printf("Broadcast Address: %s\n", broadcast_str);
    printf("Usable Hosts:     %u\n", usable_hosts);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *ip = argv[1];
    const char *subnet = argv[2];

    if (!is_valid_ip(ip)) {
        fprintf(stderr, "Error: Invalid IP address format.\n");
        return EXIT_FAILURE;
    }

    if (!is_valid_subnet(subnet)) {
        fprintf(stderr, "Error: Invalid subnet mask format.\n");
        return EXIT_FAILURE;
    }

    calculate_subnet(ip, subnet);

    return EXIT_SUCCESS;
}