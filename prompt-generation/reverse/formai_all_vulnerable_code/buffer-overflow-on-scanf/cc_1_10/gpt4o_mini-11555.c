//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void calculate_subnet(char *ip, int subnet_mask) {
    struct in_addr ip_addr;
    struct in_addr net_addr;
    struct in_addr broadcast_addr;
    
    // Convert IP string to binary format
    if (inet_pton(AF_INET, ip, &ip_addr) <= 0) {
        printf("Invalid IP address format.\n");
        return;
    }

    // Calculate the network address
    long mask = (0xFFFFFFFF << (32 - subnet_mask)) & 0xFFFFFFFF;
    net_addr.s_addr = ip_addr.s_addr & mask;

    // Calculate the broadcast address
    broadcast_addr.s_addr = net_addr.s_addr | ~mask;

    // Calculate valid host range
    struct in_addr first_host;
    struct in_addr last_host;
    first_host.s_addr = net_addr.s_addr + 1;
    last_host.s_addr = broadcast_addr.s_addr - 1;

    // Display the results
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: /%d\n", subnet_mask);
    printf("Network Address: %s\n", inet_ntoa(net_addr));
    printf("Broadcast Address: %s\n", inet_ntoa(broadcast_addr));
    printf("First Valid Host: %s\n", inet_ntoa(first_host));
    printf("Last Valid Host: %s\n", inet_ntoa(last_host));
    printf("Total Valid Hosts: %ld\n", (1 << (32 - subnet_mask)) - 2);
}

int main() {
    char ip[16];
    int subnet_mask;

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Enter an IP address (e.g., 192.168.1.1): ");
    scanf("%s", ip);
    
    printf("Enter the subnet mask (e.g., 24): ");
    scanf("%d", &subnet_mask);
    
    if (subnet_mask < 0 || subnet_mask > 32) {
        printf("Invalid subnet mask. It must be between 0 and 32.\n");
        return 1;
    }
    
    calculate_subnet(ip, subnet_mask);
    
    return 0;
}