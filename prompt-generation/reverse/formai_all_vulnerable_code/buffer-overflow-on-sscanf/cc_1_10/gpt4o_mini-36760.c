//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define IP_LEN 16
#define MASK_LEN 16

typedef struct {
    uint8_t octets[4];
} IPAddress;

void splitIP(const char* ip_str, IPAddress* ip) {
    sscanf(ip_str, "%hhu.%hhu.%hhu.%hhu", &ip->octets[0], &ip->octets[1], &ip->octets[2], &ip->octets[3]);
}

IPAddress getSubnetMask(int prefix) {
    IPAddress mask = { .octets = {0, 0, 0, 0} };
    for (int i = 0; i < 4; i++) {
        if (prefix >= 8) {
            mask.octets[i] = 255;
            prefix -= 8;
        } else {
            mask.octets[i] = (uint8_t)(255 << (8 - prefix)) & 255;
            break;
        }
    }
    return mask;
}

IPAddress calculateNetworkAddress(IPAddress* ip, IPAddress* mask) {
    IPAddress network = { .octets = {0, 0, 0, 0} };
    for (int i = 0; i < 4; i++) {
        network.octets[i] = ip->octets[i] & mask->octets[i];
    }
    return network;
}

IPAddress calculateBroadcastAddress(IPAddress* network, IPAddress* mask) {
    IPAddress broadcast = { .octets = {0, 0, 0, 0} };
    for (int i = 0; i < 4; i++) {
        broadcast.octets[i] = network->octets[i] | (~mask->octets[i] & 255);
    }
    return broadcast;
}

unsigned int calculateTotalHosts(int prefix) {
    return (1 << (32 - prefix)) - 2; // Subtracting network and broadcast addresses
}

void printIPAddress(IPAddress* ip) {
    printf("%hhu.%hhu.%hhu.%hhu\n", ip->octets[0], ip->octets[1], ip->octets[2], ip->octets[3]);
}

int main() {
    char ip_str[IP_LEN];
    char mask_str[MASK_LEN];
    int prefix;

    printf("Enter IP address (e.g., 192.168.1.1): ");
    scanf("%s", ip_str);
    printf("Enter subnet mask (e.g., 255.255.255.0) or CIDR prefix (e.g., /24): ");
    scanf("%s", mask_str);

    IPAddress ip;
    splitIP(ip_str, &ip);

    IPAddress mask;
    if (mask_str[0] == '/') {
        prefix = atoi(&mask_str[1]);
        mask = getSubnetMask(prefix);
    } else {
        splitIP(mask_str, &mask);
        prefix = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++) {
                if (mask.octets[i] & (1 << (7 - j))) {
                    prefix++;
                } else {
                    break;
                }
            }
        }
    }

    printf("\nCalculating subnet details...\n");
    IPAddress network = calculateNetworkAddress(&ip, &mask);
    IPAddress broadcast = calculateBroadcastAddress(&network, &mask);
    unsigned int total_hosts = calculateTotalHosts(prefix);

    printf("\nIP Address: ");
    printIPAddress(&ip);
    printf("Subnet Mask: ");
    printIPAddress(&mask);
    printf("Network Address: ");
    printIPAddress(&network);
    printf("Broadcast Address: ");
    printIPAddress(&broadcast);
    printf("Total Usable Hosts: %u\n", total_hosts);

    return 0;
}