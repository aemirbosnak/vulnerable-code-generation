//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_SUBNETS 256

// Structure to hold subnet information
typedef struct {
    uint8_t subnet[4];
    uint8_t mask[4];
    uint8_t broadcast[4];
    uint8_t first_host[4];
    uint8_t last_host[4];
    int total_hosts;
} SubnetInfo;

// Function prototypes
void calculate_subnet_info(const char *ip_address, int prefix_length, SubnetInfo *subnet_info);
void print_subnet_info(const SubnetInfo *subnet_info);
void ip_to_bytes(const char *ip_address, uint8_t *bytes);
void bytes_to_ip(const uint8_t *bytes, char *ip_address);
void print_usage();

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    int prefix_length = atoi(argv[2]);

    if (prefix_length < 0 || prefix_length > 32) {
        fprintf(stderr, "Error: Prefix length must be between 0 and 32.\n");
        return EXIT_FAILURE;
    }
    
    SubnetInfo subnet_info;
    calculate_subnet_info(ip_address, prefix_length, &subnet_info);
    print_subnet_info(&subnet_info);

    return EXIT_SUCCESS;
}

void calculate_subnet_info(const char *ip_address, int prefix_length, SubnetInfo *subnet_info) {
    uint8_t ip_bytes[4];
    ip_to_bytes(ip_address, ip_bytes);

    // Calculate subnet mask
    for (int i = 0; i < 4; i++) {
        if (prefix_length >= 8) {
            subnet_info->mask[i] = 255;
            prefix_length -= 8;
        } else {
            subnet_info->mask[i] = (uint8_t)(255 << (8 - prefix_length));
            prefix_length = 0;
        }
    }

    // Calculate subnet address
    for (int i = 0; i < 4; i++) {
        subnet_info->subnet[i] = ip_bytes[i] & subnet_info->mask[i];
    }

    // Calculate broadcast address
    for (int i = 0; i < 4; i++) {
        subnet_info->broadcast[i] = subnet_info->subnet[i] | (~subnet_info->mask[i]);
    }

    // Calculate first and last host
    for (int i = 0; i < 4; i++) {
        subnet_info->first_host[i] = subnet_info->subnet[i];
        subnet_info->last_host[i] = subnet_info->broadcast[i];
    }
    
    subnet_info->first_host[3] += 1;  // First host is +1 from subnet
    subnet_info->last_host[3] -= 1;   // Last host is -1 from broadcast

    // Calculate total hosts
    subnet_info->total_hosts = 1 << (32 - prefix_length);
    subnet_info->total_hosts -= 2; // Subtract 2 for network and broadcast address
}

void ip_to_bytes(const char *ip_address, uint8_t *bytes) {
    sscanf(ip_address, "%hhu.%hhu.%hhu.%hhu", &bytes[0], &bytes[1], &bytes[2], &bytes[3]);
}

void bytes_to_ip(const uint8_t *bytes, char *ip_address) {
    sprintf(ip_address, "%hhu.%hhu.%hhu.%hhu", bytes[0], bytes[1], bytes[2], bytes[3]);
}

void print_subnet_info(const SubnetInfo *subnet_info) {
    char subnet_str[16], broadcast_str[16], first_host_str[16], last_host_str[16];
    
    bytes_to_ip(subnet_info->subnet, subnet_str);
    bytes_to_ip(subnet_info->broadcast, broadcast_str);
    bytes_to_ip(subnet_info->first_host, first_host_str);
    bytes_to_ip(subnet_info->last_host, last_host_str);

    printf("Subnet Address: %s\n", subnet_str);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet_info->mask[0], subnet_info->mask[1], subnet_info->mask[2], subnet_info->mask[3]);
    printf("Broadcast Address: %s\n", broadcast_str);
    printf("First Host: %s\n", first_host_str);
    printf("Last Host: %s\n", last_host_str);
    printf("Total Hosts Available: %d\n", subnet_info->total_hosts);
}

void print_usage() {
    printf("Usage: ./subnet_calculator <IP Address> <Prefix Length>\n");
    printf("Example: ./subnet_calculator 192.168.1.1 24\n");
}