//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert decimal to binary
void decimalToBinary(int n, char *binary) {
    for (int i = 31; i >= 0; i--) {
        binary[i] = (n % 2) ? '1' : '0';
        n /= 2;
    }
    binary[32] = '\0'; // Null-terminate the string
}

// Function to calculate subnet information
void calculateSubnet(const char *ip_address, const char *subnet_mask) {
    unsigned int ip[4], mask[4], network[4], broadcast[4], usable_hosts;
    
    sscanf(ip_address, "%u.%u.%u.%u", &ip[0], &ip[1], &ip[2], &ip[3]);
    sscanf(subnet_mask, "%u.%u.%u.%u", &mask[0], &mask[1], &mask[2], &mask[3]);

    // Calculate the network address
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
    }

    // Calculate the broadcast address
    for (int i = 0; i < 4; i++) {
        broadcast[i] = network[i] | (~mask[i] & 0xFF);
    }

    // Calculate the number of usable hosts
    int ones_count = 0;
    for (int i = 0; i < 4; i++) {
        unsigned int temp = mask[i];
        while (temp) {
            ones_count += temp & 1;
            temp >>= 1;
        }
    }
    usable_hosts = pow(2, (32 - ones_count)) - 2; // -2 for network and broadcast addresses

    // Print results
    printf("\nSubnet Information:\n");
    printf("IP Address: %s\n", ip_address);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Network Address: %u.%u.%u.%u\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast Address: %u.%u.%u.%u\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Usable Hosts: %u\n\n", usable_hosts);
}

// Main function to drive the calculator
int main() {
    char ip_address[16], subnet_mask[16];
    char option;

    printf("Welcome to the C Subnet Calculator!\n");
    
    while (1) {
        printf("Please enter an IP address (xxx.xxx.xxx.xxx): ");
        fgets(ip_address, sizeof(ip_address), stdin);
        ip_address[strcspn(ip_address, "\n")] = 0;  // Remove newline character

        printf("Please enter a subnet mask (xxx.xxx.xxx.xxx): ");
        fgets(subnet_mask, sizeof(subnet_mask), stdin);
        subnet_mask[strcspn(subnet_mask, "\n")] = 0;  // Remove newline character

        calculateSubnet(ip_address, subnet_mask);
        
        printf("Would you like to calculate another subnet? (y/n): ");
        option = getchar();
        getchar(); // Clear the newline after getchar()
        
        if (option != 'y' && option != 'Y') {
            break;
        }
    }

    printf("Thank you for using the C Subnet Calculator! Goodbye!\n");
    return 0;
}