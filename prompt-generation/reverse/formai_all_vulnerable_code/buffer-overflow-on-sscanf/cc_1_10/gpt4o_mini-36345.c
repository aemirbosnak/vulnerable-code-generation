//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define CIDR_MAX 32
#define IP_SEGMENT 256

void calculate_subnet(const char *ip, int subnet_mask) {
    unsigned char ip_bytes[4];
    unsigned char subnet_bytes[4];
    unsigned char network_bytes[4];
    
    // Parse IP address
    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &ip_bytes[0], &ip_bytes[1], &ip_bytes[2], &ip_bytes[3]);
    
    // Calculate the subnet bytes based on the subnet mask
    for (int i = 0; i < 4; i++) {
        if (subnet_mask > 8) {
            subnet_bytes[i] = 255; // All bits are set
            subnet_mask -= 8;
        } else {
            subnet_bytes[i] = (unsigned char)(256 - (1 << (8 - subnet_mask)));
            subnet_mask = 0; // No bits left to process
        }
    }
    
    // Calculate the network address
    for (int i = 0; i < 4; i++) {
        network_bytes[i] = ip_bytes[i] & subnet_bytes[i];
    }

    // Display results
    printf("Calculating subnet for: %s/%d\n", ip, (32 - (int)log2(256 - subnet_bytes[3])));
    printf("Subnet Mask: %hhu.%hhu.%hhu.%hhu\n", subnet_bytes[0], subnet_bytes[1], subnet_bytes[2], subnet_bytes[3]);
    printf("Network Address: %hhu.%hhu.%hhu.%hhu\n", network_bytes[0], network_bytes[1], network_bytes[2], network_bytes[3]);
    
    // Determine and print the range of valid host addresses
    unsigned char first_host[4] = {network_bytes[0], network_bytes[1], network_bytes[2], network_bytes[3] + 1};
    unsigned char last_host[4] = {network_bytes[0], network_bytes[1], network_bytes[2], 255 - (255 - subnet_bytes[3]) - 1};
    
    printf("Valid Host Range: %hhu.%hhu.%hhu.%hhu - %hhu.%hhu.%hhu.%hhu\n", 
           first_host[0], first_host[1], first_host[2], first_host[3], 
           last_host[0], last_host[1], last_host[2], last_host[3]);
    
    // Total number of valid host addresses
    int total_hosts = (1 << (32 - (32 - (int)log2(256 - subnet_bytes[3])))) - 2;
    printf("Total Valid Hosts: %d\n", total_hosts);
}

int main() {
    char ip[16];
    int subnet_mask;
    char input[20];

    printf("Welcome to the Surprising C Subnet Calculator!\n");
    
    while (1) {
        printf("Please enter an IP address (or type 'exit' to quit): ");
        scanf("%s", input);
        
        // Exit condition
        if (strcmp(input, "exit") == 0) {
            printf("Goodbye, thank you for using our Subnet Calculator!\n");
            break;
        }
        
        // Validate IP address format
        if (sscanf(input, "%15s", ip) != 1) {
            printf("Invalid input! Ensure you enter a valid IP address.\n");
            continue;
        }
        
        printf("Now, please enter the subnet mask (e.g., 24): ");
        scanf("%d", &subnet_mask);
        
        // Validate subnet mask
        if (subnet_mask < 0 || subnet_mask > CIDR_MAX) {
            printf("Invalid subnet mask! It should be between 0 and %d.\n", CIDR_MAX);
            continue;
        }
        
        // Call the subnet calculation function
        calculate_subnet(ip, subnet_mask);
    }

    return 0;
}