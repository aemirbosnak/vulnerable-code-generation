//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function to convert IP address and subnet mask from string to integer array
void parse_ip(char *ip_str, unsigned char *ip) {
    sscanf(ip_str, "%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);
}

// Function to calculate the number of usable hosts
int calculate_usable_hosts(int subnet_mask) {
    return (1 << (32 - subnet_mask)) - 2;
}

// Function to calculate network address
void calculate_network_address(unsigned char *ip, unsigned char *mask, unsigned char *network) {
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
    }
}

// Function to calculate broadcast address
void calculate_broadcast_address(unsigned char *network, unsigned char *mask, unsigned char *broadcast) {
    for (int i = 0; i < 4; i++) {
        broadcast[i] = network[i] | ~mask[i];
    }
}

// Function to print IP address in dot-decimal notation
void print_ip(unsigned char *ip) {
    printf("%hhu.%hhu.%hhu.%hhu", ip[0], ip[1], ip[2], ip[3]);
}

// Main function
int main() {
    char ip_str[16];
    char mask_str[16];
    unsigned char ip[4], mask[4], network[4], broadcast[4];
    int subnet_mask;

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter an IP address (e.g., 192.168.1.1): ");
    scanf("%15s", ip_str);
    
    printf("Please enter a subnet mask (e.g., 255.255.255.0 or CIDR notation (e.g., /24)): ");
    scanf("%15s", mask_str);

    // Determine if subnet mask is in CIDR format
    if (mask_str[0] == '/') {
        subnet_mask = atoi(&mask_str[1]);
        if (subnet_mask < 0 || subnet_mask > 32) {
            fprintf(stderr, "Invalid subnet mask provided!\n");
            return EXIT_FAILURE;
        }
        // Convert CIDR to subnet mask
        for (int i = 0; i < 4; i++) {
            mask[i] = (subnet_mask >= 8) ? 255 : (subnet_mask == 0) ? 0 : (1 << subnet_mask) - 1;
            subnet_mask -= 8;
        }
    } else {
        parse_ip(mask_str, mask);
        subnet_mask = 0;
        for (int i = 0; i < 4; i++) {
            if (mask[i] == 255) {
                subnet_mask += 8;
            } else if (mask[i] == 0) {
                break;
            } else {
                subnet_mask += 8 - __builtin_clz(mask[i]) + 1;  // Count leading zeros
                break;
            }
        }
    }
    
    parse_ip(ip_str, ip);

    calculate_network_address(ip, mask, network);
    calculate_broadcast_address(network, mask, broadcast);
    int usable_hosts = calculate_usable_hosts(subnet_mask);

    printf("\nSubnet Details:\n");
    printf("Network Address: ");
    print_ip(network);
    printf("\nBroadcast Address: ");
    print_ip(broadcast);
    printf("\nNumber of Usable Hosts: %d\n", usable_hosts);
    
    return EXIT_SUCCESS;
}