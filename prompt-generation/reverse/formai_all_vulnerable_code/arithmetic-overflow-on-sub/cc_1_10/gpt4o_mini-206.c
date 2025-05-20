//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_BUFFER 256

typedef struct {
    char ip[16];
    int subnet_mask;
    char network[16];
    char broadcast[16];
    int hosts;
} SubnetInfo;

void calculate_subnet(SubnetInfo *info) {
    struct in_addr ip_addr;
    inet_pton(AF_INET, info->ip, &ip_addr);
    
    // Calculate the base network address and broadcast address
    unsigned int ip_num = ntohl(ip_addr.s_addr);
    unsigned int mask = ~((1 << (32 - info->subnet_mask)) - 1);
    
    unsigned int network_num = ip_num & mask;
    unsigned int broadcast_num = network_num | ~mask;
    
    inet_ntop(AF_INET, &network_num, info->network, sizeof(info->network));
    inet_ntop(AF_INET, &broadcast_num, info->broadcast, sizeof(info->broadcast));
    
    info->hosts = (1 << (32 - info->subnet_mask)) - 2; // -2 for network and broadcast addresses
}

void display_results(SubnetInfo *info) {
    printf("\n=== Futuristic Subnet Calculator ===\n");
    printf("IP Address: %s\n", info->ip);
    printf("Subnet Mask: /%d\n", info->subnet_mask);
    printf("Network Address: %s\n", info->network);
    printf("Broadcast Address: %s\n", info->broadcast);
    printf("Total Usable Hosts: %d\n", info->hosts);
}

int main() {
    SubnetInfo subnet;
    char input_buffer[MAX_BUFFER];
    
    printf("Welcome to the Futuristic Subnet Calculator 3000!\n");
    printf("Please enter an IP address (IPv4) and subnet mask (e.g., 192.168.1.1/24): ");
    
    fgets(input_buffer, sizeof(input_buffer), stdin);
    sscanf(input_buffer, "%15s/%d", subnet.ip, &subnet.subnet_mask);
    
    if (subnet.subnet_mask < 0 || subnet.subnet_mask > 32) {
        printf("Error: Subnet mask must be between 0 and 32.\n");
        return EXIT_FAILURE;
    }

    calculate_subnet(&subnet);
    
    display_results(&subnet);
    
    printf("Do you want to perform another calculation? (yes/no): ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    
    if (strncasecmp(input_buffer, "yes", 3) == 0) {
        main();
    } else {
        printf("Thank you for using the Futuristic Subnet Calculator 3000! Stay connected!\n");
    }

    return EXIT_SUCCESS;
}