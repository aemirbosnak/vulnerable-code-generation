//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_SUBNET_LENGTH 24

struct subnet_info {
    char subnet_mask[MAX_SUBNET_LENGTH];
    char ip_address[MAX_LINE_LENGTH];
    char network_address[MAX_LINE_LENGTH];
    char broadcast_address[MAX_LINE_LENGTH];
    char first_usable_address[MAX_LINE_LENGTH];
    char last_usable_address[MAX_LINE_LENGTH];
    char network_prefix[MAX_LINE_LENGTH];
};

struct subnet_info calculate_subnet(char* ip_address, char* subnet_mask) {
    int ip_octet1, ip_octet2, ip_octet3, ip_octet4;
    int subnet_octet1, subnet_octet2, subnet_octet3, subnet_octet4;
    struct subnet_info subnet_info;

    ip_octet1 = atoi(ip_address + 0);
    ip_octet2 = atoi(ip_address + 1);
    ip_octet3 = atoi(ip_address + 2);
    ip_octet4 = atoi(ip_address + 3);

    subnet_octet1 = atoi(subnet_mask + 0);
    subnet_octet2 = atoi(subnet_mask + 1);
    subnet_octet3 = atoi(subnet_mask + 2);
    subnet_octet4 = atoi(subnet_mask + 3);

    // Calculate network address
    subnet_info.network_address[0] = (ip_octet1 & ~(subnet_octet1 - 1)) + (1 << 24);
    subnet_info.network_address[1] = (ip_octet2 & ~(subnet_octet2 - 1)) + (1 << 16);
    subnet_info.network_address[2] = (ip_octet3 & ~(subnet_octet3 - 1)) + (1 << 8);
    subnet_info.network_address[3] = ip_octet4;

    // Calculate broadcast address
    subnet_info.broadcast_address[0] = (ip_octet1 & ~(subnet_octet1 - 1)) + (subnet_octet1 - 1) + (1 << 24);
    subnet_info.broadcast_address[1] = (ip_octet2 & ~(subnet_octet2 - 1)) + (subnet_octet2 - 1) + (1 << 16);
    subnet_info.broadcast_address[2] = (ip_octet3 & ~(subnet_octet3 - 1)) + (subnet_octet3 - 1) + (1 << 8);
    subnet_info.broadcast_address[3] = ip_octet4;

    // Calculate first usable address
    subnet_info.first_usable_address[0] = (ip_octet1 & ~(subnet_octet1 - 1)) + (subnet_octet1 - 1) + (1 << 24);
    subnet_info.first_usable_address[1] = (ip_octet2 & ~(subnet_octet2 - 1)) + (subnet_octet2 - 1) + (1 << 16);
    subnet_info.first_usable_address[2] = (ip_octet3 & ~(subnet_octet3 - 1)) + (subnet_octet3 - 1) + (1 << 8);
    subnet_info.first_usable_address[3] = ip_octet4;

    // Calculate last usable address
    subnet_info.last_usable_address[0] = (ip_octet1 & ~(subnet_octet1 - 1)) + (subnet_octet1 - 1) + (1 << 24);
    subnet_info.last_usable_address[1] = (ip_octet2 & ~(subnet_octet2 - 1)) + (subnet_octet2 - 1) + (1 << 16);
    subnet_info.last_usable_address[2] = (ip_octet3 & ~(subnet_octet3 - 1)) + (subnet_octet3 - 1) + (1 << 8);
    subnet_info.last_usable_address[3] = ip_octet4;

    // Calculate network prefix
    subnet_info.network_prefix[0] = (ip_octet1 & ~(subnet_octet1 - 1)) + (1 << 24);
    subnet_info.network_prefix[1] = (ip_octet2 & ~(subnet_octet2 - 1)) + (1 << 16);
    subnet_info.network_prefix[2] = (ip_octet3 & ~(subnet_octet3 - 1)) + (1 << 8);
    subnet_info.network_prefix[3] = ip_octet4;

    return subnet_info;
}

int main() {
    char ip_address[MAX_LINE_LENGTH];
    char subnet_mask[MAX_SUBNET_LENGTH];
    char network_address[MAX_LINE_LENGTH];
    char broadcast_address[MAX_LINE_LENGTH];
    char first_usable_address[MAX_LINE_LENGTH];
    char last_usable_address[MAX_LINE_LENGTH];
    char network_prefix[MAX_LINE_LENGTH];

    printf("Enter the IP address: ");
    scanf("%s", ip_address);
    printf("Enter the subnet mask: ");
    scanf("%s", subnet_mask);

    struct subnet_info subnet_info = calculate_subnet(ip_address, subnet_mask);

    printf("Network Address: %s\n", subnet_info.network_address);
    printf("Broadcast Address: %s\n", subnet_info.broadcast_address);
    printf("First Usable Address: %s\n", subnet_info.first_usable_address);
    printf("Last Usable Address: %s\n", subnet_info.last_usable_address);
    printf("Network Prefix: %s\n", subnet_info.network_prefix);

    return 0;
}