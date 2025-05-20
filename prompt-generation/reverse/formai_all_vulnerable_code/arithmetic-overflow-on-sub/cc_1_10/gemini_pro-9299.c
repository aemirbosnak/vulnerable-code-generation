//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned long ip;
    unsigned int cidr;
    unsigned long subnet_mask;
    unsigned long broadcast_address;
    unsigned long network_address;
    unsigned long host_min;
    unsigned long host_max;
    unsigned int num_hosts;
} subnet_info;

int main() {
    subnet_info subnet;

    // Get the IP address and CIDR from the user.
    printf("Enter the IP address: ");
    scanf("%lu", &subnet.ip);
    printf("Enter the CIDR: ");
    scanf("%u", &subnet.cidr);

    // Calculate the subnet mask.
    subnet.subnet_mask = ~(0xFFFFFFFF << subnet.cidr);

    // Calculate the broadcast address.
    subnet.broadcast_address = subnet.ip | ~subnet.subnet_mask;

    // Calculate the network address.
    subnet.network_address = subnet.ip & subnet.subnet_mask;

    // Calculate the first and last host addresses.
    subnet.host_min = subnet.network_address + 1;
    subnet.host_max = subnet.broadcast_address - 1;

    // Calculate the number of hosts.
    subnet.num_hosts = (1 << (32 - subnet.cidr)) - 2;

    // Print the subnet information.
    printf("Subnet Information:\n");
    printf("IP Address: %lu\n", subnet.ip);
    printf("CIDR: %u\n", subnet.cidr);
    printf("Subnet Mask: %lu\n", subnet.subnet_mask);
    printf("Broadcast Address: %lu\n", subnet.broadcast_address);
    printf("Network Address: %lu\n", subnet.network_address);
    printf("First Host Address: %lu\n", subnet.host_min);
    printf("Last Host Address: %lu\n", subnet.host_max);
    printf("Number of Hosts: %u\n", subnet.num_hosts);

    return 0;
}