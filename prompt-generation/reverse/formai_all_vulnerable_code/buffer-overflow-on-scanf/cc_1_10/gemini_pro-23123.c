//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to hold the subnet information
typedef struct subnet {
    unsigned int ip_address;
    unsigned int subnet_mask;
    unsigned int network_address;
    unsigned int broadcast_address;
    unsigned int first_usable_address;
    unsigned int last_usable_address;
    unsigned int total_usable_addresses;
} subnet_t;

// Function to check if the given IP address is valid
int is_valid_ip_address(unsigned int ip_address) {
    // Check if the IP address is in the range of valid IP addresses
    if (ip_address < 0 || ip_address > 4294967295) {
        return 0;
    }

    // Check if each octet of the IP address is in the range of 0 to 255
    unsigned int octets[4];
    for (int i = 0; i < 4; i++) {
        octets[i] = (ip_address >> (8 * i)) & 0xFF;
        if (octets[i] < 0 || octets[i] > 255) {
            return 0;
        }
    }

    // The IP address is valid
    return 1;
}

// Function to check if the given subnet mask is valid
int is_valid_subnet_mask(unsigned int subnet_mask) {
    // Check if the subnet mask is in the range of valid subnet masks
    if (subnet_mask < 0 || subnet_mask > 4294967295) {
        return 0;
    }

    // Check if the subnet mask is a valid binary number
    unsigned int bit_count = 0;
    for (int i = 0; i < 32; i++) {
        if ((subnet_mask >> i) & 1) {
            bit_count++;
        }
    }
    if (bit_count == 0 || bit_count > 32) {
        return 0;
    }

    // The subnet mask is valid
    return 1;
}

// Function to calculate the network address of the given subnet
unsigned int calculate_network_address(unsigned int ip_address, unsigned int subnet_mask) {
    return ip_address & subnet_mask;
}

// Function to calculate the broadcast address of the given subnet
unsigned int calculate_broadcast_address(unsigned int network_address, unsigned int subnet_mask) {
    return network_address | (~subnet_mask);
}

// Function to calculate the first usable address of the given subnet
unsigned int calculate_first_usable_address(unsigned int network_address) {
    return network_address + 1;
}

// Function to calculate the last usable address of the given subnet
unsigned int calculate_last_usable_address(unsigned int broadcast_address) {
    return broadcast_address - 1;
}

// Function to calculate the total number of usable addresses in the given subnet
unsigned int calculate_total_usable_addresses(unsigned int subnet_mask) {
    // Calculate the number of bits in the subnet mask
    unsigned int bit_count = 0;
    for (int i = 0; i < 32; i++) {
        if ((subnet_mask >> i) & 1) {
            bit_count++;
        }
    }

    // Calculate the total number of usable addresses
    unsigned int total_usable_addresses = pow(2, (32 - bit_count)) - 2;

    return total_usable_addresses;
}

// Function to print the subnet information
void print_subnet_information(subnet_t subnet) {
    printf("IP Address: %u\n", subnet.ip_address);
    printf("Subnet Mask: %u\n", subnet.subnet_mask);
    printf("Network Address: %u\n", subnet.network_address);
    printf("Broadcast Address: %u\n", subnet.broadcast_address);
    printf("First Usable Address: %u\n", subnet.first_usable_address);
    printf("Last Usable Address: %u\n", subnet.last_usable_address);
    printf("Total Usable Addresses: %u\n", subnet.total_usable_addresses);
}

int main() {
    // Get the IP address from the user
    printf("Enter the IP address: ");
    unsigned int ip_address;
    scanf("%u", &ip_address);

    // Get the subnet mask from the user
    printf("Enter the subnet mask: ");
    unsigned int subnet_mask;
    scanf("%u", &subnet_mask);

    // Check if the IP address and subnet mask are valid
    if (!is_valid_ip_address(ip_address)) {
        printf("Invalid IP address\n");
        return 1;
    }
    if (!is_valid_subnet_mask(subnet_mask)) {
        printf("Invalid subnet mask\n");
        return 1;
    }

    // Calculate the subnet information
    subnet_t subnet;
    subnet.ip_address = ip_address;
    subnet.subnet_mask = subnet_mask;
    subnet.network_address = calculate_network_address(ip_address, subnet_mask);
    subnet.broadcast_address = calculate_broadcast_address(subnet.network_address, subnet_mask);
    subnet.first_usable_address = calculate_first_usable_address(subnet.network_address);
    subnet.last_usable_address = calculate_last_usable_address(subnet.broadcast_address);
    subnet.total_usable_addresses = calculate_total_usable_addresses(subnet_mask);

    // Print the subnet information
    print_subnet_information(subnet);

    return 0;
}