//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STRING_LENGTH 20

void calculateSubnet(const char *ip, const char *subnet_mask) {
    unsigned char ip_bytes[4];
    unsigned char mask_bytes[4];
    unsigned char network_bytes[4];
    unsigned char broadcast_bytes[4];
    unsigned char usable_network_start[4];
    unsigned char usable_network_end[4];
    
    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &ip_bytes[0], &ip_bytes[1], &ip_bytes[2], &ip_bytes[3]);
    sscanf(subnet_mask, "%hhu.%hhu.%hhu.%hhu", &mask_bytes[0], &mask_bytes[1], &mask_bytes[2], &mask_bytes[3]);
    
    // Subnet calculations
    for(int i = 0; i < 4; i++) {
        network_bytes[i] = ip_bytes[i] & mask_bytes[i];
        broadcast_bytes[i] = network_bytes[i] | (~mask_bytes[i] & 0xFF);
    }
    
    // Usable address range calculations
    for(int i = 0; i < 4; i++) {
        usable_network_start[i] = network_bytes[i];
        usable_network_end[i] = broadcast_bytes[i];
    }
    
    // Usable IP addresses: incrementing usable_network_start and decrementing usable_network_end
    usable_network_start[3] += 1; // Start with the first usable IP
    usable_network_end[3] -= 1;     // End with the last usable IP
    
    printf("\nCalculating for IP: %s with Subnet Mask: %s\n", ip, subnet_mask);
    printf("--------------------------------------------------------------------\n");
    printf("Network Address: %hhu.%hhu.%hhu.%hhu\n", network_bytes[0], network_bytes[1], network_bytes[2], network_bytes[3]);
    printf("Broadcast Address: %hhu.%hhu.%hhu.%hhu\n", broadcast_bytes[0], broadcast_bytes[1], broadcast_bytes[2], broadcast_bytes[3]);
    printf("Usable IP Range: %hhu.%hhu.%hhu.%hhu - %hhu.%hhu.%hhu.%hhu\n",
           usable_network_start[0], usable_network_start[1], usable_network_start[2], usable_network_start[3],
           usable_network_end[0], usable_network_end[1], usable_network_end[2], usable_network_end[3]);
    
    // Calculate the number of usable addresses
    int total_host_bits = 32 - (mask_bytes[0] + mask_bytes[1] + mask_bytes[2] + mask_bytes[3]);
    int usable_host_count = pow(2, total_host_bits) - 2; // Subtract 2 for network and broadcast
    printf("Total Usable Addresses: %d\n", usable_host_count);
    printf("--------------------------------------------------------------------\n");
}

int main() {
    char input_ip[MAX_STRING_LENGTH];
    char input_mask[MAX_STRING_LENGTH];

    printf("\nWelcome to the Shockingly Awesome Subnet Calculator!\n");
    printf("Please enter the IP address (e.g. 192.168.1.1): ");
    fgets(input_ip, MAX_STRING_LENGTH, stdin);
    input_ip[strcspn(input_ip, "\n")] = 0;  // Remove trailing newline

    printf("Now, enter the subnet mask (e.g. 255.255.255.0): ");
    fgets(input_mask, MAX_STRING_LENGTH, stdin);
    input_mask[strcspn(input_mask, "\n")] = 0; // Remove trailing newline

    if (strlen(input_ip) == 0 || strlen(input_mask) == 0) {
        printf("OOPS! Looks like you didn't provide valid input. Try again!\n");
        return 1;
    }

    // Calculate and display the subnet information
    calculateSubnet(input_ip, input_mask);

    return 0;
}