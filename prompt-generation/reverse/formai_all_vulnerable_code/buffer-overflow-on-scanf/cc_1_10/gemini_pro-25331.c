//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Structure to store subnet information
typedef struct subnet {
    unsigned int address;
    unsigned int netmask;
    unsigned int broadcast;
    unsigned int first_host;
    unsigned int last_host;
    unsigned int num_hosts;
} subnet_t;

// Function to calculate subnet information
subnet_t calculate_subnet(unsigned int address, unsigned int netmask) {
    subnet_t subnet;

    // Get subnet address
    subnet.address = address & netmask;

    // Get broadcast address
    subnet.broadcast = subnet.address | ~netmask;

    // Get first host address
    subnet.first_host = subnet.address + 1;

    // Get last host address
    subnet.last_host = subnet.broadcast - 1;

    // Get number of hosts
    subnet.num_hosts = ~netmask & 0xFFFFFFFF;

    return subnet;
}

// Function to print subnet information
void print_subnet(subnet_t subnet) {
    char address_str[INET_ADDRSTRLEN];
    char netmask_str[INET_ADDRSTRLEN];
    char broadcast_str[INET_ADDRSTRLEN];
    char first_host_str[INET_ADDRSTRLEN];
    char last_host_str[INET_ADDRSTRLEN];

    // Convert addresses to strings
    inet_ntop(AF_INET, &subnet.address, address_str, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &subnet.netmask, netmask_str, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &subnet.broadcast, broadcast_str, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &subnet.first_host, first_host_str, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &subnet.last_host, last_host_str, INET_ADDRSTRLEN);

    // Print subnet information
    printf("Subnet Address: %s\n", address_str);
    printf("Netmask: %s\n", netmask_str);
    printf("Broadcast Address: %s\n", broadcast_str);
    printf("First Host Address: %s\n", first_host_str);
    printf("Last Host Address: %s\n", last_host_str);
    printf("Number of Hosts: %d\n", subnet.num_hosts);
}

int main() {
    // Get user input
    char address_str[INET_ADDRSTRLEN];
    char netmask_str[INET_ADDRSTRLEN];
    printf("Enter the subnet address: ");
    scanf("%s", address_str);
    printf("Enter the netmask: ");
    scanf("%s", netmask_str);

    // Convert addresses to unsigned integers
    unsigned int address = inet_addr(address_str);
    unsigned int netmask = inet_addr(netmask_str);

    // Calculate subnet information
    subnet_t subnet = calculate_subnet(address, netmask);

    // Print subnet information
    print_subnet(subnet);

    return 0;
}