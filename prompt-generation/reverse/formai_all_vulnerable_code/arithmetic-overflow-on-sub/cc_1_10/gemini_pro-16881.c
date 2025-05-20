//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    unsigned int address;
    unsigned int subnet_mask;
    unsigned int network_address;
    unsigned int broadcast_address;
    unsigned int host_min;
    unsigned int host_max;
    unsigned int num_hosts;
    unsigned int num_subnets;
} subnet_info;

void print_usage() {
    printf("Usage: subnet_calculator <network address> <subnet mask>\n");
    printf("Example: subnet_calculator 192.168.1.0 255.255.255.0\n");
}

unsigned int parse_ip_address(char *ip_address) {
    unsigned int address = 0;
    char *token;
    char *saveptr;
    token = strtok_r(ip_address, ".", &saveptr);
    while (token != NULL) {
        address = (address << 8) | atoi(token);
        token = strtok_r(NULL, ".", &saveptr);
    }
    return address;
}

unsigned int parse_subnet_mask(char *subnet_mask) {
    unsigned int mask = 0;
    char *token;
    char *saveptr;
    token = strtok_r(subnet_mask, ".", &saveptr);
    while (token != NULL) {
        mask = (mask << 8) | atoi(token);
        token = strtok_r(NULL, ".", &saveptr);
    }
    return mask;
}

subnet_info calculate_subnet(unsigned int address, unsigned int mask) {
    subnet_info info;
    info.address = address;
    info.subnet_mask = mask;
    info.network_address = address & mask;
    info.broadcast_address = info.network_address | ~mask;
    info.host_min = info.network_address + 1;
    info.host_max = info.broadcast_address - 1;
    info.num_hosts = (unsigned int) pow(2, 32 - (int) log2(mask));
    info.num_subnets = (unsigned int) pow(2, (int) log2(mask));
    return info;
}

void print_subnet_info(subnet_info info) {
    printf("Network Address: %u.%u.%u.%u\n",
        (info.network_address >> 24) & 0xFF,
        (info.network_address >> 16) & 0xFF,
        (info.network_address >> 8) & 0xFF,
        info.network_address & 0xFF);
    printf("Subnet Mask: %u.%u.%u.%u\n",
        (info.subnet_mask >> 24) & 0xFF,
        (info.subnet_mask >> 16) & 0xFF,
        (info.subnet_mask >> 8) & 0xFF,
        info.subnet_mask & 0xFF);
    printf("Broadcast Address: %u.%u.%u.%u\n",
        (info.broadcast_address >> 24) & 0xFF,
        (info.broadcast_address >> 16) & 0xFF,
        (info.broadcast_address >> 8) & 0xFF,
        info.broadcast_address & 0xFF);
    printf("Host Min: %u.%u.%u.%u\n",
        (info.host_min >> 24) & 0xFF,
        (info.host_min >> 16) & 0xFF,
        (info.host_min >> 8) & 0xFF,
        info.host_min & 0xFF);
    printf("Host Max: %u.%u.%u.%u\n",
        (info.host_max >> 24) & 0xFF,
        (info.host_max >> 16) & 0xFF,
        (info.host_max >> 8) & 0xFF,
        info.host_max & 0xFF);
    printf("Number of Hosts: %u\n", info.num_hosts);
    printf("Number of Subnets: %u\n", info.num_subnets);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }
    unsigned int address = parse_ip_address(argv[1]);
    unsigned int mask = parse_subnet_mask(argv[2]);
    subnet_info info = calculate_subnet(address, mask);
    print_subnet_info(info);
    return 0;
}