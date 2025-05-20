//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to calculate subnet mask
void calculateSubnetMask(int subnet_mask[], int prefix_length) {
    int index, subnet_octets[4] = {0, 0, 0, 0};
    
    for (index = 0; index < prefix_length; index++) {
        subnet_octets[index/8] |= (1 << (7 - index % 8));
    }
    
    for (index = 0; index < 4; index++) {
        subnet_mask[index] = subnet_octets[index];
    }
}

// Function to calculate subnet address
void calculateSubnetAddress(uint8_t ipv4_address[], int subnet_mask[], uint8_t subnet_address[]) {
    int index;
    
    for (index = 0; index < 4; index++) {
        subnet_address[index] = ipv4_address[index] & subnet_mask[index];
    }
}

int main() {
    // Declare input variables
    uint8_t ipv4_address[4];
    int prefix_length;
    
    // Prompt user for input
    printf("Enter IPv4 address in dotted decimal notation (e.g. 192.168.0.1): ");
    scanf("%u.%u.%u.%u", &ipv4_address[0], &ipv4_address[1], &ipv4_address[2], &ipv4_address[3]);
    printf("Enter prefix length (0-32): ");
    scanf("%d", &prefix_length);
    
    // Initialize output variables
    int subnet_mask[4];
    uint8_t subnet_address[4];
    
    // Calculate subnet mask and subnet address
    calculateSubnetMask(subnet_mask, prefix_length);
    calculateSubnetAddress(ipv4_address, subnet_mask, subnet_address);
    
    // Print results to user
    printf("Subnet mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
    printf("Subnet address: %u.%u.%u.%u\n", subnet_address[0], subnet_address[1], subnet_address[2], subnet_address[3]);
    
    return 0;
}