//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void print_binary(uint32_t num) {
    for (int i = 31; i >= 0; i--) {
        printf("%u", (num >> i) & 1);
        if (i % 8 == 0) {
            printf(" "); // Space every 8 bits for readability
        }
    }
    printf("\n");
}

void display_help() {
    printf("Welcome to the Grateful Subnet Calculator!\n");
    printf("This program helps you determine your subnet information.\n");
    printf("Please provide the IP address and subnet mask.\n");
}

uint32_t ip_to_long(const char *ip) {
    uint32_t result = 0;
    unsigned int octet[4];
    sscanf(ip, "%u.%u.%u.%u", &octet[0], &octet[1], &octet[2], &octet[3]);
    result |= (octet[0] << 24);
    result |= (octet[1] << 16);
    result |= (octet[2] << 8);
    result |= octet[3];
    return result;
}

void long_to_ip(uint32_t long_ip, char *ip) {
    sprintf(ip, "%u.%u.%u.%u",
            (long_ip >> 24) & 0xFF,
            (long_ip >> 16) & 0xFF,
            (long_ip >> 8) & 0xFF,
            long_ip & 0xFF);
}

int main() {
    display_help();

    char ip_input[16];
    char mask_input[16];
    
    printf("Please enter the IP address (e.g., 192.168.1.1): ");
    fgets(ip_input, sizeof(ip_input), stdin);
    ip_input[strcspn(ip_input, "\n")] = 0; // Remove newline

    printf("Please enter the subnet mask (e.g., 255.255.255.0): ");
    fgets(mask_input, sizeof(mask_input), stdin);
    mask_input[strcspn(mask_input, "\n")] = 0; // Remove newline

    uint32_t ip = ip_to_long(ip_input);
    uint32_t mask = ip_to_long(mask_input);
    uint32_t network_address = ip & mask;
    uint32_t broadcast_address = network_address | ~mask;
    uint32_t first_host = network_address + 1;
    uint32_t last_host = broadcast_address - 1;
    
    char network_ip[16];
    char broadcast_ip[16];
    char first_host_ip[16];
    char last_host_ip[16];

    long_to_ip(network_address, network_ip);
    long_to_ip(broadcast_address, broadcast_ip);
    long_to_ip(first_host, first_host_ip);
    long_to_ip(last_host, last_host_ip);

    printf("\n--- Subnet Information ---\n");
    printf("IP Address:       %s\n", ip_input);
    printf("Subnet Mask:      %s\n", mask_input);
    printf("Network Address:  %s\n", network_ip);
    printf("Broadcast Address: %s\n", broadcast_ip);
    printf("First Host:      %s\n", first_host_ip);
    printf("Last Host:       %s\n", last_host_ip);
    printf("-------------------------\n");

    printf("Thank you for using the Grateful Subnet Calculator! Have a lovely day!\n");

    return 0;
}