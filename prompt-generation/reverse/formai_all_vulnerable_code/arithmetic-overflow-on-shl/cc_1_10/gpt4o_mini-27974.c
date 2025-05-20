//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold IP address and its subnet mask
typedef struct {
    char ip[16];         // IPv4 format: xxx.xxx.xxx.xxx
    char subnet_mask[16]; // Subnet mask in the same format
    unsigned int subnet_size; // Number of addresses in the subnet
} Subnet;

// Function to calculate the subnet size based on a given CIDR notation
unsigned int calculateSubnetSize(int cidr) {
    return (1 << (32 - cidr)); // 2^(32 - cidr)
}

// Function to convert an IP address string to a numerical representation
unsigned long ipToLong(const char *ip) {
    unsigned long num = 0;
    unsigned int octet;
    char *token;
    char *ip_copy = strdup(ip); // Copy to avoid modifying the original

    token = strtok(ip_copy, ".");
    while (token != NULL) {
        octet = (unsigned int)atoi(token);
        num = (num << 8) | octet; // Shift left and add the octet
        token = strtok(NULL, ".");
    }
    free(ip_copy);
    return num;
}

// Function to check if the IP address and subnet mask are valid
int validateInput(const char *ip, const char *subnet_mask) {
    // Simple validation: Check if IP and subnet mask are not empty
    if (strlen(ip) == 0 || strlen(subnet_mask) == 0) {
        return 0; // Invalid
    }
    
    // More detailed validation can be added as needed
    return 1; // Valid
}

// Function to display subnet details
void displaySubnetInfo(Subnet subnet) {
    printf("IP Address: %s\n", subnet.ip);
    printf("Subnet Mask: %s\n", subnet.subnet_mask);
    printf("Number of Addresses in Subnet: %u\n", subnet.subnet_size);
}

// Function to obtain CIDR from subnet mask
int getCIDRfromMask(const char *subnet_mask) {
    int cidr = 0;
    unsigned long num = ipToLong(subnet_mask);
    
    while (num) {
        cidr += (num & 1);
        num >>= 1;
    }
    
    return cidr;
}

// The whimsical main function of our Subnet Calculator
int main() {
    Subnet mySubnet;
    int cidr;
    
    // Welcome header
    printf("============================================\n");
    printf("   Welcome to the Whimsical Subnet Calculator!   \n");
    printf("============================================\n");
    
    // Get IP Address
    printf("Enter the IP Address (e.g., 192.168.1.1): ");
    fgets(mySubnet.ip, sizeof(mySubnet.ip), stdin);
    mySubnet.ip[strcspn(mySubnet.ip, "\n")] = 0; // Remove trailing newline
    
    // Get Subnet Mask
    printf("Enter the Subnet Mask (e.g., 255.255.255.0): ");
    fgets(mySubnet.subnet_mask, sizeof(mySubnet.subnet_mask), stdin);
    mySubnet.subnet_mask[strcspn(mySubnet.subnet_mask, "\n")] = 0; // Remove trailing newline
    
    // Validate input
    if (!validateInput(mySubnet.ip, mySubnet.subnet_mask)) {
        printf("Invalid IP address or subnet mask entered. Please try again.\n");
        return EXIT_FAILURE;
    }
    
    // Calculate CIDR notation from subnet mask
    cidr = getCIDRfromMask(mySubnet.subnet_mask);
    mySubnet.subnet_size = calculateSubnetSize(cidr);
    
    // Output the subnet information
    displaySubnetInfo(mySubnet);
    
    // Farewell footer
    printf("============================================\n");
    printf("   Thank you for using the Subnet Calculator!  \n");
    printf("============================================\n");
    
    return EXIT_SUCCESS;
}