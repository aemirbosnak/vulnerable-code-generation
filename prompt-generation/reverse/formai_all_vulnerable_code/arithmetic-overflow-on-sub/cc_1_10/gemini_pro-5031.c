//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Define the structure of the subnet
    struct subnet {
        unsigned long subnet_address;
        unsigned long subnet_mask;
        unsigned long broadcast_address;
        unsigned long network_address;
        unsigned long usable_host_range;
        unsigned long total_hosts;
        unsigned long prefix_length;
    };

    // Declare the variables
    struct subnet subnet;
    unsigned long ip_address;
    unsigned long subnet_mask;
    int prefix_length;

    // Get the input from the user
    printf("Enter the IP address: ");
    scanf("%lu", &ip_address);
    printf("Enter the subnet mask: ");
    scanf("%lu", &subnet_mask);
    printf("Enter the prefix length: ");
    scanf("%d", &prefix_length);

    // Calculate the subnet address
    subnet.subnet_address = ip_address & subnet_mask;

    // Calculate the broadcast address
    subnet.broadcast_address = subnet.subnet_address | ~subnet_mask;

    // Calculate the network address
    subnet.network_address = subnet.subnet_address & ~(~0 << prefix_length);

    // Calculate the usable host range
    subnet.usable_host_range = subnet.broadcast_address - subnet.network_address - 1;

    // Calculate the total number of hosts
    subnet.total_hosts = pow(2, 32 - prefix_length) - 2;

    // Print the output
    printf("Subnet Address: %lu\n", subnet.subnet_address);
    printf("Broadcast Address: %lu\n", subnet.broadcast_address);
    printf("Network Address: %lu\n", subnet.network_address);
    printf("Usable Host Range: %lu\n", subnet.usable_host_range);
    printf("Total Hosts: %lu\n", subnet.total_hosts);

    return 0;
}