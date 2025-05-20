//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 16

typedef struct {
    unsigned char octets[4];
} IPAddress;

typedef struct {
    IPAddress network;
    IPAddress broadcast;
    int subnetMask;
    int totalHosts;
} Subnet;

void parseIP(char *ipStr, IPAddress *ip) {
    sscanf(ipStr, "%hhu.%hhu.%hhu.%hhu", &ip->octets[0], &ip->octets[1], &ip->octets[2], &ip->octets[3]);
}

void printIP(IPAddress ip) {
    printf("%d.%d.%d.%d", ip.octets[0], ip.octets[1], ip.octets[2], ip.octets[3]);
}

void calculateSubnet(IPAddress ip, int subnetMask, Subnet *subnet) {
    unsigned int mask = (1 << (32 - subnetMask)) - 1;
    unsigned int networkAddr = (ip.octets[0] << 24) | (ip.octets[1] << 16) | (ip.octets[2] << 8) | ip.octets[3];
    
    subnet->network.octets[0] = (networkAddr >> 24) & 0xFF;
    subnet->network.octets[1] = (networkAddr >> 16) & 0xFF;
    subnet->network.octets[2] = (networkAddr >> 8) & 0xFF;
    subnet->network.octets[3] = networkAddr & 0xFF;

    subnet->totalHosts = (1 << (32 - subnetMask)) - 2; // 2 less for network and broadcast address
    subnet->broadcast.octets[0] = subnet->network.octets[0] | (mask >> 24);
    subnet->broadcast.octets[1] = subnet->network.octets[1] | ((mask >> 16) & 0xFF);
    subnet->broadcast.octets[2] = subnet->network.octets[2] | ((mask >> 8) & 0xFF);
    subnet->broadcast.octets[3] = subnet->network.octets[3] | (mask & 0xFF);

    subnet->subnetMask = subnetMask;
}

void displaySubnet(Subnet subnet) {
    printf("Network Address: ");
    printIP(subnet.network);
    printf("\nBroadcast Address: ");
    printIP(subnet.broadcast);
    printf("\nSubnet Mask: /%d\n", subnet.subnetMask);
    printf("Total Hosts: %d\n", subnet.totalHosts);
}

int main() {
    char ipStr[16];
    int subnetMask;
    Subnet subnet;

    printf("Enter the IP address (e.g., 192.168.1.1): ");
    scanf("%15s", ipStr);

    printf("Enter the Subnet Mask (e.g., 24 for /24): ");
    scanf("%d", &subnetMask);

    if (subnetMask < 0 || subnetMask > 30) {
        printf("Invalid subnet mask. It must be between 0 and 30.\n");
        return 1;
    }

    IPAddress ip;
    parseIP(ipStr, &ip);
    calculateSubnet(ip, subnetMask, &subnet);
    displaySubnet(subnet);

    return 0;
}