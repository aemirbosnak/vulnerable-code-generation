//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function to print the binary representation of an IP address
void print_binary(unsigned char *ip) {
    for (int i = 0; i < 4; i++) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (ip[i] >> j) & 1);
        }
        if (i < 3) printf(".");
    }
    printf("\n");
}

// Function to calculate the subnet mask
void calculate_subnet_mask(int prefix_length, unsigned char *subnet_mask) {
    for (int i = 0; i < 4; i++) {
        if (prefix_length >= 8) {
            subnet_mask[i] = 255; // Full byte
            prefix_length -= 8;
        } else {
            subnet_mask[i] = (unsigned char)(255 << (8 - prefix_length)) & 255;
            prefix_length = 0; // All done
        }
    }
}

// Function to calculate the network address
void calculate_network_address(unsigned char *ip, unsigned char *subnet_mask, unsigned char *network_address) {
    for (int i = 0; i < 4; i++) {
        network_address[i] = ip[i] & subnet_mask[i];
    }
}

// Function to calculate the broadcast address
void calculate_broadcast_address(unsigned char *network_address, unsigned char *subnet_mask, unsigned char *broadcast_address) {
    for (int i = 0; i < 4; i++) {
        broadcast_address[i] = network_address[i] | (~subnet_mask[i] & 255);
    }
}

// Function to calculate the number of valid hosts
int calculate_hosts(int prefix_length) {
    return (1 << (32 - prefix_length)) - 2; // Subtracting network and broadcast addresses
}

// Function to convert string IP to unsigned char array
int ip_str_to_bin(const char *ip_str, unsigned char *ip_bin) {
    return inet_pton(AF_INET, ip_str, ip_bin);
}

// Function to print the results
void print_results(unsigned char *ip, unsigned char *subnet_mask, unsigned char *network_address, unsigned char *broadcast_address, int valid_hosts) {
    printf("IP Address: ");
    print_binary(ip);
    printf("Subnet Mask: ");
    print_binary(subnet_mask);
    printf("Network Address: ");
    print_binary(network_address);
    printf("Broadcast Address: ");
    print_binary(broadcast_address);
    printf("Valid Hosts: %d\n", valid_hosts);
}

int main() {
    char ip_str[16];
    int prefix_length;
    unsigned char ip[4], subnet_mask[4], network_address[4], broadcast_address[4];

    printf("Enter an IP address (e.g., 192.168.1.1): ");
    fgets(ip_str, sizeof(ip_str), stdin);
    ip_str[strcspn(ip_str, "\n")] = 0; // Remove newline character at the end

    printf("Enter subnet prefix length (e.g., 24): ");
    scanf("%d", &prefix_length);

    if (prefix_length < 0 || prefix_length > 32) {
        fprintf(stderr, "Error: Prefix length must be between 0 and 32.\n");
        return EXIT_FAILURE;
    }

    if (ip_str_to_bin(ip_str, ip) != 1) {
        fprintf(stderr, "Error: Invalid IP address format.\n");
        return EXIT_FAILURE;
    }

    calculate_subnet_mask(prefix_length, subnet_mask);
    calculate_network_address(ip, subnet_mask, network_address);
    calculate_broadcast_address(network_address, subnet_mask, broadcast_address);
    int valid_hosts = calculate_hosts(prefix_length);

    print_results(ip, subnet_mask, network_address, broadcast_address, valid_hosts);

    return EXIT_SUCCESS;
}