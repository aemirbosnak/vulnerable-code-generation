//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Define the network class structures
typedef enum
{
    CLASS_A,
    CLASS_B,
    CLASS_C
} network_class;

typedef struct
{
    uint32_t ip_address;
    uint32_t subnet_mask;
    uint32_t network_address;
    uint32_t broadcast_address;
    uint32_t number_of_hosts;
} subnet_info;

// Define the function prototypes
network_class get_network_class(uint32_t ip_address);
subnet_info calculate_subnet_info(uint32_t ip_address, uint32_t subnet_mask);
void print_subnet_info(subnet_info subnet);

int main()
{
    // Declare the variables
    uint32_t ip_address, subnet_mask;

    // Prompt the user for the IP address
    printf("Enter the IP address (e.g., 192.168.1.1): ");
    scanf("%u", &ip_address);

    // Prompt the user for the subnet mask
    printf("Enter the subnet mask (e.g., 255.255.255.0): ");
    scanf("%u", &subnet_mask);

    // Get the network class
    network_class network_class = get_network_class(ip_address);

    // Calculate the subnet information
    subnet_info subnet_info = calculate_subnet_info(ip_address, subnet_mask);

    // Print the subnet information
    printf("\nSubnet Information:\n");
    printf("Network class: ");
    switch (network_class)
    {
    case CLASS_A:
        printf("Class A");
        break;
    case CLASS_B:
        printf("Class B");
        break;
    case CLASS_C:
        printf("Class C");
        break;
    default:
        printf("Invalid network class");
        break;
    }
    printf("\nIP address: %s\n", inet_ntoa(*(struct in_addr *)&ip_address));
    printf("Subnet mask: %s\n", inet_ntoa(*(struct in_addr *)&subnet_mask));
    printf("Network address: %s\n", inet_ntoa(*(struct in_addr *)&subnet_info.network_address));
    printf("Broadcast address: %s\n", inet_ntoa(*(struct in_addr *)&subnet_info.broadcast_address));
    printf("Number of hosts: %u\n", subnet_info.number_of_hosts);

    return 0;
}

// Get the network class
network_class get_network_class(uint32_t ip_address)
{
    // Check the first octet of the IP address
    uint8_t first_octet = (ip_address >> 24) & 0xFF;
    if (first_octet >= 1 && first_octet <= 127)
    {
        return CLASS_A;
    }
    else if (first_octet >= 128 && first_octet <= 191)
    {
        return CLASS_B;
    }
    else if (first_octet >= 192 && first_octet <= 223)
    {
        return CLASS_C;
    }
    else
    {
        return -1; // Invalid network class
    }
}

// Calculate the subnet information
subnet_info calculate_subnet_info(uint32_t ip_address, uint32_t subnet_mask)
{
    // Create a subnet_info structure
    subnet_info subnet;

    // Calculate the network address
    subnet.network_address = ip_address & subnet_mask;

    // Calculate the broadcast address
    subnet.broadcast_address = subnet.network_address | ~subnet_mask;

    // Calculate the number of hosts
    subnet.number_of_hosts = (1 << (32 - ntohl(subnet_mask))) - 2;

    // Return the subnet_info structure
    return subnet;
}

// Print the subnet information
void print_subnet_info(subnet_info subnet)
{
    // Print the network address
    printf("Network address: %s\n", inet_ntoa(*(struct in_addr *)&subnet.network_address));

    // Print the broadcast address
    printf("Broadcast address: %s\n", inet_ntoa(*(struct in_addr *)&subnet.broadcast_address));

    // Print the number of hosts
    printf("Number of hosts: %u\n", subnet.number_of_hosts);
}