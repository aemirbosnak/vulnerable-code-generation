//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define the IPv4 address structure
typedef struct {
    uint8_t octet1;
    uint8_t octet2;
    uint8_t octet3;
    uint8_t octet4;
} IPv4Address;

// Define the subnet mask structure
typedef struct {
    uint8_t mask1;
    uint8_t mask2;
    uint8_t mask3;
    uint8_t mask4;
} SubnetMask;

// Define the subnet calculator function
void subnet_calculator(IPv4Address ip_address, SubnetMask subnet_mask) {
    // Calculate the network address
    IPv4Address network_address;
    network_address.octet1 = ip_address.octet1 & subnet_mask.mask1;
    network_address.octet2 = ip_address.octet2 & subnet_mask.mask2;
    network_address.octet3 = ip_address.octet3 & subnet_mask.mask3;
    network_address.octet4 = ip_address.octet4 & subnet_mask.mask4;

    // Calculate the broadcast address
    IPv4Address broadcast_address;
    broadcast_address.octet1 = ip_address.octet1 | ~subnet_mask.mask1;
    broadcast_address.octet2 = ip_address.octet2 | ~subnet_mask.mask2;
    broadcast_address.octet3 = ip_address.octet3 | ~subnet_mask.mask3;
    broadcast_address.octet4 = ip_address.octet4 | ~subnet_mask.mask4;

    // Calculate the number of hosts per subnet
    uint32_t num_hosts = 0;
    for (int i = 0; i < 32; i++) {
        if ((subnet_mask.mask1 >> i) & 0x1) {
            num_hosts += 1;
        }
        if ((subnet_mask.mask2 >> i) & 0x1) {
            num_hosts += 1;
        }
        if ((subnet_mask.mask3 >> i) & 0x1) {
            num_hosts += 1;
        }
        if ((subnet_mask.mask4 >> i) & 0x1) {
            num_hosts += 1;
        }
    }

    // Print the results
    printf("Network address: %d.%d.%d.%d\n", network_address.octet1, network_address.octet2, network_address.octet3, network_address.octet4);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast_address.octet1, broadcast_address.octet2, broadcast_address.octet3, broadcast_address.octet4);
    printf("Number of hosts per subnet: %d\n", num_hosts);
}

// Define the main function
int main() {
    // Get the IP address from the user
    char ip_address_str[16];
    printf("Enter the IP address: ");
    scanf("%s", ip_address_str);

    // Convert the IP address string to an IPv4 address structure
    IPv4Address ip_address;
    sscanf(ip_address_str, "%hhu.%hhu.%hhu.%hhu", &ip_address.octet1, &ip_address.octet2, &ip_address.octet3, &ip_address.octet4);

    // Get the subnet mask from the user
    char subnet_mask_str[16];
    printf("Enter the subnet mask: ");
    scanf("%s", subnet_mask_str);

    // Convert the subnet mask string to a SubnetMask structure
    SubnetMask subnet_mask;
    sscanf(subnet_mask_str, "%hhu.%hhu.%hhu.%hhu", &subnet_mask.mask1, &subnet_mask.mask2, &subnet_mask.mask3, &subnet_mask.mask4);

    // Calculate the subnet information
    subnet_calculator(ip_address, subnet_mask);

    return 0;
}