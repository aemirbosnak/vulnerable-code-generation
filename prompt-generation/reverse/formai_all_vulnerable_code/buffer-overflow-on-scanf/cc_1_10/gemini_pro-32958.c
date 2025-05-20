//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of bits in an IPv4 address
#define MAX_BITS 32

// Define the structure of an IPv4 address
typedef struct {
    unsigned char octets[4];
} ipv4_address;

// Define the structure of a subnet mask
typedef struct {
    unsigned char octets[4];
} subnet_mask;

// Define the function to calculate the network address
ipv4_address calculate_network_address(ipv4_address ip, subnet_mask mask) {
    ipv4_address network_address;
    for (int i = 0; i < 4; i++) {
        network_address.octets[i] = ip.octets[i] & mask.octets[i];
    }
    return network_address;
}

// Define the function to calculate the broadcast address
ipv4_address calculate_broadcast_address(ipv4_address ip, subnet_mask mask) {
    ipv4_address broadcast_address;
    for (int i = 0; i < 4; i++) {
        broadcast_address.octets[i] = ip.octets[i] | ~mask.octets[i];
    }
    return broadcast_address;
}

// Define the function to calculate the number of hosts on a subnet
unsigned int calculate_num_hosts(subnet_mask mask) {
    unsigned int num_hosts = 0;
    for (int i = 0; i < 4; i++) {
        num_hosts += (unsigned int)pow(2, 8 - mask.octets[i]);
    }
    return num_hosts - 2; // Subtract 2 for the network address and broadcast address
}

// Define the function to print an IPv4 address
void print_ip_address(ipv4_address ip) {
    printf("%u.%u.%u.%u", ip.octets[0], ip.octets[1], ip.octets[2], ip.octets[3]);
}

// Define the function to print a subnet mask
void print_subnet_mask(subnet_mask mask) {
    printf("%u.%u.%u.%u", mask.octets[0], mask.octets[1], mask.octets[2], mask.octets[3]);
}

// Define the function to print the subnet information
void print_subnet_info(ipv4_address ip, subnet_mask mask) {
    printf("IP Address: ");
    print_ip_address(ip);
    printf("\nSubnet Mask: ");
    print_subnet_mask(mask);
    printf("\nNetwork Address: ");
    print_ip_address(calculate_network_address(ip, mask));
    printf("\nBroadcast Address: ");
    print_ip_address(calculate_broadcast_address(ip, mask));
    printf("\nNumber of Hosts: %u\n", calculate_num_hosts(mask));
}

// Define the main function
int main() {
    // Get the IP address from the user
    ipv4_address ip;
    printf("Enter the IP address: ");
    scanf("%u.%u.%u.%u", &ip.octets[0], &ip.octets[1], &ip.octets[2], &ip.octets[3]);

    // Get the subnet mask from the user
    subnet_mask mask;
    printf("Enter the subnet mask: ");
    scanf("%u.%u.%u.%u", &mask.octets[0], &mask.octets[1], &mask.octets[2], &mask.octets[3]);

    // Calculate and print the subnet information
    print_subnet_info(ip, mask);

    return 0;
}