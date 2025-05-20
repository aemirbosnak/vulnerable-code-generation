//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

typedef struct {
    unsigned int address;
    unsigned int netmask;
    unsigned int broadcast;
    unsigned int first_usable;
    unsigned int last_usable;
    unsigned int num_hosts;
} subnet_info_t;

void calculate_subnet(subnet_info_t *subnet, char *ip_address, char *netmask) {
    // Convert IP address and netmask to binary
    struct in_addr ip_addr;
    struct in_addr netmask_addr;
    inet_aton(ip_address, &ip_addr);
    inet_aton(netmask, &netmask_addr);

    // Extract address and netmask bits
    subnet->address = ntohl(ip_addr.s_addr);
    subnet->netmask = ntohl(netmask_addr.s_addr);

    // Calculate broadcast, first usable, and last usable addresses
    subnet->broadcast = subnet->address | ~subnet->netmask;
    subnet->first_usable = subnet->address + 1;
    subnet->last_usable = subnet->broadcast - 1;

    // Calculate number of hosts
    unsigned int num_ones = 0;
    for (int i = 0; i < 32; i++) {
        if ((subnet->netmask >> i) & 1) {
            num_ones++;
        }
    }
    subnet->num_hosts = (1 << (32 - num_ones)) - 2;
}

void print_subnet_info(subnet_info_t *subnet) {
    // Convert addresses to string
    char ip_address[INET_ADDRSTRLEN];
    char netmask[INET_ADDRSTRLEN];
    char broadcast[INET_ADDRSTRLEN];
    char first_usable[INET_ADDRSTRLEN];
    char last_usable[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &subnet->address, ip_address, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &subnet->netmask, netmask, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &subnet->broadcast, broadcast, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &subnet->first_usable, first_usable, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &subnet->last_usable, last_usable, INET_ADDRSTRLEN);

    // Print subnet information
    printf("IP Address: %s\n", ip_address);
    printf("Netmask: %s\n", netmask);
    printf("Broadcast Address: %s\n", broadcast);
    printf("First Usable Address: %s\n", first_usable);
    printf("Last Usable Address: %s\n", last_usable);
    printf("Number of Hosts: %u\n", subnet->num_hosts);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <netmask>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Allocate memory for subnet information
    subnet_info_t *subnet = malloc(sizeof(subnet_info_t));
    if (subnet == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Calculate subnet information
    calculate_subnet(subnet, argv[1], argv[2]);

    // Print subnet information
    print_subnet_info(subnet);

    // Free memory
    free(subnet);

    return EXIT_SUCCESS;
}