//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Classifying Ethernet networks requires precision, just as in the art of deduction.
// Allow me to present a code that unravels the mysteries of subnets.

#define MAX_NETWORKS 100

// Struct to represent a subnet
typedef struct {
    char network[16];     // Network address in dot-decimal notation
    char mask[16];        // Subnet mask in dot-decimal notation
    int hosts;            // Number of valid hosts
} Subnet;

// Function to calculate the number of hosts in a subnet
int calculate_hosts(char *mask) {
    int mask_bits = 0;
    
    // Count the number of '1's in the subnet mask
    for (int i = 0; mask[i] != '\0'; i++) {
        if (mask[i] == '1') {
            mask_bits++;
        }
    }
    
    // The formula for the number of hosts in a subnet:
    return (1 << (32 - mask_bits)) - 2; // subtract 2 for network and broadcast addresses
}

// Function to print the subnet details
void print_subnet_details(Subnet subnet) {
    printf("Network Address: %s\n", subnet.network);
    printf("Subnet Mask: %s\n", subnet.mask);
    printf("Number of Valid Hosts: %d\n", subnet.hosts);
    printf("---------------------------------------\n");
}

// Function to retrieve subnet details from the user
void input_subnet_info(Subnet *subnet) {
    printf("Enter the network address (e.g., 192.168.0.0): ");
    scanf("%s", subnet->network);
    
    printf("Enter the subnet mask in CIDR (e.g., /24): ");
    int cidr;
    scanf("%d", &cidr);
    
    // Convert CIDR to binary mask
    for (int i = 0; i < 32; i++) {
        if (i < cidr) {
            strcat(subnet->mask, "1");
        } else {
            strcat(subnet->mask, "0");
        }
    }
    
    // Calculate the number of hosts in the subnet
    subnet->hosts = calculate_hosts(subnet->mask);
}

int main() {
    printf("Welcome to Sherlock's Subnet Calculator!\n");
    printf("Your trusty assistant will aid in sifting through the complexities of networking.\n");
    printf("-----------------------------------------------------\n");
    
    Subnet subnets[MAX_NETWORKS];
    int subnet_count = 0;
    
    char continue_calc = 'y';
    
    while (continue_calc == 'y' && subnet_count < MAX_NETWORKS) {
        // Initialize the subnet struct
        strcpy(subnets[subnet_count].mask, ""); // Clear previous contents
        
        // Retrieve subnet information from the user
        input_subnet_info(&subnets[subnet_count]);
        
        // Print the details for the current subnet
        print_subnet_details(subnets[subnet_count]);
        
        subnet_count++; // Increment the count of subnets
        
        printf("Would you like to calculate another subnet? (y/n): ");
        scanf(" %c", &continue_calc);
    }
    
    printf("Thank you for using Sherlock's Subnet Calculator!\n");
    printf("Now you are equipped with knowledge worthy of a detective!\n");
    
    return 0;
}