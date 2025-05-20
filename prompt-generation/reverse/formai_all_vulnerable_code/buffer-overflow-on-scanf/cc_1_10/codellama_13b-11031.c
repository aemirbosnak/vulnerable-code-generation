//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: recursive
// Subnet Calculator
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to convert IP address to binary
void ip_to_binary(char *ip, int *binary) {
    int i;
    char *ptr;
    for (i = 0; i < 4; i++) {
        binary[i] = strtol(ip, &ptr, 10);
        ip = ptr;
    }
}

// Function to calculate the subnet mask
void calculate_subnet(int *binary, int subnet) {
    int i;
    for (i = 0; i < 4; i++) {
        binary[i] = binary[i] & ~(subnet - 1);
    }
}

// Function to calculate the network address
void calculate_network(int *binary, int subnet) {
    int i;
    for (i = 0; i < 4; i++) {
        binary[i] = binary[i] & (subnet - 1);
    }
}

// Function to convert binary to IP address
void binary_to_ip(int *binary, char *ip) {
    sprintf(ip, "%d.%d.%d.%d", binary[0], binary[1], binary[2], binary[3]);
}

// Function to calculate the broadcast address
void calculate_broadcast(int *binary, int subnet) {
    int i;
    for (i = 0; i < 4; i++) {
        binary[i] = binary[i] | ~(subnet - 1);
    }
}

// Function to calculate the number of host addresses
void calculate_host_addresses(int *binary, int subnet) {
    int i;
    for (i = 0; i < 4; i++) {
        binary[i] = binary[i] ^ (subnet - 1);
    }
}

// Function to print the results
void print_results(int *binary, int subnet, char *ip, char *network, char *broadcast, int host_addresses) {
    printf("IP address: %s\n", ip);
    printf("Subnet mask: %d\n", subnet);
    printf("Network address: %s\n", network);
    printf("Broadcast address: %s\n", broadcast);
    printf("Number of host addresses: %d\n", host_addresses);
}

// Main function
int main() {
    char ip[16];
    int binary[4];
    int subnet;
    char network[16];
    char broadcast[16];
    int host_addresses;

    // Take input from user
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter subnet mask: ");
    scanf("%d", &subnet);

    // Convert IP address to binary
    ip_to_binary(ip, binary);

    // Calculate the subnet mask
    calculate_subnet(binary, subnet);

    // Calculate the network address
    calculate_network(binary, subnet);
    binary_to_ip(binary, network);

    // Calculate the broadcast address
    calculate_broadcast(binary, subnet);
    binary_to_ip(binary, broadcast);

    // Calculate the number of host addresses
    calculate_host_addresses(binary, subnet);
    host_addresses = binary[0];

    // Print the results
    print_results(binary, subnet, ip, network, broadcast, host_addresses);

    return 0;
}