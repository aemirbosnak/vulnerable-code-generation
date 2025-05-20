//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_SUBNET_MASK 32
#define MAX_IP_ADDRESS_LENGTH 16

void print_usage(const char *program_name) {
    printf("Usage: %s <ip_address> <subnet_mask>\n", program_name);
    printf("Example: %s 192.168.1.0 24\n", program_name);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int subnet_mask = atoi(argv[2]);

    if (subnet_mask < 0 || subnet_mask > MAX_SUBNET_MASK) {
        printf("Invalid subnet mask.\n");
        return 1;
    }

    struct in_addr ip;
    if (inet_aton(ip_address, &ip) == 0) {
        printf("Invalid IP address.\n");
        return 1;
    }

    int ip_address_length = strlen(ip_address);
    if (ip_address_length > MAX_IP_ADDRESS_LENGTH) {
        printf("IP address too long.\n");
        return 1;
    }

    char subnet_mask_binary[MAX_SUBNET_MASK];
    for (int i = 0; i < MAX_SUBNET_MASK; i++) {
        if (i < subnet_mask) {
            subnet_mask_binary[i] = '1';
        } else {
            subnet_mask_binary[i] = '0';
        }
    }

    char ip_address_binary[MAX_IP_ADDRESS_LENGTH];
    for (int i = 0; i < MAX_IP_ADDRESS_LENGTH; i++) {
        if (i < ip_address_length) {
            ip_address_binary[i] = ip_address[i];
        } else {
            ip_address_binary[i] = '0';
        }
    }

    char subnet_address_binary[MAX_SUBNET_MASK];
    for (int i = 0; i < MAX_SUBNET_MASK; i++) {
        if (subnet_mask_binary[i] == '1') {
            subnet_address_binary[i] = ip_address_binary[i];
        } else {
            subnet_address_binary[i] = '0';
        }
    }

    char network_address_binary[MAX_SUBNET_MASK];
    for (int i = 0; i < MAX_SUBNET_MASK; i++) {
        if (subnet_mask_binary[i] == '1') {
            network_address_binary[i] = '0';
        } else {
            network_address_binary[i] = ip_address_binary[i];
        }
    }

    char broadcast_address_binary[MAX_SUBNET_MASK];
    for (int i = 0; i < MAX_SUBNET_MASK; i++) {
        if (subnet_mask_binary[i] == '1') {
            broadcast_address_binary[i] = '1';
        } else {
            broadcast_address_binary[i] = ip_address_binary[i];
        }
    }

    char network_address[MAX_IP_ADDRESS_LENGTH];
    for (int i = 0; i < MAX_IP_ADDRESS_LENGTH; i++) {
        network_address[i] = network_address_binary[i];
    }

    char broadcast_address[MAX_IP_ADDRESS_LENGTH];
    for (int i = 0; i < MAX_IP_ADDRESS_LENGTH; i++) {
        broadcast_address[i] = broadcast_address_binary[i];
    }

    printf("Subnet Mask: %s\n", subnet_mask_binary);
    printf("IP Address: %s\n", ip_address_binary);
    printf("Subnet Address: %s\n", subnet_address_binary);
    printf("Network Address: %s\n", network_address);
    printf("Broadcast Address: %s\n", broadcast_address);

    return 0;
}