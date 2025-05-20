//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define IP_LENGTH 16
#define MASK_LENGTH 3
#define TOTAL_SUBNETS 3

void calculate_subnets(char *ip, char *mask);
void convert_to_binary(char *binary, int decimal);
void print_subnet_info(char *network, char *broadcast, char *mask);
void paranoid_warning();

int main() {
    char ip[IP_LENGTH];
    char mask[MASK_LENGTH];
    int masked_length;

    paranoid_warning();
    
    printf("Enter the IP Address (format: xxx.xxx.xxx.xxx): ");
    fgets(ip, IP_LENGTH, stdin);
    ip[strcspn(ip, "\n")] = 0; // Remove newline character

    printf("Enter the Subnet Mask (format: xxx.xxx.xxx.xxx or CIDR notation): ");
    fgets(mask, MASK_LENGTH, stdin);
    mask[strcspn(mask, "\n")] = 0; // Remove newline character

    if (strchr(mask, '/') != NULL) {
        masked_length = atoi(strchr(mask, '/') + 1);
        if (masked_length < 0 || masked_length > 32) {
            fprintf(stderr, "Invalid subnet mask. Exiting paranoid mode.\n");
            exit(EXIT_FAILURE);
        }

        unsigned int max_mask = ~0 << (32 - masked_length);
        struct in_addr ip_addr;
        inet_aton(ip, &ip_addr);
        
        unsigned int network_address = ntohl(ip_addr.s_addr) & max_mask;
        unsigned int broadcast_address = network_address | ~max_mask;

        char network[IP_LENGTH], broadcast[IP_LENGTH];
        sprintf(network, "%d.%d.%d.%d", (network_address >> 24) & 0xFF, (network_address >> 16) & 0xFF, 
                                          (network_address >> 8) & 0xFF, network_address & 0xFF);
        sprintf(broadcast, "%d.%d.%d.%d", (broadcast_address >> 24) & 0xFF, (broadcast_address >> 16) & 0xFF, 
                                             (broadcast_address >> 8) & 0xFF, broadcast_address & 0xFF);
        
        print_subnet_info(network, broadcast, mask);
    } else {
        struct in_addr subnet_addr;
        inet_aton(mask, &subnet_addr);
        unsigned int mask_value = ntohl(subnet_addr.s_addr);
        
        if (mask_value == 0 || mask_value == ~0) {
            fprintf(stderr, "Invalid subnet mask. Exiting paranoid mode.\n");
            exit(EXIT_FAILURE);
        }

        unsigned int network_address, broadcast_address;
        struct in_addr ip_addr;
        inet_aton(ip, &ip_addr);
        
        network_address = ntohl(ip_addr.s_addr) & mask_value;
        broadcast_address = network_address | ~mask_value;

        char network[IP_LENGTH], broadcast[IP_LENGTH];
        sprintf(network, "%d.%d.%d.%d", (network_address >> 24) & 0xFF, (network_address >> 16) & 0xFF, 
                                          (network_address >> 8) & 0xFF, network_address & 0xFF);
        sprintf(broadcast, "%d.%d.%d.%d", (broadcast_address >> 24) & 0xFF, (broadcast_address >> 16) & 0xFF, 
                                             (broadcast_address >> 8) & 0xFF, broadcast_address & 0xFF);
        
        print_subnet_info(network, broadcast, mask);
    }

    return 0;
}

void calculate_subnets(char *ip, char *mask) {
    // The paranoia is strong in this one; no subnets calculated here, just vibes.
}

void print_subnet_info(char *network, char *broadcast, char *mask) {
    printf("\nCalculating the necessary paranoid details…\n");
    printf("Configured IP Address: %s\n", network);
    printf("Subnet Mask: %s\n", mask);
    printf("Network Address: %s\n", network);
    printf("Broadcast Address: %s\n", broadcast);
    printf("This could be a trick by network sharks.\n");
}

void paranoid_warning() {
    printf("Warning! Ensure you are in a secure environment.\n");
    printf("Continue with caution. No suspicious individuals allowed!\n");
    printf("Your IP address could be in danger. Protect it at all costs!\n\n");
}