//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 5

typedef struct {
    unsigned char octets[4];
    unsigned char mask;
} IPAddress;

int main() {
    // Define some funny variables
    char *ip_addr = "192.168.1.1";
    char *mask = "24";
    int num_hosts = 254;
    char *broadcast_addr = "192.168.1.255";

    // Create an IPAddress struct
    IPAddress ip;
    memset(&ip, 0, sizeof(IPAddress));

    // Parse the IP address
    if (sscanf(ip_addr, "%hhu.%hhu.%hhu.%hhu", &ip.octets[0], &ip.octets[1], &ip.octets[2], &ip.octets[3]) != 4) {
        printf("Invalid IP address: %s\n", ip_addr);
        return 1;
    }

    // Parse the subnet mask
    if (sscanf(mask, "%hhu", &ip.mask) != 1) {
        printf("Invalid subnet mask: %s\n", mask);
        return 1;
    }

    // Calculate the number of hosts
    num_hosts = (1 << (32 - ip.mask)) - 2;

    // Calculate the broadcast address
    ip.octets[3] |= (1 << (8 - (ip.mask % 8))) - 1;
    sprintf(broadcast_addr, "%hhu.%hhu.%hhu.%hhu", ip.octets[0], ip.octets[1], ip.octets[2], ip.octets[3]);

    // Print the results
    printf("IP address: %s\n", ip_addr);
    printf("Subnet mask: %s\n", mask);
    printf("Number of hosts: %d\n", num_hosts);
    printf("Broadcast address: %s\n", broadcast_addr);

    return 0;
}