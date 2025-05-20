//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define IP_ADDR_LEN 4
#define MAX_SUBNET_MASK_LEN 32

// Structure to store IP address and subnet mask
typedef struct {
    uint8_t addr[IP_ADDR_LEN];
    uint8_t mask[IP_ADDR_LEN];
} ip_addr_t;

// Function to check if the IP address is valid
int is_valid_ip_addr(ip_addr_t *addr) {
    for (int i = 0; i < IP_ADDR_LEN; i++) {
        if (addr->addr[i] < 0 || addr->addr[i] > 255) {
            return 0;
        }
    }
    return 1;
}

// Function to check if the subnet mask is valid
int is_valid_subnet_mask(ip_addr_t *mask) {
    uint32_t mask_int = 0;
    for (int i = 0; i < IP_ADDR_LEN; i++) {
        mask_int |= mask->addr[i] << (8 * i);
    }
    if (mask_int == 0 || mask_int == 0xFFFFFFFF) {
        return 0;
    }
    for (int i = 0; i < IP_ADDR_LEN; i++) {
        if (mask->addr[i] != 0 && mask->addr[i] != 255) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the network address
void calc_network_addr(ip_addr_t *addr, ip_addr_t *mask, ip_addr_t *network_addr) {
    for (int i = 0; i < IP_ADDR_LEN; i++) {
        network_addr->addr[i] = addr->addr[i] & mask->addr[i];
    }
}

// Function to calculate the broadcast address
void calc_broadcast_addr(ip_addr_t *addr, ip_addr_t *mask, ip_addr_t *broadcast_addr) {
    for (int i = 0; i < IP_ADDR_LEN; i++) {
        broadcast_addr->addr[i] = addr->addr[i] | ~mask->addr[i];
    }
}

// Function to get the number of hosts in the subnet
uint32_t get_num_hosts(ip_addr_t *mask) {
    uint32_t mask_int = 0;
    for (int i = 0; i < IP_ADDR_LEN; i++) {
        mask_int |= mask->addr[i] << (8 * i);
    }
    return ~mask_int - 2;
}

// Function to print the subnet calculator results
void print_results(ip_addr_t *addr, ip_addr_t *mask, ip_addr_t *network_addr, ip_addr_t *broadcast_addr, uint32_t num_hosts) {
    printf("IP Address: %u.%u.%u.%u\n", addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3]);
    printf("Subnet Mask: %u.%u.%u.%u\n", mask->addr[0], mask->addr[1], mask->addr[2], mask->addr[3]);
    printf("Network Address: %u.%u.%u.%u\n", network_addr->addr[0], network_addr->addr[1], network_addr->addr[2], network_addr->addr[3]);
    printf("Broadcast Address: %u.%u.%u.%u\n", broadcast_addr->addr[0], broadcast_addr->addr[1], broadcast_addr->addr[2], broadcast_addr->addr[3]);
    printf("Number of Hosts: %u\n", num_hosts);
}

int main(int argc, char **argv) {
    ip_addr_t addr, mask, network_addr, broadcast_addr;
    uint32_t num_hosts;

    if (argc != 3) {
        printf("Usage: %s <IP address> <subnet mask>\n", argv[0]);
        return 1;
    }

    // Parse the IP address
    if (sscanf(argv[1], "%hhu.%hhu.%hhu.%hhu", &addr.addr[0], &addr.addr[1], &addr.addr[2], &addr.addr[3]) != 4) {
        printf("Invalid IP address: %s\n", argv[1]);
        return 1;
    }

    // Parse the subnet mask
    if (sscanf(argv[2], "%hhu.%hhu.%hhu.%hhu", &mask.addr[0], &mask.addr[1], &mask.addr[2], &mask.addr[3]) != 4) {
        printf("Invalid subnet mask: %s\n", argv[2]);
        return 1;
    }

    // Check if the IP address and subnet mask are valid
    if (!is_valid_ip_addr(&addr)) {
        printf("Invalid IP address: %s\n", argv[1]);
        return 1;
    }
    if (!is_valid_subnet_mask(&mask)) {
        printf("Invalid subnet mask: %s\n", argv[2]);
        return 1;
    }

    // Calculate the network address and broadcast address
    calc_network_addr(&addr, &mask, &network_addr);
    calc_broadcast_addr(&addr, &mask, &broadcast_addr);

    // Get the number of hosts in the subnet
    num_hosts = get_num_hosts(&mask);

    // Print the results
    print_results(&addr, &mask, &network_addr, &broadcast_addr, num_hosts);

    return 0;
}