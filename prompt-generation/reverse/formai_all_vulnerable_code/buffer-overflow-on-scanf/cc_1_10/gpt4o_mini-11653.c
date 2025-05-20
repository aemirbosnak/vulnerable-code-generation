//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void print_binary(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
}

void print_ip(unsigned char *ip) {
    for (int i = 0; i < 4; i++) {
        printf("%d", ip[i]);
        if (i < 3) {
            printf(".");
        }
    }
}

void calculate_subnet(unsigned char *ip, unsigned char *mask, unsigned char *network, unsigned char *broadcast) {
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
        broadcast[i] = network[i] | (~mask[i] & 0xFF);
    }
}

void display_subnet_info(unsigned char *ip, unsigned char *mask) {
    unsigned char network[4], broadcast[4];

    calculate_subnet(ip, mask, network, broadcast);

    printf("\nIP Address: ");
    print_ip(ip);
    printf("\nSubnet Mask: ");
    print_ip(mask);
    printf("\nNetwork Address: ");
    print_ip(network);
    printf("\nBroadcast Address: ");
    print_ip(broadcast);
    printf("\n");
}

int calculate_hosts(unsigned char *mask) {
    int host_bits = 0;
    for (int i = 0; i < 4; i++) {
        unsigned char temp = ~mask[i];
        for (int j = 0; j < 8; j++) {
            if (temp & (1 << (7 - j))) {
                host_bits++;
            }
        }
    }
    return pow(2, host_bits) - 2; // subtract 2 for network and broadcast addresses
}

int main() {
    unsigned char ip[4], mask[4];

    printf("Welcome to the Subnet Calculator!\n");
    
    // Input IP address
    printf("Please enter an IP address (e.g., 192.168.1.1): ");
    scanf("%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);

    // Input Subnet Mask
    printf("Please enter a subnet mask (e.g., 255.255.255.0): ");
    scanf("%hhu.%hhu.%hhu.%hhu", &mask[0], &mask[1], &mask[2], &mask[3]);

    // Display subnet information
    display_subnet_info(ip, mask);

    // Calculate and display number of hosts
    int number_of_hosts = calculate_hosts(mask);
    printf("Number of usable hosts: %d\n", number_of_hosts);

    // Showing binary representation
    printf("\nBinary Representation:\n");
    printf("IP Address: ");
    for (int i = 0; i < 4; i++) {
        print_binary(ip[i]);
        if (i < 3) {
            printf(".");
        }
    }
    printf("\n");

    printf("Subnet Mask: ");
    for (int i = 0; i < 4; i++) {
        print_binary(mask[i]);
        if (i < 3) {
            printf(".");
        }
    }
    printf("\n");

    return 0;
}