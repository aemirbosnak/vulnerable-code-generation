//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LEN 16

// Function to calculate the number of hosts based on subnet mask
int calculate_hosts(int subnet_mask) {
    return pow(2, (32 - subnet_mask)) - 2; // Subtracting 2 for network and broadcast addresses
}

// Function to calculate the subnet from given IP address and subnet mask
void calculate_subnet(char *ip_addr, int subnet_mask, char *subnet_addr) {
    unsigned int ip_parts[4];
    sscanf(ip_addr, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);
    
    // Calculating subnet address
    unsigned int mask = (0xFFFFFFFF << (32 - subnet_mask)) & 0xFFFFFFFF;
    unsigned int subnet = (ip_parts[0] << 24) | (ip_parts[1] << 16) | (ip_parts[2] << 8) | ip_parts[3];
    subnet = subnet & mask;

    sprintf(subnet_addr, "%u.%u.%u.%u", (subnet >> 24) & 0xFF, (subnet >> 16) & 0xFF, (subnet >> 8) & 0xFF, subnet & 0xFF);
}

// Function to display usage
void display_usage(char *prog_name) {
    printf("Usage: %s <IP_ADDRESS> <SUBNET_MASK>\n", prog_name);
    printf("Example: %s 192.168.1.1 24\n", prog_name);
}

// Main Function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage(argv[0]);
        return 1;
    }

    char *ip_addr = argv[1];
    int subnet_mask = atoi(argv[2]);

    if (subnet_mask < 0 || subnet_mask > 32) {
        printf("Error: Subnet mask must be between 0 and 32.\n");
        return 1;
    }

    char subnet_addr[MAX_IP_LEN];
    calculate_subnet(ip_addr, subnet_mask, subnet_addr);
    
    int total_hosts = calculate_hosts(subnet_mask);

    printf("IP Address      : %s\n", ip_addr);
    printf("Subnet Mask     : /%d\n", subnet_mask);
    printf("Subnet Address   : %s\n", subnet_addr);
    printf("Total Hosts in /%d : %d\n", subnet_mask, total_hosts);

    // Display the first and last usable IP addresses
    unsigned int subnet_parts[4];
    sscanf(subnet_addr, "%u.%u.%u.%u", &subnet_parts[0], &subnet_parts[1], &subnet_parts[2], &subnet_parts[3]);

    unsigned int base_address = (subnet_parts[0] << 24) | (subnet_parts[1] << 16) | (subnet_parts[2] << 8) | subnet_parts[3];
    unsigned int first_usable = base_address + 1;
    unsigned int last_usable = base_address + total_hosts;

    printf("First Usable IP : %u.%u.%u.%u\n", (first_usable >> 24) & 0xFF, (first_usable >> 16) & 0xFF, (first_usable >> 8) & 0xFF, first_usable & 0xFF);
    printf("Last Usable IP  : %u.%u.%u.%u\n", (last_usable >> 24) & 0xFF, (last_usable >> 16) & 0xFF, (last_usable >> 8) & 0xFF, last_usable & 0xFF);

    return 0;
}