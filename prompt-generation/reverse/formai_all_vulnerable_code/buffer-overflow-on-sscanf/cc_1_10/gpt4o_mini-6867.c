//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void calculate_subnet(char *cidr_notation);
void display_info(unsigned char subnet[4], unsigned char mask[4], unsigned char network[4], unsigned char broadcast[4], int total_hosts);
void split_cidr(char *cidr_notation, unsigned char ip[4], int *prefix_length);
unsigned char* decimal_to_binary(unsigned char octet);
unsigned char* calculate_broadcast_address(unsigned char network[4], unsigned char mask[4]);
unsigned char* calculate_network_address(unsigned char ip[4], unsigned char mask[4]);
int calculate_total_hosts(int prefix_length);

int main() {
    char cidr_notation[20];
    
    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter your CIDR notation (e.g., 192.168.1.0/24): ");
    
    while (1) {
        fgets(cidr_notation, sizeof(cidr_notation), stdin);
        cidr_notation[strcspn(cidr_notation, "\n")] = 0; // Remove newline character
        if (strstr(cidr_notation, "/") != NULL) {
            calculate_subnet(cidr_notation);
            break;
        } else {
            printf("Invalid input format. Please enter a valid CIDR notation (e.g., 192.168.1.0/24): ");
        }
    }

    return 0;
}

void calculate_subnet(char *cidr_notation) {
    unsigned char ip[4] = {0};
    int prefix_length = 0;
    
    split_cidr(cidr_notation, ip, &prefix_length);
    
    unsigned char mask[4] = {0};
    for (int i = 0; i < 4; i++) {
        if (prefix_length >= 8) {
            mask[i] = 255;
            prefix_length -= 8;
        } else {
            mask[i] = (unsigned char)(255 << (8 - prefix_length) & 255);
            prefix_length = 0;
        }
    }
    
    unsigned char network[4] = {0};
    unsigned char broadcast[4] = {0};
    
    memcpy(network, calculate_network_address(ip, mask), sizeof(network));
    memcpy(broadcast, calculate_broadcast_address(network, mask), sizeof(broadcast));

    int total_hosts = calculate_total_hosts(32 - __builtin_popcount(*(unsigned int*)mask));

    display_info(network, mask, network, broadcast, total_hosts);
}

void display_info(unsigned char subnet[4], unsigned char mask[4], unsigned char network[4], unsigned char broadcast[4], int total_hosts) {
    printf("\nSubnet Information:\n");
    printf("Network Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Subnet Mask: %d.%d.%d.%d (CIDR: /%d)\n", mask[0], mask[1], mask[2], mask[3], 32 - __builtin_popcount(*(unsigned int*)mask));
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Total Hosts: %d\n", total_hosts);
}

void split_cidr(char *cidr_notation, unsigned char ip[4], int *prefix_length) {
    char *token = strtok(cidr_notation, "/");
    if (token != NULL) {
        sscanf(token, "%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);
    }
    
    token = strtok(NULL, "/");
    if (token != NULL) {
        *prefix_length = atoi(token);
    }
}

unsigned char* decimal_to_binary(unsigned char octet) {
    static unsigned char binary[9];
    for (int i = 0; i < 8; i++) {
        binary[7 - i] = (octet & (1 << i)) ? '1' : '0';
    }
    binary[8] = '\0';
    return binary;
}

unsigned char* calculate_broadcast_address(unsigned char network[4], unsigned char mask[4]) {
    static unsigned char broadcast[4];
    for (int i = 0; i < 4; i++) {
        broadcast[i] = network[i] | (~mask[i] & 255);
    }
    return broadcast;
}

unsigned char* calculate_network_address(unsigned char ip[4], unsigned char mask[4]) {
    static unsigned char network[4];
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
    }
    return network;
}

int calculate_total_hosts(int prefix_length) {
    return (int)pow(2, prefix_length) - 2; // 2 for network and broadcast addresses
}