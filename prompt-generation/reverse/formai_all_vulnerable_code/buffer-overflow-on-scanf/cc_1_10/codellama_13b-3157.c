//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: future-proof
/*
 * A unique C Subnet Calculator example program in a future-proof style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_SUBNET_MASK_LEN 32

// Structure to store the subnet information
typedef struct {
    uint32_t ip_address;
    uint32_t subnet_mask;
    uint32_t network_address;
    uint32_t broadcast_address;
    uint32_t number_of_hosts;
    uint32_t number_of_subnets;
} Subnet;

// Function to calculate the subnet information
void calculate_subnet(Subnet *subnet) {
    subnet->network_address = subnet->ip_address & subnet->subnet_mask;
    subnet->broadcast_address = subnet->network_address | ~subnet->subnet_mask;
    subnet->number_of_hosts = (subnet->subnet_mask >> 1) + 1;
    subnet->number_of_subnets = (subnet->subnet_mask >> 2) + 1;
}

// Main function
int main() {
    Subnet subnet;
    char ip_address[16], subnet_mask[16];

    // Get the IP address and subnet mask from the user
    printf("Enter the IP address: ");
    scanf("%s", ip_address);
    printf("Enter the subnet mask: ");
    scanf("%s", subnet_mask);

    // Convert the IP address and subnet mask to integers
    subnet.ip_address = inet_addr(ip_address);
    subnet.subnet_mask = inet_addr(subnet_mask);

    // Calculate the subnet information
    calculate_subnet(&subnet);

    // Print the subnet information
    printf("Network address: %s\n", inet_ntoa(subnet.network_address));
    printf("Broadcast address: %s\n", inet_ntoa(subnet.broadcast_address));
    printf("Number of hosts: %d\n", subnet.number_of_hosts);
    printf("Number of subnets: %d\n", subnet.number_of_subnets);

    return 0;
}