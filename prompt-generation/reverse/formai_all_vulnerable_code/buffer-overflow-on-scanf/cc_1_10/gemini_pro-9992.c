//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct subnet {
    uint32_t ip_address;
    uint32_t subnet_mask;
    uint32_t broadcast_address;
    uint32_t first_usable_address;
    uint32_t last_usable_address;
    uint32_t number_of_hosts;
} subnet_t;

subnet_t calculate_subnet(uint32_t ip_address, uint8_t subnet_prefix_length) {
    subnet_t subnet;

    // Mask the IP address with the subnet mask
    subnet.ip_address = ip_address & ((1 << (32 - subnet_prefix_length)) - 1);

    // Set the subnet mask
    subnet.subnet_mask = (1 << (32 - subnet_prefix_length)) - 1;

    // Calculate the broadcast address
    subnet.broadcast_address = subnet.ip_address | ~subnet.subnet_mask;

    // Calculate the first usable address
    subnet.first_usable_address = subnet.ip_address + 1;

    // Calculate the last usable address
    subnet.last_usable_address = subnet.broadcast_address - 1;

    // Calculate the number of hosts
    subnet.number_of_hosts = (1 << (32 - subnet_prefix_length)) - 2;

    return subnet;
}

int main() {
    uint32_t ip_address;
    uint8_t subnet_prefix_length;

    // Get the IP address from the user
    printf("Enter the IP address: ");
    scanf("%u", &ip_address);

    // Get the subnet prefix length from the user
    printf("Enter the subnet prefix length: ");
    scanf("%hhu", &subnet_prefix_length);

    // Calculate the subnet
    subnet_t subnet = calculate_subnet(ip_address, subnet_prefix_length);

    // Print the subnet information
    printf("IP Address: %u\n", subnet.ip_address);
    printf("Subnet Mask: %u\n", subnet.subnet_mask);
    printf("Broadcast Address: %u\n", subnet.broadcast_address);
    printf("First Usable Address: %u\n", subnet.first_usable_address);
    printf("Last Usable Address: %u\n", subnet.last_usable_address);
    printf("Number of Hosts: %u\n", subnet.number_of_hosts);

    return 0;
}