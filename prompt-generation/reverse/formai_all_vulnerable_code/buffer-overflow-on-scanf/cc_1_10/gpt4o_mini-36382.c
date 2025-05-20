//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_ADDRESSES 256

void calculate_subnet(unsigned char ip[], unsigned char subnet[], unsigned char network[], unsigned char broadcast[], int *total_hosts, unsigned char usable_hosts_start[], unsigned char usable_hosts_end[]) {
    // Calculate network address
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & subnet[i];
    }

    // Calculate broadcast address
    for (int i = 0; i < 4; i++) {
        broadcast[i] = network[i] | (~subnet[i] & 0xFF);
    }

    // Calculate total number of hosts
    int zeros_count = 0;
    for (int i = 0; i < 4; i++) {
        zeros_count += __builtin_popcount(~subnet[i]);
    }
    *total_hosts = (1 << zeros_count) - 2; // Subtracting 2 for network and broadcast addresses

    // Calculate usable host range start and end
    for (int i = 0; i < 4; i++) {
        usable_hosts_start[i] = network[i];
        usable_hosts_end[i] = broadcast[i];
    }
    usable_hosts_start[3] += 1; // First usable address
    usable_hosts_end[3] -= 1; // Last usable address
}

void print_ip_address(const char *label, unsigned char ip[]) {
    printf("%s: %d.%d.%d.%d\n", label, ip[0], ip[1], ip[2], ip[3]);
}

int main() {
    unsigned char ip[4];
    unsigned char subnet[4];
    unsigned char network[4];
    unsigned char broadcast[4];
    unsigned char usable_hosts_start[4];
    unsigned char usable_hosts_end[4];
    int total_hosts;

    // Input: IP Address
    printf("Enter an IP address (e.g., 192.168.1.1): ");
    scanf("%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);

    // Input: Subnet Mask
    printf("Enter a subnet mask (e.g., 255.255.255.0): ");
    scanf("%hhu.%hhu.%hhu.%hhu", &subnet[0], &subnet[1], &subnet[2], &subnet[3]);

    // Calculate subnet information
    calculate_subnet(ip, subnet, network, broadcast, &total_hosts, usable_hosts_start, usable_hosts_end);

    // Output: Network Address
    print_ip_address("Network Address", network);

    // Output: Broadcast Address
    print_ip_address("Broadcast Address", broadcast);

    // Output: Total Usable Hosts
    printf("Total Hosts: %d\n", total_hosts);

    // Output: Usable Host Range
    print_ip_address("Usable Hosts Start", usable_hosts_start);
    print_ip_address("Usable Hosts End", usable_hosts_end);

    return 0;
}