//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// function to calculate subnet mask and broadcast address
void calculate_subnet_and_broadcast_address(uint32_t ip_address, uint8_t subnet_mask, uint32_t *subnet_address, uint32_t *broadcast_address) {
    // calculate subnet mask as 32-bit unsigned int
    uint32_t subnet_mask_bitwise = (uint32_t)(pow(2, subnet_mask) - 1) << (32 - subnet_mask);
    
    // calculate subnet address by performing a bitwise AND with subnet mask
    *subnet_address = ip_address & subnet_mask_bitwise;
    
    // calculate the inverted subnet mask and perform a bitwise OR with subnet address to get broadcast address
    uint32_t inverted_subnet_mask_bitwise = ~subnet_mask_bitwise;
    *broadcast_address = *subnet_address | inverted_subnet_mask_bitwise;
}

int main() {
    // prompt user to enter IP address and subnet mask
    printf("Enter IP address in decimal format (example: 192.168.0.1): ");
    char ip_address_input[16];
    scanf("%s", ip_address_input);
    printf("Enter subnet mask in CIDR notation (example: 24): ");
    uint8_t subnet_mask;
    scanf("%hhu", &subnet_mask);
    
    // convert IP address from decimal string to 32-bit unsigned int
    char *ip_address_string = ip_address_input;
    uint8_t ip_address_parts[4];
    int j = 0;
    for (int i = 0; ip_address_string[i] != '\0'; i++) {
        if (ip_address_string[i] == '.') {
            ip_address_parts[j] = atoi(ip_address_string);
            ip_address_string += (i - j) + 1;
            j = i + 1;
        }
    }
    ip_address_parts[j] = atoi(ip_address_string);
    uint32_t ip_address = (ip_address_parts[0] << 24) | (ip_address_parts[1] << 16) | (ip_address_parts[2] << 8) | ip_address_parts[3];
    
    // calculate subnet and broadcast addresses
    uint32_t subnet_address, broadcast_address;
    calculate_subnet_and_broadcast_address(ip_address, subnet_mask, &subnet_address, &broadcast_address);
    
    // convert subnet and broadcast addresses to decimal dotted format and print to console
    uint8_t subnet_address_parts[4], broadcast_address_parts[4];
    subnet_address_parts[0] = (subnet_address >> 24) & 0xFF;
    subnet_address_parts[1] = (subnet_address >> 16) & 0xFF;
    subnet_address_parts[2] = (subnet_address >> 8) & 0xFF;
    subnet_address_parts[3] = subnet_address & 0xFF;
    broadcast_address_parts[0] = (broadcast_address >> 24) & 0xFF;
    broadcast_address_parts[1] = (broadcast_address >> 16) & 0xFF;
    broadcast_address_parts[2] = (broadcast_address >> 8) & 0xFF;
    broadcast_address_parts[3] = broadcast_address & 0xFF;
    printf("Subnet Address: %u.%u.%u.%u\n", subnet_address_parts[0], subnet_address_parts[1], subnet_address_parts[2], subnet_address_parts[3]);
    printf("Broadcast Address: %u.%u.%u.%u\n", broadcast_address_parts[0], broadcast_address_parts[1], broadcast_address_parts[2], broadcast_address_parts[3]);
    
    return 0;
}