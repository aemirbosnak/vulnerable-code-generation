//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to hold subnet information
typedef struct subnet {
    unsigned int address;
    unsigned int subnet_mask;
    unsigned int broadcast_address;
    unsigned int network_address;
    unsigned int host_range;
} subnet_t;

// Function to calculate subnet information
subnet_t calculate_subnet(unsigned int address, unsigned int subnet_mask) {
    subnet_t subnet;
    subnet.address = address;
    subnet.subnet_mask = subnet_mask;
    subnet.network_address = address & subnet_mask;
    subnet.broadcast_address = subnet.network_address | ~subnet_mask;
    subnet.host_range = pow(2, 32 - count_bits(subnet_mask)) - 2;
    return subnet;
}

// Function to count the number of bits set in a mask
int count_bits(unsigned int mask) {
    int count = 0;
    while (mask) {
        count += mask & 1;
        mask >>= 1;
    }
    return count;
}

// Function to print subnet information
void print_subnet(subnet_t subnet) {
    printf("Address: %u.%u.%u.%u\n", subnet.address & 0xFF, (subnet.address >> 8) & 0xFF, (subnet.address >> 16) & 0xFF, (subnet.address >> 24) & 0xFF);
    printf("Subnet Mask: %u.%u.%u.%u\n", subnet.subnet_mask & 0xFF, (subnet.subnet_mask >> 8) & 0xFF, (subnet.subnet_mask >> 16) & 0xFF, (subnet.subnet_mask >> 24) & 0xFF);
    printf("Network Address: %u.%u.%u.%u\n", subnet.network_address & 0xFF, (subnet.network_address >> 8) & 0xFF, (subnet.network_address >> 16) & 0xFF, (subnet.network_address >> 24) & 0xFF);
    printf("Broadcast Address: %u.%u.%u.%u\n", subnet.broadcast_address & 0xFF, (subnet.broadcast_address >> 8) & 0xFF, (subnet.broadcast_address >> 16) & 0xFF, (subnet.broadcast_address >> 24) & 0xFF);
    printf("Host Range: %u\n", subnet.host_range);
}

// Function to get subnet information from user
subnet_t get_subnet_info(void) {
    subnet_t subnet;
    char ip_address[16];
    char subnet_mask[16];
    printf("Enter IP address: ");
    scanf("%s", ip_address);
    printf("Enter subnet mask: ");
    scanf("%s", subnet_mask);
    subnet.address = inet_addr(ip_address);
    subnet.subnet_mask = inet_addr(subnet_mask);
    return subnet;
}

// Main function
int main(void) {
    subnet_t subnet = get_subnet_info();
    subnet = calculate_subnet(subnet.address, subnet.subnet_mask);
    print_subnet(subnet);
    return 0;
}