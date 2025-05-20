//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to store the subnet information
typedef struct subnet {
    char *ip_address;
    char *subnet_mask;
    char *network_address;
    char *broadcast_address;
    int num_hosts;
} subnet;

// Function to calculate the subnet information
subnet calculate_subnet(char *ip_address, char *subnet_mask) {
    subnet subnet;

    // Convert the IP address and subnet mask to binary
    unsigned long ip_binary = inet_addr(ip_address);
    unsigned long subnet_mask_binary = inet_addr(subnet_mask);

    // Calculate the network address
    unsigned long network_address_binary = ip_binary & subnet_mask_binary;
    char *network_address = inet_ntoa(network_address_binary);

    // Calculate the broadcast address
    unsigned long broadcast_address_binary = network_address_binary | ~subnet_mask_binary;
    char *broadcast_address = inet_ntoa(broadcast_address_binary);

    // Calculate the number of hosts
    int num_hosts = pow(2, 32 - ntohl(subnet_mask_binary)) - 2;

    // Store the subnet information in the structure
    subnet.ip_address = ip_address;
    subnet.subnet_mask = subnet_mask;
    subnet.network_address = network_address;
    subnet.broadcast_address = broadcast_address;
    subnet.num_hosts = num_hosts;

    return subnet;
}

// Function to print the subnet information
void print_subnet(subnet subnet) {
    printf("IP Address: %s\n", subnet.ip_address);
    printf("Subnet Mask: %s\n", subnet.subnet_mask);
    printf("Network Address: %s\n", subnet.network_address);
    printf("Broadcast Address: %s\n", subnet.broadcast_address);
    printf("Number of Hosts: %d\n", subnet.num_hosts);
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

    // Calculate the subnet information
    subnet subnet = calculate_subnet(ip_address, subnet_mask);

    // Print the subnet information
    print_subnet(subnet);

    return 0;
}