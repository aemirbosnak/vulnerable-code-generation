//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_IP_LEN 15
#define MAX_SUBNET_LEN 2

typedef struct ip_address {
    uint8_t octet1;
    uint8_t octet2;
    uint8_t octet3;
    uint8_t octet4;
} ip_address_t;

// Helper functions
ip_address_t get_ip(char* ip_str) {
    ip_address_t ip = {0, 0, 0, 0};
    sscanf(ip_str, "%hhu.%hhu.%hhu.%hhu", &ip.octet1, &ip.octet2, &ip.octet3, &ip.octet4);
    return ip;
}

void print_ip(ip_address_t ip) {
    printf("%d.%d.%d.%d", ip.octet1, ip.octet2, ip.octet3, ip.octet4);
}

// Main functions
void subnet_calculator(char* ip_str, char* subnet_str) {
    ip_address_t ip = get_ip(ip_str);
    uint8_t subnet = atoi(subnet_str);

    // Calculate subnet mask
    uint8_t mask_octet1 = (subnet >= 8) ? 255 : (255 - (1 << (8 - subnet)));
    uint8_t mask_octet2 = (subnet >= 8) ? (subnet > 8) ? 255 : 0 : 0;
    uint8_t mask_octet3 = (subnet >= 16) ? (subnet > 16) ? 255 : 0 : 0;
    uint8_t mask_octet4 = (subnet >= 24) ? (subnet > 24) ? 255 : 0 : 0;
    ip_address_t subnet_mask = {mask_octet1, mask_octet2, mask_octet3, mask_octet4};

    // Calculate network address
    ip_address_t network_address = {ip.octet1 & subnet_mask.octet1, ip.octet2 & subnet_mask.octet2, 
                                    ip.octet3 & subnet_mask.octet3, ip.octet4 & subnet_mask.octet4};

    // Calculate broadcast address
    uint8_t broadcast_octet1 = (~subnet_mask.octet1) | ip.octet1;
    uint8_t broadcast_octet2 = (~subnet_mask.octet2) | ip.octet2;
    uint8_t broadcast_octet3 = (~subnet_mask.octet3) | ip.octet3;
    uint8_t broadcast_octet4 = (~subnet_mask.octet4) | ip.octet4;
    ip_address_t broadcast_address = {broadcast_octet1, broadcast_octet2, broadcast_octet3, broadcast_octet4};

    // Calculate host range
    ip_address_t first_ip = {network_address.octet1, network_address.octet2, network_address.octet3, network_address.octet4 + 1};
    ip_address_t last_ip = {broadcast_address.octet1, broadcast_address.octet2, broadcast_address.octet3, broadcast_address.octet4 - 1};

    // Print results
    printf("IP address: ");
    print_ip(ip);
    printf("\n");
    printf("Subnet mask: ");
    print_ip(subnet_mask);
    printf("\n");
    printf("Network address: ");
    print_ip(network_address);
    printf("\n");
    printf("Broadcast address: ");
    print_ip(broadcast_address);
    printf("\n");
    printf("Host range: ");
    print_ip(first_ip);
    printf(" - ");
    print_ip(last_ip);
    printf("\n");
}

int main() {
    char ip_str[MAX_IP_LEN+1];
    char subnet_str[MAX_SUBNET_LEN+1];

    // Get IP address and subnet from user
    printf("Enter IP address in the format X.X.X.X (where X is a number between 0 and 255): ");
    fgets(ip_str, MAX_IP_LEN+1, stdin);
    ip_str[strcspn(ip_str, "\n")] = 0; // Remove newline character
    printf("Enter subnet mask in CIDR notation (e.g. /24): ");
    fgets(subnet_str, MAX_SUBNET_LEN+1, stdin);
    subnet_str[strcspn(subnet_str, "\n")] = 0; // Remove newline character

    subnet_calculator(ip_str, subnet_str);

    return 0;
}