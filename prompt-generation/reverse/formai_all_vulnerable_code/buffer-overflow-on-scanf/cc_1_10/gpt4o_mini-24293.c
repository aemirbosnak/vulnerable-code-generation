//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 16
#define MAX_MASK_LENGTH 3

// Function to convert string IP to a numerical format
unsigned int ip_to_int(const char *ip) {
    struct sockaddr_in sa;
    inet_pton(AF_INET, ip, &(sa.sin_addr));
    return ntohl(sa.sin_addr.s_addr);
}

// Function to convert numerical format back to string IP
void int_to_ip(unsigned int ip, char *output) {
    struct in_addr ip_addr;
    ip_addr.s_addr = htonl(ip);
    inet_ntop(AF_INET, &ip_addr, output, MAX_IP_LENGTH);
}

// Function to calculate subnet information
void calculate_subnet(const char *ip, int mask) {
    unsigned int ip_num = ip_to_int(ip);
    unsigned int mask_num = (mask == 32) ? 0xFFFFFFFF : ~((1 << (32 - mask)) - 1);
    unsigned int network_address = ip_num & mask_num;
    unsigned int broadcast_address = network_address | ~mask_num;
    unsigned int usable_hosts = (mask == 32) ? 0 : (1 << (32 - mask)) - 2;

    char network_ip[MAX_IP_LENGTH];
    char broadcast_ip[MAX_IP_LENGTH];

    int_to_ip(network_address, network_ip);
    int_to_ip(broadcast_address, broadcast_ip);

    printf("\nSubnet Information:\n");
    printf("---------------------\n");
    printf("IP Address:        %s\n", ip);
    printf("Subnet Mask:      %d\n", mask);
    printf("Network Address:  %s\n", network_ip);
    printf("Broadcast Address: %s\n", broadcast_ip);
    printf("Usable Hosts:     %u\n", usable_hosts);
}

int main() {
    char ip[MAX_IP_LENGTH];
    char mask_input[MAX_MASK_LENGTH];
    int mask;

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter an IP Address (in format xxx.xxx.xxx.xxx): ");
    scanf("%s", ip);
    printf("Please enter a subnet mask (1-32): ");
    scanf("%s", mask_input);
    
    // Validate the mask input
    mask = atoi(mask_input);
    if (mask < 1 || mask > 32) {
        fprintf(stderr, "Error: Subnet mask must be between 1 and 32.\n");
        return EXIT_FAILURE;
    }

    // Validate IP address
    struct sockaddr_in sa;
    if (inet_pton(AF_INET, ip, &(sa.sin_addr)) == 0) {
        fprintf(stderr, "Error: Invalid IP Address format.\n");
        return EXIT_FAILURE;
    }

    // Calculate and display subnet information
    calculate_subnet(ip, mask);
    
    return EXIT_SUCCESS;
}