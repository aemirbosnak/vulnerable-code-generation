//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of bits in an IPv4 address
#define MAX_BITS 32

// Define the structure of an IPv4 address
typedef struct {
    unsigned char octet1;
    unsigned char octet2;
    unsigned char octet3;
    unsigned char octet4;
} IPv4Address;

// Define the structure of a subnet mask
typedef struct {
    unsigned char octet1;
    unsigned char octet2;
    unsigned char octet3;
    unsigned char octet4;
} SubnetMask;

// Define the structure of a subnet
typedef struct {
    IPv4Address network_address;
    IPv4Address broadcast_address;
    unsigned int num_hosts;
} Subnet;

// Function to convert an IPv4 address from a string to a struct
IPv4Address string_to_ipv4(char *address) {
    IPv4Address ipv4;
    sscanf(address, "%hhu.%hhu.%hhu.%hhu", &ipv4.octet1, &ipv4.octet2, &ipv4.octet3, &ipv4.octet4);
    return ipv4;
}

// Function to convert a subnet mask from a string to a struct
SubnetMask string_to_subnet_mask(char *mask) {
    SubnetMask subnet_mask;
    sscanf(mask, "%hhu.%hhu.%hhu.%hhu", &subnet_mask.octet1, &subnet_mask.octet2, &subnet_mask.octet3, &subnet_mask.octet4);
    return subnet_mask;
}

// Function to calculate the network address of a subnet
IPv4Address calculate_network_address(IPv4Address ip_address, SubnetMask subnet_mask) {
    IPv4Address network_address;
    network_address.octet1 = ip_address.octet1 & subnet_mask.octet1;
    network_address.octet2 = ip_address.octet2 & subnet_mask.octet2;
    network_address.octet3 = ip_address.octet3 & subnet_mask.octet3;
    network_address.octet4 = ip_address.octet4 & subnet_mask.octet4;
    return network_address;
}

// Function to calculate the broadcast address of a subnet
IPv4Address calculate_broadcast_address(IPv4Address network_address, SubnetMask subnet_mask) {
    IPv4Address broadcast_address;
    broadcast_address.octet1 = network_address.octet1 | ~subnet_mask.octet1;
    broadcast_address.octet2 = network_address.octet2 | ~subnet_mask.octet2;
    broadcast_address.octet3 = network_address.octet3 | ~subnet_mask.octet3;
    broadcast_address.octet4 = network_address.octet4 | ~subnet_mask.octet4;
    return broadcast_address;
}

// Function to calculate the number of hosts in a subnet
unsigned int calculate_num_hosts(SubnetMask subnet_mask) {
    unsigned int num_hosts = 0;
    for (int i = 0; i < MAX_BITS; i++) {
        if ((subnet_mask.octet1 >> i) & 1) {
            num_hosts += (unsigned int) pow(2, 32 - i - 1);
        }
    }
    return num_hosts - 2; // Subtract 2 for the network and broadcast addresses
}

// Function to print the details of a subnet
void print_subnet(Subnet subnet) {
    printf("Network Address: %hhu.%hhu.%hhu.%hhu\n", subnet.network_address.octet1, subnet.network_address.octet2, subnet.network_address.octet3, subnet.network_address.octet4);
    printf("Broadcast Address: %hhu.%hhu.%hhu.%hhu\n", subnet.broadcast_address.octet1, subnet.broadcast_address.octet2, subnet.broadcast_address.octet3, subnet.broadcast_address.octet4);
    printf("Number of Hosts: %u\n", subnet.num_hosts);
}

// Main function
int main() {
    // Get the IP address and subnet mask from the user
    char ip_address[16];
    char subnet_mask[16];
    printf("Enter the IP address: ");
    scanf("%s", ip_address);
    printf("Enter the subnet mask: ");
    scanf("%s", subnet_mask);

    // Convert the IP address and subnet mask to structs
    IPv4Address ip_address_struct = string_to_ipv4(ip_address);
    SubnetMask subnet_mask_struct = string_to_subnet_mask(subnet_mask);
    

    // Calculate the network address, broadcast address, and number of hosts
    Subnet subnet;
    subnet.network_address = calculate_network_address(ip_address_struct, subnet_mask_struct);
    subnet.broadcast_address = calculate_broadcast_address(subnet.network_address, subnet_mask_struct);
    subnet.num_hosts = calculate_num_hosts(subnet_mask_struct);

    // Print the details of the subnet
    print_subnet(subnet);

    return 0;
}