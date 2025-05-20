//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: statistical
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    unsigned int ip_address;
    unsigned int subnet_mask;
    unsigned int network_address;
    unsigned int broadcast_address;
    unsigned int number_of_hosts;
    unsigned int cidr;
} subnet_info;

int main() {
    // Initialize variables
    unsigned int ip_address, subnet_mask, cidr;
    char ip_address_str[16];
    char subnet_mask_str[16];
    subnet_info subnet;

    // Get the IP address from the user
    printf("Enter the IP address (e.g., 192.168.1.1): ");
    scanf("%s", ip_address_str);

    // Convert the IP address string to an integer
    ip_address = inet_addr(ip_address_str);

    // Get the subnet mask from the user
    printf("Enter the subnet mask (e.g., 255.255.255.0): ");
    scanf("%s", subnet_mask_str);

    // Convert the subnet mask string to an integer
    subnet_mask = inet_addr(subnet_mask_str);

    // Calculate the network address
    subnet.network_address = ip_address & subnet_mask;

    // Calculate the broadcast address
    subnet.broadcast_address = subnet.network_address | ~subnet_mask;

    // Calculate the number of hosts
    subnet.number_of_hosts = pow(2, 32 - count_bits(subnet_mask)) - 2;

    // Calculate the CIDR notation
    subnet.cidr = count_bits(subnet_mask);

    // Print the subnet information
    printf("\nSubnet Information:\n");
    printf("IP Address: %s\n", ip_address_str);
    printf("Subnet Mask: %s\n", subnet_mask_str);
    printf("Network Address: %u.%u.%u.%u\n",
        (subnet.network_address >> 24) & 0xff,
        (subnet.network_address >> 16) & 0xff,
        (subnet.network_address >> 8) & 0xff,
        subnet.network_address & 0xff);
    printf("Broadcast Address: %u.%u.%u.%u\n",
        (subnet.broadcast_address >> 24) & 0xff,
        (subnet.broadcast_address >> 16) & 0xff,
        (subnet.broadcast_address >> 8) & 0xff,
        subnet.broadcast_address & 0xff);
    printf("Number of Hosts: %u\n", subnet.number_of_hosts);
    printf("CIDR Notation: /%u\n", subnet.cidr);

    return 0;
}

int count_bits(unsigned int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}