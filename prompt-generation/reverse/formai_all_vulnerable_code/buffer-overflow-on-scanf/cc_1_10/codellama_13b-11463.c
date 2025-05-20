//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store subnet information
typedef struct {
    char *ip_address;
    int subnet_mask;
    int network_id;
    int broadcast_address;
    int number_of_hosts;
} SubnetInfo;

// Function to calculate the subnet mask from the number of hosts
int calculate_subnet_mask(int number_of_hosts) {
    int subnet_mask = 0;
    // Calculate the number of hosts and the subnet mask
    if (number_of_hosts > 0 && number_of_hosts <= 16) {
        subnet_mask = 0xffffff00;
    } else if (number_of_hosts > 16 && number_of_hosts <= 32) {
        subnet_mask = 0xffff0000;
    } else if (number_of_hosts > 32 && number_of_hosts <= 64) {
        subnet_mask = 0xff000000;
    } else if (number_of_hosts > 64 && number_of_hosts <= 128) {
        subnet_mask = 0x00000000;
    }
    return subnet_mask;
}

// Function to calculate the network ID from the IP address and subnet mask
int calculate_network_id(char *ip_address, int subnet_mask) {
    // Convert the IP address to an integer
    int ip_address_int = atoi(ip_address);
    // Apply the subnet mask to the IP address
    int network_id = ip_address_int & subnet_mask;
    return network_id;
}

// Function to calculate the broadcast address from the IP address, subnet mask, and number of hosts
int calculate_broadcast_address(char *ip_address, int subnet_mask, int number_of_hosts) {
    // Calculate the network ID
    int network_id = calculate_network_id(ip_address, subnet_mask);
    // Calculate the broadcast address
    int broadcast_address = network_id | ~subnet_mask;
    return broadcast_address;
}

// Function to calculate the number of hosts from the subnet mask
int calculate_number_of_hosts(int subnet_mask) {
    int number_of_hosts = 0;
    // Calculate the number of hosts
    if (subnet_mask == 0xffffff00) {
        number_of_hosts = 16;
    } else if (subnet_mask == 0xffff0000) {
        number_of_hosts = 32;
    } else if (subnet_mask == 0xff000000) {
        number_of_hosts = 64;
    } else if (subnet_mask == 0x00000000) {
        number_of_hosts = 128;
    }
    return number_of_hosts;
}

// Main function to run the subnet calculator
int main() {
    // Declare variables
    SubnetInfo subnet_info;
    char ip_address[16];
    int subnet_mask;
    int network_id;
    int broadcast_address;
    int number_of_hosts;

    // Get the IP address from the user
    printf("Enter the IP address: ");
    scanf("%s", ip_address);

    // Calculate the subnet mask
    subnet_mask = calculate_subnet_mask(number_of_hosts);

    // Calculate the network ID
    network_id = calculate_network_id(ip_address, subnet_mask);

    // Calculate the broadcast address
    broadcast_address = calculate_broadcast_address(ip_address, subnet_mask, number_of_hosts);

    // Calculate the number of hosts
    number_of_hosts = calculate_number_of_hosts(subnet_mask);

    // Print the results
    printf("Subnet Mask: %d\n", subnet_mask);
    printf("Network ID: %d\n", network_id);
    printf("Broadcast Address: %d\n", broadcast_address);
    printf("Number of Hosts: %d\n", number_of_hosts);

    return 0;
}