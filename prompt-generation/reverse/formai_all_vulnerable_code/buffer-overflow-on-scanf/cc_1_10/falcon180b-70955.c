//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip_address[16];
    char subnet_mask[16];
    char network_address[16];
    int num_of_hosts;

    // Ask user for IP address
    printf("Enter IP address: ");
    scanf("%s", ip_address);

    // Ask user for subnet mask
    printf("Enter subnet mask: ");
    scanf("%s", subnet_mask);

    // Convert IP address and subnet mask to binary
    int ip_binary[4];
    int subnet_binary[4];
    for (int i = 0; i < 4; i++) {
        ip_binary[i] = atoi(ip_address + (i * 3));
        subnet_binary[i] = atoi(subnet_mask + (i * 3));
    }

    // Calculate network address
    for (int i = 0; i < 4; i++) {
        if (subnet_binary[i] == 0) {
            network_address[i * 3] = '0';
            network_address[(i * 3) + 1] = '0';
            network_address[(i * 3) + 2] = '0';
        } else if (subnet_binary[i] == 1) {
            network_address[i * 3] = '0';
            network_address[(i * 3) + 1] = '0';
            network_address[(i * 3) + 2] = '1';
        } else {
            network_address[i * 3] = '1';
            network_address[(i * 3) + 1] = '0';
            network_address[(i * 3) + 2] = '0';
        }
    }
    network_address[9] = '\0';

    // Calculate number of hosts
    int num_of_subnets = 32 - subnet_binary[0] - subnet_binary[1] - subnet_binary[2];
    num_of_hosts = pow(2, num_of_subnets) - 2;

    // Print results
    printf("Network address: %s\n", network_address);
    printf("Number of hosts: %d\n", num_of_hosts);

    return 0;
}