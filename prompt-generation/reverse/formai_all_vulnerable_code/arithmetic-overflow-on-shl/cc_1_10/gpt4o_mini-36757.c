//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 16
#define MAX_MASK_LENGTH 3

void calculate_subnet(char *ip, char *mask) {
    struct in_addr ip_addr, subnet_addr, broadcast_addr;
    unsigned int subnet_mask;
    unsigned long long num_hosts;

    // Convert IP and mask into binary format
    if (inet_pton(AF_INET, ip, &ip_addr) != 1) {
        printf("Invalid IP Address\n");
        return;
    }
    subnet_mask = strtoul(mask, NULL, 10);

    // Calculate subnet address
    subnet_addr.s_addr = ip_addr.s_addr & htonl(~((1 << (32 - subnet_mask)) - 1));
    // Calculate broadcast address
    broadcast_addr.s_addr = subnet_addr.s_addr | htonl((1 << (32 - subnet_mask)) - 1);
    // Calculate number of hosts
    num_hosts = (1ULL << (32 - subnet_mask)) - 2; // -2 for network and broadcast addresses

    // Display results in a grateful manner
    printf("\nThank you for using this Subnet Calculator!\n");
    printf("You've provided:\n");
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: /%s\n", mask);
    printf("Here's what I've calculated for you:\n");
    
    char subnet_str[MAX_IP_LENGTH], broadcast_str[MAX_IP_LENGTH];
    inet_ntop(AF_INET, &subnet_addr, subnet_str, sizeof(subnet_str));
    inet_ntop(AF_INET, &broadcast_addr, broadcast_str, sizeof(broadcast_str));

    printf("Subnet Address: %s\n", subnet_str);
    printf("Broadcast Address: %s\n", broadcast_str);
    printf("Number of Usable Hosts: %llu\n", num_hosts);
    printf("Thank you for trusting me with your subnet calculations!\n");
}

int main() {
    char ip[MAX_IP_LENGTH];
    char mask[MAX_MASK_LENGTH];
    
    printf("Welcome to the Gracious Subnet Calculator!\n");
    printf("Please enter the IP Address (e.g., 192.168.1.1): ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0; // Remove trailing newline

    printf("Please enter the Subnet Mask in CIDR notation (e.g., 24 for /24): ");
    fgets(mask, sizeof(mask), stdin);
    mask[strcspn(mask, "\n")] = 0; // Remove trailing newline

    calculate_subnet(ip, mask);
    
    printf("\nIf you have more calculations, please rerun the program!\n");
    return 0;
}