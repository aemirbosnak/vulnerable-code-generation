//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of bits in an IPv4 address
#define MAX_BITS 32

// Define the structure of an IPv4 address
typedef struct
{
    unsigned char octets[4];
} IPv4_Address;

// Define the structure of a subnet mask
typedef struct
{
    unsigned int bits;
} Subnet_Mask;

// Define the structure of a subnet calculator
typedef struct
{
    IPv4_Address ip_address;
    Subnet_Mask subnet_mask;
    IPv4_Address network_address;
    IPv4_Address broadcast_address;
    unsigned int num_hosts;
} Subnet_Calculator;

// Define the function to initialize a subnet calculator
void initialize_subnet_calculator(Subnet_Calculator *subnet_calculator, char *ip_address, char *subnet_mask)
{
    // Convert the IP address to an IPv4 address structure
    sscanf(ip_address, "%hhu.%hhu.%hhu.%hhu", &subnet_calculator->ip_address.octets[0], &subnet_calculator->ip_address.octets[1], &subnet_calculator->ip_address.octets[2], &subnet_calculator->ip_address.octets[3]);

    // Convert the subnet mask to a Subnet Mask structure
    sscanf(subnet_mask, "%u", &subnet_calculator->subnet_mask.bits);

    // Calculate the network address
    for (int i = 0; i < 4; i++)
    {
        subnet_calculator->network_address.octets[i] = subnet_calculator->ip_address.octets[i] & subnet_calculator->subnet_mask.bits;
    }

    // Calculate the broadcast address
    for (int i = 0; i < 4; i++)
    {
        subnet_calculator->broadcast_address.octets[i] = subnet_calculator->network_address.octets[i] | ~subnet_calculator->subnet_mask.bits;
    }

    // Calculate the number of hosts
    subnet_calculator->num_hosts = pow(2, 32 - subnet_calculator->subnet_mask.bits) - 2;
}

// Define the function to print the subnet calculation results
void print_subnet_calculation_results(Subnet_Calculator *subnet_calculator)
{
    printf("IP Address: %hhu.%hhu.%hhu.%hhu\n", subnet_calculator->ip_address.octets[0], subnet_calculator->ip_address.octets[1], subnet_calculator->ip_address.octets[2], subnet_calculator->ip_address.octets[3]);
    printf("Subnet Mask: %u\n", subnet_calculator->subnet_mask.bits);
    printf("Network Address: %hhu.%hhu.%hhu.%hhu\n", subnet_calculator->network_address.octets[0], subnet_calculator->network_address.octets[1], subnet_calculator->network_address.octets[2], subnet_calculator->network_address.octets[3]);
    printf("Broadcast Address: %hhu.%hhu.%hhu.%hhu\n", subnet_calculator->broadcast_address.octets[0], subnet_calculator->broadcast_address.octets[1], subnet_calculator->broadcast_address.octets[2], subnet_calculator->broadcast_address.octets[3]);
    printf("Number of Hosts: %u\n", subnet_calculator->num_hosts);
}

// Define the main function
int main(int argc, char *argv[])
{
    // Check if the user has provided the correct number of arguments
    if (argc != 3)
    {
        printf("Usage: %s <ip_address> <subnet_mask>\n", argv[0]);
        return 1;
    }

    // Initialize the subnet calculator
    Subnet_Calculator subnet_calculator;
    initialize_subnet_calculator(&subnet_calculator, argv[1], argv[2]);

    // Print the subnet calculation results
    print_subnet_calculation_results(&subnet_calculator);

    return 0;
}