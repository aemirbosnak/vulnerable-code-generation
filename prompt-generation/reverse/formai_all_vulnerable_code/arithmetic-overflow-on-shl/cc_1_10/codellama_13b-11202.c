//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the subnet mask
unsigned long calculate_subnet_mask(int subnet_mask_bits) {
    unsigned long subnet_mask = 0;
    for (int i = 0; i < subnet_mask_bits; i++) {
        subnet_mask |= (1 << (31 - i));
    }
    return subnet_mask;
}

// Function to calculate the number of available hosts in a subnet
int calculate_available_hosts(int subnet_mask_bits) {
    return (int)pow(2, (32 - subnet_mask_bits));
}

// Function to calculate the broadcast address of a subnet
unsigned long calculate_broadcast_address(unsigned long ip_address, unsigned long subnet_mask) {
    return ip_address | ~subnet_mask;
}

// Function to calculate the network address of a subnet
unsigned long calculate_network_address(unsigned long ip_address, unsigned long subnet_mask) {
    return ip_address & subnet_mask;
}

// Function to calculate the subnet ID of a subnet
unsigned long calculate_subnet_id(unsigned long ip_address, unsigned long subnet_mask) {
    return ip_address & subnet_mask;
}

// Function to calculate the wildcard mask of a subnet
unsigned long calculate_wildcard_mask(unsigned long subnet_mask) {
    return ~subnet_mask;
}

// Function to calculate the IP address of the first available host in a subnet
unsigned long calculate_first_available_host(unsigned long network_address, int subnet_mask_bits) {
    return network_address + 1;
}

// Function to calculate the IP address of the last available host in a subnet
unsigned long calculate_last_available_host(unsigned long broadcast_address, int subnet_mask_bits) {
    return broadcast_address - 1;
}

int main() {
    unsigned long ip_address = 192 << 24 | 168 << 16 | 0 << 8 | 1;
    int subnet_mask_bits = 24;
    unsigned long subnet_mask = calculate_subnet_mask(subnet_mask_bits);
    unsigned long network_address = calculate_network_address(ip_address, subnet_mask);
    unsigned long broadcast_address = calculate_broadcast_address(ip_address, subnet_mask);
    int available_hosts = calculate_available_hosts(subnet_mask_bits);
    unsigned long first_available_host = calculate_first_available_host(network_address, subnet_mask_bits);
    unsigned long last_available_host = calculate_last_available_host(broadcast_address, subnet_mask_bits);
    printf("IP Address: %lu\n", ip_address);
    printf("Subnet Mask: %lu\n", subnet_mask);
    printf("Network Address: %lu\n", network_address);
    printf("Broadcast Address: %lu\n", broadcast_address);
    printf("Available Hosts: %d\n", available_hosts);
    printf("First Available Host: %lu\n", first_available_host);
    printf("Last Available Host: %lu\n", last_available_host);
    return 0;
}