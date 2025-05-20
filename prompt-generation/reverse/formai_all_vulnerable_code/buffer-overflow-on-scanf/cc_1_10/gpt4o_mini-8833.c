//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function to convert CIDR to subnet mask
void cidr_to_mask(int cidr, char *mask) {
    unsigned long netmask = 0xFFFFFFFF << (32 - cidr);
    sprintf(mask, "%u.%u.%u.%u", 
            (netmask >> 24) & 0xFF, 
            (netmask >> 16) & 0xFF, 
            (netmask >> 8)  & 0xFF, 
            netmask & 0xFF);
}

// Function to calculate network, broadcast, and valid hosts
void calculate_subnet_properties(const char *ip, const char *mask) {
    struct in_addr ip_addr, mask_addr, network_addr, broadcast_addr;

    inet_aton(ip, &ip_addr);
    inet_aton(mask, &mask_addr);

    // Calculate network address
    network_addr.s_addr = ip_addr.s_addr & mask_addr.s_addr;

    // Calculate broadcast address
    broadcast_addr.s_addr = network_addr.s_addr | ~mask_addr.s_addr;

    // Valid hosts calculation
    unsigned long first_host = ntohl(network_addr.s_addr) + 1;
    unsigned long last_host = ntohl(broadcast_addr.s_addr) - 1;

    // Output results
    printf("=========================================\n");
    printf("Cyberpunk Subnet Calculator\n");
    printf("=========================================\n");
    printf("IP Address:     %s\n", ip);
    printf("Subnet Mask:    %s\n", mask);
    printf("Network Address: %s\n", inet_ntoa(network_addr));
    printf("Broadcast Address: %s\n", inet_ntoa(broadcast_addr));
    printf("Valid Hosts:    %lu - %lu\n", first_host, last_host);
    printf("Total Valid Hosts: %lu\n", last_host - first_host + 1);
    printf("=========================================\n");
}

int main() {
    char input_ip[16];
    int cidr;
    char mask[16];

    printf("\033[1;32mEnter your IP Address (Cyberpunk style): \033[0m");
    scanf("%s", input_ip);
    printf("\033[1;32mEnter your CIDR ( /8 to /30 ): \033[0m");
    scanf("%d", &cidr);

    if (cidr < 8 || cidr > 30) {
        printf("CIDR must be between 8 and 30.\n");
        return 1;
    }

    cidr_to_mask(cidr, mask);
    calculate_subnet_properties(input_ip, mask);

    printf("\033[1;34mGood luck in the Neon City!\033[0m\n");
    return 0;
}