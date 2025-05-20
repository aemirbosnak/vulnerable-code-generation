//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage() {
    printf("Usage: ./subnet_calculator <IP> <Subnet_Mask>\n");
    printf("Example: ./subnet_calculator 192.168.1.10 255.255.255.0\n");
}

void parse_ip(const char* ip, unsigned char* bytes) {
    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &bytes[0], &bytes[1], &bytes[2], &bytes[3]);
}

void parse_mask(const char* mask, unsigned char* bytes) {
    sscanf(mask, "%hhu.%hhu.%hhu.%hhu", &bytes[0], &bytes[1], &bytes[2], &bytes[3]);
}

unsigned int calculate_network_address(unsigned char* ip, unsigned char* mask) {
    unsigned int network_address = 0;
    for (int i = 0; i < 4; i++) {
        network_address |= (ip[i] & mask[i]) << (8 * (3 - i));
    }
    return network_address;
}

void print_ip(unsigned char* ip) {
    printf("%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
}

void print_network_info(unsigned char* ip, unsigned char* mask, unsigned int network_address) {
    printf("Sherlock Holmes' Network Analysis:\n");
    printf("-------------------------------------\n");
    
    printf("Public IP Address: ");
    print_ip(ip);
    printf("\n");

    printf("Subnet Mask: ");
    print_ip(mask);
    printf("\n");

    printf("Calculated Network Address: ");
    unsigned char network_bytes[4];
    for (int i = 0; i < 4; i++) {
        network_bytes[i] = (network_address >> (8 * (3 - i))) & 0xFF;
    }
    print_ip(network_bytes);
    printf("\n");
    
    unsigned int wildcard_mask = ~(*(unsigned int*)mask);
    printf("Wildcard Mask: ");
    unsigned char wildcard_bytes[4];
    for (int i = 0; i < 4; i++) {
        wildcard_bytes[i] = (wildcard_mask >> (8 * (3 - i))) & 0xFF;
    }
    print_ip(wildcard_bytes);
    printf("\n");

    unsigned int total_hosts = (1 << (32 - __builtin_popcount(*(unsigned int*)mask))) - 2;
    printf("Total Usable Hosts: %u\n", total_hosts);
    printf("-------------------------------------\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }
    
    unsigned char ip[4];
    unsigned char mask[4];

    parse_ip(argv[1], ip);
    parse_mask(argv[2], mask);

    unsigned int network_address = calculate_network_address(ip, mask);
    print_network_info(ip, mask, network_address);

    return 0;
}