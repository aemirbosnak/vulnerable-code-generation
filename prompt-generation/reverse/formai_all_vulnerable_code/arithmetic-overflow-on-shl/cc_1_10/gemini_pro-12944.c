//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_IP_ADDR_LEN 16
#define MAX_SUBNET_MASK_LEN 16

// Structures
typedef struct {
    unsigned char octets[4];
} IPAddress;

typedef struct {
    unsigned char octets[4];
    unsigned char prefix_length;
} SubnetMask;

// Functions
void print_ip_address(IPAddress ip_addr) {
    printf("%u.%u.%u.%u\n", ip_addr.octets[0], ip_addr.octets[1], ip_addr.octets[2], ip_addr.octets[3]);
}

void print_subnet_mask(SubnetMask subnet_mask) {
    printf("%u.%u.%u.%u/%u\n", subnet_mask.octets[0], subnet_mask.octets[1], subnet_mask.octets[2], subnet_mask.octets[3], subnet_mask.prefix_length);
}

int main() {
    // Variables
    IPAddress ip_addr;
    SubnetMask subnet_mask;
    unsigned int num_hosts;
    unsigned int num_subnets;

    // Get the IP address from the user
    printf("Enter the IP address: ");
    scanf("%s", ip_addr.octets);

    // Get the subnet mask from the user
    printf("Enter the subnet mask: ");
    scanf("%s/%u", subnet_mask.octets, &subnet_mask.prefix_length);

    // Calculate the number of hosts
    num_hosts = (1 << (32 - subnet_mask.prefix_length)) - 2;

    // Calculate the number of subnets
    num_subnets = (1 << subnet_mask.prefix_length);

    // Print the results
    printf("IP Address: ");
    print_ip_address(ip_addr);
    printf("Subnet Mask: ");
    print_subnet_mask(subnet_mask);
    printf("Number of Hosts: %u\n", num_hosts);
    printf("Number of Subnets: %u\n", num_subnets);

    return 0;
}