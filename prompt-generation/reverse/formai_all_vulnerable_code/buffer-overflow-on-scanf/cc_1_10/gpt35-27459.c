//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to convert subnet mask from CIDR notation to dotted decimal notation
void cidr_to_ddn(unsigned int cidr, char* ddn) {
    unsigned int mask = 0xffffffff << (32 - cidr);
    sprintf(ddn, "%d.%d.%d.%d", (mask & 0xff000000) >> 24,
                                (mask & 0x00ff0000) >> 16,
                                (mask & 0x0000ff00) >> 8,
                                (mask & 0x000000ff));
}

// Helper function to convert dotted decimal subnet mask to CIDR notation
unsigned int ddn_to_cidr(char* ddn) {
    unsigned int cidr = 0;
    char* token;
    token = strtok(ddn, ".");
    while (token != NULL) {
        cidr += 8 - __builtin_popcount(atoi(token));
        token = strtok(NULL, ".");
    }
    return cidr;
}

// Main program
int main() {
    // Declare variables
    char ip[16], mask[16], network[16], broadcast[16];
    unsigned int cidr, net_addr, bcast_addr, hosts;

    // Get input from user
    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter subnet mask in dotted decimal notation: ");
    scanf("%s", mask);

    // Calculate network address, broadcast address, and number of hosts
    cidr = ddn_to_cidr(mask);
    cidr_to_ddn(cidr, mask);
    net_addr = inet_addr(ip) & inet_addr(mask);
    bcast_addr = net_addr | ~inet_addr(mask);
    hosts = (~inet_addr(mask)) & 0x7fffffff;

    // Convert network address and broadcast address to dotted decimal notation
    sprintf(network, "%d.%d.%d.%d", (net_addr & 0xff000000) >> 24,
                                      (net_addr & 0x00ff0000) >> 16,
                                      (net_addr & 0x0000ff00) >> 8,
                                      (net_addr & 0x000000ff));
    sprintf(broadcast, "%d.%d.%d.%d", (bcast_addr & 0xff000000) >> 24,
                                         (bcast_addr & 0x00ff0000) >> 16,
                                         (bcast_addr & 0x0000ff00) >> 8,
                                         (bcast_addr & 0x000000ff));

    // Display results
    printf("\nIPv4 Address:\t\t%s\n", ip);
    printf("Subnet Mask:\t\t%s\n", mask);
    printf("CIDR Notation:\t\t/%d\n", cidr);
    printf("Network Address:\t%s\n", network);
    printf("Broadcast Address:\t%s\n", broadcast);
    printf("Number of Hosts:\t%d\n", hosts);

    return 0;
}