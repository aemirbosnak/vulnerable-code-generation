//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function to convert string IP to binary form
int str_to_bin(const char *ip_str, struct in_addr *ip_bin) {
    return inet_pton(AF_INET, ip_str, ip_bin);
}

// Function to display binary representation of an IP address
void display_bin_ip(struct in_addr ip) {
    unsigned char *bytes = (unsigned char*)&ip;
    for (int i = 0; i < 4; i++) {
        printf("%d", bytes[i]);
        if (i < 3) printf(".");
    }
}

// Function to calculate network and broadcast addresses
void calculate_network_broadcast(struct in_addr ip, struct in_addr mask, struct in_addr *network, struct in_addr *broadcast) {
    network->s_addr = ip.s_addr & mask.s_addr;
    broadcast->s_addr = network->s_addr | ~mask.s_addr;
}

// Function to calculate number of hosts
unsigned int calculate_num_hosts(struct in_addr mask) {
    unsigned int bits = (__builtin_popcount(~mask.s_addr));
    return (1 << bits) - 2;  // Subtracting two for network and broadcast addresses
}

// Function to print subnet information
void print_subnet_info(struct in_addr ip, struct in_addr mask) {
    struct in_addr network, broadcast;

    calculate_network_broadcast(ip, mask, &network, &broadcast);
    unsigned int num_hosts = calculate_num_hosts(mask);

    printf("IP Address: ");
    display_bin_ip(ip);
    printf("\n");

    printf("Subnet Mask: ");
    display_bin_ip(mask);
    printf("\n");

    printf("Network Address: ");
    display_bin_ip(network);
    printf("\n");

    printf("Broadcast Address: ");
    display_bin_ip(broadcast);
    printf("\n");

    printf("Number of Valid Hosts: %u\n", num_hosts);
    printf("Valid Host IP Range: ");
    display_bin_ip(network);
    printf(" - ");
    display_bin_ip(broadcast);
    printf("\n");
}

// Main function
int main() {
    char ip_str[16], mask_str[16];
    struct in_addr ip, mask;

    printf("Enter IP Address (e.g., 192.168.1.1): ");
    scanf("%15s", ip_str);
    printf("Enter Subnet Mask (e.g., 255.255.255.0): ");
    scanf("%15s", mask_str);
    
    if (str_to_bin(ip_str, &ip) != 1) {
        printf("Invalid IP address format.\n");
        return EXIT_FAILURE;
    }

    if (str_to_bin(mask_str, &mask) != 1) {
        printf("Invalid subnet mask format.\n");
        return EXIT_FAILURE;
    }
    
    print_subnet_info(ip, mask);
    
    return EXIT_SUCCESS;
}