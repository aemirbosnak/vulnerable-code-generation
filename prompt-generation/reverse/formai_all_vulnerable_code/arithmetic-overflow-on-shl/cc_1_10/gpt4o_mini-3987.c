//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

#define IPV4_LEN 15
#define SUBNET_MASK_LEN 18

typedef struct {
    char ip[IPV4_LEN + 1];
    char subnet_mask[SUBNET_MASK_LEN + 1];
} NetworkConfig;

void convert_to_binary(uint32_t num, char *binary_str) {
    for(int i = 31; i >= 0; i--) {
        binary_str[i] = (num & (1 << i)) ? '1' : '0';
    }
    binary_str[32] = '\0';
}

void print_binary(const char *title, uint32_t number) {
    char binary_str[33];
    convert_to_binary(number, binary_str);
    printf("%s: %s\n", title, binary_str);
}

uint32_t ip_to_uint(const char *ip) {
    struct in_addr addr;
    inet_pton(AF_INET, ip, &addr);
    return ntohl(addr.s_addr);
}

void uint_to_ip(uint32_t uint_ip, char *ip) {
    struct in_addr addr;
    addr.s_addr = htonl(uint_ip);
    strcpy(ip, inet_ntoa(addr));
}

void calculate_subnet(NetworkConfig *config) {
    uint32_t ip = ip_to_uint(config->ip);
    uint32_t subnet = ip_to_uint(config->subnet_mask);
    
    uint32_t network_address = ip & subnet;
    uint32_t broadcast_address = network_address | ~subnet;

    char net_ip[IPV4_LEN + 1];
    char broad_ip[IPV4_LEN + 1];

    uint_to_ip(network_address, net_ip);
    uint_to_ip(broadcast_address, broad_ip);

    printf("Network Address: %s\n", net_ip);
    printf("Broadcast Address: %s\n", broad_ip);
    printf("Usable Hosts: %d\n", (broadcast_address - network_address - 1));
}

int main() {
    NetworkConfig config;

    printf("Subnet Calculator\n");
    printf("==================\n");

    printf("Enter IP Address (e.g. 192.168.1.1): ");
    fgets(config.ip, sizeof(config.ip), stdin);
    config.ip[strcspn(config.ip, "\n")] = 0; // Remove newline character

    printf("Enter Subnet Mask (e.g. 255.255.255.0): ");
    fgets(config.subnet_mask, sizeof(config.subnet_mask), stdin);
    config.subnet_mask[strcspn(config.subnet_mask, "\n")] = 0; // Remove newline character

    // Input validation here could be added

    printf("\nCalculating...\n");
    printf("==================\n");
    
    uint32_t ip_numeric = ip_to_uint(config.ip);
    uint32_t subnet_numeric = ip_to_uint(config.subnet_mask);
    
    printf("IP Address (Numeric): %u\n", ip_numeric);
    print_binary("IP Address (Binary)", ip_numeric);
    
    printf("Subnet Mask (Numeric): %u\n", subnet_numeric);
    print_binary("Subnet Mask (Binary)", subnet_numeric);

    calculate_subnet(&config);

    return 0;
}