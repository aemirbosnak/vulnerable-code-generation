//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LEN 16

// Function to calculate network address
void calculate_network_address(const char *ip, const char *subnet_mask, char *network_address) {
    struct in_addr ip_addr, mask_addr, net_addr;
    
    inet_pton(AF_INET, ip, &ip_addr);
    inet_pton(AF_INET, subnet_mask, &mask_addr);

    net_addr.s_addr = ip_addr.s_addr & mask_addr.s_addr;
    inet_ntop(AF_INET, &net_addr, network_address, MAX_IP_LEN);
}

// Function to calculate broadcast address
void calculate_broadcast_address(const char *ip, const char *subnet_mask, char *broadcast_address) {
    struct in_addr ip_addr, mask_addr, broadcast_addr;
    
    inet_pton(AF_INET, ip, &ip_addr);
    inet_pton(AF_INET, subnet_mask, &mask_addr);
    
    broadcast_addr.s_addr = (ip_addr.s_addr & mask_addr.s_addr) | ~mask_addr.s_addr;
    inet_ntop(AF_INET, &broadcast_addr, broadcast_address, MAX_IP_LEN);
}

// Function to convert CIDR to subnet mask
void cidr_to_subnet_mask(int cidr, char *subnet_mask) {
    unsigned int mask = (0xFFFFFFFF << (32 - cidr)) & 0xFFFFFFFF;
    struct in_addr mask_addr;
    mask_addr.s_addr = htonl(mask);
    inet_ntop(AF_INET, &mask_addr, subnet_mask, MAX_IP_LEN);
}

// Function to calculate number of usable IPs
int calculate_usable_ips(int cidr) {
    return (1 << (32 - cidr)) - 2; // Subtract 2 for network and broadcast
}

// Function to validate IP address
int valid_ip(const char *ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) == 1;
}

// Function to validate CIDR notation
int valid_cidr(int cidr) {
    return cidr >= 0 && cidr <= 32;
}

int main() {
    char ip[MAX_IP_LEN];
    int cidr;
    char subnet_mask[MAX_IP_LEN];
    char network_address[MAX_IP_LEN];
    char broadcast_address[MAX_IP_LEN];
    
    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter a valid IP address (IPv4): ");
    scanf("%s", ip);

    if (!valid_ip(ip)) {
        printf("Invalid IP address format.\n");
        return 1;
    }

    printf("Please enter subnet mask in CIDR notation (0-32): ");
    scanf("%d", &cidr);

    if (!valid_cidr(cidr)) {
        printf("Invalid CIDR notation. Must be between 0 and 32.\n");
        return 1;
    }

    cidr_to_subnet_mask(cidr, subnet_mask);
    calculate_network_address(ip, subnet_mask, network_address);
    calculate_broadcast_address(ip, subnet_mask, broadcast_address);
    int usable_ips = calculate_usable_ips(cidr);

    printf("\nResults:\n");
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Network Address: %s\n", network_address);
    printf("Broadcast Address: %s\n", broadcast_address);
    printf("Usable IP Addresses: %d\n", usable_ips);

    return 0;
}