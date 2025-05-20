//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    char ip_address[16]; // IPv4 address
    int subnet_mask; // Subnet mask
    int num_hosts; // Number of hosts per subnet
    int num_subnets; // Number of subnets
    int host_id; // Host ID
    int subnet_id; // Subnet ID
    int broadcast_address; // Broadcast address
    int network_address; // Network address
    int wildcard_mask; // Wildcard mask

    // Get the IP address from the user
    printf("Enter the IPv4 address: ");
    scanf("%s", ip_address);

    // Get the subnet mask from the user
    printf("Enter the subnet mask: ");
    scanf("%d", &subnet_mask);

    // Calculate the number of hosts per subnet
    num_hosts = (1 << (32 - subnet_mask)) - 2;

    // Calculate the number of subnets
    num_subnets = (1 << subnet_mask);

    // Calculate the host ID
    host_id = strtoul(ip_address, NULL, 10) & ((1 << (32 - subnet_mask)) - 1);

    // Calculate the subnet ID
    subnet_id = strtoul(ip_address, NULL, 10) & strtoul("255.255.255.0", NULL, 10);

    // Calculate the broadcast address
    broadcast_address = strtoul(ip_address, NULL, 10) | ((1 << (32 - subnet_mask)) - 1);

    // Calculate the network address
    network_address = strtoul(ip_address, NULL, 10) & ~((1 << (32 - subnet_mask)) - 1);

    // Calculate the wildcard mask
    wildcard_mask = ~((1 << (32 - subnet_mask)) - 1);

    // Print the results
    printf("\nSubnet Calculator Results:\n");
    printf("-----------------------------------------\n");
    printf("IP Address: %s\n", ip_address);
    printf("Subnet Mask: %d\n", subnet_mask);
    printf("Number of Hosts per Subnet: %d\n", num_hosts);
    printf("Number of Subnets: %d\n", num_subnets);
    printf("Host ID: %d\n", host_id);
    printf("Subnet ID: %d\n", subnet_id);
    printf("Broadcast Address: %d\n", broadcast_address);
    printf("Network Address: %d\n", network_address);
    printf("Wildcard Mask: %d\n", wildcard_mask);

    return 0;
}