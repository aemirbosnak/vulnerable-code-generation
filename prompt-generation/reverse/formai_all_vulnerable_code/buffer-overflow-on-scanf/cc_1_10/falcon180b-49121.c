//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {

    char ip_address[MAX_SIZE];
    char subnet_mask[MAX_SIZE];
    char broadcast_address[MAX_SIZE];
    char network_address[MAX_SIZE];
    int num_hosts;
    int i;

    // Get IP address from user
    printf("Enter IP address: ");
    scanf("%s", ip_address);

    // Get subnet mask from user
    printf("Enter subnet mask: ");
    scanf("%s", subnet_mask);

    // Convert IP address and subnet mask to integer representation
    int ip_int = inet_addr(ip_address);
    int subnet_int = inet_addr(subnet_mask);

    // Calculate number of hosts in the subnet
    int num_bits = 0;
    while (subnet_int!= 0) {
        if (subnet_int & 1) {
            num_bits++;
        }
        subnet_int >>= 1;
    }
    num_hosts = (int)pow(2, num_bits) - 2;

    // Calculate network address
    int network_int = ip_int & subnet_int;

    // Convert network address to dotted decimal notation
    sprintf(network_address, "%d.%d.%d.%d", (network_int >> 24) & 0xFF,
            (network_int >> 16) & 0xFF, (network_int >> 8) & 0xFF, network_int & 0xFF);

    // Calculate broadcast address
    int broadcast_int = network_int | ~subnet_int;

    // Convert broadcast address to dotted decimal notation
    sprintf(broadcast_address, "%d.%d.%d.%d", (broadcast_int >> 24) & 0xFF,
            (broadcast_int >> 16) & 0xFF, (broadcast_int >> 8) & 0xFF, broadcast_int & 0xFF);

    // Print results
    printf("IP address: %s\n", ip_address);
    printf("Subnet mask: %s\n", subnet_mask);
    printf("Network address: %s\n", network_address);
    printf("Broadcast address: %s\n", broadcast_address);
    printf("Number of hosts: %d\n", num_hosts);

    return 0;
}