//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_SUBNETS 256

typedef struct {
    char ip[16];
    char subnet_mask[16];
    char network[16];
    char broadcast[16];
    int total_hosts;
} Subnet;

void calculate_subnet_details(const char *ip_addr, const char *subnet_mask, Subnet *subnet) {
    struct in_addr ip, mask;
    if (inet_pton(AF_INET, ip_addr, &ip) != 1 || inet_pton(AF_INET, subnet_mask, &mask) != 1) {
        fprintf(stderr, "Invalid IP address or subnet mask\n");
        return;
    }

    // Calculate network address
    struct in_addr network;
    network.s_addr = ip.s_addr & mask.s_addr;
    strcpy(subnet->network, inet_ntoa(network));

    // Calculate broadcast address
    struct in_addr broadcast;
    broadcast.s_addr = network.s_addr | ~mask.s_addr;
    strcpy(subnet->broadcast, inet_ntoa(broadcast));

    // Calculate number of hosts
    subnet->total_hosts = (1 << (32 - (32 - __builtin_popcount(mask.s_addr)))) - 2;

    // Store the results
    strcpy(subnet->ip, ip_addr);
    strcpy(subnet->subnet_mask, subnet_mask);
}

void print_subnet_details(Subnet *subnet) {
    printf("Subnet Details:\n");
    printf("IP Address: %s\n", subnet->ip);
    printf("Subnet Mask: %s\n", subnet->subnet_mask);
    printf("Network Address: %s\n", subnet->network);
    printf("Broadcast Address: %s\n", subnet->broadcast);
    printf("Total Usable Hosts: %d\n", subnet->total_hosts);
}

void convert_decimal_to_binary(unsigned int num, char *binary) {
    for (int i = 31; i >= 0; i--) {
        binary[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
    binary[32] = '\0';
}

int main() {
    char ip_addr[16];
    char subnet_mask[16];
    Subnet subnet;

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter the IP address (e.g., 192.168.1.1): ");
    scanf("%15s", ip_addr);
    printf("Please enter the subnet mask (e.g., 255.255.255.0): ");
    scanf("%15s", subnet_mask);

    calculate_subnet_details(ip_addr, subnet_mask, &subnet);
    
    print_subnet_details(&subnet);

    // Optional: Display binary representation of IP address and subnet mask
    char binary_ip[33], binary_mask[33], binary_network[33], binary_broadcast[33];
    convert_decimal_to_binary(inet_addr(subnet.ip), binary_ip);
    convert_decimal_to_binary(inet_addr(subnet.subnet_mask), binary_mask);
    convert_decimal_to_binary(inet_addr(subnet.network), binary_network);
    convert_decimal_to_binary(inet_addr(subnet.broadcast), binary_broadcast);

    printf("\nBinary Representation:\n");
    printf("IP Address in Binary: %s\n", binary_ip);
    printf("Subnet Mask in Binary: %s\n", binary_mask);
    printf("Network Address in Binary: %s\n", binary_network);
    printf("Broadcast Address in Binary: %s\n", binary_broadcast);

    return 0;
}