//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Defines the maximum number of bits in an IPv4 address
#define MAX_BITS 32

// Defines the number of bits in an octet
#define BITS_PER_OCTET 8

// Defines the number of octets in an IPv4 address
#define OCTETS_PER_ADDRESS 4

// Defines the maximum number of subnets that can be created
#define MAX_SUBNETS 256

// Defines the maximum number of hosts per subnet
#define MAX_HOSTS 254

// Defines the default subnet mask
#define DEFAULT_SUBNET_MASK "255.255.255.0"

// Defines the default gateway address
#define DEFAULT_GATEWAY_ADDRESS "192.168.1.1"

// Defines the default DNS server address
#define DEFAULT_DNS_SERVER_ADDRESS "8.8.8.8"

// Structure to store the subnet calculator results
typedef struct {
    char subnet_mask[MAX_BITS];
    char network_address[MAX_BITS];
    char broadcast_address[MAX_BITS];
    unsigned int num_subnets;
    unsigned int num_hosts_per_subnet;
    char gateway_address[MAX_BITS];
    char dns_server_address[MAX_BITS];
} subnet_calculator_results;

// Function to calculate the subnet calculator results
subnet_calculator_results calculate_subnet(char *ip_address, char *subnet_mask) {
    // Initialize the results structure
    subnet_calculator_results results;

    // Convert the IP address and subnet mask to binary
    char ip_address_binary[MAX_BITS];
    char subnet_mask_binary[MAX_BITS];
    for (int i = 0; i < MAX_BITS; i++) {
        ip_address_binary[i] = (ip_address[i / BITS_PER_OCTET] & (1 << (BITS_PER_OCTET - 1 - i % BITS_PER_OCTET))) ? '1' : '0';
        subnet_mask_binary[i] = (subnet_mask[i / BITS_PER_OCTET] & (1 << (BITS_PER_OCTET - 1 - i % BITS_PER_OCTET))) ? '1' : '0';
    }

    // Calculate the network address
    char network_address_binary[MAX_BITS];
    for (int i = 0; i < MAX_BITS; i++) {
        network_address_binary[i] = (ip_address_binary[i] & subnet_mask_binary[i]) ? '1' : '0';
    }

    // Convert the network address back to decimal
    char network_address[MAX_BITS];
    for (int i = 0; i < OCTETS_PER_ADDRESS; i++) {
        unsigned int octet = 0;
        for (int j = 0; j < BITS_PER_OCTET; j++) {
            octet |= (network_address_binary[i * BITS_PER_OCTET + j] == '1') << (BITS_PER_OCTET - 1 - j);
        }
        network_address[i] = octet;
    }

    // Calculate the broadcast address
    char broadcast_address_binary[MAX_BITS];
    for (int i = 0; i < MAX_BITS; i++) {
        broadcast_address_binary[i] = (ip_address_binary[i] | ~subnet_mask_binary[i]) ? '1' : '0';
    }

    // Convert the broadcast address back to decimal
    char broadcast_address[MAX_BITS];
    for (int i = 0; i < OCTETS_PER_ADDRESS; i++) {
        unsigned int octet = 0;
        for (int j = 0; j < BITS_PER_OCTET; j++) {
            octet |= (broadcast_address_binary[i * BITS_PER_OCTET + j] == '1') << (BITS_PER_OCTET - 1 - j);
        }
        broadcast_address[i] = octet;
    }

    // Calculate the number of subnets
    unsigned int num_subnets = pow(2, 32 - subnet_mask_binary[0]);

    // Calculate the number of hosts per subnet
    unsigned int num_hosts_per_subnet = pow(2, 32 - subnet_mask_binary[3]);

    // Calculate the gateway address
    char gateway_address[MAX_BITS];
    for (int i = 0; i < OCTETS_PER_ADDRESS; i++) {
        gateway_address[i] = network_address[i];
    }
    gateway_address[OCTETS_PER_ADDRESS - 1] += 1;

    // Calculate the DNS server address
    char dns_server_address[MAX_BITS];
    for (int i = 0; i < OCTETS_PER_ADDRESS; i++) {
        dns_server_address[i] = network_address[i];
    }
    dns_server_address[OCTETS_PER_ADDRESS - 1] += 2;

    // Store the results in the structure
    strcpy(results.subnet_mask, subnet_mask);
    strcpy(results.network_address, network_address);
    strcpy(results.broadcast_address, broadcast_address);
    results.num_subnets = num_subnets;
    results.num_hosts_per_subnet = num_hosts_per_subnet;
    strcpy(results.gateway_address, gateway_address);
    strcpy(results.dns_server_address, dns_server_address);

    return results;
}

// Function to print the subnet calculator results
void print_results(subnet_calculator_results results) {
    printf("Subnet Mask: %s\n", results.subnet_mask);
    printf("Network Address: %s\n", results.network_address);
    printf("Broadcast Address: %s\n", results.broadcast_address);
    printf("Number of Subnets: %u\n", results.num_subnets);
    printf("Number of Hosts per Subnet: %u\n", results.num_hosts_per_subnet);
    printf("Gateway Address: %s\n", results.gateway_address);
    printf("DNS Server Address: %s\n", results.dns_server_address);
}

// Main function
int main() {
    // Get the IP address and subnet mask from the user
    char ip_address[MAX_BITS];
    char subnet_mask[MAX_BITS];
    printf("Enter the IP address: ");
    scanf("%s", ip_address);
    printf("Enter the subnet mask: ");
    scanf("%s", subnet_mask);

    // Calculate the subnet calculator results
    subnet_calculator_results results = calculate_subnet(ip_address, subnet_mask);

    // Print the subnet calculator results
    print_results(results);

    return 0;
}