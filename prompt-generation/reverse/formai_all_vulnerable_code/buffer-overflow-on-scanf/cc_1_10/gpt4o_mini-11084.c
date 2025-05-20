//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert IP address to binary
void ip_to_binary(unsigned char ip[], char *binary) {
    for(int i = 0; i < 4; i++) {
        for(int j = 7; j >= 0; j--) {
            binary[i * 8 + (7 - j)] = (ip[i] & (1 << j)) ? '1' : '0';
        }
    }
    binary[32] = '\0'; // Null terminate the string
}

// Function to calculate the network address
void calculate_network_address(unsigned char ip[], unsigned char mask[], unsigned char network[]) {
    for(int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
    }
}

// Function to calculate the broadcast address
void calculate_broadcast_address(unsigned char network[], unsigned char mask[], unsigned char broadcast[]) {
    for(int i = 0; i < 4; i++) {
        broadcast[i] = network[i] | (~mask[i] & 0xFF);
    }
}

// Function to calculate the first usable address
void calculate_first_usable_address(unsigned char network[], unsigned char first[]) {
    memcpy(first, network, 4);
    first[3] += 1; // Increment the last octet
}

// Function to calculate the last usable address
void calculate_last_usable_address(unsigned char broadcast[], unsigned char last[]) {
    memcpy(last, broadcast, 4);
    last[3] -= 1; // Decrement the last octet
}

// Function to print the IP address in human-readable form
void print_ip(unsigned char ip[], const char *label) {
    printf("%s: %d.%d.%d.%d\n", label, ip[0], ip[1], ip[2], ip[3]);
}

// Function to count usable hosts
int count_usable_hosts(unsigned char mask[]) {
    int host_bits = 0;
    for (int i = 0; i < 4; i++) {
        unsigned char octet = mask[i];
        for (int j = 0; j < 8; j++) {
            if (!(octet & (1 << j))) { // Count zeros in the subnet mask
                host_bits++;
            }
        }
    }
    return (1 << host_bits) - 2; // 2 are reserved for network and broadcast addresses
}

int main() {
    unsigned char ip[4], mask[4], network[4], broadcast[4], first[4], last[4];
    char binary_ip[33], binary_mask[33];

    printf("***** Simple Subnet Calculator *****\n");
    
    // Input IP address
    printf("Enter an IP address (format: x.x.x.x): ");
    scanf("%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);

    // Input subnet mask
    printf("Enter Subnet mask (format: x.x.x.x): ");
    scanf("%hhu.%hhu.%hhu.%hhu", &mask[0], &mask[1], &mask[2], &mask[3]);

    // Calculate network address
    calculate_network_address(ip, mask, network);
    
    // Calculate broadcast address
    calculate_broadcast_address(network, mask, broadcast);
    
    // Calculate first usable address
    calculate_first_usable_address(network, first);
    
    // Calculate last usable address
    calculate_last_usable_address(broadcast, last);
    
    // Convert IP and mask to binary
    ip_to_binary(ip, binary_ip);
    ip_to_binary(mask, binary_mask);

    // Display subnet details
    printf("\n***** Subnet Details *****\n");
    print_ip(ip, "IP Address");
    print_ip(mask, "Subnet Mask");
    print_ip(network, "Network Address");
    print_ip(broadcast, "Broadcast Address");
    print_ip(first, "First Usable IP Address");
    print_ip(last, "Last Usable IP Address");

    int usable_hosts = count_usable_hosts(mask);
    printf("Number of Usable Hosts: %d\n", usable_hosts);
    
    // Display binary representation
    printf("\nBinary Representation:\n");
    printf("IP Address: %s\n", binary_ip);
    printf("Subnet Mask: %s\n", binary_mask);
    
    return 0;
}