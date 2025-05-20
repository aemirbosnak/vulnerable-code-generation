//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to store the subnet information
typedef struct {
    unsigned int ip_address;
    unsigned int subnet_mask;
    unsigned int network_address;
    unsigned int broadcast_address;
    unsigned int number_of_hosts;
} SubnetInfo;

// Function to calculate the subnet information
SubnetInfo calculate_subnet(unsigned int ip_address, unsigned int subnet_mask) {
    SubnetInfo subnet_info;

    // Calculate the network address
    subnet_info.network_address = ip_address & subnet_mask;

    // Calculate the broadcast address
    subnet_info.broadcast_address = subnet_info.network_address | ~subnet_mask;

    // Calculate the number of hosts
    subnet_info.number_of_hosts = (unsigned int) pow(2, 32 - count_ones(subnet_mask)) - 2;

    return subnet_info;
}

// Function to count the number of ones in a binary number
int count_ones(unsigned int number) {
    int count = 0;
    while (number) {
        if (number & 1) {
            count++;
        }
        number >>= 1;
    }
    return count;
}

// Function to print the subnet information
void print_subnet_info(SubnetInfo subnet_info) {
    printf("IP Address: %d.%d.%d.%d\n",
        (subnet_info.ip_address >> 24) & 0xFF,
        (subnet_info.ip_address >> 16) & 0xFF,
        (subnet_info.ip_address >> 8) & 0xFF,
        subnet_info.ip_address & 0xFF);
    printf("Subnet Mask: %d.%d.%d.%d\n",
        (subnet_info.subnet_mask >> 24) & 0xFF,
        (subnet_info.subnet_mask >> 16) & 0xFF,
        (subnet_info.subnet_mask >> 8) & 0xFF,
        subnet_info.subnet_mask & 0xFF);
    printf("Network Address: %d.%d.%d.%d\n",
        (subnet_info.network_address >> 24) & 0xFF,
        (subnet_info.network_address >> 16) & 0xFF,
        (subnet_info.network_address >> 8) & 0xFF,
        subnet_info.network_address & 0xFF);
    printf("Broadcast Address: %d.%d.%d.%d\n",
        (subnet_info.broadcast_address >> 24) & 0xFF,
        (subnet_info.broadcast_address >> 16) & 0xFF,
        (subnet_info.broadcast_address >> 8) & 0xFF,
        subnet_info.broadcast_address & 0xFF);
    printf("Number of Hosts: %d\n", subnet_info.number_of_hosts);
}

// Main function
int main() {
    // Get the IP address and subnet mask from the user
    unsigned int ip_address;
    unsigned int subnet_mask;
    printf("Enter the IP address: ");
    scanf("%d", &ip_address);
    printf("Enter the subnet mask: ");
    scanf("%d", &subnet_mask);

    // Calculate the subnet information
    SubnetInfo subnet_info = calculate_subnet(ip_address, subnet_mask);

    // Print the subnet information
    print_subnet_info(subnet_info);

    return 0;
}