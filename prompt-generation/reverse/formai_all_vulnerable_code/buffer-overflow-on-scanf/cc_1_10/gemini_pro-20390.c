//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to store subnet information
typedef struct subnet {
    unsigned int ip_address; // Network address of the subnet
    unsigned int subnet_mask; // Subnet mask of the subnet
    unsigned int broadcast_address; // Broadcast address of the subnet
    unsigned int number_of_hosts; // Number of hosts in the subnet
} subnet;

// Function to calculate the subnet information
subnet calculate_subnet(unsigned int ip_address, unsigned int subnet_mask) {
    subnet subnet;
    subnet.ip_address = ip_address;
    subnet.subnet_mask = subnet_mask;
    subnet.broadcast_address = ip_address | ~subnet_mask;
    subnet.number_of_hosts = pow(2, 32 - count_bits(subnet_mask)) - 2;
    return subnet;
}

// Function to count the number of bits set in a given number
int count_bits(unsigned int number) {
    int count = 0;
    while (number) {
        number &= number - 1;
        count++;
    }
    return count;
}

// Function to print the subnet information
void print_subnet_information(subnet subnet) {
    printf("Network address: %u.%u.%u.%u\n",
           (subnet.ip_address >> 24) & 0xFF,
           (subnet.ip_address >> 16) & 0xFF,
           (subnet.ip_address >> 8) & 0xFF,
           subnet.ip_address & 0xFF);

    printf("Subnet mask: %u.%u.%u.%u\n",
           (subnet.subnet_mask >> 24) & 0xFF,
           (subnet.subnet_mask >> 16) & 0xFF,
           (subnet.subnet_mask >> 8) & 0xFF,
           subnet.subnet_mask & 0xFF);

    printf("Broadcast address: %u.%u.%u.%u\n",
           (subnet.broadcast_address >> 24) & 0xFF,
           (subnet.broadcast_address >> 16) & 0xFF,
           (subnet.broadcast_address >> 8) & 0xFF,
           subnet.broadcast_address & 0xFF);

    printf("Number of hosts: %u\n", subnet.number_of_hosts);
}

// Main function
int main() {
    // Get the IP address and subnet mask from the user
    unsigned int ip_address, subnet_mask;
    printf("Enter the IP address: ");
    scanf("%u", &ip_address);
    printf("Enter the subnet mask: ");
    scanf("%u", &subnet_mask);

    // Calculate the subnet information
    subnet subnet = calculate_subnet(ip_address, subnet_mask);

    // Print the subnet information
    print_subnet_information(subnet);

    return 0;
}