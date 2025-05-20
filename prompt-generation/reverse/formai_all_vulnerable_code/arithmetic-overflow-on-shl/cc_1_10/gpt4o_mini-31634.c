//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void calculate_subnet(const char *ip_str, const char *mask_str, int depth);
void print_subnet_details(struct in_addr ip, struct in_addr mask, int depth);
void convert_to_binary(const char *ip_str, const char *mask_str, char *binary_ip, char *binary_mask);

int main() {
    char ip[16], mask[16];
    int depth = 0;

    printf("Enter IP address (x.x.x.x): ");
    scanf("%15s", ip);
    printf("Enter Subnet mask (x.x.x.x): ");
    scanf("%15s", mask);

    // Validate IP address and subnet mask
    struct in_addr ip_addr, mask_addr;
    if (inet_pton(AF_INET, ip, &ip_addr) <= 0 || inet_pton(AF_INET, mask, &mask_addr) <= 0) {
        printf("Invalid IP address or subnet mask format.\n");
        return 1;
    }

    calculate_subnet(ip, mask, depth);
    
    return 0;
}

void calculate_subnet(const char *ip_str, const char *mask_str, int depth) {
    struct in_addr ip_addr, mask_addr, network_addr;

    inet_pton(AF_INET, ip_str, &ip_addr);
    inet_pton(AF_INET, mask_str, &mask_addr);
    
    network_addr.s_addr = ip_addr.s_addr & mask_addr.s_addr;

    print_subnet_details(ip_addr, mask_addr, depth);
    
    char binary_ip[35] = {0}, binary_mask[35] = {0};
    convert_to_binary(ip_str, mask_str, binary_ip, binary_mask);
    
    printf("Binary IP: %s\nBinary Mask: %s\n", binary_ip, binary_mask);
    printf("Depth: %d\n", depth);

    // Recursive call - Limit depth to prevent infinite recursion
    if (depth < 5) {
        char new_ip[16], new_mask[16];
        sprintf(new_ip, "%d.%d.%d.%d", 
                (network_addr.s_addr >> 24) & 0xFF,
                (network_addr.s_addr >> 16) & 0xFF,
                (network_addr.s_addr >> 8) & 0xFF,
                network_addr.s_addr & 0xFF);
        
        sprintf(new_mask, "%d.%d.%d.%d", 
                (mask_addr.s_addr >> 24) & 0xFF,
                (mask_addr.s_addr >> 16) & 0xFF,
                (mask_addr.s_addr >> 8) & 0xFF,
                mask_addr.s_addr & 0xFF);
        
        printf("Next iteration with subnet: {%s, %s}\n", new_ip, new_mask);
        calculate_subnet(new_ip, new_mask, depth + 1);
    }
}

void print_subnet_details(struct in_addr ip, struct in_addr mask, int depth) {
    printf("\nSubnet Details (iteration depth: %d):\n", depth);
    printf("IP Address: %s\n", inet_ntoa(ip));
    printf("Subnet Mask: %s\n", inet_ntoa(mask));
    printf("Network Address: %s\n", inet_ntoa((struct in_addr){ip.s_addr & mask.s_addr}));
    printf("Broadcast Address: %s\n", inet_ntoa((struct in_addr){(ip.s_addr & mask.s_addr) | ~mask.s_addr}));
}

void convert_to_binary(const char *ip_str, const char *mask_str, char *binary_ip, char *binary_mask) {
    struct in_addr ip_addr, mask_addr;
    inet_pton(AF_INET, ip_str, &ip_addr);
    inet_pton(AF_INET, mask_str, &mask_addr);

    for (int i = 31; i >= 0; i--) {
        binary_ip[31 - i] = (ip_addr.s_addr & (1 << i)) ? '1' : '0';
        binary_mask[31 - i] = (mask_addr.s_addr & (1 << i)) ? '1' : '0';
    }
    binary_ip[32] = '\0';
    binary_mask[32] = '\0';
}