//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16
#define MAX_CIDR_LENGTH 3

// Function to calculate the binary representation of the IP
void calculate_binary(const char *ip_addr, char binary[4][9]) {
    int octet;
    char *token;
    char ip_copy[MAX_IP_LENGTH];

    // Copy the IP address to modify it
    strncpy(ip_copy, ip_addr, MAX_IP_LENGTH);
    token = strtok(ip_copy, ".");

    int i = 0;
    while (token != NULL && i < 4) {
        octet = atoi(token);
        // Convert each octet to binary
        for (int j = 0; j < 8; j++) {
            binary[i][7 - j] = (octet & (1 << j)) ? '1' : '0';
        }
        binary[i][8] = '\0'; // Null-terminate the string
        token = strtok(NULL, ".");
        i++;
    }
}

// Function to print the binary representation
void print_binary(char binary[4][9]) {
    printf("Binary Representation:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s", binary[i]);
        if (i != 3) printf(".");
    }
    printf("\n");
}

// Function to calculate network and broadcast address
void calculate_network_broadcast(const char *ip_addr, const char *subnet_mask, char network[16], char broadcast[16]) {
    unsigned int ip[4], mask[4];
    
    sscanf(ip_addr, "%u.%u.%u.%u", &ip[0], &ip[1], &ip[2], &ip[3]);
    sscanf(subnet_mask, "%u.%u.%u.%u", &mask[0], &mask[1], &mask[2], &mask[3]);
    
    // Calculate network address
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
    }
    
    // Calculate broadcast address
    for (int i = 0; i < 4; i++) {
        broadcast[i] = ip[i] | ~mask[i] & 255;
    }
}

// Function to calculate number of hosts
void calculate_hosts(const char *subnet_mask) {
    int ones = 0, total_hosts;
    
    for (int i = 0; i < 4; i++) {
        unsigned int octet;
        sscanf(&subnet_mask[i * 4], "%u", &octet);
        while (octet) {
            ones += octet & 1;
            octet >>= 1;
        }
    }
    
    total_hosts = (1 << (32 - ones)) - 2; // 2 for network and broadcast addresses
    printf("Total usable hosts: %d\n", total_hosts);
}

int main() {
    char ip_addr[MAX_IP_LENGTH];
    char subnet_mask[MAX_IP_LENGTH];
    char binary[4][9];
    char network[16], broadcast[16];

    // Gather user input
    printf("Welcome to the Subnet Calculator!\n");
    printf("Enter the IP address (format: A.B.C.D): ");
    scanf("%s", ip_addr);
    
    printf("Enter the Subnet mask (format: A.B.C.D): ");
    scanf("%s", subnet_mask);
    
    // Calculate binary representation
    calculate_binary(ip_addr, binary);
    print_binary(binary);
    
    // Calculate network and broadcast addresses
    calculate_network_broadcast(ip_addr, subnet_mask, network, broadcast);
    printf("Network Address: %u.%u.%u.%u\n", (unsigned char)network[0], (unsigned char)network[1], (unsigned char)network[2], (unsigned char)network[3]);
    printf("Broadcast Address: %u.%u.%u.%u\n", (unsigned char)broadcast[0], (unsigned char)broadcast[1], (unsigned char)broadcast[2], (unsigned char)broadcast[3]);
    
    // Calculate number of hosts
    calculate_hosts(subnet_mask);
    
    printf("Thank you for using the Subnet Calculator. Happy Networking!\n");
    
    return 0;
}