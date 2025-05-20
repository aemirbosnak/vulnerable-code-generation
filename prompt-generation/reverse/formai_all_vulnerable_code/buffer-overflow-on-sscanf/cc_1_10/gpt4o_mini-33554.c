//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define MAX_IP_LENGTH 15
#define MAX_SUBNET_LENGTH 3

typedef struct {
    unsigned int ip[4];
    unsigned int subnet_mask[4];
} Network;

void display_help() {
    printf("C Subnet Calculator - Usage: ./subnet_calculator <IP_address> <Subnet_mask>\n");
    printf("Example: ./subnet_calculator 192.168.1.10 255.255.255.0\n");
}

void split_ip(const char *ip_string, unsigned int *ip_parts) {
    sscanf(ip_string, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);
}

void split_subnet(const char *subnet_string, unsigned int *subnet_parts) {
    sscanf(subnet_string, "%u.%u.%u.%u", &subnet_parts[0], &subnet_parts[1], &subnet_parts[2], &subnet_parts[3]);
}

unsigned int calculate_network_address(Network *network) {
    for (int i = 0; i < 4; i++) {
        network->ip[i] &= network->subnet_mask[i];
    }
    return 0;
}

void print_ip_address(unsigned int *ip) {
    printf("IP Address: %u.%u.%u.%u\n", ip[0], ip[1], ip[2], ip[3]);
}

void print_subnet_mask(unsigned int *subnet_mask) {
    printf("Subnet Mask: %u.%u.%u.%u\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
}

void print_network_address(const Network *network) {
    printf("Network Address: ");
    print_ip_address(network->ip);
}

int calculate_hosts_in_subnet(const unsigned int *subnet_mask) {
    unsigned int host_bits = 0;
    for (int i = 0; i < 4; i++) {
        host_bits += (subnet_mask[i] ^ 255);
    }
    return (1 << (32 - host_bits)) - 2; // Subtracting 2 for Network and Broadcast address
}

unsigned int calculate_broadcast_address(Network *network) {
    unsigned int broadcast[4];
    for (int i = 0; i < 4; i++) {
        broadcast[i] = network->ip[i] | (~network->subnet_mask[i] & 255);
    }
    printf("Broadcast Address: %u.%u.%u.%u\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_help();
        return 1;
    }

    Network network;
    split_ip(argv[1], network.ip);
    split_subnet(argv[2], network.subnet_mask);
    
    // Calculate the Network Address
    calculate_network_address(&network);

    // Print Results
    printf("\n--- Network Information ---\n");
    print_ip_address(network.ip);
    print_subnet_mask(network.subnet_mask);
    print_network_address(&network);

    // Calculate and print Broadcast Address
    calculate_broadcast_address(&network);

    // Calculate and print the available hosts in subnet
    int available_hosts = calculate_hosts_in_subnet(network.subnet_mask);
    printf("Available Hosts: %d\n", available_hosts);

    return 0;
}