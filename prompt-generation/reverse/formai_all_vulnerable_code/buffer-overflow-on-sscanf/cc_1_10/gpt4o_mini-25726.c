//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 16
#define MAX_CIDR_LENGTH 3
#define MAX_SUBNETS 256

void displayHelp() {
    printf("=== C Subnet Calculator ===\n");
    printf("Usage: subnet_calculator <IP_Address/CIDR>\n");
    printf("Example: subnet_calculator 192.168.1.1/24\n");
    printf("This program calculates the subnet, broadcast, and usable hosts.\n");
    printf("==========================\n");
}

void calculateSubnet(char *ip_cidr) {
    char ip_str[MAX_IP_LENGTH];
    int cidr;
    struct in_addr ip_addr, subnet_addr, broadcast_addr;
    unsigned long ip_binary, subnet_binary, broadcast_binary;
    unsigned long mask;

    // Split the IP and CIDR
    if (sscanf(ip_cidr, "%15[^/]/%d", ip_str, &cidr) != 2) {
        fprintf(stderr, "Invalid format. Use: <IP_Address/CIDR>\n");
        return;
    }

    if (cidr < 0 || cidr > 32) {
        fprintf(stderr, "CIDR must be between 0 and 32.\n");
        return;
    }

    // Convert IP string to binary
    if (inet_aton(ip_str, &ip_addr) == 0) {
        fprintf(stderr, "Invalid IP address.\n");
        return;
    }

    // Calculate subnet mask in binary
    mask = (cidr < 32) ? (~0UL >> (32 - cidr)) : ~0UL;
    subnet_binary = (ntohl(ip_addr.s_addr) & mask);
    broadcast_binary = subnet_binary | ~mask;
    
    subnet_addr.s_addr = htonl(subnet_binary);
    broadcast_addr.s_addr = htonl(broadcast_binary);
    
    // Calculate usable hosts
    unsigned long total_hosts = (1UL << (32 - cidr)) - 2; // Subtracting network and broadcast addresses

    // Print results
    printf("Results for %s:\n", ip_cidr);
    printf("  Subnet Address: %s\n", inet_ntoa(subnet_addr));
    printf("  Broadcast Address: %s\n", inet_ntoa(broadcast_addr));
    printf("  Total Usable Hosts: %lu\n", total_hosts);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        displayHelp();
        return EXIT_FAILURE;
    }

    calculateSubnet(argv[1]);
    return EXIT_SUCCESS;
}