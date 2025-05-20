//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    // Declare variables
    char ip[16], mask[16], network[16], broadcast[16];
    int i, j, k, m, n;

    // Get input from user
    printf("Enter IP address: ");
    scanf("%s", ip);

    // Convert IP address to integer
    int ipInt = inet_addr(ip);

    // Get input from user
    printf("Enter subnet mask: ");
    scanf("%s", mask);

    // Convert subnet mask to integer
    int maskInt = inet_addr(mask);

    // Get network address
    for (i = 0; i < 4; i++) {
        if ((ipInt & (0xFF000000 >> (8 * i))) == 0) {
            network[i] = '0';
        }
        else {
            network[i] = '1';
        }
    }

    // Get broadcast address
    for (i = 0; i < 4; i++) {
        if ((ipInt & (0xFF000000 >> (8 * i))) == 0) {
            broadcast[i] = '0';
        }
        else {
            broadcast[i] = '1';
        }
    }

    // Get number of hosts
    int hosts = 0;
    for (i = 0; i < 4; i++) {
        if (broadcast[i] == '1') {
            hosts++;
        }
    }

    // Get number of subnets
    int subnets = 0;
    while ((ipInt & (0xFF000000 >> (8 * subnets))) == 0) {
        subnets++;
    }

    // Calculate number of hosts per subnet
    int hostsPerSubnet = pow(2, 8 - subnets);

    // Print results
    printf("\nIP address: %s\n", ip);
    printf("Subnet mask: %s\n", mask);
    printf("Network address: %s\n", network);
    printf("Broadcast address: %s\n", broadcast);
    printf("Number of hosts: %d\n", hosts);
    printf("Number of subnets: %d\n", subnets);
    printf("Hosts per subnet: %d\n", hostsPerSubnet);

    return 0;
}