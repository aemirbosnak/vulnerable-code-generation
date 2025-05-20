//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void calculate_subnet(const char *ip, const char *mask) {
    struct in_addr ip_addr, mask_addr, network_addr, broadcast_addr;

    // Convert strings to in_addr
    if (inet_aton(ip, &ip_addr) == 0 || inet_aton(mask, &mask_addr) == 0) {
        fprintf(stderr, "Invalid IP address or subnet mask.\n");
        return;
    }

    // Calculate the network address
    network_addr.s_addr = ip_addr.s_addr & mask_addr.s_addr;

    // Calculate the broadcast address
    broadcast_addr.s_addr = network_addr.s_addr | ~mask_addr.s_addr;

    // Display the results
    char network_str[INET_ADDRSTRLEN];
    char broadcast_str[INET_ADDRSTRLEN];
    
    inet_ntop(AF_INET, &network_addr, network_str, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &broadcast_addr, broadcast_str, INET_ADDRSTRLEN);

    printf("IP Address:         %s\n", ip);
    printf("Subnet Mask:        %s\n", mask);
    printf("Network Address:    %s\n", network_str);
    printf("Broadcast Address:  %s\n", broadcast_str);

    // Calculate valid host range
    struct in_addr valid_start, valid_end;
    valid_start.s_addr = network_addr.s_addr + 1; // First valid host
    valid_end.s_addr = broadcast_addr.s_addr - 1; // Last valid host

    char valid_start_str[INET_ADDRSTRLEN];
    char valid_end_str[INET_ADDRSTRLEN];
    
    inet_ntop(AF_INET, &valid_start, valid_start_str, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &valid_end, valid_end_str, INET_ADDRSTRLEN);

    printf("Valid Host Range:   %s - %s\n", valid_start_str, valid_end_str);
}

int main() {
    char ip[INET_ADDRSTRLEN];
    char mask[INET_ADDRSTRLEN];

    // Input from user
    printf("Enter IP Address (xxx.xxx.xxx.xxx): ");
    scanf("%s", ip);
    printf("Enter Subnet Mask (xxx.xxx.xxx.xxx): ");
    scanf("%s", mask);

    // Calculate and display subnet details
    calculate_subnet(ip, mask);
    
    return 0;
}