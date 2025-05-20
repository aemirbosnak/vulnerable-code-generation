//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    struct sockaddr_in addr;
    char *ip_addr;
    int i, j, k, l, m, n;
    unsigned int mask;
    long int ip_num;
    int network_addr, broadcast_addr, usable_hosts;
    int octet[4];
    char subnet_mask[16], wildcard_mask[16], network_id[16], broadcast_id[16];

    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    ip_addr = argv[1];

    // Convert the IP address to a 32-bit integer
    ip_num = inet_addr(ip_addr);

    // Extract the octets from the IP address
    for (i = 0; i < 4; i++) {
        octet[i] = (ip_num >> (24 - 8 * i)) & 0xFF;
    }

    // Print the octets in dotted decimal notation
    printf("IP address: %d.%d.%d.%d\n", octet[0], octet[1], octet[2], octet[3]);

    // Get the subnet mask
    printf("Enter the subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnet_mask);

    // Convert the subnet mask to a 32-bit integer
    mask = inet_addr(subnet_mask);

    // Extract the octets from the subnet mask
    for (i = 0; i < 4; i++) {
        octet[i] = (mask >> (24 - 8 * i)) & 0xFF;
    }

    // Print the octets in dotted decimal notation
    printf("Subnet mask: %d.%d.%d.%d\n", octet[0], octet[1], octet[2], octet[3]);

    // Calculate the network address
    network_addr = ip_num & mask;

    // Convert the network address to a dotted decimal string
    for (i = 0; i < 4; i++) {
        octet[i] = (network_addr >> (24 - 8 * i)) & 0xFF;
    }

    sprintf(network_id, "%d.%d.%d.%d", octet[0], octet[1], octet[2], octet[3]);

    // Print the network address
    printf("Network address: %s\n", network_id);

    // Calculate the broadcast address
    broadcast_addr = network_addr | ~mask;

    // Convert the broadcast address to a dotted decimal string
    for (i = 0; i < 4; i++) {
        octet[i] = (broadcast_addr >> (24 - 8 * i)) & 0xFF;
    }

    sprintf(broadcast_id, "%d.%d.%d.%d", octet[0], octet[1], octet[2], octet[3]);

    // Print the broadcast address
    printf("Broadcast address: %s\n", broadcast_id);

    // Calculate the number of usable hosts
    usable_hosts = (broadcast_addr - network_addr) - 2;

    // Print the number of usable hosts
    printf("Number of usable hosts: %d\n", usable_hosts);

    // Calculate the wildcard mask
    for (i = 0; i < 4; i++) {
        octet[i] = ~octet[i];
    }

    sprintf(wildcard_mask, "%d.%d.%d.%d", octet[0], octet[1], octet[2], octet[3]);

    // Print the wildcard mask
    printf("Wildcard mask: %s\n", wildcard_mask);

    return 0;
}