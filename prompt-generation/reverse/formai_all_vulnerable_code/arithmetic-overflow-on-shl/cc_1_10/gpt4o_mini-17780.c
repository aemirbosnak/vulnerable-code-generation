//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function to calculate subnet details
void calculate_subnet(char *ip, char *mask) {
    struct sockaddr_in sa;
    unsigned int ip_bin, mask_bin, network_bin, broadcast_bin;
    char network[INET_ADDRSTRLEN], broadcast[INET_ADDRSTRLEN];

    // Convert IP and mask from string to binary format
    if (inet_pton(AF_INET, ip, &(sa.sin_addr)) == 1) {
        ip_bin = ntohl(sa.sin_addr.s_addr);
    } else {
        fprintf(stderr, "Invalid IP address\n");
        exit(EXIT_FAILURE);
    }

    if (inet_pton(AF_INET, mask, &(sa.sin_addr)) == 1) {
        mask_bin = ntohl(sa.sin_addr.s_addr);
    } else {
        fprintf(stderr, "Invalid subnet mask\n");
        exit(EXIT_FAILURE);
    }

    // Calculate Network and Broadcast addresses
    network_bin = ip_bin & mask_bin;
    broadcast_bin = network_bin | ~mask_bin;

    // Convert binary to string format
    sa.sin_addr.s_addr = htonl(network_bin);
    inet_ntop(AF_INET, &(sa.sin_addr), network, INET_ADDRSTRLEN);

    sa.sin_addr.s_addr = htonl(broadcast_bin);
    inet_ntop(AF_INET, &(sa.sin_addr), broadcast, INET_ADDRSTRLEN);

    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", mask);
    printf("Network Address: %s\n", network);
    printf("Broadcast Address: %s\n", broadcast);

    // Calculate the number of hosts
    unsigned int num_hosts = (1 << (32 - __builtin_popcount(mask_bin))) - 2;
    printf("Number of Hosts: %u\n", num_hosts);

    if (num_hosts < 0) {
        fprintf(stderr, "Oh no! An invalid number of hosts was calculated.\n");
    }
}

int main() {
    char ip[INET_ADDRSTRLEN], mask[INET_ADDRSTRLEN];

    printf("Welcome to the MAP of Subnetting! \nPrepare for your mind to be blown!\n\n");

    // Get the IP Address from user
    printf("Enter a valid IP Address (e.g., 192.168.0.1): ");
    fgets(ip, sizeof(ip), stdin);
    strtok(ip, "\n"); // Remove trailing newline

    // Get the Subnet Mask from user
    printf("Enter the Subnet Mask (e.g., 255.255.255.0): ");
    fgets(mask, sizeof(mask), stdin);
    strtok(mask, "\n"); // Remove trailing newline

    printf("Calculating...Hold on tight!\n\n");
    calculate_subnet(ip, mask);
    
    printf("\nAnd there you have it! The mysteries of subnetting unveiled. Go forth and conquer the networks!\n");
    return 0;
}