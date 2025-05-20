//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: shocked
/*
 * Subnet Calculator Example Program
 *
 * This program calculates the subnet mask for a given IP address and subnet size.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_SUBNET_SIZE 32

// Structure to store the IP address and subnet mask
struct ip_address {
    char ip[INET_ADDRSTRLEN];
    char subnet[INET_ADDRSTRLEN];
};

// Function to calculate the subnet mask
void calculate_subnet(struct ip_address *addr, int subnet_size) {
    // Calculate the subnet mask
    int mask = ~((1 << (MAX_SUBNET_SIZE - subnet_size)) - 1);

    // Convert the subnet mask to a string
    char subnet_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &mask, subnet_str, INET_ADDRSTRLEN);

    // Store the subnet mask in the address structure
    strcpy(addr->subnet, subnet_str);
}

int main() {
    // Declare a structure to store the IP address and subnet mask
    struct ip_address addr;

    // Get the IP address from the user
    printf("Enter the IP address: ");
    fgets(addr.ip, INET_ADDRSTRLEN, stdin);

    // Get the subnet size from the user
    int subnet_size;
    printf("Enter the subnet size: ");
    scanf("%d", &subnet_size);

    // Calculate the subnet mask
    calculate_subnet(&addr, subnet_size);

    // Print the subnet mask
    printf("Subnet mask: %s\n", addr.subnet);

    return 0;
}