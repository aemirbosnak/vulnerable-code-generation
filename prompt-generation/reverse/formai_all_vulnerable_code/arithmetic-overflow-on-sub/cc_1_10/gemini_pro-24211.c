//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Declare variables
    int cidr, num_hosts, num_networks, num_subnets, subnet_mask, host_mask;
    char ip_addr[16];
    char subnet_mask_str[16];
    char host_mask_str[16];

    // Get user input
    printf("Enter the IP address: ");
    scanf("%s", ip_addr);

    printf("Enter the CIDR notation: ");
    scanf("%d", &cidr);

    // Calculate the number of hosts and networks
    num_hosts = (1 << (32 - cidr)) - 2;
    num_networks = (1 << cidr) - 1;

    // Calculate the subnet mask and host mask
    subnet_mask = 0xFFFFFFFF << (32 - cidr);
    host_mask = ~subnet_mask;

    // Convert the subnet mask and host mask to strings
    sprintf(subnet_mask_str, "%d.%d.%d.%d",
        (subnet_mask >> 24) & 0xFF,
        (subnet_mask >> 16) & 0xFF,
        (subnet_mask >> 8) & 0xFF,
        subnet_mask & 0xFF);

    sprintf(host_mask_str, "%d.%d.%d.%d",
        (host_mask >> 24) & 0xFF,
        (host_mask >> 16) & 0xFF,
        (host_mask >> 8) & 0xFF,
        host_mask & 0xFF);

    // Calculate the number of subnets
    num_subnets = num_hosts / 256;

    // Print the results
    printf("\nSubnet Calculator Results:\n");
    printf("IP Address: %s\n", ip_addr);
    printf("CIDR Notation: %d\n", cidr);
    printf("Number of Hosts: %d\n", num_hosts);
    printf("Number of Networks: %d\n", num_networks);
    printf("Number of Subnets: %d\n", num_subnets);
    printf("Subnet Mask: %s\n", subnet_mask_str);
    printf("Host Mask: %s\n", host_mask_str);

    return 0;
}