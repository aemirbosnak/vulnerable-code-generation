//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LENGTH 16
#define MAX_SUBNET_MASK_LENGTH 3

void parse_ip(const char *ip_str, unsigned char *ip) {
    sscanf(ip_str, "%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);
}

void parse_subnet_mask(const char *subnet_str, unsigned char *subnet_mask) {
    int mask_length = atoi(subnet_str);
    for (int i = 0; i < 4; i++) {
        if (mask_length >= 8) {
            subnet_mask[i] = 255;
            mask_length -= 8;
        } else {
            subnet_mask[i] = (unsigned char)(255 << (8 - mask_length)) & 255;
            mask_length = 0;
        }
    }
}

void calculate_subnet(const unsigned char *ip, const unsigned char *subnet_mask, unsigned char *network_address, unsigned char *broadcast_address, int *number_of_hosts) {
    for (int i = 0; i < 4; i++) {
        network_address[i] = ip[i] & subnet_mask[i];
        broadcast_address[i] = network_address[i] | (~subnet_mask[i] & 255);
    }
    
    int host_bits = 0;
    for (int i = 0; i < 4; i++) {
        host_bits += (subnet_mask[i] ^ 255);
    }
    
    *number_of_hosts = (int)pow(2, (host_bits * 8)) - 2; // Exclude network and broadcast addresses
}

void display_results(const unsigned char *ip, const unsigned char *subnet_mask, const unsigned char *network_address, const unsigned char *broadcast_address, int number_of_hosts) {
    printf("IP Address: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
    printf("Network Address: %d.%d.%d.%d\n", network_address[0], network_address[1], network_address[2], network_address[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
    printf("Number of Usable Hosts: %d\n", number_of_hosts);
}

int main() {
    char ip_str[MAX_IP_LENGTH];
    char subnet_str[MAX_SUBNET_MASK_LENGTH];
    unsigned char ip[4] = {0}, subnet_mask[4] = {0};
    unsigned char network_address[4] = {0}, broadcast_address[4] = {0};
    int number_of_hosts = 0;

    printf("Welcome to the Advanced C Subnet Calculator!\n");
    printf("Please enter the IP address (format: x.x.x.x): ");
    fgets(ip_str, MAX_IP_LENGTH, stdin);
    ip_str[strcspn(ip_str, "\n")] = 0; // Remove trailing newline

    printf("Please enter the subnet mask length (e.g., 24): ");
    fgets(subnet_str, MAX_SUBNET_MASK_LENGTH, stdin);
    subnet_str[strcspn(subnet_str, "\n")] = 0; // Remove trailing newline

    parse_ip(ip_str, ip);
    parse_subnet_mask(subnet_str, subnet_mask);
    calculate_subnet(ip, subnet_mask, network_address, broadcast_address, &number_of_hosts);
    display_results(ip, subnet_mask, network_address, broadcast_address, number_of_hosts);

    return 0;
}