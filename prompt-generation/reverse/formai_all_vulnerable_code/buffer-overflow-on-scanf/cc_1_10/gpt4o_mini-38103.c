//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate subnet details
void calculate_subnet(const char *ip, const char *subnet_mask) {
    unsigned int ip_parts[4], mask_parts[4], network_parts[4], wildcard_parts[4];

    // Parse IP address
    sscanf(ip, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);
    
    // Parse subnet mask
    sscanf(subnet_mask, "%u.%u.%u.%u", &mask_parts[0], &mask_parts[1], &mask_parts[2], &mask_parts[3]);

    // Calculate Network Address
    for (int i = 0; i < 4; i++) {
        network_parts[i] = ip_parts[i] & mask_parts[i];
        wildcard_parts[i] = 255 - mask_parts[i];
    }

    printf("Given IP: %s\n", ip);
    printf("Given Subnet Mask: %s\n", subnet_mask);
    printf("Network Address: %u.%u.%u.%u\n", 
           network_parts[0], network_parts[1], network_parts[2], network_parts[3]);
    printf("Wildcard Mask: %u.%u.%u.%u\n", 
           wildcard_parts[0], wildcard_parts[1], wildcard_parts[2], wildcard_parts[3]);
}

// Function to calculate number of hosts
unsigned int calculate_hosts(const char *subnet_mask) {
    unsigned int mask_parts[4];
    sscanf(subnet_mask, "%u.%u.%u.%u", &mask_parts[0], &mask_parts[1], &mask_parts[2], &mask_parts[3]);
    
    unsigned int mask_in_binary = (mask_parts[0] << 24) | (mask_parts[1] << 16) | 
                                   (mask_parts[2] << 8) | mask_parts[3];
    unsigned int host_bits = ~mask_in_binary; // Invert mask to get host bits
    unsigned int host_count = (1 << (32 - __builtin_popcount(mask_in_binary))) - 2; // 2 for network and broadcast address
    
    return host_count;
}

// Main function
int main() {
    char ip[16];
    char subnet_mask[16];
    
    printf("Enter IP Address (e.g., 192.168.1.1): ");
    scanf("%s", ip);
    
    printf("Enter Subnet Mask (e.g., 255.255.255.0): ");
    scanf("%s", subnet_mask);
    
    calculate_subnet(ip, subnet_mask);
    
    unsigned int host_count = calculate_hosts(subnet_mask);
    printf("Total Number of Hosts: %u\n", host_count);
    
    return 0;
}